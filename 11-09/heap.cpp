#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Student {
public:
  Student(string name = "Anonymous",
				  float gpa = 0.0);
  void Print() const;
private:
	string name;
	float gpa;
};

Student::Student(string name, float gpa)
 : name(name), gpa(gpa) {
}

void Student::Print() const {
	cout << setw(5) << setprecision(2) << fixed
       << gpa << " " << name << endl;
}

int main()
{
	vector<Student> roster(5);
	for(Student s : roster) {
		s.Print();
	}
}