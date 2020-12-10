#include "date.hpp"
#include "time.hpp"

class calendar : public date, public time
{
  public:
  //constructors
  calendar();
  //destructor
  ~calendar();

  //Booking function
  bool book(date Date, time timeRange);
  //Query function
  bool query(date Date, time timeRange);
  //Delete function
  bool del(date Date, time timeRange);
  //Introduction function
  void introduction();

  
};
