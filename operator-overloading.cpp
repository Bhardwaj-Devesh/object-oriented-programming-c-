#include<bits/stdc++.h>
using namespace std;

class Fraction{
    private: 
        int numerator;
        int denominator;
    public:
        // parameterised constructor
        Fraction(int numerator, int denominator){
            this->numerator = numerator; this->denominator = denominator;
        }

        void simplify(){
            int gcd = __gcd(this->numerator, this->denominator);
            this->numerator = this->numerator/gcd;
            this->denominator = this->denominator/gcd;
        }

        // f1.add(f2);
        // we should make another copy of parameter in memeory so we have to take is by reference
        // we don't want that anyone can change f2
        void add(const Fraction& f2){
            int d = this->denominator * f2.denominator;
            int n = this->numerator*f2.denominator + f2.numerator*this->denominator;

            this->numerator = n;
            this->denominator = d;
            simplify();
        }

        void multiply(const Fraction& f2){
            this->numerator = this->numerator*f2.numerator;
            this->denominator = this->denominator *f2.denominator;
            simplify();
        }

        void print(){
            cout<<this->numerator<<" "<<this->denominator<<endl;
        }  
        
        // We can make this function const function because we are not changing value of any parameter
        /*NOTE : local variable get destoryed once the function ends.*/
        Fraction operator+(const Fraction &f2) const {
            int d = this->denominator * f2.denominator;
            int n = this->numerator*f2.denominator + f2.numerator*this->denominator;
            Fraction f3(n,d);
            f3.simplify();
            return f3;
        }
        Fraction operator*(const Fraction& f2) const {
            int n = this->numerator*f2.numerator;
            int d = this->denominator *f2.denominator;
            Fraction f3(n,d);
            f3.simplify();
            return f3;
        }

        // It is not a const function because we are changing the value of its parameter
        // pre-increment
        Fraction& operator++(){
            this->numerator = this->numerator + this->denominator;
            simplify();
            return *this;
        }
        /* *this means we are dereferencing the pointer => which implies "give me the actual object that this pointer is pointing to"*/

        // post-increament
        /*NOTE: There is no nesting in post Increment operation*/
        void operator++(int){
            Fraction fnew(this->numerator,this->denominator);
            this->numerator = this->numerator + this->denominator;
            simplify();
            fnew.simplify();
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(3,1);

    /* OPERATOR OVERLOADING */
    // f3 = f1 + f2;
    /*
    Fraction f3 = f1 + f2; // => f1.operator+(f2)
    f3.print();
    Fraction f4 = f1*f2; // -> f1.operator*(f2)
    f4.print();

    ++f1;
    f1.print();
    Fraction f5 = ++(++f1);
    f5.print();
    */
   // post-increment operator overloading
    f1.print();
   f1++;
   f1.print();
}