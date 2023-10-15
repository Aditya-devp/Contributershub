# Python3 Program for recursive binary search.


# Returns index of x in arr if present, else -1
def binarySearch(arr, l, r, x):

	# Check base case
	if r >= l:

		mid = l + (r - l) // 2

		# If element is present at the middle itself
		if arr[mid] == x:
			return mid

		# If element is smaller than mid, then it
		# can only be present in left subarray
		elif arr[mid] > x:
			return binarySearch(arr, l, mid-1, x)

		# Else the element can only be present
		# in right subarray
		else:
			return binarySearch(arr, mid + 1, r, x)

	# Element is not present in the array
	else:
		return -1


# Driver Code
if __name__ == '__main__':
	arr = [2, 3, 4, 10, 40]
	x = 10
	
	# Function call
	result = binarySearch(arr, 0, len(arr)-1, x)
	
	if result != -1:
		print("Element is present at index", result)
	else:
		print("Element is not present in array")

# Output:
# Element is present at index 3

# Time Complexity: 
# Best Case: O(1)
# Average Case: O(log N)
# Worst Case: O(log N)

# Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(logN).
