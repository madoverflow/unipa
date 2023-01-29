package v2;
import java.io.Serializable;
import java.util.*;

public final class Catalogo implements Serializable {
    private final ArrayList<Libro> libri;
    private final ArrayList<Dizionario> dizionari;
    private final ArrayList<Documento> documenti;

    public Catalogo(){
        this.libri = new ArrayList<>();
        this.dizionari = new ArrayList<>();
        this.documenti = new ArrayList<>();
    }
    public Catalogo(ArrayList<Libro> libri, ArrayList<Dizionario> dizionari, ArrayList<Documento> documenti){
        this.libri = libri;
        this.dizionari = dizionari;
        this.documenti = documenti;
    }

    public ArrayList<Libro> getLibri() {
        return new ArrayList<Libro>(this.libri);
    }

    public ArrayList<Dizionario> getDizionari() {
        return new ArrayList<Dizionario>(this.dizionari);
    }

    public ArrayList<Documento> getDocumenti() {
        return new ArrayList<Documento>(this.documenti);
    }

    public void addBook(Libro libro){
        this.libri.add(libro);
    }
    public void addDictionary(Dizionario dizionario){
        this.dizionari.add(dizionario);
    }
    public void addDocument(Documento documento){
        this.documenti.add(documento);
    }

    public void insertBook(int posizione, Libro libro){
        this.libri.set(posizione,libro);
    }

    public void insertDictionary(int posizione, Dizionario dizionario){
        this.dizionari.set(posizione,dizionario);
    }

    public void insertDocument(int posizione, Documento documento){
        this.documenti.set(posizione,documento);
    }

    public void deleteBook(int posizione){
        this.libri.remove(posizione);
    }

    public void deleteDictionary(int posizione){
        this.dizionari.remove(posizione);
    }

    public void deleteDocument(int posizione){
        this.documenti.remove(posizione);
    }

    public void search(String titolo){
        System.out.println("Libri da titolo: " + titolo + "\n");
        for(Libro libro : this.libri)
            if(libro.getTitolo().equals(titolo))
                System.out.println(libro);
        System.out.println("Dizionari da titolo: " + titolo + "\n");
        for(Dizionario dizionario : this.dizionari)
            if(dizionario.getTitolo().equals(titolo))
                System.out.println(dizionario);
    }

    public void search(String nome, String cognome){
        System.out.println("Libri dell'autore " + nome + " " + cognome + "\n");
        for(Libro libro : this.libri)
           for(Autore autore : libro.getAutori())
               if(autore.getNome().equals(nome) && autore.getCognome().equals(cognome))
                   System.out.println(libro);
        System.out.println("Dizionari dell'autore " + nome + " " + cognome + "\n");
        for(Dizionario dizionario : this.dizionari)
            for(Autore autore : dizionario.getAutori())
                if(autore.getNome().equals(nome) && autore.getCognome().equals(cognome))
                    System.out.println(dizionario);
    }

    public void search(int dimensioneGB){
        System.out.println("CompactDisc di dimensione: " + dimensioneGB + "\n");
        for(Documento documento : this.documenti) {
            CompactDisc disco = (CompactDisc) documento;
            if (disco.getDimensioneGB() == dimensioneGB)
                System.out.println(disco);
        }
    }
}
