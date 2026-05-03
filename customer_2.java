import java.io.*;
import java.net.*;

public class customer_2 {
    public static void main(String[] args) {
        try (Socket socket = new Socket("127.0.0.1", 8080)) {
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                out.println("Hello from Java!");
                System.out.println("Message sent to server C++.");
            } catch (IOException e) {
                e.printStackTrace();
        }
    }
}

