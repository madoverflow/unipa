package v2;
import java.io.Serializable;
import java.util.*;

public class Dizionario extends Documento implements Serializable {
    private final String titolo;
    private final String linguaMadre;
    private final String linguaTraduzione;
    private final String casaEditrice;
    private double prezzo;
    private final int id;
    private final ArrayList<Autore> autori;

    public Dizionario(String titolo, String linguaMadre, String linguaTraduzione,
                     String casaEditrice, ArrayList<Autore> autori, double prezzo){
        this.id = ++ Documento.id;
        this.titolo = titolo;
        this.linguaMadre = linguaMadre;
        this.linguaTraduzione = linguaTraduzione;
        this.casaEditrice = casaEditrice;
        this.prezzo = prezzo;
        Collections.sort(autori);
        this.autori = autori;
    }

    @Override
    public String getInfo(){
        return "Dizionario";
    }

    public final String getTitolo() {
        return titolo;
    }

    public final String getLinguaMadre() {
        return linguaMadre;
    }

    public final String getLinguaTraduzione() {
        return linguaTraduzione;
    }

    public final String getCasaEditrice() {
        return casaEditrice;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public final ArrayList<Autore> getAutori() {
        return new ArrayList<Autore>(this.autori);
    }

    @Override
    public String toString() {
        return "Dizionario{" +
                "titolo='" + titolo + '\'' +
                ", linguaMadre='" + linguaMadre + '\'' +
                ", linguaTraduzione='" + linguaTraduzione + '\'' +
                ", casaEditrice='" + casaEditrice + '\'' +
                ", autori=" + autori +
                '}';
    }

    @Override
    public boolean equals(Object obj){
        if(obj==null)
            return false;
        if(this==obj)
            return true;
        if(obj.getClass()!=this.getClass())
            return false;
        Dizionario d = (Dizionario) obj;
        if(!this.getTitolo().equals(d.getTitolo()))
            return false;
        if(this.getAutori().size()!=d.getAutori().size())
            return false;
        for(Autore a1 : this.getAutori())
            if(!d.getAutori().contains(a1))
                return false;
        return true;
    }
}
