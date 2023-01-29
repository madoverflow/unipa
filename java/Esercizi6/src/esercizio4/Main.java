package esercizio4;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        File in = new File("testo.txt");
        File out = new File("out.txt");
        BufferedReader buffer = new BufferedReader(new FileReader(in));
        PrintWriter write = new PrintWriter(new FileWriter(out));
        int carattere;

        while((carattere = buffer.read()) != -1)
            write.print((char)carattere);
        buffer.close();
        write.close();

    }
}