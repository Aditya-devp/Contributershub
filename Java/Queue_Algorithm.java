import java.util.LinkedList;

public class Queue<T> {
    private LinkedList<T> list = new LinkedList<T>();

    public void enqueue(T item) {
        list.addLast(item);
    }

    public T dequeue() {
        return list.poll();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public int size() {
        return list.size();
    }
}