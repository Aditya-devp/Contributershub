// DFS algorithm implemented in Java
//contributed by @whyanujjwhy
package org.example.algorithms;

import java.util.*;

//main class
class DFS {
  private LinkedList<Integer> adjLists[];
  private boolean visited[];

  // Graph creation
  DFS(int vertices) {
    adjLists = new LinkedList[vertices];
    visited = new boolean[vertices];

    for (int i = 0; i < vertices; i++)
      adjLists[i] = new LinkedList<Integer>();
  }

  // Adding edges src->dest
  void addEdge(int src, int dest) {
    adjLists[src].add(dest);
  }

  // DFS algorithm function
  //called recursively
  void dfsTraversal(int vertex) {
    visited[vertex] = true;
    System.out.print(vertex + " ");

    Iterator<Integer> ite = adjLists[vertex].listIterator();
    while (ite.hasNext()) {
      int adj = ite.next();
      if (!visited[adj])
        dfsTraversal(adj);
    }
  }

  public static void main(String args[]) {
    DFS g = new DFS(4); //graph of 4 nodes

    //edges in the directed graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(2, 0);

    System.out.println("Depth First Traversal");

    g.dfsTraversal(2);  //start node is 2
  }
}
