package model;

import java.io.Serializable;
import java.util.*;

public class Libro extends Documento implements Serializable {
    private final String casaEditrice;
    private final List<Autore> listaAutori;

    public Libro(String titolo, double prezzo, String casaEditrice, List<Autore> autori){
        super(titolo, prezzo);
        this.casaEditrice = casaEditrice;
        autori.sort(Comparator.comparing(Autore::getCognome).thenComparing(Autore::getNome));
        this.listaAutori = autori;
    }

    public String getCasaEditrice() {
        return this.casaEditrice;
    }
    public List<Autore> getListaAutori() {
        return new ArrayList<>(this.listaAutori);
    }

    @Override
    public String toString() {
        return "Libro{" +
                "id=" + super.getId() +
                "titolo='" + super.getTitolo() + '\'' +
                ", prezzo=" + super.getPrezzo() +
                "casaEditrice='" + casaEditrice + '\'' +
                ", listaAutori=" + listaAutori +
                '}';
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        if(this == obj)
            return true;
        if(obj.getClass() != Libro.class)
            return false;
        Libro libro = (Libro) obj;
        if(!this.getTitolo().equals(libro.getTitolo()))
            return false;
        if(!this.getCasaEditrice().equals(libro.getCasaEditrice()))
            return false;
        if(this.getPrezzo() != libro.getPrezzo())
            return false;
        if(this.getListaAutori().size() != libro.getListaAutori().size())
            return false;
        return libro.getListaAutori().containsAll(this.getListaAutori());
    }
}
