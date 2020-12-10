#include <iostream>
#include <string>
#include <iomanip>
#include "calendar.hpp"
using namespace std;

int main()
{
  //Initionalizes variables that will be used
  int introductionchoice, month, day, h1, m1, h2, m2, mon1, day1, choice,j;

  //Date class variables
  date Date;

  //Time class variables
  class time timeRange;

  //Calendar class variables
  calendar calendate;

  //Call introduction which will be like a starting menu and allow them to choose which course of action they will take
  Date.introduction();

  //Takes the value that corresponds to the user's menu choice
  cin>> introductionchoice;
  cout<<"\n";

  //Date get functions
  Date.get_day();
  Date.get_month();

  //Date set functions
  Date.set_month(month);
  Date.set_day(day);

  //Time get functions
  timeRange.getbeginHour();
  timeRange.getbeginMinute();
  timeRange.getendHour();
  timeRange.getendMinute();

  //Time set functions
  timeRange.setbeginHour(h1);
  timeRange.setbeginMinute(m1);
  timeRange.setendHour(h2);
  timeRange.setendMinute(m2);
  
  //Determines what happens based on the user's choice
  if (introductionchoice == 1)

  {   
      //If user chooses 1 it will run the book function   
      calendate.book(Date, timeRange);

      cout<<"\n";
      cout<<"Would you like to return to the main menu?"<<endl;
      cout<<"Type 1 for yes" <<endl;
      cout<<"\n";
      cin>>choice;
      cout<<"\n";

      //If user chooses 1 it will return to the main menu
      if (choice == 1)
      {
        cout<<"\n";
        
        //Runs main again to return to the beginning of the code and run the menu again
        return main();

      }
      else
    {
      //If user does not choose 1 the code will exit
      cout<<"Goodbye"<<endl;
      exit(1);
    }
  }

  else if (introductionchoice == 2)
  {
    //If user chooses 2 it will run the query function
    calendate.query(Date, timeRange);
    cout<<"\n";
    cout<<"Would you like to return to the main menu?"<<endl;
    cout<<"Type 1 for yes" <<endl;
    cout<<"\n";
    cout<<"\n";
    cin>>choice;

    //If user chooses 1 it will return to the main menu
    if (choice == 1)
    {
      cout<<"\n";

      //Runs main again to return to the beginning of the code and run the menu again
      return main();
    }
    else
    {
      //If user does not choose 1 the code will exit
      cout<<"Goodbye"<<endl;
      exit(1);
    }
  }

  else if (introductionchoice == 3)
  {
    //If user chooses 3 it will run the delete function
    calendate.del(Date, timeRange);
    cout<<"\n";
    cout<<"Would you like to return to the main menu?"<<endl;
    cout<<"Type 1 for yes" <<endl;
    cout<<"\n";
    cout<<"\n";
    cin>>choice;

    //If user chooses 1 it will return to the main menu
    if (choice == 1)
    {
      //Runs main again to return to the beginning of the code and run the menu again
      return main();
    }
    else
    {
      //If user does not choose 1 the code will exit
      cout<<"Goodbye"<<endl;
      exit(1);
    }
  }
  
  else if (introductionchoice == 4)
  {
    //If user chooses 4 it will exit the menu and end the program
    cout<<"Goodbye"<<endl;
    exit(1);
  }

  else
  {
    //FUNNY ERROR MESSAGE, BONUS MARKS PLEASE?
    //If user chooses anything else it will show a message letting them know there is no function for their chocie
    cout<<"Developers have yet to create more functions.... this is awkward" << endl;
    cout<<"\n";

    //This will then run the main again to return them to the menu
    return main();
    exit(1);
  }
}