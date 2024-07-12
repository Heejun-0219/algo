
fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }

    val arr = IntArray(n) { readln().toInt() }

    val sum = arr.sum().toLong()
    val maxValue = (arr.maxOrNull() ?: 0).toLong()

    val result = binarySearch(arr, sum, maxValue, m)
    print(result)
}

fun binarySearch(arr: IntArray, sum: Long, maxValue: Long, m: Int): Long {
    var lo = maxValue
    var hi = sum
    var result: Long = 0
    while (lo <= hi) {
        val mid = (lo + hi) / 2
        if (go(arr, mid, m)) {
            result = mid
            hi = mid - 1
        }
        else lo = mid + 1
    }
    return result
}

fun go(arr: IntArray, money: Long, m: Int): Boolean {
    var cnt = 1
    var tmp = money
    for (i in arr) {
        if (tmp - i < 0) {
            tmp = money
            cnt++
        }
        tmp -= i
    }
    return cnt <= m
}
