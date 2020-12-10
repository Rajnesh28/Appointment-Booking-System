#include "calendar.hpp"
#include <iostream>
#include <string>
using namespace std;

//Calendar constructor
calendar::calendar()

{
  //Do nothing//
}

//Calendar destructor
calendar::~calendar()

{
  //Do nothing//
}

int j;

//Booking function defition
bool calendar::book(date Date, time timeRange)

{
  //Collects user inputs
  int mon1,day1;
  cout<<" Please choose the month for which you would like to book? (eg. January = 1, February = 2...December = 12) " <<endl;
  mon1 = Date.get_month();
  cin>>mon1;
  cout<< "\n";
  cout<<" Please choose the day for which you like to book? (Holidays and weekends are not allowed)" <<endl;
  day1 = Date.get_day();
  cin>>day1;

  //Checks if the user input is valid before continuing
  if ((Date.isValid(mon1,day1) == false && Date.isWeekend(mon1,day1) == false && Date.isHoliday(mon1,day1) == false))
  {
    //Get functions
    int beginh,endh,beginm,endm, choice;
    cout<<"Please enter the starting hour" <<endl;
    beginh = getbeginHour();
    endh = getendHour();
    beginm = getbeginMinute();
    endm = getbeginMinute();
    
    //Collects user input for times
    cin>>beginh;
    cout<<"\n";
    cout<<"Please enter the starting minute"<<endl;
    cin>>beginm;
    cout<<"\n";
    cout<<"Please enter the ending hour" <<endl;
    cin>>endh;
    cout<<"\n";
    cout<<"Please enter the ending minute"<<endl;
    cin>>endm;
    cout<<"\n";
    
    //Checks once again if the new user input is valid before continuing
    if ((timeRange.isValid(beginh,endh,beginm,endm) == false))
    {
      //Prints the users choices to confirm
        cout<<"You have chosen " << mon1 <<" / " << day1 << " /2020"<<endl;
      cout<<" From " << beginh <<" : " << beginm << " to " << endh << " : " << endm;

      cout<<"\n";
      cout<<"\n";
      cout<<"Processing \n";

      int i1 = 0;
      int i2 = 0;

      //Converts the users hour and minute choices into a timeslot for the array appointed
      if ((beginm == 0) && (endm == 0))
      {
        i1 = beginh * 2;
        i2 = endh * 2;
        for (int j = i1; i1 < i2; i1++)
        {
          //Sets this specific timeslot to be true so it will appear as booked
          timeRange.appointed[mon1][day1][j] = true;
          cout<<"Appointment has been successfully booked" << endl;
        }
      }

      else if ((endm != 0) && (endm != 0))
      {
        i1 = (beginh * 2) + 1;
        i2 = (endh * 2) + 1;
        for (int j = i1; i1 < i2; i1++)
        {
          //Sets this specific timeslot to be true so it will appear as booked
          timeRange.appointed[mon1][day1][j] = true;
          cout<<"Appointment has been successfully booked" << endl;
        }
      } 

      else if ((beginm != 0) && (endm == 0))
      {
        i1 = (beginh * 2) + 1;
        i2 = endh * 2;
        for (int j = i1; i1 < i2; i1++)
        {
          //Sets this specific timeslot to be true so it will appear as booked
          timeRange.appointed[mon1][day1][j] = true;
          cout<<"Appointment has been successfully booked" << endl;
        }
      }
     
      else if ((beginm == 0) && (endm != 0))
      {
        i1 = beginh * 2;
        i2 = (endh * 2) + 1;
        for (int j = i1; i1 < i2; i1++)
        {
          //Sets this specific timeslot to be true so it will appear as booked
          timeRange.appointed[mon1][day1][j] = true;
          cout<<"Appointment has been successfully booked" << endl;
        }
        //Asks if user would like to return to menu once the booking is complete
        cout<<" Would you like to go to the main menu";
      }
    }
  }
  return false;
}

//Query function definiton
bool calendar::query(date Date, time timeRange)

