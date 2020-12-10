#include "time.hpp"
#include <iostream>
#include <string>

using namespace std;

// set functions
void time::setbeginHour(int h1)
{
    beginHour = h1;
}
void time::setendHour(int h2)
{
    endHour = h2;
}
void time::setbeginMinute(int m1)
{
    beginMinute = m1;
}
void time::setendMinute(int m2)
{
    endMinute = m2;
}

// get functions
int time::getbeginHour()
{
    return beginHour;
}
int time::getendHour()
{
    return endHour;
}
int time::getbeginMinute()
{
    return beginMinute;
}
int time::getendMinute()
{
    return endMinute;
}

// checks if time range is valid
bool time::isValid(int h1,int h2,int m1,int m2)
{
    // checks if hours are not outside of 0-24 time slots and makes sure end time
    // is not greater than start time
    if (h1 > 23 || h2 > 23 || h1 < 0 || h2 < 0 || h1 > h2)
    {
        cout<<"Illegal Input"<<endl;
        cout<<"Invalid Hour Value(s)" <<endl;
      return true;
    }
    // checks if the start minutes are a multiple of 30 minutes
    else if (m1 != 0 && m1 != 30)
    {
        cout<<"Illegal Input"<<endl;
        cout<<"Invalid Minute Value(s)" <<endl;
        return true;
    }
    // checks if the end minutes are a multiple of 30 minutes
    else if (m2 != 0 && m2 != 30)
    {
      cout<<"Illegal Input"<<endl;
      cout<<"Invalid Minute Value(s)" <<endl;
      return true;
    }
    else 
    {
      return false;
    }
    // if all of the above passes returns a 1
}


//Output function for class information of the timerange
void time::outputmembertimerange(double h1, double h2, double m1, double m2)
{
  if ((m1 == 0)&&(m2 == 0))
  {
    cout << "You've chosen " << h1 << ":" << "00" << " to " << h2 << ":" << "00" << endl; 
  }
  else if ((m1 == 30) && (m2 == 0))
  {
    cout << "You've chosen " << h1 << ":" << "30" << " to " << h2 << ":" << "00" << endl; 
  }
  else if ((m1 == 0) && (m2 == 30))
 {
  cout << "You've chosen " << h1 << ":" << "00" << " to " << h2 << ":" << "30" << endl; 
 } 
 else if ((m1 == 30)&& (m2 == 30))
 {
  cout << "You've chosen " << h1 << ":" << "30" << " to " << h2 << ":" << "30" << endl; 
 }
}


//Keep just incase can be implemented//
/*
  bool time::setTime(int h1, int h2, int m1, int m2)
  {
    myArray[48];
    int j[] = convertToArray(int h1, int h2, int m2, int);
    myArray[j] = true;
    return myArray[];
  }
*/

/*
int convertToArray(int h1, int h2, int m1, int m2)
{
  int appointed[48] = {0};
  void printFreeTimeSlots();
  int i1 = 0;
  int i2 = 0;
  if ((m1 == 0) && (m2 == 0))
  {
      i1 = h1 * 2;
      i2 = h2 * 2;
      for (int j = i1; i1 <= i2; i1++)
      {
          return appointed[j];
      }
  }

  if ((m1 != 0) && (m2 != 0))
  {
      i1 = (h1 * 2) + 1;
      i2 = (h2 * 2) + 1;
      for (int j = i1; i1 <= i2; i1++)
      {
        return appointed[j];
      }
  } 

  if ((m1 != 0) && (m2 == 0))
  {
      i1 = (h1 * 2) + 1;
      i2 = h2 * 2;
      for (int j = i1; i1 <= i2; i1++)
      {
        return appointed[j];
      }
  }
  
  if ((m1 == 0) && (m2 != 0))
  {
      i1 = h1 * 2;
      i2 = (h2 * 2) + 1;
      for (int j = i1; i1 <= i2; i1++)
      {
        return appointed[j];
      }
  }
}

*/