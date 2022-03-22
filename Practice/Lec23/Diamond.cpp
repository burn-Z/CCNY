#include <iostream>
#include <string>

using namespace std;

struct date
{
	int day = 0;
	int month = 0;
	int year = 0;
};
struct address
{
	string streetName = "-";
	string apt = "-";
	int zipcode = 0;
	string city = "-";
	string state = "-";
};
class CommunityMember {
private:
	int ID = 0;
	string firstName = "None";
	string lastName = "None";
	date DOB;
	address k;
	int SSN = 0;
public:
	void setID(int id) {	this->ID = id;	}
	void setFirstName(string fN) {	this->firstName = fN;	}
	void setLastName(string lN) {	this->lastName = lN;	}
	void setDOB(date d) {	this->DOB = d;	}
	void setAddress(address a) {	this->k = a;	}
	void setSSN(int ssn) {	this->SSN = ssn;	}

	int getID() const {	return this->ID;}
	string getFirsName() const {	return this->firstName;}
	string getLastName() const {	return this->lastName;}
	date getDOB() const {	return this->DOB;}
	address getAddress() const {	return this->k;}
	int getSSN() const {	return this->SSN;}

	virtual void print() = 0;
};

struct course
{
	int courseID = 0;
	int instructorID = 0;
};

class Student : public virtual CommunityMember {
private:
	string major = "";
	double gpa = 0;
	course* enrolled = new course[5];
public:
	void setMajor(string m) {	this->major = m;	}
	void setGpa(double gpa) {	this->gpa = gpa;	}
	void setEnrolled(course* e) {	this->enrolled = e;	}

	string getMajor() const {	return this->major;	}
	double getGpa() const {	return this->gpa;	}
	course* getEnrolled() const {	return this->enrolled;	}

	void print() {
		date d = getDOB();
		address a = getAddress();
		double gpa = getGpa();

		cout << "STUDENT INFO" << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << "Name:\t\t" << getFirsName() << " " << getLastName() << endl;
		cout << "Student ID:\t" << getID() << endl << endl;
		cout << "Birthdate:\t\t" << d.month << "/" << d.day << endl;
		cout << "Student Address:\t" << a.streetName << ", " << a.apt << endl <<
				"\t\t\t" << a.city << ", " << a.state << ", " << a.zipcode <<
				 endl<< endl;
		cout << "\t" << getMajor() << " Major - ";
		cout << (gpa>2? "Good":"Bad");
		cout << " Academic Standing - ";
		cout << "GPA: " << gpa << endl;
	}
};

class Instructor : public virtual CommunityMember {
private:
	string department = "-";
	course* teach = new course[2];
public:
	void setDepartment(string d) {	this->department = d;	}
	void setTeach(course* t) {	this->teach = t;	}

	string getDepartment() const {	return this->department;	}
	course* getTeach() const {	return this->teach;	}

	void print() {
		date d = getDOB();
		address a = getAddress();

		cout << endl << "STAFF INFO" << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << "Name:\t" << getFirsName() << " " << getLastName() << endl;
		cout << "ID:\t" << getID() << endl << endl;
		cout << "Birthdate:\t" << d.month << "/" << d.day << endl;
		cout << "Address:\t" << a.streetName << ", " << a.apt << endl <<
				"\t\t" << a.city << ", " << a.state << ", " << a.zipcode <<
				 endl << endl;
		cout << "Department: " << getDepartment() << endl;
	}
};

class TeachingAssistant : public Student, public Instructor
{
private:
	int advisorID = 0;
public:
	void setAdvisorID(int id) {	this->advisorID = id;	}
	int getAdvisorID() const {	return this->advisorID;	}
	void print() {
		Student::print();
		cout << endl << endl;
		Instructor::print();
		cout << "Advisor ID: " << getAdvisorID() << endl;
	}
};

int main() {
	TeachingAssistant t;
	t.setFirstName("Kevin");
	t.setLastName("Troy");
	t.setID(1235711);
	date dob;
	dob.month = 6;
	dob.day = 18;
	t.setDOB(dob);
	address a;
	a.streetName = "1274 DuPoint St.";
	a.apt = "";
	a.zipcode = 10101;
	a.city = "New York";
	a.state = "NY";
	t.setAddress(a);
	t.setGpa(3.765);
	t.setMajor("Applied Mathematics");
	t.setDepartment("MTH");
	t.setAdvisorID(8085);

	t.print();

	return 0;
}