{
  //Collects user inputs
  int mon1,day1, querychoice;
  cout<<" Please choose the month for which you would like to query? (eg. January = 1, February = 2...December = 12) " <<endl;
  mon1 = Date.get_month();
  cin>>mon1;
  cout<< "\n";
  cout<<" Please choose the day for which you like to query? (Holidays and weekends are not allowed)" <<endl;
  day1 = Date.get_day();
  cin>>day1;
  cout<<" Would you like to search a specific time slot or view all available time slots for this day? "<<endl;
  cout<<" 1- to view specific timeslot"<<endl;
  cout<<" 2- to view all available time slots for this day" << endl;
  
  cin>>querychoice;

  //If user decides to check query
  if (querychoice == 1)
  {
    //Checks if the user input is valid before continuing
    if ((Date.isValid(mon1,day1) == false && Date.isWeekend(mon1,day1) == false && Date.isHoliday(mon1,day1) == false))
    {
      //Get functions
      int beginh,endh,beginm,endm;

      beginh = getbeginHour();
      endh = getendHour();
      beginm = getbeginMinute();
      endm = getbeginMinute();

      //Collects user input for times
      cout<<"Please enter the starting hour" <<endl;
      cin>>beginh;
      cout<<"\n";
      cout<<"Please enter the starting minute"<<endl;
      cin>>beginm;
      cout<<"\n";
      cout<<"Please enter the ending hour" <<endl;
      cin>>endh;
      cout<<"\n";
      cout<<"Please enter the ending minute"<<endl;
      cin>>endm;
      cout<<"\n";
      
      if ((timeRange.isValid(beginh,endh,beginm,endm) == false))
      {
        cout<<"You have chosen " << mon1 <<" / " << day1<< " /2020"<<endl;
        cout<<" From " << beginh <<" : " << beginm << " to " << endh << " : " << endm;

        cout<<"\n";
        cout<<"\n";
        cout<<"Processing \n";

        int i1 = 0;
        int i2 = 0;

        if ((beginm == 0) && (endm == 0))
        {
          i1 = beginh * 2;
          i2 = endh * 2;
          for (int j = i1; i1 < i2; i1++)
          {
            if (timeRange.appointed[mon1][day1][j] == true)
              {
              cout<<"Appointment has already been booked" << endl;
              }
            else if (timeRange.appointed[mon1][day1][j] == false)
            {
              cout<<"This appointment is available" <<endl;
            }
          }
        }

        else if ((endm != 0) && (endm != 0))
        {
          i1 = (beginh * 2) + 1;
          i2 = (endh * 2) + 1;
          for (int j = i1; i1 < i2; i1++)
          {
            if (timeRange.appointed[mon1][day1][j] == true)
            {
              cout<<"Appointment has already been booked" << endl;

            }
            else if (timeRange.appointed[mon1][day1][j] == false)
            {
              cout<<"This appointment is available" <<endl;
            }
          }
        } 

        else if ((beginm != 0) && (endm == 0))
        {
          i1 = (beginh * 2) + 1;
          i2 = endh * 2;
          for (int j = i1; i1 < i2; i1++)
          {
            if (timeRange.appointed[mon1][day1][j] == true)
            {
              cout<<"Appointment has already been booked" << endl;
            }
            else if (timeRange.appointed[mon1][day1][j] == false)
            {
              cout<<"This appointment is available" <<endl;
            }
          }
        }

        else if ((beginm == 0) && (endm != 0))
        {
          i1 = beginh * 2;
          i2 = (endh * 2) + 1;
          for (int j = i1; i1 < i2; i1++)
          {
            if (timeRange.appointed[mon1][day1][j] == true)
              {
              cout<<"Appointment has already been booked" << endl;
              }
            else if (timeRange.appointed[mon1][day1][j] == false)
            {
              cout<<"This appointment is available" <<endl;
            }
          }
        }
      }
    }
  }

  else if (querychoice == 2)
  {
    if ((Date.isValid(mon1,day1) == false && Date.isWeekend(mon1,day1) == false && Date.isHoliday(mon1,day1) == false))
    {
      for (int i=0; i<48; i++)
      {

        cout<<"time slot "<<i+1<<" ("<<Date.printFreeTimeSlots[i]<<")"<<" is available\n";

    }
  }
  return false;
}
  return false;
}

