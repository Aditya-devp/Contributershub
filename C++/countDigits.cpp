#include<bits/stdc++.h>
using namespace std;

//approach 1
int count_digits( int n )
{
   int x = n; int count =0;
   while( x !=0 ) 
   {
       x = x / 10;
       count++;
   }
   return count;
}

//approach 2
int countDigits(int n)
{
    string x = to_string(n);
    return x.length();
}

//approach 3
int countDig(int n) 
{
    int count = floor(log10(n) + 1);
    return count;
}


int main()
{
   int n = 12345;
   cout<< "Number of digits in "<<n<<" is "<<count_digits(n) << " : 1st approach" <<endl;
   cout<< "Number of digits in "<<n<<" is "<<countDigits(n) << " : 2nd approach" <<endl;
   cout<< "Number of digits in "<<n<<" is "<<countDig(n) << " : 3rd approach" <<endl;

   return 0;
}
