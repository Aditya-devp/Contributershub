def insertion_sort(arr):
    comparison=0
    for i in range(1,len(arr)):
        key=arr[i]
        j=i-1

        while j>0 and key<arr[j]:
            comparison=+1
            arr[j+1]=arr[j]
            j-=1
            arr[j+1]=key
    return comparison


num_elements=int(input("Enter the number of elements (between 10 and 20): "))
if num_elements<10 and num_elements>20:
    print("Number of elements should be between 10 and 20 .")
numbers=[]

for i in range(num_elements):
    number=int(input(f"Enter element {i+1}:"))
    numbers.append(number)

comparisons=insertion_sort(numbers)

print("Sorted array:",numbers)
print(f"Number of comparisons during sorting:{comparisons}")