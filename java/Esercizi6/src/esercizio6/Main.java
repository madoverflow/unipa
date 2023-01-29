package esercizio6;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        int numeroRighe = 1, numeroParole = 0, numeroLettere = 0, numeroCaratteri = 0;
        int caratterePrecedente,carattereCorrente;
        File file = new File("input.txt");

        if(file.exists() && file.length()>0){
            FileReader reader = new FileReader(file);
            caratterePrecedente = reader.read();
            if(caratterePrecedente == '\n')
                numeroRighe++;
            else{
                if(String.valueOf((char)caratterePrecedente).matches("[a-zA-Z]")){
                    numeroLettere++;
                    numeroCaratteri++;
                }
                else{
                    if(caratterePrecedente != ' ')
                        numeroCaratteri++;
                }
            }
            while( (carattereCorrente = reader.read()) != -1){
                if(carattereCorrente == '\n'){
                    if(String.valueOf((char) caratterePrecedente).matches("\\w"))
                        numeroParole++;
                    numeroRighe++;
                }
                else{
                    if(String.valueOf((char)carattereCorrente).matches("[a-zA-Z]")){
                        numeroLettere++;
                        numeroCaratteri++;
                    }
                    else{
                        if(carattereCorrente == ' ' || carattereCorrente == '\t') {
                            if (String.valueOf((char) caratterePrecedente).matches("[^\\s\\n]"))
                                numeroParole++;
                        }
                        else
                            numeroCaratteri++;
                    }
                }
                caratterePrecedente = carattereCorrente;
            }
            if(String.valueOf((char) caratterePrecedente).matches("\\w"))
                numeroParole++;
            reader.close();
            System.out.println("Dettagli file letto:\nNumero righe: " + numeroRighe + "\nNumero parole: " +
                    numeroParole + "\nNumero lettere: " + numeroLettere + "\nNumero carateri: " + numeroCaratteri);
        }
        else
            System.out.println("Problemi con il file");

    }
}
