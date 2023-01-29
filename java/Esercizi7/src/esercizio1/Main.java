package esercizio1;
import java.util.*;

public class Main {
    public static void main(String[] args){
        int numeroInserito;
        boolean flag = false;
        double inversoMoltiplicativo;
        Scanner stdIn = new Scanner(System.in);
        do {
            System.out.print("Inserisci un numero intero: ");
            try{
                numeroInserito = stdIn.nextInt();
                inversoMoltiplicativo = 1/numeroInserito;
                System.out.println("Inverso moltiplicativo: " + inversoMoltiplicativo);
            }
            catch(InputMismatchException ex){
                System.out.println("Formato numero non valido. Riprovare.");
                stdIn.nextLine();
                flag = true;
            }
            catch(ArithmeticException ex){
                System.out.println("Non puoi dividere un numero per 0");
                flag = true;
            }
        }while(flag);
        stdIn.close();
    }
}
