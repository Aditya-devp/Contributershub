// Have To Complete This Program Question is also given
/* Try To Complete the Code in the Given Format
Code : Polynomial Class
Send Feedback
Implement a polynomial class, with following properties and functions.
Properties :
1. An integer (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)
Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
Sample Input 2 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
2
Sample Output 2 :
-4x0 -1x1 3x2 1x3 -4x5
Sample Input 3 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
3
Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8
*/
#include<iostream>
using namespace std;
class Polynomial{
    private:
    int *degCoef;
    int  capacity;

    public:
    // default Constructor 
    Polynomial(){
        degCoef = new int[5];
        capacity =5;
        for (int i=0;i<capacity;i++)
        {
            degCoef[i]=0;
        }
    }

    // Copy constructor 
    Polynomial(Polynomial const &p){
        this->capacity = p.capacity;
        for(int i=0;i<capacity;i++)
        {
            this->degCoef[i]= p.degCoef[i];
        }
    }

    // copy assignment operator
    void  SetCoefficient(int element, int degree){
        this->degCoef[degree]=element;
    }
    void increase_size(int degree){
        capacity= 2*degree;
        int *newdegcoef = new int[capacity];
        for(int i=0 i<capacity;i++)
        {
            newdegcoef[i]= degCoef[i];
        }
        delete [] degCoef ;
        degCoef = newdegcoef;

    }
    // setCoefficient 

};
