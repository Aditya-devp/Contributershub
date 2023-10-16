fun mergeSort(arr: IntArray) {
    if (arr.size > 1) {
        val middle = arr.size / 2
        val left = arr.copyOfRange(0, middle)
        val right = arr.copyOfRange(middle, arr.size)

        mergeSort(left)
        mergeSort(right)

        var i = 0
        var j = 0
        var k = 0

        while (i < left.size && j < right.size) {
            if (left[i] < right[j]) {
                arr[k] = left[i]
                i++
            } else {
                arr[k] = right[j]
                j++
            }
            k++
        }

        while (i < left.size) {
            arr[k] = left[i]
            i++
            k++
        }

        while (j < right.size) {
            arr[k] = right[j]
            j++
            k++
        }
    }
}

fun main() {
    println("Enter the number of elements:")
    val n = readLine()!!.toInt()

    println("Enter $n elements separated by spaces:")
    val arr = readLine()!!.split(" ").map { it.toInt() }.toIntArray()

    mergeSort(arr)

    println("Sorted array:")
    for (element in arr) {
        print("$element ")
    }
}
