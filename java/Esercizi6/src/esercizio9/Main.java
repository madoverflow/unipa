package esercizio9;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        FileReader reader = new FileReader("input.txt");
        PrintWriter writer = new PrintWriter("cripted.txt");
        int key = 10;
        int carattere;

        System.out.println("Criptando file...");
        while( (carattere = reader.read()) != -1){
            writer.print((char)(carattere + key));
        }
        writer.close();
        reader.close();
        System.out.println("Criptazione terminata.");
        System.out.println("Decriptando...");
        reader = new FileReader("cripted.txt");
        while( (carattere = reader.read()) != -1)
            System.out.print((char)(carattere - key));
        System.out.println("\nDecriptazione terminata");
    }
}
