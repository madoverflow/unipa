package esercizio2;
import java.io.*;

public class Main {
    public static void main(String[] agrs) throws IOException {
        File file = new File("testo.txt");
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        int carattere;

        System.out.println("Stampa del file con BufferedReader carattere per carattere");
        while((carattere = buffer.read()) != -1)
            System.out.println((char)carattere);
        buffer.close();
    }
}
