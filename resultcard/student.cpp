#include <iostream>
#include <fstream>
#include "date.cpp"
#include "list.cpp"
using namespace std;

class Student
{
private:
    string id;
    string name;
    Date dob;
    int age;
    List s1;
    List s2;
    List s3;

public:
    Student(string, string, Date, int, List &, List &, List &);
    void setData(string, string, Date, int, List &, List &, List &);
    void setId(string);
    void setName(string);
    void setDate(Date);
    void setAge(int);
    void setS1(List &);
    void setS2(List &);
    void setS3(List &);
    string getId();
    string getName();
    Date getDate();
    int getAge();
    List &getS1();
    List &getS2();
    List &getS3();
    void printData(const string &filename);
};

Student::Student(string i, string n, Date d, int a, List &s1, List &s2, List &s3)
{
    this->setData(i, n, d, a, s1, s2, s3);
}

void Student::setData(string i, string n, Date d, int a, List &s1, List &s2, List &s3)
{
    setId(i);
    setName(n);
    setDate(d);
    setAge(a);
    setS1(s1);
    setS2(s2);
    setS3(s3);
}

void Student::setId(string i)
{
    id = i;
}

void Student::setName(string n)
{
    name = n;
}

void Student::setDate(Date d)
{
    dob = d;
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setS1(List &l1)
{
    s1 = l1;
}

void Student::setS2(List &l2)
{
    s2 = l2;
}

void Student::setS3(List &l3)
{
    s3 = l3;
}

string Student::getId()
{
    return id;
}

string Student::getName()
{
    return name;
}

Date Student::getDate()
{
    return dob;
}

int Student::getAge()
{
    return age;
}

List &Student::getS1()
{
    return s1;
}

List &Student::getS2()
{
    return s2;
}

List &Student::getS3()
{
    return s3;
}

void Student::printData(const string &filename)
{
    ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << "ID: " << this->getId() << endl;
        outputFile << "Name: " << this->getName() << endl;
        outputFile << "DOB: ";
        this->getDate().printDate(outputFile);
        outputFile << "Age: " << this->getAge() << endl;

        outputFile << "Result Card:" << endl;

        outputFile << "1st Semester:" << endl;
        this->getS1().printList(outputFile);

        outputFile << "2nd Semester:" << endl;
        this->getS2().printList(outputFile);

        outputFile << "3rd Semester:" << endl;
        this->getS3().printList(outputFile);

        outputFile.close();
        cout << "Data stored in the file successfully." << endl;
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

main()
{
    // Result Card
    Date dob(5, 12, 2000);
    List l1(3);
    // Data for 1st semester
    Data d1("GE-161", "Intro to Info. & Comm. Technology", 80, 3);
    Data d2("GE-152", "Probability & Statistics", 35, 3);
    Data d3("CC-111", "Discrete Structures", 55, 3);
    l1.add(d1);
    l1.add(d2);
    l1.add(d3);

    // Data for 2nd semester
    Data d4("CC-112", "Programming Fundamentals", 85, 4);
    Data d5("CC-215", "Digital Logic Design", 85, 4);
    Data d6("GE-164", "Communication and Presentation Skills", 85, 3);
    List l2(3);
    l2.add(d4);
    l2.add(d5);
    l2.add(d6);

    // Data for 3rd semester
    Data d7("CC-114", "OOP", 35, 4);
    Data d8("CC-220", "Computer Organization and Assembly Language", 80, 4);
    Data d9("GE-165", "Professional Ethics", 75, 3);
    List l3(3);
    l3.add(d7);
    l3.add(d8);
    l3.add(d9);

    // Student Result Card
    Student s("BCS21211", "Huzaifa Hameed", dob, 22, l1, l2, l3);
    s.printData("D:/Semester 4/Data Structure and Algorithms/Assignment-1/resultcard.txt");
}
