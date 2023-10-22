/* In this code we will learn some new concepts of object oreinted programming
    suppose i want to create a new int variable  
    like 
    int a=5;
    int const b= a;         // this will work because the constant integer is always valued  during the time of initialisation 
    now if we declare the const variable like this 
    int a;
    a=5;
    int const b; // compiler wil on spot show the error beccuase you  
    b=a;
    will the above line of code work the ans is NO this is because during the time of variable decleration the const object is asssigned
    to the garbage value so now if we try to cchange the content of the const variable we will get an error
    now this constatnt variable is useless for us
    This is similarly applicable in the case of a Reference Variable 
    int i=5;
    int &j=i;
    in the above line i passed a reference of i varuiable in  j and now any changes made by j will be reflected in the i variable
    now if try the reference variable by doing like this  what happens
    int &j ;
    j=i; // will this line of code work  the anser is simply NO this line of code will not work because in the rerference variable also it is initialised during the time of decleration 
 */
 /* So Our Purpose of this program is to create a constant data inside a class data member 
    such that once the valueof the data is initialised it cannot be changed any further */
 #include<iostream>
 using namespace std;
 class Student{
    private:
    int age ;
    int const roll_number;
    public:
    Student(int age , int r): roll_number(r) {                               // so this is how we declare initialization list  so here it will just do allocate the value during the time of initialization
      this->age=age;
     // roll_number=r;             // still it is showing error it is because the garbge value has been allocated just as the student object was created 
                                          // to avoid this kind of problem and to serve the purpose we use "Initialization List Concept" 
    }
    void display()
    {
        cout<<"Age = "<<age<<"\tRoll Number = "<<roll_number<<endl;
    }
 };
 int main()
 {
    Student S1(21,22);
    S1.display();
    //S1.age =20;
    //S1.roll_number = 101; //so this will show error because our constant value is initialised with a garbage value 
                                       // so what could be done now should we create a constructor lets see..
 }
