//Include necessary libraries//
#include "date.hpp"
#include <iostream>
using namespace std;

const int thanksgivingday = 12;
const int thanksgivingmonth = 10;
const int remembrance = 11;

//get month//
int date::get_month()
{
  return month;
}

//get day//
int date::get_day()
{
  return day;
}

//set month//
void date::set_month(int month)
{
  this->month = month;
}

//set day//
void date::set_day(int day)
{
  this->day = day;
}

//Initialize constructor functions//
date::date(int mon1, int d1)
{
  month = mon1;
  day = d1;

}

//Date constructor set to do nothing//
date::date()
{
  //do nothing
}

//Check if the dates are appropriate with reference to the guidelines//
//If not, output an error statement//
bool date::isValid(int month, int day)
{
  if ((day<1 || day>31)||(month<9 || month>12)||(day<8 && month<9)||(day>20 && month > 11))
  {
    cout<<"Illegal Input"<<endl;
    cout<<"Invalid Date"<<endl;
    return true;
  }
  else if ((month == 9)||(month == 10))
  {
    if (day == 31)
    {
      cout<<"Illegal Input"<<endl;
      cout<<"Invalid Date"<<endl;
      return true;
    }
  }

  return false;
}

//Check if the dates are appropriate regarding the weekend restrictions//
//If not, output an error statement//
bool date::isWeekend(int month, int day)
{
    //All weekend days in september are invalid
    if (month == 9)
  {
    if ((day == 12)||(day == 13)||(day == 19)||(day == 20)||(day == 26)||(day == 27))
    {
      cout<<"Illegal Input"<<endl;
      cout<<"Weekends Are Not Allowed"<<endl;
      return true;
    }
  }
    //All weekend days in october are invalid
  else if (month == 10)
  {
    if ((day == 3)||(day == 4)||(day == 10)||(day == 11)||(day == 17)||(day == 18)||(day == 24)||(day == 25))
    {
      cout<<"Illegal Input"<<endl;
      cout<<"Weekend Are Not Allowed"<<endl;
      return true;

    }
  }
  else if (month == 11)
    {
     //All weekend days in november are invalid
      if ((day == 1)||(day == 7)||(day == 8)||(day == 14)||(day == 15)||(day == 21)||(day == 22)||(day == 28)||(day == 29))
      {
      cout<<"Illegal Input"<<endl;
      cout<<"Weekend Are Not Allowed"<<endl;
      return true;
      }
    }
  else if (month == 12)
  {
  //All weekend days in december are invalid
    if ((day == 5)||(day == 6)||(day == 12)||(day == 13)||(day == 19)||(day == 20)||(day == 26)||(day == 27))
    {
      cout<<"Illegal Input"<<endl;
      cout<<"Weekend Are Not Allowed"<<endl;
      return true;
    }
  }

  return false;
}


//Check if dates are appropriate regarding the holiday restrictions//
//If not, output an error statement//
bool date::isHoliday(int month, int day)
{
  if (month == 10) // Use integer value, const int does not pass through value//
  {
    if (day == 12) // Use integer value, const int does not pass through value//
    {
      cout << "Illegal Input" << endl;
      cout << "Can't book on a Holiday. It is thanksgiving" << endl;
      return true;
    }
  }
  else if (month  == 11) // Use integer value, const int does not pass through value//
  {
    if (day == 11)
    {
      cout << "Illegal Input" << endl;
      cout << "Can't book on a Holiday. It is remembrance day." << endl;
      return true;
    }
  }
  return false;
}

//Output class information regarding hte month choice and date//
void date::outputmembermonth(int month, int day)
{
  if (month == 9)
  {
      cout<<"You've chosen September " << day <<endl;
  }

  else if (month == 10)
  {
      cout<<"You've chosen October " << day <<endl;
  }
  else if (month == 11)
  {
      cout<<"You've chosen November " << day <<endl;
  }

  else if (month == 12)
  {
      cout<<"You've chosen December " << day <<endl;
  }
  else 
  {
    cout<<"Illegal Date: Months must be between September and December" << endl;
    exit(1);
  }
}


//Checks if the first and second date choices are equal and returns true if they are
bool equal(date appointment1,date monthchoice)
{
    if (appointment1.month==monthchoice.month && appointment1.day==monthchoice.day)
    {
      return true;
    }
    else
    {
      return false;
    }
}

//Introduction used for user to decide what course of action they would like to take while using the program
void date::introduction()
{
  
  int introductionchoice;
  cout<<" You have the options below to choose which service you would like... " <<endl;
  cout<<"1- Book an appointment" <<endl;
  cout<<"2- Query an appointment" <<endl;
  cout<<"3- Delete an appointment" <<endl;
  cout<<"4- Exit the program" <<endl;
  cout<<"\n";
  cout<<" Please input a number corresponding with what you want... " <<endl;
  cout<<"\n";
}


//overloading insertion operator function design
ostream& operator<<(ostream &out, const date &Date)
{ 
  //Prints out the free time slots
  
  out << "The booked timeslots are on this month: " << Date.month;
  out<< " and this day " <<Date.day;
  return out;
}