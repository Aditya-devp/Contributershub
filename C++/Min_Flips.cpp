#include <iostream>
#include <stack>

using namespace std;

int solve(string s) {
    int len = s.size(), w = 0, b = 0, mul = 1, res = 0;
    stack<int> st;
    for(char c : s) {
        if(c == '+') {
            st.push(1);
            w++;
        }
        else {
            st.push(-1);
        }
    }
    b = len - w;
    while(!st.empty() && b != 0) {
        if(st.top() * mul == 1) 
            w--;
        else {
            res++;
            b--;
            swap(b, w);
            mul *= -1;
        }
        st.pop();
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s);
    
    return 0;
}
