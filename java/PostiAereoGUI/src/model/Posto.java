package model;

import java.io.Serializable;
import java.util.Comparator;

public class Posto implements Comparable<Posto>, Serializable {
    public static final String LETTERE_PREDEFINITE[] = {"A","B","C"};
    private final int numero;
    private final String lettera;

    public Posto(int numero, String lettera){
        this.numero = numero;
        this.lettera = lettera;
    }

    public int getNumero() {
        return numero;
    }

    public String getLettera() {
        return lettera;
    }

    @Override
    public String toString() {
        return this.numero + "" + this.lettera;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        if(obj.getClass() != Posto.class)
            return false;
        Posto posto = (Posto) obj;
        return this.getNumero() == posto.getNumero() && this.getLettera().equals(posto.getLettera());
    }

    @Override
    public int compareTo(Posto o) {
        return Comparator
                .comparing(Posto::getNumero)
                .thenComparing(Posto::getLettera)
                .compare(this, o);
    }
}
