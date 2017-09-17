#include <iostream>
using namespace std;

class Rational
{
   private:
   int numer;
   int denom; 
 
   public:
   Rational();
   Rational(int); 
   Rational(int, int); 
   const Rational add(const Rational &) const; 
   const Rational subtract(const Rational &) const; 
   const Rational multiply(const Rational &) const; 
   const Rational divide(const Rational &) const; 
   void display() const; 
};
   Rational::Rational() // first construct
   {
      numer = 0;
      denom = 1;
      return;
   }
   Rational::Rational(int a)  // second construct
   {
      numer = a;
      denom = 1;
      return;
   }
   Rational::Rational(int a, int b) // third construct
   {
      numer = a;
      denom = b;
      return;
   }
   const Rational Rational::add(const Rational &b) const
   {
      Rational j;
      j.numer =  ((numer * b.denom) + (denom * b.numer));
      j.denom = (denom * b.denom);
      return j;
   }
   const Rational Rational::subtract(const Rational &b) const
   {
      Rational j;
      j.numer =  ((numer * b.denom) - (denom * b.numer));
      j.denom = (denom * b.denom);
      return j;
   }
   const Rational Rational::multiply(const Rational &b) const
   {
      Rational j;
      j.numer =  (numer * b.numer);
      j.denom = (denom * b.denom);
      return j;
   }
   const Rational Rational::divide(const Rational &b) const
   {
      Rational j;
      j.numer =  (numer * b.denom);
      j.denom =  (denom * b.numer);
      return j;
   }
   void Rational::display() const
   {
      cout << numer << '/' << denom;
      return;
   }
   
int main()
{
   Rational a(1,4);
   Rational b(1,4);
   Rational c;
   Rational d;
   Rational e;
   Rational f;
   c = a.add(b);
   d = a.subtract(b);
   e = a.multiply(b);
   f = a.divide(b);
   c.display();
   d.display();
   e.display();
   f.display();
   return 0;
}