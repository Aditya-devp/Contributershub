class Deque {
	static final int MAX = 100;
	int arr[];
	int front;
	int rear;
	int size;

	public Deque(int size)
	{
		arr = new int[MAX];
		front = -1;
		rear = 0;
		this.size = size;
	}

	// Checks whether Deque is full or not.
	boolean isFull()
	{
		return ((front == 0 && rear == size - 1)
				|| front == rear + 1);
	}

	// Checks whether Deque is empty or not.
	boolean isEmpty() { return (front == -1); }

	// Inserts an element at front
	void insertfront(int key)
	{
		// check whether Deque if full or not
		if (isFull()) {
			System.out.println("Overflow");
			return;
		}

		// If queue is initially empty
		if (front == -1) {
			front = 0;
			rear = 0;
		}

		// front is at first position of queue
		else if (front == 0)
			front = size - 1;

		else // decrement front end by '1'
			front = front - 1;

		// insert current element into Deque
		arr[front] = key;
	}

	// function to inset element at rear end
	// of Deque.
	void insertrear(int key)
	{
		if (isFull()) {
			System.out.println(" Overflow ");
			return;
		}

		// If queue is initially empty
		if (front == -1) {
			front = 0;
			rear = 0;
		}

		// rear is at last position of queue
		else if (rear == size - 1)
			rear = 0;

		// increment rear end by '1'
		else
			rear = rear + 1;

		// insert current element into Deque
		arr[rear] = key;
	}

	// Deletes element at front end of Deque
	void deletefront()
	{
		// check whether Deque is empty or not
		if (isEmpty()) {
			System.out.println("Queue Underflow\n");
			return;
		}

		// Deque has only one element
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else
			// back to initial position
			if (front == size - 1)
			front = 0;

		else // increment front by '1' to remove current
			// front value from Deque
			front = front + 1;
	}

	// Delete element at rear end of Deque
	void deleterear()
	{
		if (isEmpty()) {
			System.out.println(" Underflow");
			return;
		}

		// Deque has only one element
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else if (rear == 0)
			rear = size - 1;
		else
			rear = rear - 1;
	}

	// Returns front element of Deque
	int getFront()
	{
		// check whether Deque is empty or not
		if (isEmpty()) {
			System.out.println(" Underflow");
			return -1;
		}
		return arr[front];
	}

	// function return rear element of Deque
	int getRear()
	{
		// check whether Deque is empty or not
		if (isEmpty() || rear < 0) {
			System.out.println(" Underflow\n");
			return -1;
		}
		return arr[rear];
	}

	// Driver code
	public static void main(String[] args)
	{
		try (Scanner input = new Scanner(System.in)) {
            System.out.println("Enter size of dequeue you want: ");
            int maxSize = input.nextInt();
            Stack stack = new Stack(maxSize);
            int choice;
            do {
                System.out.println("1. Insert at Front");
                System.out.println("2. Insert at Rear");
                System.out.println("3. Dequeue Front Element");
                System.out.println("4. Dequeue Rear Element");
                System.out.println("5. Peek Front");
                System.out.println("6. Peek Rear");
				System.out.println("7. Exit");
                System.out.println("Enter your choice: ");
                choice = input.nextInt();
                switch (choice) {
                    case 1:
                        System.out.println("Enter element to insert at front: ");
                        int element = input.nextInt();
                        dq.insertfront(element);
                        break;
                    case 2:
                        System.out.println("Enter element to insert at rear: ");
                        int element = input.nextInt();
						dq.insertrear(element);
                        break;
                    case 3:
                        System.out.println("Dequeued element from front is " + dq.getFront());
						dq.deletefront();
                        break;
                    case 4:
                        System.out.println("Dequeued element from rear is " + dq.getRear());
						dq.deleterear();
                        break;
                    case 5:
                        System.out.println("Front element is " + dq.getFront());
                        break;
                    case 6:
                        System.out.println("Rear element is " + dq.getRear());
                        break;
					case 7:
                        System.out.println("Exit done");
                        break;
                    default:
                        System.out.println("Invalid choice");
                }
            } while (choice != 7);
        } catch (InputMismatchException exception) {
            System.out.println(exception);
        } catch (Exception exception) {
            System.out.println(exception);
        }
	}
}
