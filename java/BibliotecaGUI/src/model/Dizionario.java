package model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Dizionario extends Documento implements Serializable {
    private final String linguaMadre;
    private final String linguaTraduzione;
    private final String casaEditrice;
    private final List<Autore> listaAutori;

    public Dizionario(String titolo, String linguaMadre, String linguaTraduzione,
                      String casaEditrice, List<Autore> autori, double prezzo) {
        super(titolo, prezzo);
        this.linguaMadre = linguaMadre;
        this.linguaTraduzione = linguaTraduzione;
        this.casaEditrice = casaEditrice;
        autori.sort(Comparator.comparing(Autore::getCognome).thenComparing(Autore::getNome));
        this.listaAutori = autori;
    }

    public String getLinguaMadre() {
        return linguaMadre;
    }

    public String getLinguaTraduzione() {
        return linguaTraduzione;
    }

    public String getCasaEditrice() {
        return casaEditrice;
    }

    public List<Autore> getListaAutori() {
        return new ArrayList<>(this.listaAutori);
    }

    @Override
    public String toString() {
        return "Dizionario{" +
                "titolo='" + super.getTitolo() + '\'' +
                ", prezzo=" + super.getPrezzo() +
                "linguaMadre='" + linguaMadre + '\'' +
                ", linguaTraduzione='" + linguaTraduzione + '\'' +
                ", casaEditrice='" + casaEditrice + '\'' +
                ", id=" + super.getId() +
                ", listaAutori=" + listaAutori +
                '}';
    }

    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        if(this == obj)
            return true;
        if(obj.getClass() != Dizionario.class)
            return false;
        Dizionario dizionario = (Dizionario) obj;
        if(!this.getTitolo().equals(dizionario.getTitolo()))
            return false;
        if(!this.getCasaEditrice().equals(dizionario.getCasaEditrice()))
            return false;
        if(!this.getLinguaMadre().equals(dizionario.getLinguaMadre()))
            return false;
        if(!this.getLinguaTraduzione().equals(dizionario.getLinguaTraduzione()))
            return false;
        if(this.getPrezzo() != dizionario.getPrezzo())
            return false;
        if(this.getListaAutori().size() != dizionario.getListaAutori().size())
            return false;
        return dizionario.getListaAutori().containsAll(this.getListaAutori());
    }
}
