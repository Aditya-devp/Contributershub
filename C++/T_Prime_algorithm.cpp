#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
int main(){
    long long int n;
    std::cin>>n;
    long long int arr[n];
    // std::vector <int> xx;
    std::map <int,int> xx;
    // xx.push_back(2);
    // xx.push_back(3);
    xx[2]=1;
    xx[3]=1;
    for(int i=5;i<=1000000;i++){
        int flag=0;
        for(int j=2;j<=int(std::sqrt(i));j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0)
        xx[i]=1;
    }
    for(long long int j=0;j<n;j++){
        std::cin>>arr[j];
        long long int count=0;
        long long int flag=0;
        if(arr[j]%int(std::sqrt(arr[j]))==0){
            if(std::sqrt(arr[j])!=int(std::sqrt(arr[j])))
            count=0;
            else{
                if(xx[int(std::sqrt(arr[j]))]==1)
                count=1;
            }
        }
        if(count==0 or arr[j]==1)
        std::cout<<"NO"<<std::endl;
        else if(count==1)
        std::cout<<"YES"<<std::endl;
    }
}