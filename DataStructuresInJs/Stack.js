//stack
class Stack {
    // Array is used to implement stack
    constructor() {
        this.items = [];
    }
    // push function
    push(element) {
        // push element into the list items
        this.items.push(element);
    }
    // pop function
    pop() {
        if (this.items.length == 0) return -1;
        return this.items.pop();
    }

    // isEmpty function
    isEmpty() {
        // return true if stack is empty
        return this.items.length == 0;
    }

    // peek function
    peek() {
        return this.items[this.items.length - 1];
    }
}

//sample usage -------------------------------------------------------

let s = new Stack();
s.push(1);
s.push(2);
s.push(3);
s.push(4);
while(s.isEmpty() == false){
    console.log(s.pop());
}

