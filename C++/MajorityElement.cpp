#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElements(vector<int> v){
    int element1 = v[0];
    int c1 = 1;
    int element2 = 0;
    int c2 = 0;
    for(int i=1; i<v.size(); i++)
    {
        if(element1 == v[i])
        {
            c1++;
        }
        else if(element2 == v[i])
        {
            c2++;
        }
        else if(c1 == 0)
        {
            element1 = v[i];
            c1 = 1;
        }
        else if(c2 == 0)
        {
            element2 = v[i];
            c2 = 1;
        }
        else{
            c1--;
            c2--;
        }
    }
    c1 = c2 = 0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == element1) c1++;
        else if(v[i] == element2) c2++;
    }
    vector<int> ans;
    if(c1>v.size()/3) 
    {
        ans.push_back(element1);
    }
    if(c2>v.size()/3)
    {
        ans.push_back(element2);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int x;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    vector<int> ans;
    ans = majorityElements(v);
    if(ans.size()==0)
    {
        cout<<"NO majority Elements"<<endl;
    }
    else{
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<< " ";
        }
    }
    return 0;
}