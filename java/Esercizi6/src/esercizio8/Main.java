package esercizio8;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        int key = 10;
        int carattere;

        FileReader reader = new FileReader("input.txt");
        PrintWriter writer = new PrintWriter(new FileWriter("input.txt",true));
        writer.print('\n');
        while( (carattere = reader.read()) != -1){
            if(carattere != '\n')
                writer.print((char)(carattere+key));
            else
                writer.print((char)carattere);
        }
        reader.close();
        writer.close();
    }
}
