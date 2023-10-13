import java.util.PriorityQueue

class Graph(val V: Int) {
    private val adjacencyList = Array(V) { mutableListOf<Pair<Int, Int>>() }

    fun addEdge(u: Int, v: Int, weight: Int) {
        adjacencyList[u].add(Pair(v, weight))
        adjacencyList[v].add(Pair(u, weight)) // For undirected graphs
    }

    fun dijkstra(src: Int) {
        val dist = IntArray(V) { Int.MAX_VALUE }
        dist[src] = 0
        val priorityQueue = PriorityQueue<Pair<Int, Int>>(compareBy { it.second })
        priorityQueue.add(Pair(src, 0))

        while (priorityQueue.isNotEmpty()) {
            val (u, _) = priorityQueue.poll()

            for ((v, weight) in adjacencyList[u]) {
                val newDist = dist[u] + weight
                if (newDist < dist[v]) {
                    dist[v] = newDist
                    priorityQueue.add(Pair(v, newDist))
                }
            }
        }

        for (i in 0 until V) {
            println("Shortest distance from $src to $i is ${dist[i]}")
        }
    }
}

fun main() {
    println("Enter the number of vertices (V):")
    val V = readLine()!!.toInt()

    val graph = Graph(V)

    println("Enter the number of edges (E):")
    val E = readLine()!!.toInt()

    println("Enter the edges (u v weight) separated by spaces:")
    repeat(E) {
        val (u, v, weight) = readLine()!!.split(" ").map { it.toInt() }
        graph.addEdge(u, v, weight)
    }

    println("Enter the source vertex:")
    val source = readLine()!!.toInt()

    graph.dijkstra(source)
}
