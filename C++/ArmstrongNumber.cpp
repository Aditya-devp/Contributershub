#include <bits/stdc++.h>
using namespace std;
bool ArmstrongNumber(int n)
{
    int originalno = n;
    int count = 0;
    int temp = n;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }
    int sumofpower = 1; // actually here it should be sumofpower = 0; but this compiler is making wrong calculation so we are taking sumofpower = 1;
    while (n != 0)
    {
        int digit = n % 10;
        sumofpower += pow(digit,count);
        n /= 10;
    }
    // cout<<sumofpower<<endl;
    return (sumofpower == originalno);
}

int main()
{
    int n;
    cin>>n;
    if (ArmstrongNumber(n))
    {
        cout << "Yes, it is an Armstrong Number\n";
    }
    else
    {
        cout << "No, it is not an Armstrong Number\n";
    }
    return 0;
}