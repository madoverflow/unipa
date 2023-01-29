package v1;
import java.util.*;

public class Menu {
    public static void start(CatalogoLibri catalogo, ArrayList<Autore> listaAutori) {
        boolean flag = true,authorFlag;
        int choice,numeroAutore;
        String titoloLibro,casaEditrice,nomeAutore,cognomeAutore;
        double prezzoLibro;
        ArrayList<Autore> autoriLibro;
        ArrayList<Libro> libriAutore;
        Libro l;
        Scanner stdIn = new Scanner(System.in);

        do {
            System.out.println("Scegli una delle seguenti opzioni:\n1 -> inserisci libro nel catalogo" +
                    "\n2 -> ricerca libro per autore\n3 -> stampa catalogo\n0 -> per uscire");
            choice = stdIn.nextInt();
            stdIn.nextLine();
            switch (choice) {
                case 1:
                    autoriLibro = new ArrayList<>();
                    System.out.print("Titolo libro: ");
                    titoloLibro = stdIn.nextLine();
                    System.out.print("Casa editrice libro: ");
                    casaEditrice = stdIn.nextLine();
                    System.out.print("Prezzo libro: ");
                    prezzoLibro = stdIn.nextDouble();
                    stdIn.nextLine();
                    do{
                        System.out.print("Numero autore: ");
                        numeroAutore = stdIn.nextInt();
                        if(!autoriLibro.contains(listaAutori.get(numeroAutore)))
                            autoriLibro.add(listaAutori.get(numeroAutore));
                        System.out.println("Vuoi inserire altri autori?\ntrue per continuare\nfalse per uscire");
                        authorFlag = stdIn.nextBoolean();
                        stdIn.nextLine();
                    }while(authorFlag);
                    l = new Libro(titoloLibro, prezzoLibro, casaEditrice, autoriLibro);
                    catalogo.aggiungiLibro(l);
                    break;
                case 2:
                    System.out.print("Nome autore: ");
                    nomeAutore = stdIn.nextLine();
                    System.out.print("Cognome autore: ");
                    cognomeAutore = stdIn.nextLine();
                    libriAutore = catalogo.ricerca(nomeAutore,cognomeAutore);
                    if(libriAutore.size()==0)
                        System.out.println("Nessun libro trovato per quell'autore");
                    else {
                        System.out.println("Elenco libri scritti dall'autore:");
                        for (Libro book : libriAutore)
                            System.out.println(book);
                    }
                    break;
                case 3:
                    catalogo.stampaCatalogo();
                    break;
                case 0:
                    System.out.println("Menu terminato");
                    flag = false;
                    break;
                default:
                    System.out.println("Opzione non valida. Riprovare");
                    stdIn.nextLine();
                   break;
            }
        }while(flag);
    }
}