//Delete function definiton
bool calendar::del(date Date, time timeRange)

{
  //Collects user inputs
  int mon1,day1;
  cout<<" Please choose the month for which you would like to delete?(eg. January = 1, February = 2...December = 12) " <<endl;
  mon1 = Date.get_month();
  cin>>mon1;
  cout<< "\n";
  cout<<" Please choose the day for which you like to delete? (Holidays and weekends are not allowed)" <<endl;
  day1 = Date.get_day();
  cin>>day1;

  //Checks if the user input is valid before continuing
  if ((Date.isValid(mon1,day1) == false && Date.isWeekend(mon1,day1) == false && Date.isHoliday(mon1,day1) == false))
  {
    //Get functions
    int beginh,endh,beginm,endm;

    beginh = getbeginHour();
    endh = getendHour();
    beginm = getbeginMinute();
    endm = getbeginMinute();
  

    cout<<"Please enter the starting hour" <<endl;
    cin>>beginh;
    cout<<"\n";
    cout<<"Please enter the starting minute"<<endl;
    cin>>beginm;
    cout<<"\n";
    cout<<"Please enter the ending hour" <<endl;
    cin>>endh;
    cout<<"\n";
    cout<<"Please enter the ending minute"<<endl;
    cin>>endm;
    cout<<"\n";
    if ((timeRange.isValid(beginh,endh,beginm,endm) == false))
    {
        cout<<"You have chosen " << mon1 <<" / " << day1 << " /2020"<<endl;
      cout<<" From " << beginh <<" : " << beginm << " to " << endh << " : " << endm;

      cout<<"\n";
      cout<<"\n";
      cout<<"Processing \n";

      int i1 = 0;
      int i2 = 0;

      if ((beginm == 0) && (endm == 0))
      {
        i1 = beginh * 2;
        i2 = endh * 2;
        for (int j = i1; i1 < i2; i1++)
        {
          if (timeRange.appointed[mon1][day1][j] == true)
            {
            timeRange.appointed[mon1][day1][j] = false;
            cout<<" The appointment has been succesfully deleted" <<endl;
            }
          else if (timeRange.appointed[mon1][day1][j] == false)
          {
            cout << "This time is already available" <<endl;
          }
        }
      }

      else if ((endm != 0) && (endm != 0))
      {
        i1 = (beginh * 2) + 1;
        i2 = (endh * 2) + 1;
        for (int j = i1; i1 < i2; i1++)
        {
          if (timeRange.appointed[mon1][day1][j] == true)
          {
            timeRange.appointed[mon1][day1][j] = false;
            cout<<" The appointment has been succesfully deleted" <<endl;
          }
          else if (timeRange.appointed[mon1][day1][j] == false)
          {
            cout << "This time is already available" <<endl;
          }
        }
      } 

      else if ((beginm != 0) && (endm == 0))
      {
        i1 = (beginh * 2) + 1;
        i2 = endh * 2;
        for (int j = i1; i1 < i2; i1++)
        {
          if (timeRange.appointed[mon1][day1][j] == true)
          {
            timeRange.appointed[mon1][day1][j] = false;
            cout<<" The appointment has been succesfully deleted" <<endl;
          }
          else if (timeRange.appointed[mon1][day1][j] == false)
          {
            cout << "This time is already available" <<endl;
          }
        }
      }

      else if ((beginm == 0) && (endm != 0))
      {
        i1 = beginh * 2;
        i2 = (endh * 2) + 1;
        for (int j = i1; i1 < i2; i1++)
        {
          if (timeRange.appointed[mon1][day1][j] == true)
          {
            timeRange.appointed[mon1][day1][j] = false;
            cout<<" The appointment has been succesfully deleted" <<endl;
          }
          else if (timeRange.appointed[mon1][day1][j] == false)
          {
            cout << "This time is already available" <<endl;
          }
        }
      }
    }
  }

  return false;

}


