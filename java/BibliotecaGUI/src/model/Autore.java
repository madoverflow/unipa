package model;

import java.io.Serializable;

public class Autore implements Serializable {
    private final String nome;
    private final String cognome;

    public Autore(String nome, String cognome) {
        this.nome = nome;
        this.cognome = cognome;
    }

    public final String getNome() {
        return nome;
    }

    public final String getCognome() {
        return cognome;
    }

    @Override
    public String toString() {
        return this.nome + " " + this.cognome;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (this == o)
            return true;
        if (o.getClass() != this.getClass())
            return false;
        Autore a = (Autore) o;
        if (!this.getNome().equals(a.getNome()))
            return false;
        return this.getCognome().equals(a.getCognome());
    }
}
