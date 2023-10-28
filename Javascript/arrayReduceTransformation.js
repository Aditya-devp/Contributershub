/*
Given an integer array 'nums', a reducer function 'func', and an initial value 'init', return a reduced array.

A reduced array is created by applying the following operation: val = func(init, nums[0]), 
val = func(val, nums[1]), 
val = func(val, nums[2]), ... 
until every element in the array has been processed. The final value of val is returned.

If the length of the array is 0, it should return 'init'.

Sample Input:
nums = [1,2,3,4]
func = function sum(accum,curr){ return accum + curr; }
init = 0

Sampl Output:
10

Explantion:
intially,value is init = 0,
(0) + nums[0] = 1
(1) + nums[1] = 3
(3) + nums[2] = 6
(6) + nums[3] = 10
The final answer is 10.
*/

var reduce = function(nums, func, init) {
    let val=init;
    for(let i=0;i<nums.length;++i){
        val=func(val,nums[i])
    }
    return val;
};