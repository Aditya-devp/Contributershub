#include<iostream>
#include<algorithm>
using namespace std;
class Fraction{
    private:
        int numerator ;
        int denominator;
    public:
        Fraction(int numerator, int denominator)
        {
            this->numerator=numerator;
            this->denominator=denominator;
        }
        void Print(){
            cout<<numerator<<"/"<<denominator<<endl;
        }
        void  simplyfy(){
            int gcd =1;                                                                                                    // to simplify the two fractions we will take the gcd of two Numbers 
            int j = min(this->numerator, this->denominator);                                        // so what does  gcd of two number gives it basically gives the number that is most nearly divisible by both the digits 
            for(int i=1;i<=j;i++){
                if(this->numerator%i == 0 && this->denominator%i == 0)
                    gcd=i;
            }
            this->numerator=this->numerator/gcd;
            this->denominator=this->denominator/gcd;    
        }
        void add(Fraction const  &f2)                                                                     // this helps in passing the reference of the object and does not create a copy object to perform the operations
        {                                                                                                                  // by adding a "const" before the object variable we can just read the value and not modify it
            int lcm = denominator*f2.denominator;
            int x = lcm/denominator;
            int y = lcm/f2.denominator;
            int num = ((x*numerator)+(y*f2.numerator));
            this->numerator = num;
            this->denominator =lcm;
        }
        void multiply(Fraction const &f4)
        {
            this->numerator = this->numerator*f4.numerator;
            this->denominator = this->denominator*f4.denominator;
        }
};
int main()
{
    Fraction f1(7,12);
    Fraction f2(8,6);
    Fraction f3(13,39);
    Fraction f4(52,65);
    f1.Print();
    f2.Print();
    f1.add(f2);
    f1.simplyfy();
    cout<<"Addition"<<endl;
    f1.Print();
    cout<<"Next Operation"<<endl;
    f3.Print();
    f4.Print();
    cout<<"Multiplication"<<endl;
    f3.multiply(f4);
    f3.simplyfy();
    f3.Print();
    return 0;
}