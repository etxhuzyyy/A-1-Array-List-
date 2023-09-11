#include<iostream>
#include <string>
using namespace std;
int limit[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string monthNames[13]={"Null","January","February","March","April","May","June","July","August","September","Ocotber","November","December"};

class Date
{
		private:
			int day;
			int month;
			int year;
		public:
			Date();
			Date(int,int,int);
			void setDate(int ,int ,int);
			void setDay(int);
			void setMonth(int );
			void setYear(int );
			int getDay();
			int getMonth();
			int getYear();
			void printDate(ofstream& outputFile);
};
Date::Date()
{
    day = 1;
    month = 1;
    year = 1900;
}
Date::Date(int d,int m,int y)
{
		this->setDate(d,m,y);
}
void Date::setDate(int d,int m,int y)
{
		this->setYear(y);
		this->setMonth(m);
		this->setDay(d);
}
void Date::setYear(int y)
{
		year = ((y>=1900&&y<=2023)?y:1900);
}
void Date::setMonth(int m)
{
		month= ((m>=1&&m<=12)?m:1);
}
void Date::setDay(int d)
{
		day = ((d>=1&&d<=limit[this->getMonth()])?d:1);
		if(this->getMonth()==2&&this->getYear()%4==0)
			day=((d>=1&&d<=29)?d:1);
}
int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
		return month;
}
int Date::getYear()
{
		return year;
}
void Date::printDate(ofstream& outputFile) 
{
    outputFile << this->getDay() << "-" << monthNames[this->getMonth()] << "-" << this->getYear() << endl;
}

