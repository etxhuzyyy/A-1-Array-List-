#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Data
{
private:
    string cCode;
    string cName;
    int marks;
    float gpa;
    float cgpa;
    string grade;
    int credits;

public:
    Data();
    Data(string, string, int, int);
    void setData(string, string, int, int);
    void setcCode(string);
    void setcName(string);
    void setMarks(int);
    void setCredits(int);
    void calculateGpaAndGrade();
    string getcCode();
    string getcName();
    int getMarks();
    float getGpa();
    string getGrade();
    int getCredits();
    void printData(ofstream &outputFile);
};
// Default Constructor
Data::Data()
{
    cCode = " ";
    cName = " ";
    marks = 0;
    credits = 0;
    gpa = 0.00;
    grade = "N/A"; // Default grade
}
// Initialize Values
Data::Data(string cCode, string cName, int marks, int credits)
{
    this->setData(cCode, cName, marks, credits);
}
void Data::setData(string c, string n, int m, int cr)
{
    this->setcCode(c);
    this->setcName(n);
    this->setMarks(m);
    this->setCredits(cr);
    calculateGpaAndGrade();
}
// Setter Methods
void Data::setcCode(string c)
{
    cCode = c;
}
void Data::setcName(string n)
{
    cName = n;
}
void Data::setMarks(int m)
{
    if (m >= 0)
    {
        marks = m;
    }
    else
    {
        cout << "Invalid marks value. Please enter a positive number." << endl;
    }
}
void Data::setCredits(int c)
{
    credits = c;
}

// New method to calculate GPA and grade
void Data::calculateGpaAndGrade()
{
    // Define your grading criteria and GPA values here
    if (marks >= 85)
    {
        gpa = 4.0;
        grade = "A";
    }
    else if (marks >= 80)
    {
        gpa = 3.7;
        grade = "A-";
    }
    else if (marks >= 75)
    {
        gpa = 3.3;
        grade = "B+";
    }
    else if (marks >= 70)
    {
        gpa = 3.0;
        grade = "B";
    }
    else if (marks >= 65)
    {
        gpa = 2.7;
        grade = "C+";
    }
    else if (marks >= 60)
    {
        gpa = 2.3;
        grade = "C-";
    }
    else if (marks >= 50)
    {
        gpa = 2.0;
        grade = "D";
    }
    else
    {
        gpa = 2.0;
        grade = "F";
    }
}

// Getter Methods
// Method to get the grade
string Data::getGrade()
{
    return grade;
}
string Data::getcCode()
{
    return cCode;
}
string Data::getcName()
{
    return cName;
}
int Data::getMarks()
{
    return marks;
}
int Data::getCredits()
{
    return credits;
}
float Data::getGpa()
{
    return gpa;
}
void Data::printData(ofstream &outputFile)
{
    outputFile << "Course Code: " << this->getcCode() << endl;
    outputFile << "Course Name: " << this->getcName() << endl;
    outputFile << "Marks: " << this->getMarks() << endl;
    outputFile << "Credit Hours: " << this->getCredits() << endl;
    outputFile << "Grade: " << this->getGrade() << endl;
    outputFile << "GPA: " << this->getGpa() << endl;
}
