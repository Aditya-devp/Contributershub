lengthStack = 5
Stack = [None] * 5
Pointer = 0


def Push(Item):
    global lengthStack, Stack, Pointer
    if Pointer >= lengthStack:
        print("Stack is full")
        return False
    Stack[Pointer] = Item
    Pointer += 1
    return True


def Pop():
    global lengthStack, Stack, Pointer
    if Pointer == 0:
        print("Stack is empty")
        return False
    Stack[Pointer]  = None
    Pointer -= 1
    return True






