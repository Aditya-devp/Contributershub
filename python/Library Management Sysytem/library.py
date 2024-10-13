import os

class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self.is_borrowed = False

    def __str__(self):
        return f"{self.title} by {self.author}"

class User:
    def __init__(self, name):
        self.name = name
        self.borrowed_books = []

    def borrow_book(self, library, title):
        book = library.get_book_by_title(title)
        if book and not book.is_borrowed:
            book.is_borrowed = True
            self.borrowed_books.append(book)
            library.record_borrowed_book(self.name, book)
            print(f"You have successfully borrowed '{book.title}'")
        else:
            print(f"Sorry, '{title}' is not available.")

    def return_book(self, library, title):
        for book in self.borrowed_books:
            if book.title == title:
                book.is_borrowed = False
                self.borrowed_books.remove(book)
                library.update_returned_book(self.name, book)
                print(f"You have returned '{book.title}'")
                return
        print(f"You don't have '{title}' to return.")

class Library:
    def __init__(self, book_file, borrowed_file):
        self.books = []
        self.book_file = book_file
        self.borrowed_file = borrowed_file
        self.load_books()

    def load_books(self):
        if os.path.exists(self.book_file):
            with open(self.book_file, 'r') as f:
                for line in f:
                    title, author, is_borrowed = line.strip().split(',')
                    book = Book(title, author)
                    book.is_borrowed = True if is_borrowed == 'True' else False
                    self.books.append(book)

    def save_books(self):
        with open(self.book_file, 'w') as f:
            for book in self.books:
                f.write(f"{book.title},{book.author},{book.is_borrowed}\n")

    def display_books(self):
        print("\nAvailable Books:")
        available_books = [book for book in self.books if not book.is_borrowed]
        if not available_books:
            print("No books available.")
        for book in available_books:
            print(book)

    def get_book_by_title(self, title):
        for book in self.books:
            if book.title.lower() == title.lower():
                return book
        return None

    def add_book(self, title, author):
        book = Book(title, author)
        self.books.append(book)
        self.save_books()
        print(f"'{title}' by {author} has been added to the library.")

    def record_borrowed_book(self, user_name, book):
        with open(self.borrowed_file, 'a') as f:
            f.write(f"{user_name},{book.title},{book.author}\n")

    def update_returned_book(self, user_name, book):
        with open(self.borrowed_file, 'r') as f:
            lines = f.readlines()

        with open(self.borrowed_file, 'w') as f:
            for line in lines:
                if not (user_name in line and book.title in line):
                    f.write(line)

def main():
    library = Library('data.txt', 'borrowed.txt')
    
    while True:
        print("\n--- Library Menu ---")
        print("1. View Available Books")
        print("2. Borrow a Book")
        print("3. Return a Book")
        print("4. Donate a Book")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            library.display_books()

        elif choice == '2':
            user_name = input("Enter your name: ")
            user = User(user_name)
            title = input("Enter the book title you want to borrow: ")
            user.borrow_book(library, title)

        elif choice == '3':
            user_name = input("Enter your name: ")
            user = User(user_name)
            title = input("Enter the book title you want to return: ")
            user.return_book(library, title)

        elif choice == '4':
            title = input("Enter the book title you want to donate: ")
            author = input("Enter the book's author: ")
            library.add_book(title, author)

        elif choice == '5':
            print("Goodbye!")
            library.save_books()
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
