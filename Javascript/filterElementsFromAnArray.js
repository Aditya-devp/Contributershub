/*
Given an integer array 'arr' and a filtering function 'func', return a filtered array 'filteredArr'.

The 'func' function takes one or two arguments:
 - arr[i] -> number from the 'arr'
 - i -> index of 'arr[i]'

 'filteredArr' should only contain the elements from the 'arr' for which the expression func(arr[i], i) evaluates to a truthy value. A truthy value is a value where Boolean(value) returns true.


 Sample Input:
 arr=[0,10,20,30], func=function greaterThan10(n){ return n>10;}

 Sample output:
 [20,30]

 Explanation:
 const newArray = filter(arr,func); //[20,30]
 The function filters out values that are not greater than 10.
*/

var filter = function(arr, func) {
    let a=[];
    for(let i=0;i<arr.length;++i){
        if(func(arr[i],i)) a.push(arr[i])
    }
    return a;
};