#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) // NOTE: loop start from i = 1 to n-1 -> "(n-2) loops"
    {
        // temp is the element which we will be inserting at correct position
        int temp = arr[i]; // Initially, temp = arr[1], as we will check its correct position from ind = 1 to ind = 0

        int j = i - 1;
        // j is assigned as i - 1, as we will be running loop from (i-1)th index until we find correct position of temp in range (0, i - 1)

        while (j >= 0 && arr[j] > temp) // Running while loop, until we find correct place for temp
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // As soon as arr[j] <= temp, while loop will break
        arr[j + 1] = temp; // We will assign temp to (j+1)th index position
    }
}

int main()
{
    int a[] = {23, 56, 32, 775, 23, 775, 3, 1000, 64};

    int n = sizeof(a) / sizeof(a[0]); // Size of array is calculated in this manner
    insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}