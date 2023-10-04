#include <iostream>
using namespace std;

int main()
{
    int a,b;
    char op;
    cin >>a >> b;
    cin>>op;

    switch (op)
    {
    case '+':
        cout<<a+b<<endl;
        break;
    case '-':
        cout<<a-b<<endl;
        break;
    case '*':
        cout<<a*b<<endl;
        break;
    case '/':
        cout<<a/b<<endl;
        break;
    case '%':
        cout<<a%b<<endl;
        break;
    
    default:
        cout<<"invalid case"<<endl;
        break;
    }
    return 0;
}