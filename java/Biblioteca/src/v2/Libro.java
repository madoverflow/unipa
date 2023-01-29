package v2;
import java.io.Serializable;
import java.util.*;

public class Libro extends Documento implements Serializable {
    private final String titolo;
    private double prezzo;
    private final String casaEditrice;
    private final int id;
    private final ArrayList<Autore> autori;

    public Libro(String titolo, double prezzo, String casaEditrice, ArrayList<Autore> autori){
        this.id = ++Documento.id;
        this.titolo = titolo;
        this.prezzo = prezzo;
        this.casaEditrice = casaEditrice;
        Collections.sort(autori);
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

    @Override
    public String getInfo(){
        return "Libro";
    }

    @Override
    public boolean equals(Object obj){
        if(obj==null)
            return false;
        if(this==obj)
            return true;
        if(obj.getClass()!=this.getClass())
            return false;
        Libro l = (Libro) obj;
        if(!this.getTitolo().equals(l.getTitolo()))
            return false;
        if(this.getAutori().size()!=l.getAutori().size())
            return false;
        for(Autore a1 : this.getAutori())
            if(!l.getAutori().contains(a1))
                return false;
        return true;
    }
}
