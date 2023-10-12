class Graph(private val vertices: Int) {
    private val adjacencyList: Array<MutableList<Int>> = Array(vertices) { mutableListOf() }

    fun addEdge(u: Int, v: Int) {
        adjacencyList[u].add(v)
    }

    fun dfs(startVertex: Int) {
        val visited = BooleanArray(vertices)
        dfsRecursive(startVertex, visited)
    }

    private fun dfsRecursive(vertex: Int, visited: BooleanArray) {
        visited[vertex] = true
        print("$vertex ")

        for (adjacentVertex in adjacencyList[vertex]) {
            if (!visited[adjacentVertex]) {
                dfsRecursive(adjacentVertex, visited)
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

    println("Depth-First Traversal (starting from vertex 0):")
    graph.dfs(0)
}
