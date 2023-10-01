import java.io.*;

public class file_copy_paste {
    public static void main(String[] args) {
        try {
            FileReader r = new FileReader("copy.txt");
            FileWriter w = new FileWriter("paste.txt");

            int character;
            while((character = r.read()) != -1) {
                System.out.print((char) character);
                w.write(character);
            } 
            r.close(); // close 
            w.close();
            System.out.println("Sucefully copied file!");
        } catch (Exception e) {
            System.out.println(e);
            // TODO: handle exception
        }
    }
}
