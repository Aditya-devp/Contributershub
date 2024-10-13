#include<bits/stdc++.h>
#include<string.h>
using namespace std;
void learnpair()
{
    pair<int,int>p={1,3};
    cout<<p.first<<" "<<p.second;
    cout<<"\n";
    pair<int,pair<int,int>>n={1,{4,5}};
    pair<int,int>arr[]={{1,2},{2,3},{3,4},{4,5}};
    cout<<arr[0].first<<" "<<arr[1].second<<" "<<arr[3].first;
}
void learnvector()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
   /*Method-1 For Iteration */ 
    for(vector<int>:: iterator it=v.begin();it!=v.end();it++)
    {
           cout<<*(it)<<" ";
    }
    cout<<"\n";
    /*Deletion in a vector */
    v.erase(v.begin()+1);
    /*Method-2 For Iteration*/
    for(auto it :v)
    {
        cout<<(it)<<" ";
    }
    cout<<"\n";
    /*Deletion in a vector */
    v.erase(v.begin()+0,v.begin()+2);
   /*Method-3 for Iteration*/
    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<< *(it)<<" ";
    }
    cout<<"\n";
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    for(auto it :v)
        cout<<(it)<<" ";
    cout<<"\n";
    /*Insert Functions*/
    /*Supose i create a vector and i want to insert  it to another vector*/
    vector<int>vc(2,80);
    v.insert(v.begin()+1,vc.begin(),vc.end());
    for(auto it :v)
        cout<<(it)<<" ";
    cout<<"\n";
    /*sppose i want to insert a particular number at a particular position */
    v.insert(v.begin()+3,73);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        cout<< *(it)<<" ";
    cout << "\n";
    /*Suppose i want to insert the number in the beginning */
    v.insert(v.begin()+0,12);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *(it) << " ";
    cout<<"\n";
    /*Suppose i want to know the size of the element */
    cout<<v.size();
    cout<<"\n";
    /*if you want to remove the last element */
    v.pop_back();
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *(it) << " ";
    cout << "\n";
    /*How to erase the elements inside the container*/
    for(auto it :vc)
        cout<<(it)<<" ";
    vc.clear();
    cout<<"\nIs the above container empty ??"<<vc.empty();
}
void learnlist()
{
    list<int>ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    ls.emplace_back(5);
    ls.push_front(0);
    for(auto it :ls)
        cout<<(it)<<" ";
    cout<<"\n";
}
void learndeque()
{
    deque<int>dq;
    dq.push_back(10);
    dq.emplace_back(20);
    dq.push_front(30);
    dq.emplace_front(100);
    for(deque<int>::iterator it=dq.begin();it!=dq.end();it++)
        cout<<*(it)<<" ";
    cout<<"\n";
    cout<<dq.back()<<"\n";
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
        cout << *(it) << " ";
    cout<<"\n";
    cout<<dq.front()<<"\n";
    for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
        cout << *(it) << " ";
    cout<<"\n";
}
void learnstack()
{
    stack<int>st;
    /*Insertion in stack */
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    /*Operations can be done on the top of the stack */
    st.top()*=5;
    /*Print what is at the top of the stack*/
    cout<<st.top()<<"\n";
    cout<<st.size()<<"\n";
    cout<<st.empty()<<"\n";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    stack<int>st1,st2;
    st1.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    st1.swap(st2);
    cout<<st1.top()<<" ";
    cout<<st2.top()<<" ";
}
void learnqueue()
{

}
int main()
{
    learnstack();
    return 0;
} 