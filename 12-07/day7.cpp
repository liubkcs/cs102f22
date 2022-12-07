// day 7 advent of code.

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <map>
using namespace std;

enum NodeType { File, Dir };

class TreeNode {
public:
  TreeNode(NodeType type,
	   string name,
	   TreeNode* parent = nullptr,
	   unsigned size = 0);
  friend ostream& operator << (ostream&, const TreeNode&);
  friend void showTree(ostream&, TreeNode*, string);
  TreeNode* getParent() { return parent; }
  unsigned getSize() { return size; }
  TreeNode* getSubdir(string name) { return entries[name]; }
  unsigned addDirUsages();
  unsigned findDirToDelete(unsigned needToFree);
private:
  TreeNode* parent;
  NodeType type;
  string name;
  unsigned size;
  map<string, TreeNode*> entries;
};

TreeNode::TreeNode(NodeType type,
		   string name,
		   TreeNode* parent,
		   unsigned size)
  : parent(parent), type(type), name(name), size(size)
{
  if(parent) {
    parent->entries[name] = this;
  }
  // When adding a file, add its size to all of its ancestors.
  // (parent, grandparent, great grandparent, etc.)
  if(type == File) {
    for(TreeNode* p = parent; p != nullptr; p = p->parent) {
      p->size += size;
    }
  }
}

ostream& operator << (ostream& os, const TreeNode& t) {
  os << t.name << " (";
  switch(t.type) {
  case Dir:
    os << "dir)";
    break;
  case File:
    os << "file, size=" << t.size << ")";
  }
  return os;
}

void showTree(ostream& os, TreeNode* t, string indent = "") {
  os << indent << "- " << *t;
  if(t->type == Dir) {
    os << " USAGE=" << t->size;
  }
  os << endl;
  for(auto& item : t->entries) {
    showTree(os, item.second, indent+"  ");
  }
}

unsigned TreeNode::addDirUsages() {
  unsigned total = 0;
  if(this->type == Dir && this->size <= 100000) {
    total += this->size;
  }
  for(auto& item : this->entries) {
    total += item.second->addDirUsages(); 
  }
  return total;
}

unsigned TreeNode::findDirToDelete(unsigned needToFree) {
  unsigned toDelete = 70000000;
  if(this->type == Dir && this->size >= needToFree) {
    cout << "DELETE? " << *this << " USAGE="
	 << this->size << endl;
    toDelete = this->size;
  }
  for(auto& item : this->entries) {
    unsigned alternative =
      item.second->findDirToDelete(needToFree);
    if(alternative < toDelete) {
      toDelete = alternative;
    }
  }
  return toDelete;
}

int main()
{
  string line;
  int numLines = 0;
  TreeNode* root = new TreeNode(Dir, "/");
  cout << "ROOT IS " << *root << endl;
  TreeNode* cwd = nullptr;
  while(getline(cin, line)) {
    if(line.at(0) == '$') {	// Command
      if(line.substr(2,2) == "cd") {
	string dest = line.substr(5);
	if(dest == "/") {
	  cwd = root;
	}
	else if(dest == "..") {
	  cwd = cwd->getParent();
	}
	else {
	  cwd = cwd->getSubdir(dest);
	}
	cout << "CD [" << *cwd << "]\n";
      }
      else if(line.substr(2,2) == "ls") {
	cout << "LS\n";
      }
      else {
	cout << "UNKNOWN command: " << line << endl;
	return -1;
      }
    }
    else if(line.substr(0,3) == "dir") {
      string name = line.substr(4);
      // cout << "DIR [" << name << "]\n";
      TreeNode *t = new TreeNode(Dir, name, cwd);
      cout << *t << endl;
    }
    else if(isdigit(line.at(0))) {
      istringstream ss(line);
      int size;
      string name;
      ss >> size >> name; // Assuming no spaces in filename
      // cout << "FILE [" << size << "][" << name << "]\n";
      TreeNode *t = new TreeNode(File, name, cwd, size);
      cout << *t << endl;
    }
    numLines++;
  }
  // cout << numLines << " lines\n";
  cout << "THE TREE!!!!!!!!\n";
  showTree(cout, root);
  cout << root->addDirUsages() << endl;
  const unsigned totalSpace = 70000000;
  const unsigned spaceNeeded = 30000000;
  unsigned freeSpace = totalSpace - root->getSize();
  cout << "freeSpace " << freeSpace << endl;
  unsigned needToFree = spaceNeeded - freeSpace;
  cout << "needToFree " << needToFree << endl;
  cout << root->findDirToDelete(needToFree) << endl;
  return 0;
}
