package v2;

import java.io.Serializable;

public class Autore implements Comparable<Autore>, Serializable {
    private final String nome;
    private final String cognome;

    public Autore(String nome, String cognome){
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
        return "Autore{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o){
        if(o==null)
            return false;
        if(this==o)
            return true;
        if(o.getClass()!=this.getClass())
            return false;
        Autore a = (Autore) o;
        if(!this.getNome().equals(a.getNome()))
            return false;
        if(!this.getCognome().equals(a.getCognome()))
                return false;
        return true;
    }

    @Override
    public int compareTo(Autore obj){
        if(this.getCognome().compareTo(obj.getCognome())<0)
            return -1;
        if(this.getCognome().compareTo(obj.getCognome())>0)
            return 1;
        if(this.getNome().compareTo(obj.getNome())<0)
            return -1;
        if(this.getNome().compareTo(obj.getNome())>0)
            return 1;
        return 0;
    }
}

