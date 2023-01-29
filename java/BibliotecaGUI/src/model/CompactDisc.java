package model;

import java.io.Serializable;

public class CompactDisc extends Documento implements Serializable {
    private final int dimensioneGB;
    private final String tipologia;
    private final String marca;

    public CompactDisc(String titolo, double prezzo, int dimensioneGB, String tipologia, String marca) {
        super(titolo, prezzo);
        this.dimensioneGB = dimensioneGB;
        this.tipologia = tipologia;
        this.marca = marca;
    }

    public int getDimensioneGB() {
        return dimensioneGB;
    }

    public String getTipologia() {
        return tipologia;
    }

    public String getMarca() {
        return marca;
    }

    @Override
    public String toString() {
        return "CompactDisc{" +
                "titolo='" + super.getTitolo() + '\'' +
                ", prezzo=" + super.getPrezzo() +
                ", id=" + super.getId() +
                ", dimensioneGB=" + dimensioneGB +
                ", tipologia='" + tipologia + '\'' +
                ", marca='" + marca + '\'' +
                '}';
    }

    public boolean equals(Object obj) {
        if(obj == null)
            return false;
        if(this == obj)
            return true;
        if(obj.getClass() != CompactDisc.class)
            return false;
        CompactDisc compactDisc = (CompactDisc) obj;
        if(!this.getTitolo().equals(compactDisc.getTitolo()))
            return false;
        if(!this.getTipologia().equals(compactDisc.getTipologia()))
            return false;
        if(!this.getMarca().equals(compactDisc.getMarca()))
            return false;
        if(this.getDimensioneGB() != compactDisc.getDimensioneGB())
            return false;
        return this.getPrezzo() == compactDisc.getPrezzo();
    }
}
