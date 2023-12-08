#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char *name;
    int rollNumber;
    char *className;
    char division;
    char *dob;
    char *bloodGroup;
    char *contactAddress;
    char *telephoneNumber;
    char *drivingLicense;

public:
	static int totalStudents ;
	    // Constructors
    Student();
    Student(const char *n, int roll, const char *cls, char div, const char *dob, const char *blood, const char *contact, const char *tel, const char *license);
    Student(const Student &source);

    // Destructor
    ~Student();

    // Static member function
    static void displayTotalStudents();

    // Friend class
    friend class StudentInfoPrinter;

    // Member functions
    void displayStudentInfo();
    void updateContactInfo(const char *newAddress, const char *newTel);

    // Inline function
    inline const char* getName() const { return name; }

    // Dynamic memory allocation operators
    void* operator new(size_t size);
    void operator delete(void *ptr);

};

// Static member initialization
int Student::totalStudents = 0;

// Static member function definition
void Student::displayTotalStudents() {
    cout << "Total students: " << totalStudents << endl;
}

// Constructor definitions
Student::Student()
 {
   // name = className = dob = bloodGroup = contactAddress = telephoneNumber = drivingLicense = nullptr;
    rollNumber = 0;
    division = '\0';
    totalStudents++;
}


Student::Student(const char *n, int roll, const char *cls, char div, const char *dob, const char *blood, const char *contact, const char *tel, const char *license) {
    name = strdup(n);
    rollNumber = roll;
    className = strdup(cls);
    division = div;
    this->dob = strdup(dob);
    bloodGroup = strdup(blood);
    contactAddress = strdup(contact);
    telephoneNumber = strdup(tel);
    drivingLicense = strdup(license);
    totalStudents++;
}

Student::Student(const Student &source) {
    name = strdup(source.name);
    rollNumber = source.rollNumber;
    className = strdup(source.className);
    division = source.division;
    dob = strdup(source.dob);
    bloodGroup = strdup(source.bloodGroup);
    contactAddress = strdup(source.contactAddress);
    telephoneNumber = strdup(source.telephoneNumber);
    drivingLicense = strdup(source.drivingLicense);
    totalStudents++;
}

// Destructor definition
Student::~Student() {
    delete[] name;
    delete[] className;
    delete[] dob;
    delete[] bloodGroup;
    delete[] contactAddress;
    delete[] telephoneNumber;
    delete[] drivingLicense;
    totalStudents--;
}

// Member function definitions
void Student::displayStudentInfo() {
    cout << "Name: " << name << std::endl;
    cout << "Roll Number: " << rollNumber << std::endl;
    cout << "Class: " << className << std::endl;
    cout << "Division: " << division << std::endl;
    cout << "Date of Birth: " << dob << std::endl;
    cout << "Blood Group: " << bloodGroup << std::endl;
    cout << "Contact Address: " << contactAddress << std::endl;
    cout << "Telephone Number: " << telephoneNumber << std::endl;
    cout << "Driving License: " << drivingLicense << std::endl;
}

void Student::updateContactInfo(const char *newAddress, const char *newTel) {
    delete[] contactAddress;
    delete[] telephoneNumber;
    contactAddress = strdup(newAddress);
    telephoneNumber = strdup(newTel);
}

// Friend class definition
class StudentInfoPrinter {
public:
    void printStudentInfo(const Student &student);
};

// Friend class member function definition
void StudentInfoPrinter::printStudentInfo(const Student &student) {
    cout << "Printing student information using friend class:" << std::endl;
    cout << "Name: " << student.name << std::endl;
    cout << "Roll Number: " << student.rollNumber << std::endl;
    cout << "Class: " << student.className << std::endl;
    cout << "Division: " << student.division << std::endl;
    cout << "Date of Birth: " << student.dob << std::endl;
    cout << "Blood Group: " << student.bloodGroup << std::endl;
    cout << "Contact Address: " << student.contactAddress << std::endl;
    cout << "Telephone Number: " << student.telephoneNumber << std::endl;
    cout << "Driving License: " << student.drivingLicense << std::endl;
}

// Dynamic memory allocation operators definition
void* Student::operator new(size_t size) {
    cout << "Custom new operator called" << std::endl;
    return ::new Student();
}

void Student::operator delete(void* ptr) {
    cout << "Custom delete operator called" <<endl;
    delete ptr;
}

int main() {
    // Create students
    Student s1("Jidnyasa kale", 52, "12A", 'A', "14-11-2003", "B+", "123 Main St", "555-1234", "DL123456");
    Student s2("vaishnavi karle",58, "12B", 'B', "8-10-2003", "O+", "456 Oak St", "555-5678", "DL789012");

    // Display student information
    s1.displayStudentInfo();
    cout<<" another call "<<endl;
    s2.displayStudentInfo();

    // Update contact information
    s1.updateContactInfo("789 Maple St", "555-4321");

    // Display updated information
    s1.displayStudentInfo();

    // Display total number of students using static member function
    Student::displayTotalStudents();

    // Use friend class to print student information
    StudentInfoPrinter printer;
    printer.printStudentInfo(s2);

    // Use new and delete operators
    Student* s3 = new Student("Prerana Patil", 59, "11A", 'C', "15-09-2004", "O+", "987 Pine St", "555-8765", "DL345678");
    s3->displayStudentInfo();
    delete s3;

    return 0;
}
