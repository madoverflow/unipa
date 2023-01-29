package v2;
import java.io.*;
import java.util.*;

public class Menu {
    public static void start() throws IOException, ClassNotFoundException {
        boolean flag;
        int choice;
        String nomeAutore, cognomeAutore;
        ArrayList<Autore> listaAutori = null;
        File file = new File("biblioteca.dat");
        Catalogo catalogo = null;
        Libro libro;
        Dizionario dizionario;
        Documento documento;
        Scanner stdIn = new Scanner(System.in);

        if(file.exists() && file.length()>0){
            ObjectInputStream reader = new ObjectInputStream(new FileInputStream(file));
            listaAutori = (ArrayList<Autore>) reader.readObject();
            catalogo = (Catalogo) reader.readObject();
            reader.close();
        }
        else {
            catalogo = new Catalogo();
            listaAutori = new ArrayList<>();
            do {
                System.out.print("Nome autore: ");
                nomeAutore = stdIn.nextLine();
                System.out.print("Cognome autore: ");
                cognomeAutore = stdIn.nextLine();
                listaAutori.add(new Autore(nomeAutore, cognomeAutore));
                System.out.println("Vuoi inserire altri autori?\ntrue per continuare\nfalse per uscire");
                flag = stdIn.nextBoolean();
                stdIn.nextLine();
            } while (flag);
        }
        for (int i = 0; i < listaAutori.size(); i++)
            System.out.println(listaAutori.get(i) + ", numero autore: " + i);
        do {
            flag = true;
            System.out.println("Scegli una delle seguenti opzioni:\n1 -> inserisci documento nel catalogo" +
                    "\n2 -> modifica documento del catalogo\n3 -> elimina documento del catalogo\n" +
                    "4 -> stampa catalogo\n5-> ricerca documento nel catalogo\n0 -> per uscire");
            choice = stdIn.nextInt();
            stdIn.nextLine();
            switch (choice) {
                case 0:
                    System.out.println("Menu terminato");
                    flag = false;
                    break;
                case 1:
                    do {
                        System.out.println("Scegli una delle seguenti opzioni:\n1 -> inserisci libro nel catalogo" +
                                "\n2 -> inserisci dizionario nel catalogo\n3 -> inserisci compactDisc nel " +
                                "catalogo\n0 -> per uscire");
                        choice = stdIn.nextInt();
                        stdIn.nextLine();
                        switch (choice) {
                            case 1:
                                libro = Menu.createBook(listaAutori);
                                if (Menu.isDuplicateLibro(catalogo.getLibri(), libro))
                                    System.out.println("Il libro è già stato inserito.");
                                else
                                    catalogo.addBook(libro);
                                break;
                            case 2:
                                dizionario = Menu.createDictionary(listaAutori);
                                if (Menu.isDuplicateDizionario(catalogo.getDizionari(), dizionario))
                                    System.out.println("Il dizionario è già stato inserito.");
                                else
                                    catalogo.addDictionary(dizionario);
                                break;
                            case 3:
                                catalogo.addDocument(Menu.createDocument());
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
                    } while (flag);
                    flag = true;
                    break;
                case 2:
                    System.out.println("Scegli la tipologia:\n1 -> libro\n2 -> dizionario\n3 -> documento");
                    choice = stdIn.nextInt();
                    switch (choice) {
                        case 1:
                            libro = createBook(listaAutori);
                            if(!Menu.isDuplicateLibro(catalogo.getLibri(),libro)){
                                for (int i = 0; i < catalogo.getLibri().size(); i++)
                                    System.out.println(catalogo.getLibri().get(i) + "Posizione libro: " + i);
                                System.out.print("Inserisci la posizione: ");
                                catalogo.insertBook(stdIn.nextInt(),libro);
                                stdIn.nextLine();
                            }
                            else
                                System.out.println("Libro già esistente");
                            break;
                        case 2:
                            dizionario = createDictionary(listaAutori);
                            if(!Menu.isDuplicateDizionario(catalogo.getDizionari(),dizionario)){
                                for (int i = 0; i < catalogo.getDizionari().size(); i++)
                                    System.out.println(catalogo.getDizionari().get(i) + "Posizione dizionario: " + i);
                                System.out.print("Inserisci la posizione: ");
                                catalogo.insertDictionary(stdIn.nextInt(),dizionario);
                                stdIn.nextLine();
                            }
                            else
                                System.out.println("Libro già esistente");
                            break;
                        case 3:
                           documento = Menu.createDocument();
                           for (int i = 0; i < catalogo.getDocumenti().size(); i++)
                               System.out.println(catalogo.getDocumenti().get(i) + "Posizione documento: " + i);
                           System.out.print("Inserisci la posizione: ");
                           catalogo.insertDocument(stdIn.nextInt(), documento);
                           stdIn.nextLine();
                           break;
                        default:
                            System.out.println("Operazione non valida");
                            stdIn.nextLine();
                            break;
                    }
                    break;
                case 3:
                    System.out.println("Scegli la tipologia:\n1 -> libro\n2 -> dizionario\n3 -> documento");
                    choice = stdIn.nextInt();
                    switch (choice) {
                        case 1:
                            for (int i = 0; i < catalogo.getLibri().size(); i++)
                                System.out.println(catalogo.getLibri().get(i) + "Posizione libro: " + i);
                            System.out.print("Inserisci la posizione: ");
                            catalogo.deleteBook(stdIn.nextInt());
                            stdIn.nextLine();
                            break;
                        case 2:
                            for (int i = 0; i < catalogo.getDizionari().size(); i++)
                                System.out.println(catalogo.getLibri().get(i) + "Posizione dizionario: " + i);
                            System.out.print("Inserisci la posizione: ");
                            catalogo.deleteDictionary(stdIn.nextInt());
                            stdIn.nextLine();
                            break;
                        case 3:
                            for (int i = 0; i < catalogo.getDocumenti().size(); i++)
                                System.out.println(catalogo.getLibri().get(i) + "Posizione documento: " + i);
                            System.out.print("Inserisci la posizione: ");
                            catalogo.deleteDocument(stdIn.nextInt());
                            stdIn.nextLine();
                            break;
                        default:
                            System.out.println("Operazione non valida");
                            break;
                    }
                    break;
                case 4:
                    System.out.println("Biblioteca");
                    System.out.println("\nLibri");
                    for (Libro l : catalogo.getLibri())
                        System.out.println(l);
                    System.out.println("\nDizionari");
                    for (Dizionario d : catalogo.getDizionari())
                        System.out.println(d);
                    System.out.println("\nDocumenti vari");
                    for (Documento d : catalogo.getDizionari())
                        System.out.println(d);
                    break;
                case 5:
                    System.out.println("Scegli che tipo di ricerca vuoi fare:" +
                            "\n1 -> per titolo\n2 -> per autore\n3 -> per dimensione");
                    choice = stdIn.nextInt();
                    switch (choice) {
                        case 1:
                            System.out.print("Inserisci il titolo da cercare: ");
                            catalogo.search(stdIn.nextLine());
                            break;
                        case 2:
                            System.out.print("Inserisci nome e cognome dell'autore da cercare: ");
                            catalogo.search(stdIn.nextLine(), stdIn.nextLine());
                            break;
                        case 3:
                            System.out.print("Inserisci la dimensione del CompactDisc: ");
                            catalogo.search(stdIn.nextInt());
                            stdIn.nextLine();
                            break;
                        default:
                            System.out.println("Operazione non valida");
                            break;
                    }
                    break;
                default:
                    System.out.println("Opzione non valida. Riprovare");
                    stdIn.nextLine();
                    break;
            }
        } while (flag);
        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(file));
        out.writeObject(listaAutori);
        out.writeObject(catalogo);
        out.close();
    }

