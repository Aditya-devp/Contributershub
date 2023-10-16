// This Simplest an the easiest meaning of polymorphism mean many forms
/*Polymorphism are of two types 
1. Compile Time Polymorphism
2. Runtime Polymorphism
Compile Time  Polymorphism can be achieved  by using two methods 
    I. Function Overloading  -> Function overloading is a feature in programming languages that allows multiple functions with the same name to be defined in a program, 
                                              as long as they have different parameter lists.Each version of the function performs a different operation or handles different types of arguments.
                                              When a function is overloaded, the compiler or interpreter determines which version of the function to call based on the arguments provided during the function call. 
                                             The decision is made by matching the types and number of arguments to the corresponding function definition.
                                              Function overloading provides a way to create functions that perform similar operations but on different types of data or with different parameter configurations.
                                              It improves code readability and reusability by allowing developers to use the same function name for related operations.

    II. Operator Overloading -> Operator overloading is a feature in programming languages that allows the definition of new behaviors for operators when applied to custom data types or objects. 
                                                It enables operators such as +, -, *, /, =, <, >, and others to be redefined for user-defined types, giving them additional functionality and flexibility.
                                                By overloading operators, you can define how operators should behave when used with objects of a particular class. 
                                                This allows you to create more intuitive and expressive code, resembling natural language or mathematical notation.
*/
#include <iostream>
using namespace std;
int test(int a, int b) {        // using same function name but passing different number of arguments
                                        // this type of Polymorphism is called Function Overloading...
}

int test(int a) {

}

int test() {
 
}
/*What if suppose i define  a Function like  this 
" void test () " // Function name is also same so can we diferentiate betweeen the "int test ()" Function and  the "void test ()" since they have same no of arguments  ??
Answer : The answer is no we cannot differentiate the functions of the basis of return type 
so there will be an ambiguity and the compiler will say that we cannot differentiate between two function 
 "We Differentiate the function only on the basis of no of arguments and on the basis of Function name "
*/
int main() {

}

