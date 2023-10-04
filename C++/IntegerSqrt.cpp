#include <iostream>
using namespace std;

int intcbrt(int n)
{
    int low = 1;
    int high = n;
    int ans=1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(mid * mid * mid <=n) {
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int intsqrt(int n)
{
    int low = 1;
    int high = n;
    int ans=1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(mid * mid <=n) {
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<< intsqrt(n) << endl;
    cout<< intcbrt(n) << endl;
    return 0;
}