    private static boolean isDuplicateLibro(ArrayList<Libro> libri, Libro l) {
        Comparator<Libro> comparator = new Comparator<Libro>() {
            @Override
            public int compare(Libro l1, Libro l2) {
                ArrayList<Autore> a = new ArrayList<>(l1.getAutori());
                ArrayList<Autore> b = new ArrayList<>(l2.getAutori());
                int i;
                int minimo = Math.min(l1.getAutori().size(), l2.getAutori().size());
                for (i = 0; i < minimo && a.get(i).equals(b.get(i)); i++) ;
                if (i >= minimo) {
                    if (l1.getTitolo().compareTo(l2.getTitolo()) < 0)
                        return -1;
                    if (l1.getTitolo().compareTo(l2.getTitolo()) > 0)
                        return 1;
                    if (a.size() < b.size())
                        return -1;
                    if (a.size() > b.size())
                        return 1;
                    return 0;
                }
                return a.get(i).compareTo(b.get(i));
            }
        };
        Collections.sort(libri, comparator);
        return Collections.binarySearch(libri, l, comparator) >= 0;
    }

    private static boolean isDuplicateDizionario(ArrayList<Dizionario> dizionari, Dizionario dizionario) {
        Comparator<Dizionario> comparator = new Comparator<Dizionario>() {
            @Override
            public int compare(Dizionario d1, Dizionario d2) {
                ArrayList<Autore> a = new ArrayList<>(d1.getAutori());
                ArrayList<Autore> b = new ArrayList<>(d2.getAutori());
                int i;
                int minimo = Math.min(d1.getAutori().size(), d2.getAutori().size());
                for (i = 0; i < minimo && a.get(i).equals(b.get(i)); i++) ;
                if (i >= minimo) {
                    if (d1.getTitolo().compareTo(d2.getTitolo()) < 0)
                        return -1;
                    if (d1.getTitolo().compareTo(d2.getTitolo()) > 0)
                        return 1;
                    if (a.size() < b.size())
                        return -1;
                    if (a.size() > b.size())
                        return 1;
                    return 0;
                }
                return a.get(i).compareTo(b.get(i));
            }
        };
        Collections.sort(dizionari, comparator);
        return Collections.binarySearch(dizionari, dizionario, comparator) >= 0;
    }

