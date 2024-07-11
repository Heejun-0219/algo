
fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val lectures = readln().split(" ").map { it.toInt() }

    var left = lectures.maxOrNull()!!
    var right = lectures.sum()

    while (left <= right) {
        val mid = (left + right) / 2
        var count = 1
        var sum = 0

        for (lecture in lectures) {
            if (sum + lecture > mid) {
                count++
                sum = lecture
            } else {
                sum += lecture
            }
        }

        if (count <= m) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }

    println(left)
}
