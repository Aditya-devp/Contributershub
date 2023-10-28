fun fibonacci(n: Int): Int {
    val dp = IntArray(n + 1)

    if (n <= 1) return n

    dp[0] = 0
    dp[1] = 1

    for (i in 2..n) {
        dp[i] = dp[i - 1] + dp[i - 2]
    }

    return dp[n]
}

fun main() {
    println("Enter the value of n to find the nth Fibonacci number:")
    val n = readLine()!!.toInt()

    val result = fibonacci(n)
    println("The $n-th Fibonacci number is: $result")
}
