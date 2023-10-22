#include<iostream>
#include<string >
using namespace std;
class Student{
    private:
      //string name;
        int roll;                           // 4 bytes
        int age;                        // 4bytes
    public:
        void get_details()
        {
        //    cout<<"Enter the name"<<endl;
          //  getline(cin,name);
            cout<<"Enter the Roll Number"<<endl;
            cin>>roll;
            cout<<"Enter the Age"<<endl;
            cin>>age;
        }
        void display()
        {
            //cout<<"Name\t"<<name<<endl;
            cout<<"Roll Number\t"<<roll<<endl;
            cout<<"Age\t"<<age<<endl;
        }    
};
int main()
{
    Student s;                                      // just as the student object is created the size of the object is  created 
    cout<<sizeof(s)<<"  bytes"<<endl;  // since there are two data members of int type so the  size of  obejct of class student will be 4b +4b = 8bytes          
    s.get_details();                                // this creation of  size of the object is same as the size allocation in structure in C/C++
    s.display();
    return 0;
}
