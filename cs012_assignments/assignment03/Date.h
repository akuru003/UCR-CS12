#include <iostream> // Date class interface file
using namespace std;
class Date
{
   private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;
   bool isLeap(unsigned) const;
   unsigned daysPerMonth(unsigned, unsigned) const;
   string name(unsigned) const;
   unsigned number(const string&) const;
   public:
   Date();
   Date(unsigned, unsigned, unsigned);
   Date(const string&, unsigned, unsigned);
   void printNumeric() const;
   void printAlpha() const;
   Date addDays(int) const;
};