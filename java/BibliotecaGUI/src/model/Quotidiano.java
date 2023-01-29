package model;

import java.io.Serializable;

public class Quotidiano extends Documento implements Serializable {
    private final String casaEditrice;
    private String citta;
    public Quotidiano(String titolo, double prezzo, String casaEditrice, String citta) {
        super(titolo, prezzo);
        this.casaEditrice = casaEditrice;
        this.citta = citta;
    }

    public String getCasaEditrice() {
        return casaEditrice;
    }

    public String getCitta() {
        return citta;
    }

    @Override
    public String toString() {
        return "Quotidiano{" +
                "titolo='" + super.getTitolo() + '\'' +
                ", prezzo=" + super.getPrezzo() +
                "id=" + super.getId() +
                ", casaEditrice='" + casaEditrice + '\'' +
                ", citta='" + citta + '\'' +
                '}';
    }

    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        if(this == obj)
            return true;
        if(obj.getClass() != Quotidiano.class)
            return false;
        Quotidiano quotidiano = (Quotidiano) obj;
        if(!this.getTitolo().equals(quotidiano.getTitolo()))
            return false;
        if(!this.getCasaEditrice().equals(quotidiano.getCasaEditrice()))
            return false;
        if(!this.getCitta().equals(quotidiano.getCitta()))
            return false;
        return this.getPrezzo() == quotidiano.getPrezzo();
    }
}
