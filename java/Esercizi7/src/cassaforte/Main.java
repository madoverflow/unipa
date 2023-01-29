package cassaforte;
import java.util.*;

public class Main {

    public static void main(String... args){
        boolean flag = true;
        String password;
        int choice;
        Scanner stdIn = new Scanner(System.in);
        Cassaforte cassaforte = new Cassaforte("Prova messaggio segreto","ciao1234 4");
        do{
            System.out.println("Inserisci:\n1 -> visualizza messaggio\n2 -> reimposta password\n0 -> per uscire");
            try{
                choice = stdIn.nextInt();
                stdIn.nextLine();
                switch(choice){
                    default:
                        System.out.println("Non hai inserito un'opzione valida. Riprovare");
                        break;
                    case 0:
                        System.out.println("Menu terminato.");
                        flag = false;
                        break;
                    case 1:
                        System.out.print("Inserisci la password della cassafore: ");
                        password = stdIn.nextLine();
                        cassaforte.stampaMessaggio(password);
                        break;
                    case 2:
                        System.out.print("Inserisci la nuova password: ");
                        password = stdIn.nextLine();
                        cassaforte.resetPassword(password);
                        break;
                }
            }
            catch(CassaforteException ex){
                System.out.println(ex.getMessage());
            }
            catch(InputMismatchException ex){
                System.out.println("Formato scelta non valido");
                stdIn.nextLine();
            }
            catch (NoSuchElementException ex){
                System.out.println("Formato password non valido");
            }
        }while(flag);
    }
}
