fun quickSort(arr: IntArray, low: Int, high: Int) {
    if (low < high) {
        val pivotIndex = partition(arr, low, high)
        quickSort(arr, low, pivotIndex - 1)
        quickSort(arr, pivotIndex + 1, high)
    }
}

fun partition(arr: IntArray, low: Int, high: Int): Int {
    val pivot = arr[high]
    var i = low - 1

    for (j in low until high) {
        if (arr[j] <= pivot) {
            i++
            swap(arr, i, j)
        }
    }

    swap(arr, i + 1, high)
    return i + 1
}

fun swap(arr: IntArray, i: Int, j: Int) {
    val temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
}

fun main() {
    println("Enter the number of elements:")
    val n = readLine()!!.toInt()

    println("Enter $n elements separated by spaces:")
    val arr = readLine()!!.split(" ").map { it.toInt() }.toIntArray()

    quickSort(arr, 0, n - 1)

    println("Sorted array:")
    for (element in arr) {
        print("$element ")
    }
}
