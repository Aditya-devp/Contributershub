#include <iostream>
#include <limits.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min = INT_MAX, index = i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
    }
}

void printArray(int arr[], int n){
    cout << "\nThe elements after sorting are:" << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "\nEnter elements:" << endl;
    int arr[n];
    for(int i=0;i<n;i++)
    cin >> arr[i];
    //sorting the array
    selectionSort(arr, n);
    //printing the array
    printArray(arr, n);
    return 0;
}