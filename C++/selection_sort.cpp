/*
--------------------SELCTION SORT:---------------------

SEARCH FOR MINIMUM ELEMENT AND REPLACE WITH BEGINING OF 
UNSORTED ARRAY

-> TIME COMPLEXITY: O(n2).
-------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"ENTER THE SIZE OF ARRAY: ";
    cin>>n;
    int a[n];
    cout<<"\nENTER THE ELEMENT IF ARRAY: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                int temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"\nSORTED ARRAY:\n";
     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
