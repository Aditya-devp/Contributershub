#include <iostream>

using namespace std;

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int first = array[0];
  int second = array[1];
  int third = array[2];

  for (int i = 3; i < 10; i++) {
    if (array[i] > first) {
      third = second;
      second = first;
      first = array[i];
    } else if (array[i] > second) {
      third = second;
      second = array[i];
    } else if (array[i] > third) {
      third = array[i];
    }
  }

  cout << "The third largest element is " << third << endl;

  return 0;
}
