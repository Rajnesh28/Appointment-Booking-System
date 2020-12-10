#include <string>
using namespace std;

class time
{
    // public variables
    public:

    //Set functions created//
    void setbeginHour(int);
    void setendHour(int);
    void setbeginMinute(int);
    void setendMinute(int);

    //Get functions created//
    int getbeginHour();
    int getendHour();
    int getbeginMinute();
    int getendMinute();

    //Check if the timeranges are valid
    bool isValid(int h1,int h2,int m1,int m2);

    void timeSlots(int h1, int h2, int m1, int m2, int month, int day, bool appointed);

    //Output class information regarding the timerange
    void outputmembertimerange(double h1, double h2, double m1, double m2);

    // Function that changes the user inputed times into an interget representation of that time's array value
    int convertToArray(int h1, int h2, int m1, int m2);
  
    // a 3d array representing 13 pages for months, 32 days for days in the month, and 49 time slots for the hours
    bool appointed[13][32][49];

    bool setTime(int h1, int h2, int m1, int m2);

    // private variables
    private:
    int beginHour;
    int endHour;
    int beginMinute;
    int endMinute;    
};