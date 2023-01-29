package v1;
import java.util.*;

public class Libro {
    private static int progressione = 1000;
    private final String titolo;
    private double prezzo;
    private final String casaEditrice;
    private final int id;
    private final ArrayList<Autore> autori;

    public Libro(String titolo, double prezzo, String casaEditrice, ArrayList<Autore> autori){
        this.id = ++progressione;
        this.titolo = titolo;
        this.prezzo = prezzo;
        this.casaEditrice = casaEditrice;
        this.autori = autori;

    }

    public final String getTitolo() {
        return titolo;
    }

    public final double getPrezzo() {
        return prezzo;
    }

    public final String getCasaEditrice() {
        return casaEditrice;
    }

    public final int getId() {
        return id;
    }

    public final ArrayList<Autore> getAutori() {
        return new ArrayList<Autore>(this.autori);
    }

    @Override
    public String toString() {
        return "Libro{" +
                "titolo='" + titolo + '\'' +
                ", prezzo=" + prezzo +
                ", casaEditrice='" + casaEditrice + '\'' +
                ", id=" + id +
                ", autori=" + autori +
                '}';
    }
}
