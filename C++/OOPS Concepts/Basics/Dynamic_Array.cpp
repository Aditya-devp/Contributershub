#include<iostream>
using namespace std;
class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
        DynamicArray(){
            data =new int[5];
            nextIndex = 0;
            capacity = 5;

        }
        DynamicArray(DynamicArray const &d){                            // created our own constructor so that it can do a shallow copy 
            this->data=new int[d.capacity];
            for(int i=0;i<d.nextIndex;i++)
            {
                this->data[i] =d.data[i];
            }
            this->nextIndex=d.nextIndex;
            this->capacity = d.capacity;

        }
        void operator=(DynamicArray const &d){                          // operator overloading with = for Dynamic Array
              this->data=new int[d.capacity];
            for(int i=0;i<d.nextIndex;i++)
            {
                this->data[i] =d.data[i];
            }
            this->nextIndex=d.nextIndex;
            this->capacity = d.capacity;
        }
        void add(int element){
            if(nextIndex == capacity){
                int *newData =new int[2*capacity];
                for(int i=0; i<capacity; i++ ){
                    newData[i] = data[i];
                }
                delete [] data;
                data =newData;
                capacity = 2*capacity;
            }
            data[nextIndex] = element;
            nextIndex++;
        } 
        int get(int i){             // this function will return the data at the index hich is been provided by the argument
        if(i < nextIndex){
            return data[i];
        }
        else {
            return -1;
        }
        }
        void add_element(int i , int  element){                 // add element to a certain index
        if(i<nextIndex){
        data[i] = element;
        }
        else if(i==nextIndex){
            add(element);
        }
        else {
            return ;
        }
        }
        void Display(){
            for (int i=0;i<nextIndex;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
}; 
int main(){
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    DynamicArray d2(d1);
    d1.add_element(1,200);
    d1.Display();
    d2.Display();
    DynamicArray d3;
    d3 = d1;
    d3.Display();
}