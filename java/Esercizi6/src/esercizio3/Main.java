package esercizio3;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        File in = new File("testo.txt");
        File out = new File("out.txt");
        BufferedReader buffer = new BufferedReader(new FileReader(in));
        PrintWriter write = new PrintWriter(new FileWriter(out));
        String riga;

        while((riga = buffer.readLine()) != null)
            write.println(riga);
        buffer.close();
        write.close();

    }
}
