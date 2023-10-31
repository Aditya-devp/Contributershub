// class Stack {
//   // Array is used to implement stack
//   constructor() {
//     this.items = [];
//   }
//   // push function
//   push(element) {
//     // push element into the list items
//     this.items.push(element);
//   }
//   // pop function
//   pop() {
//     if (this.items.length == 0) return -1;
//     return this.items.pop();
//   }

//   // isEmpty function
//   isEmpty() {
//     // return true if stack is empty
//     return this.items.length == 0;
//   }

//   // peek function
//   peek() {
//     return this.items[this.items.length - 1];
//   }
// }

// //logic
// /**
//  * @constructor
//  * @param {NestedInteger[]} nestedList
//  */
// var NestedIterator = function (nestedList) {
//   let s = new Stack();
//   flatten(nestedList, s);
//   NestedIterator.prototype.numbers = s;
// };

// function flatten(nestedList, s) {
//   for (let i of nestedList) {
//     if (i.isInteger()) {
//       s.push(i);
//     } else {
//       flatten(i.getList(), s);
//     }
//   }
// }

// /**
//  * @this NestedIterator
//  * @returns {boolean}
//  */
// NestedIterator.prototype.hasNext = function () {
//   if (NestedIterator.prototype.numbers.isEmpty() == true) {
//     return false;
//   } else {
//     return true;
//   }
// };

// /**
//  * @this NestedIterator
//  * @returns {integer}
//  */
// NestedIterator.prototype.next = function () {
//   if (NestedIterator.prototype.numbers.isEmpty() == true) {
//     return false;
//   } else {
//     let toReturn = NestedIterator.prototype.numbers.pop();
//     return toReturn._integer;
//   }
// };

// above code gives reverse answer
// below concept uses generator function

class NestedIterator {
    constructor(nestedList) {
      this.gen = this.listGen(nestedList);
      this.nextVal = this.gen.next();
    }
  
    hasNext() {
      return !this.nextVal.done;
    }
  
    next() {
      let val = this.nextVal.value._integer;
      this.nextVal = this.gen.next();
      return val;
    }
  
    *listGen(list) {
      for (let i of list) {
        if (i.isInteger()) {
          yield i;
        } else {
          yield* this.listGen(i.getList());
        }
      }
    }
  }
  