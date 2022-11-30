#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;
// Contacts database needs
// each person's NAME and PHONE NUMBER.
// For outgoing calls, I look up by name.
// For incoming calls, we look up by number.
// Want DB to persist across multiple runs.
// CRUD = Create, Retrieve, Update, Delete.

class Contact {
public:
  Contact(string name, string phone);
  bool matches(string query) const;
  unsigned getID() const { return id; }
  void setID(unsigned id) { this->id = id; }
  string getName() const { return name; }
  void setName(string name) { this->name = name; }
  string getPhone() const { return phone; }
  void setPhone(string phone) { this->phone = phone; }
  friend ostream& operator << (ostream&, const Contact&);
private:
  unsigned id;
  string name;
  string phone;
};

ostream& operator << (ostream& out, const Contact& c) {
	out << c.name << endl << c.phone << endl;
	return out;
}


Contact::Contact(string name, string phone)
  : name(name), phone(phone)
{}

bool Contact::matches(string query) const {
	return query == name || query == phone;
}

class Database {
public:
  Database(string filename); // constructor
  ~Database(); // destructor
  unsigned getCount() const;
  Contact* lookup(string query) const;
  void create(Contact* contact);
  void remove(Contact* contact);
private:
  string filename;
  vector<Contact*> data;
};

// Open data file and read data into memory.
Database::Database(string filename) 
  : filename(filename) {
	cout << "Loading " << filename << endl;
	ifstream ifs(filename);
	string name, phone;
	getline(ifs, name);
  getline(ifs, phone);
	while(ifs) {
		create(new Contact(name, phone));
		getline(ifs, name);
		getline(ifs, phone);
	}	
}

// Save all the in-memory data to the file.
Database::~Database() {
	cout << "Saving " << filename << endl;
	ofstream out(filename);
	for(Contact* contact : data) {
		if(contact != nullptr) {
			out << *contact;
		}
	}
}

unsigned Database::getCount() const {
	unsigned count = 0;
	for(Contact* contact : data) {
		if(contact != nullptr) {
			count++;
		}
	}
	return count;
}

Contact* Database::lookup(string query) const {
	for(Contact* contact : data) {
		if(contact != nullptr) {
			if(contact->matches(query)) {
				return contact;
			}
		}
	}
	return nullptr;
}

void Database::create(Contact* contact) {
	contact->setID(data.size()); // Next index
	data.push_back(contact);
}

void Database::remove(Contact* contact) {
	data.at(contact->getID()) = nullptr;
	delete contact;
}

int main()
{
	Database db("contacts.db");
	Contact* result = nullptr;
	while(true) {
		cout << db.getCount() << " contacts> ";
		string query;
		getline(cin, query);
		if(query == "q" || query == "quit") {
			break;
		}
		if(result != nullptr && (query == "d" || query == "delete")) {
			db.remove(result);
			result = nullptr;
			continue;
		}
		if(result != nullptr && (query == "u" || query == "update")) {
			string name, phone;
			cout << "Name [" << result->getName()
				   << "]: ";
			getline(cin, name);
			if(name != "") {
				result->setName(name);
			}
			cout << "Phone [" << result->getPhone()
				   << "]: ";
			getline(cin, phone);
			if(phone != "") {
				result->setPhone(phone);
			}
			continue;
		}
		result = db.lookup(query);
		if(result == nullptr) {
			cout << "Not found: add as Name, Phone, or Ignore? [n/p/I] ";
			string entry, name, phone;
		  getline(cin, entry);
			istringstream iss(entry);
			char choice;
			if(iss >> choice) {
				switch(tolower(choice)) {
					case 'n':
						cout << "Phone: ";
						getline(cin, phone);
						db.create(new Contact(query, phone));
						break;
					case 'p':
						cout << "Name: ";
						getline(cin, name);
						db.create(new Contact(name, query));
						break;
					break;
				}
			}
		}
		else {
			cout << *result;
		}
	}
	return 0;
}