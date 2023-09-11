#include <iostream>
#include <fstream>
#include "data.cpp"
using namespace std;

class List
{
public:
    List();
    List(int);
    void add(Data);
    void printList(ofstream &outputFile);
    void start();
    void tail();
    void next();
    void back();
    void copyList(List);
    void clearList();
    void findData(Data);
    Data getData(int);
    void updateData(Data, int);
    int getLength();
    float calculateSemesterCGPA();
    ~List();

private:
    Data *ptr;
    int length;
    int size;
    int current;
    int totalCredits;
    float totalGradePoints;
};
List::List()
{
}

List::List(int l)
{
    if (l > 0)
    {
        length = l + 1;
        size = 0;
        current = 0;
        ptr = new Data[length];
        totalCredits = 0;
        totalGradePoints = 0.0;
    }
}

void List::add(Data data)
{
    if (size == length)
    {
        cout << "List is full" << endl;
        return;
    }
    ptr[++current] = data;
    size++;
    // Update the total credits and total grade points
    totalCredits += data.getCredits();
    totalGradePoints += (data.getGpa() * data.getCredits());
}

float List::calculateSemesterCGPA()
{
    if (totalCredits > 0)
    {
        return totalGradePoints / totalCredits;
    }
    else
    {
        return 0.0; // Avoid division by zero if there are no courses
    }
}

void List::printList(ofstream &outputFile)
{
    if (size == 0)
    {
        outputFile << "List is empty" << endl;
        return;
    }
    for (int i = 1; i <= size; i++)
    {
        ptr[i].printData(outputFile);
        outputFile << endl;
    }
    // Calculate and print CGPA for the semester
    float semesterCGPA = calculateSemesterCGPA();
    outputFile << "Semester CGPA: " << semesterCGPA << endl;
}

void List::start()
{
    current = 1;
}

void List::tail()
{
    current = size;
}

void List::next()
{
    if (current == size)
    {
        cout << "Current is already at tail" << endl;
    }
    else
    {
        current++;
    }
}

void List::back()
{
    if (current == 1)
    {
        cout << "Current is already at start" << endl;
    }
    else
    {
        current--;
    }
}

void List::copyList(List l)
{
    length = l.length;
    size = l.size;
    current = l.current;
    ptr = new Data[length];
    for (int i = 1; i <= length; i++)
    {
        ptr[i] = l.ptr[i];
    }
}

void List::clearList()
{
    size = 0;
    current = 0;
}

void List::findData(Data data)
{
    for (int i = 1; i <= size; i++)
    {
        if (ptr[i].getcCode() == data.getcCode() &&
            ptr[i].getcName() == data.getcName() &&
            ptr[i].getMarks() == data.getMarks() &&
            ptr[i].getGpa() == data.getGpa())
        {
            cout << "Data found at index: " << i << endl;
            return;
        }
    }
    cout << "Data not found" << endl;
}

Data List::getData(int pos)
{
    if (pos >= 1 && pos <= size)
    {
        return ptr[pos];
    }
    else
    {
        return Data();
    }
}

void List::updateData(Data data, int pos)
{
    if (pos >= 1 && pos <= size)
    {
        ptr[pos] = data;
    }
    else
    {
        cout << "Invalid position" << endl;
    }
}

int List::getLength()
{
    return length;
}

List::~List()
{
    delete[] ptr;
}
