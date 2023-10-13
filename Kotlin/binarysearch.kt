fun binarySearch(arr: IntArray, target: Int): Int {
    var left = 0
    var right = arr.size - 1

    while (left <= right) {
        val mid = left + (right - left) / 2

        if (arr[mid] == target) {
            return mid  // Target found
        } else if (arr[mid] < target) {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return -1  // Target not found
}

fun main() {
    println("Enter the sorted array elements (space-separated):")
    val inputArray = readLine()!!.split(" ").map { it.toInt() }.toIntArray()

    println("Enter the target value:")
    val target = readLine()!!.toInt()

    val result = binarySearch(inputArray, target)

    if (result != -1) {
        println("Target $target found at index $result.")
    } else {
        println("Target $target not found in the array.")
    }
}
