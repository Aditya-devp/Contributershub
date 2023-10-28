#include <iostream>
using namespace std;
int factorial(int a){
    if(a>=1){
    return a*(factorial(a-1));}
    else{
        return 1;
    }
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int b;
	    cin>>b;
	    cout<<factorial(b)<<endl;
	}
	return 0;
}
