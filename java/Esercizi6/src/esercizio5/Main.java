package esercizio5;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        PrintWriter write_char = new PrintWriter("standard_input_carattere.txt");
        PrintWriter write_string = new PrintWriter("standard_input_stringhe.txt");
        int carattere;
        char c;
        StringBuilder riga = new StringBuilder();

        System.out.println("Inserisci una stringa: ");
        while((carattere = System.in.read()) != '$'){
            c = (char)carattere;
            write_char.print(c);
            if(c == '\n'){
                write_string.println(riga);
                riga = new StringBuilder();
            }
            else{
                riga.append(c);
            }
        }
        write_char.close();
        write_string.close();
    }
}
