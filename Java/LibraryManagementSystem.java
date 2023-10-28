import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Book {
    private String title;
    private String author;
    private int id;
    
    public Book(String title, String author, int id) {
        this.title = title;
        this.author = author;
        this.id = id;
    }
    
    public String getTitle() {
        return title;
    }
    
    public String getAuthor() {
        return author;
    }
    
    public int getId() {
        return id;
    }
}

class Library {
    private List<Book> catalog;
    
    public Library() {
        catalog = new ArrayList<>();
    }
    
    public void addBook(String title, String author, int id) {
        Book book = new Book(title, author, id);
        catalog.add(book);
    }
    
    public void displayCatalog() {
        for (Book book : catalog) {
            System.out.println("ID: " + book.getId());
            System.out.println("Title: " + book.getTitle());
            System.out.println("Author: " + book.getAuthor());
            System.out.println("--------");
        }
    }
    
    public Book findBookById(int id) {
        for (Book book : catalog) {
            if (book.getId() == id) {
                return book;
            }
        }
        return null;
    }
}

public class LibraryManagementSystem {
    public static void main(String[] args) {
        Library library = new Library();
        
        library.addBook("Book 1", "Author 1", 1);
        library.addBook("Book 2", "Author 2", 2);
        library.addBook("Book 3", "Author 3", 3);
        
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("Library Management System Menu");
            System.out.println("1. Display Catalog");
            System.out.println("2. Find Book by ID");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            
            int choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    library.displayCatalog();
                    break;
                case 2:
                    System.out.print("Enter book ID: ");
                    int id = scanner.nextInt();
                    Book foundBook = library.findBookById(id);
                    if (foundBook != null) {
                        System.out.println("Book found:");
                        System.out.println("Title: " + foundBook.getTitle());
                        System.out.println("Author: " + foundBook.getAuthor());
                    } else {
                        System.out.println("Book not found.");
                    }
                    break;
                case 3:
                    System.out.println("Goodbye!");
                    scanner.close(); // Close the Scanner
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
