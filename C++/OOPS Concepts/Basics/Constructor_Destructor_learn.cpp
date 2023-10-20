#include<iostream>
#include<string>
using namespace std ;
class Student{
    private:
        string name ;
        int id;
        char sex;
        string dob;
    public:
        // Destructor iinitialisation 
        ~Student(){
            cout<<"Deallocated the objects "<<endl;                 // note that the destructor will deallocate only those objects that are statistically created 
                                                                                         // we have to manually remove the objects 
        }
        Student(){                                  // contructor is same as of the class name it is declared inside the public access specifier
              id =0; 
              dob="21/08/2001";              
              cout<<"Default Constructor is called "<<endl;   // This type of Constructor is reffered to as Default Constructor 
        }
        Student(string &s)                                              // This is Reffered  to as copy constructor here you can se that there is an argument passed with the function
        {                                                                          // To call this type of contructor an argument is passed just as an object is created  
            cout<<"Parameterised Constructor is Called"<<endl;
            name= s;
        }
        // Dcelaring constructor with multiple paramerters
        Student(int ID , string &s, char ch){
            cout<<"Multiple Parameterised Constructor is Called"<<endl;
            name=s;
            id=ID;
            sex=ch;
        }
        Student(int id, string &name, char sex , string &dob){
            cout<<"Constructor with this-> keyword is called"<<endl;
            this->id=id;
            this->name=name;
            this->sex= sex;
            this->dob=dob;
        }
        void input()
        {
            cout<<"Enter the id of the Student"<<endl;
            cin>>id;
            cout<<"Enter Sex"<<endl;
            cin>>sex;
        }
        void display(){
            cout<<"Name\t"<<name<<endl;
            cout<<"ID\t"<<id<<endl;
            cout<<"Sex\t"<<sex<<endl;
            cout<<"Date of Birth\t"<<dob<<endl;
        }
};
int main()
{
    Student s1;                             // Just as  the object is created the default constructor is  called ...
    s1. display();
    cout<<endl;
    s1.input();
    s1.display();
   /* when you carefully observe the output you will find out that the you will find out that the the parameterised constructor is being called and you 
   will see that the output will not display the name since it is not initialised anywhere in the code uptill now and you will also see the statement of Default constructor in the output*/
   
 /*Now you will se that i will now use the parameterised constructor */
    cout<<endl;
   string str ="Pravin Kumar";                   //inorder to call the parameterised constructor you need to pass the argument just during the time of object creation as i did  here ..
   string str1 ="Navin Kumar";
   string dob1= "28/12/1999";
   Student s2(str);
   s2.input();
   cout<<endl;
   s2.display();
   cout<<endl;
   // so in the above object we saw a parameterised constructor working in the code.
   // now we wil learn about constructor with multiple arguments  how it works and later we will study about the copy constructor
   char ch='M';
    string dob="21/08/2001";
    Student *s3 =new Student(22,str,ch);
    s3->display();
    cout<<endl;   
    // now we will study about "this" keyword  and how it works
    /* like suppose we want to we have the argument same as the name of data members of the class so we whn we pass it to the member functions of  the class
        it gets confilcted between the data memeber of the class so in order to avoid this mishap what we do is we use "this" key word with and arrow "->" 
        This keyword holds the address of the current object */
    Student *s4 =new Student(22,str,ch,dob);
    s4->display();
    cout<<endl;
    // now we will learn about copy contructor how it works 
    // suppose i created a new object and now i want that object to look like the s2 object all the contents s2 should be copied to the new object that i created 
    // type 1: static object and passing a static object as argument static object
    Student s5(s2);  /// this internally works as s5.Student(s2) ;
    // another way of writing the above code is by given statement "Student s5 = s2;" this line of code will work same as the above line of code 

    /*how it works internally ->->-> When you use a copy constructor in C++, it is used to create a new object by making a copy of an existing object.
     The copy constructor is invoked when you initialize a new object with an existing object of the same type, or when you pass an object by value as a function argument.
    Internally, the copy constructor is responsible for creating a new object and initializing it with the values of an existing object. 
    It does this by taking a reference to the existing object as a parameter, and then copying the member variables of the existing object into the new object.
    The copy constructor does not invoke the constructor of the object in which another object is passed as a parameter. 
    Instead, it creates a new object by making a copy of the existing object, using the existing object's data members to initialize the new object's data members. 
    The new object is a completely separate instance of the class, with its own memory allocation and its own set of member variables.*/  

    
    s5.display();
    s5.input();
    s5.display();

    //how can we dynamically copy the object by dynamic initialisation method 
    // type 2: creating a  dynamic object but passsing a static object     
    Student *s6 =new Student(s1);
    s6->display();
    //type 3: creating a dynamic object and passing a dynamic obeject 
    Student *s7 =new Student(*s6);
    s7->display();
    //type 4: creating a static object but passing a dynamic object 
    Student s8(*s7);
    s8.display();
    // Now we will learn about copy assignment operator (=)
    // copy assignment operartor copies the object of similar constructor type that are 
    //lets see
    Student s9(22, str, ch ,dob);
    cout<<"Displaying the data of object S9"<<endl;
    s9.display();
    cout<<endl;
    cout<<"Displayin the value of object S10"<<endl;
    Student s10(21,str1,ch,dob1);
    s10.display();
    cout<<endl;
    // now lets see if the assignment operator works properly or not 
    s9=s10;  // this uses copy assignment operator  
    cout<<"Displaying the data of object s10"<<endl;
    s10.display();
    cout<<endl;
    cout<<"Displaying the data of object s9 "<<endl;
    s9.display();
    cout<<endl;
    // now lets see if it works for another value of object with different constructor argument passed
    s3->display();
    (*s3)=s10;
    cout<<endl;
    s3->display();
    // so now you can see that s3 has copied all the values of s10 and is displaying its content.
    // copy assignment operator will copy the value of the same class objects have similar data members 
    /*
    Now we will learn about the destructor 
    the work of destructor is to deallocate the memory of the objects of our class
    destructor is same as of the class name with no return type , no input arguments 
    */
    delete s3;
    delete s4;
    delete s6;
    delete s7;
    /* In C++, the delete keyword is used to free the memory that was dynamically allocated using the new keyword. 
    However, when you pass multiple objects separated by commas in the delete statement like delete s1, s2, s3, 
    it will only delete the first object s1 and leave the rest of the objects s2 and s3 still occupying memory.
    This is because the comma operator in C++ evaluates each expression from left to right and discards the result of all expressions except the last one. 
    In this case, the expression delete s1 is evaluated first and it frees the memory allocated for s1.
    The expressions s2 and s3 are evaluated next, but since they are not pointers, they are not deleted.
    If you want to delete multiple objects, you should use separate delete statements for each object, like delete s1; delete s2; delete s3;
    This will ensure that all the dynamically allocated memory for each object is freed properly. */
return 0;
}