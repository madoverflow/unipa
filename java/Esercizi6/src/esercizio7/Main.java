package esercizio7;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        int numeroProgressivo = 1000;

        PrintWriter writer = new PrintWriter(new FileWriter("input.txt",true));
        for(int i = 0; i<10; i++)
            writer.print(numeroProgressivo + "\t");
        writer.close();
    }
}