    private static Libro createBook(ArrayList<Autore> listaAutori) {
        boolean authorFlag;
        ArrayList<Autore> autoriLibro = new ArrayList<>();
        String titoloLibro, casaEditrice;
        Scanner stdIn = new Scanner(System.in);
        int numeroAutore;
        double prezzoLibro;
        Libro libro;

        System.out.print("Titolo libro: ");
        titoloLibro = stdIn.nextLine();
        System.out.print("Casa editrice libro: ");
        casaEditrice = stdIn.nextLine();
        System.out.print("Prezzo libro: ");
        prezzoLibro = stdIn.nextDouble();
        stdIn.nextLine();
        do {
            System.out.print("Numero autore: ");
            numeroAutore = stdIn.nextInt();
            if (!autoriLibro.contains(listaAutori.get(numeroAutore)))
                autoriLibro.add(listaAutori.get(numeroAutore));
            System.out.println("Vuoi inserire altri autori?\ntrue per continuare\nfalse per uscire");
            authorFlag = stdIn.nextBoolean();
            stdIn.nextLine();
        } while (authorFlag);
        System.out.print("Il libro è prestabile?\ntrue confermare\nfalse altrimenti: ");
        if (stdIn.nextBoolean())
            libro = new LibroPrestabile(titoloLibro, prezzoLibro, casaEditrice, autoriLibro);
        else
            libro = new Libro(titoloLibro, prezzoLibro, casaEditrice, autoriLibro);
        stdIn.nextLine();
        return libro;
    }

    private static Dizionario createDictionary(ArrayList<Autore> listaAutori){
        boolean authorFlag;
        ArrayList<Autore> autoriDizionario = new ArrayList<>();
        String titoloDizionario,casaEditrice,linguaMadre,linguaTraduzione;
        double prezzoDizionario;
        int numeroAutore;
        Scanner stdIn = new Scanner(System.in);

        System.out.print("Titolo dizionario: ");
        titoloDizionario = stdIn.nextLine();
        System.out.print("Casa editrice dizionario: ");
        casaEditrice = stdIn.nextLine();
        System.out.print("Lingua madre: ");
        linguaMadre = stdIn.nextLine();
        System.out.print("Lingua traduzione: ");
        linguaTraduzione = stdIn.nextLine();
        System.out.print("Prezzo dizionario: ");
        prezzoDizionario = stdIn.nextDouble();
        stdIn.nextLine();
        do {
            System.out.print("Numero autore: ");
            numeroAutore = stdIn.nextInt();
            if (!autoriDizionario.contains(listaAutori.get(numeroAutore)))
                autoriDizionario.add(listaAutori.get(numeroAutore));
            System.out.println("Vuoi inserire altri autori?\ntrue per continuare\n" +
                    "false per uscire");
            authorFlag = stdIn.nextBoolean();
            stdIn.nextLine();
        } while (authorFlag);
        return new Dizionario(titoloDizionario, linguaMadre, linguaTraduzione,
                casaEditrice, autoriDizionario, prezzoDizionario);
    }

    private static Documento createDocument(){
        String tipologia,marca;
        int dimensioneGB;
        boolean scrivibile;
        Scanner stdIn = new Scanner(System.in);

        System.out.print("Tipologia compactDisc: ");
        tipologia = stdIn.nextLine();
        System.out.print("Marca: ");
        marca = stdIn.nextLine();
        System.out.print("E' scrivibile? Risposta boolean: ");
        scrivibile = stdIn.nextBoolean();
        System.out.print("Dimensione: ");
        dimensioneGB = stdIn.nextInt();
        stdIn.nextLine();
        return new CompactDisc(dimensioneGB, tipologia, marca, scrivibile);
    }
}
