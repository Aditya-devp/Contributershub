#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n){
    bool p[n+1] = {false};
        //p[0] = false, p[1] = false;
        for(int i=2;i<n;i++){
            p[i] = true;
        }
        
    if(n<2){
        return 0;
    }    
    else{
        int cnt = 0;
        for(int i=2;i*i<=n;i++){
            if(p[i] == true){
                for(int j=i*i;j<=n; j += i){
                    p[j] = false;
                }
            }    
        }
        for(int i=0;i<n;i++){
            if(p[i]==true){
                cnt++;
            }
        }
        return cnt;
    }    
}
    
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    cout<<countPrimes(n);
    }
    return 0; 
}   
