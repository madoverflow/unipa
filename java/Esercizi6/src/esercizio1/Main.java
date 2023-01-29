package esercizio1;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] agrs) throws IOException {
        File file = new File("testo.txt");
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        Scanner input = new Scanner(file);
        String riga;

        System.out.println("Stampa del file con BufferedReader riga per riga");
        while((riga=buffer.readLine())!=null)
            System.out.println(riga);
        buffer.close();

        System.out.println("Stampa del file con Scanner riga per riga");
        while(input.hasNextLine())
            System.out.println(input.nextLine());
        input.close();
    }
}
