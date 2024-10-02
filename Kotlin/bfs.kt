import java.util.LinkedList
import java.util.Queue

class Graph(private val vertices: Int) {
    private val adjacencyList: Array<MutableList<Int>> = Array(vertices) { mutableListOf() }

    fun addEdge(u: Int, v: Int) {
        adjacencyList[u].add(v)
    }

    fun bfs(startVertex: Int) {
        val visited = BooleanArray(vertices)
        val queue: Queue<Int> = LinkedList()

        visited[startVertex] = true
        queue.add(startVertex)

        while (queue.isNotEmpty()) {
            val vertex = queue.poll()
            print("$vertex ")

            for (adjacentVertex in adjacencyList[vertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true
                    queue.add(adjacentVertex)
                }
            }
        }
    }
}

fun main() {
    val graph = Graph(7)

    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(1, 3)
    graph.addEdge(1, 4)
    graph.addEdge(2, 5)
    graph.addEdge(2, 6)

    println("BFS traversal starting from vertex 0:")
    graph.bfs(0)
}