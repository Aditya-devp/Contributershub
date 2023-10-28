# Merge Sort Algorithm Implementation

## Table of Contents

1. [Introduction](#introduction)
2. [Description](#description)
3. [Algorithm](#algorithm)
4. [Complexity](#complexity)
5. [Usage](#usage)
6. [Contributing](#contributing)
7. [License](#license)

## Introduction <a name="introduction"></a>
  
Merge sort is one of the very popular sorting algorithms in computer science education due to its efficiency and easier understanding compared to other algorithms. The algorithm is based on the divide-and-conquer paradigm.

## Description <a name="description"></a>

For this sort method, the implementation involves splitting up the array or list into individual pieces (subarrays of size 0 or 1), which we know will already be sorted, then continually merge the sublists together until the entire array is again a single sorted list.

## Algorithm <a name="algorithm">

The pseudocode/algorithm for Merge Sort is as follows:

```sh
  MergeSort(arr[], l,  r)
  If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = l+ (r-l)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
```

On the highest level, the Merge Sort function repeatedly splits the array until there is only one item (which is by default sorted), then merges adjacent "sorted" sections. This merge step is performed until the entire array is again a single section. 

## Complexity <a name="complexity"></a>

- Time Complexity: `O(n*log n)` for all cases (worst, average and best) as merge sort always divides the array into two halves and take linear time to merge two halves.
- Space Complexity: `O(n)` in the worst case. Merge sort needs extra space for the auxiliary array.

## Usage <a name="usage"></a>

This implementation of Merge Sort can be used to sort any array or list of comparable objects (i.e., objects that can be compared via the '>' and '<' operators). It can be used to sort in both ascending and descending order.