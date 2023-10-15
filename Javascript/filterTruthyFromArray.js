/*
Filter only truthy values from an array

Array.filter(Boolean) this function will return only truthy values

Sample Input:

[1,2,undefined,3,4,-5,6,0,7,8,null,9,10]

Sample Output:

[ 1, 2, 3, 4, -5, 6, 7, 8, 9, 10 ]
*/

function filterTruthy(array) {
  return array.filter(Boolean);
}
