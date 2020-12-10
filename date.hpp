#include <string>
#include <iostream>

class date
{
  
public:

    //Constructors
    date(int mon1, int d1);
    date();

    //Friend Function
    friend bool equal(date month1, date day1, date month2, date day2);
    //get functions for months and day
    int get_month();
    int get_day();

    //set functions for months and day
    void set_month(int month);
    void set_day(int day);    

    //check validity of the input
    bool isValid(int month, int day);    

    //functions for holdidays and weekends
    bool isHoliday(int month, int day);

    bool isWeekend(int month, int day);

    //functions and boolean for timeslot appointment
    bool appointed[13][32][49] = {{{false}}};
    bool appointed2[48] = {false};
    int i;
    
    //void printAppointedTimeSlots(int i, int i2, int j, int k, bool appointed[48] = {}, int h1, int h2, int m1, int m2);
    //void printFreeTimeSlots(int i, bool appointed[48] = {});

    //Output member functions
    void outputmemberdate(int month, int day);
    void outputmembermonth(int month, int day);

    //initalize constant values for holidays
    const int thanksgivingmonth = 10;
    const int thanksgivingday = 12;
    const int remembrance = 11;

    // changes the array time slot value into an actual time forthe user to see
    std::string printFreeTimeSlots[48]={"00:00-00:30", "00:30-01:00", "01:00-01:30", "01:30-02:00", "02:00-02:30", "02:30-03:00", "03:00-03:30", "03:30-04:00", "04:00-04:30", "04:30-05:00", "05:00-05:30", "05:30-06:00", "06:00-06:30", "06:30-07:00", "07:00-07:30", "07:30-08:00", "08:00-08:30", "08:30-09:00", "09:00-09:30", "09:30-10:00", "10:00-10:30", "10:30-11:00", "11:00-11:30", "11:30-12:00","12:00-12:30", "12:30-13:00", "13:00-13:30", "13:30-14:00", "14:00-14:30", "14:30-15:00", "15:00-15:30", "15:30-16:00", "16:00-16:30", "16:30-17:00", "17:00-17:30", "17:30-18:00", "18:00-18:30", "18:30-19:00", "19:00-19:30", "19:30-20:00", "20:00-20:30", "20:30-21:00", "21:00-21:30", "21:30-22:00", "22:00-22:30", "22:30-23:00", "23:00-23:30", "23:30-00:00"};  

    friend bool equal(date date1, date date2);//check if both dates are equal

    //Introduction menu function
    void introduction();
    
    //overload operator to print available times

    friend std::ostream& operator<<(std::ostream& out, const date& Date);

private:
    int month;
    int day;


};