class LL {
    public Node head;
    private int size;

    LL(){
        this.size = 0;
    }

    public class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
            this.next = null;
            size++;
        }
    }

    public void addLast(int data){
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
            size++;
            return;
        }
        Node currNode = head;
        while(currNode.next != null){
            currNode = currNode.next;
        }
        currNode.next = newNode;
    }

    public void printList(){
        if(head == null){
            System.out.println("List is empty");
            return;
        }
        Node currNode = head;
        while(currNode != null){
            System.out.print(currNode.data +  " -> ");
            currNode = currNode.next;
        }
        System.out.println("NULL");
    }

    public void deleteFirst(){
        if(head == null){
            System.out.println("the list is empty");
            return;
        }
        size--;
        head = head.next;
    }

    public void deleteLast(){
        if(head == null){
            System.out.println("the list is empty");
            return;
        }
        size--;
        if(head.next == null){
            head = null;
            return;
        }

        Node secondLast = head;
        Node lastNode = head.next;
        while(lastNode.next != null){
            lastNode = lastNode.next;
            secondLast = secondLast.next;
        }
        secondLast.next = null;
    }
    public void deleteByValue(int data){
        if(head == null){
            System.out.println("List is empty!");
        }
        Node current = head;
        while(current.next.data != data){
            current = current.next;
        }
        current.next = current.next.next;
    }
    public void addFirst(int data){
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }
    // reverses the LinkedList without the creation of a new LinkedList
    public void reverse(){
        Node prev = null;
        Node current = head;
        Node nextNode;

        while(current != null){
            nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }


    public int getSize(){
        return size;
    }

    public static void main(String[] args){
        LL list = new LL();
        list.addFirst(4);
        list.addFirst(3);
        list.addLast(2);
        list.addFirst(1);
        System.out.print("Before List: ");
        list.printList();
        list.reverse();
        System.out.print("After List: ");
        list.printList();
    }
    }

//     public int nthElementFromEnd(LL list, int i) {
//         int size = list.getSize();
//         Node current = head;
//         int num = 0;
//         while(num <= size - i + 1){
//             current = current.next;
//             num ++;
//         }
//         return current.data;
//     }
// }

// class nthElement{

//     public static int nthElementFromEnd(LL list, int n){
//         int size = list.getSize();
//         LL.Node current = list.head;
//         int num = 0;
//         while(num <= size - n + 1){
//             current = current.next;
//             num ++;
//         }
//         return current.data;
//     }
    // public static int findMiddle(LL list){
    //     Node current = list.head;
    //     int number = 0;
    //     int size = list.getSize();
    //     if(size % 2 == 0){
    //         while(number != (size/2 + 1)){
    //             current = current.next;
    //             number ++;
    //         }
    //     }
    //     else{
    //         while(number != (size/2 + 2)){
    //             current = current.next;
    //             number ++;
    //         }
    //     }
    //     return current.data;
    // }
    // public boolean detectLoop(){
    //     Node current = head;
    //     Node newCurrent = head;
    //     while(newCurrent != null && newCurrent.next != null){
    //         current = current.next;
    //         newCurrent = newCurrent.next.next;
    //         if(current == newCurrent){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
       // public void reverseLinkedList(){
    //     Node current = head;
    //     LL newList = new LL();
    //     while(current != null){
    //         newList.addFirst(current.data);
    //         current = current.next;
    //     }
    //     newList.printList();
    // }


