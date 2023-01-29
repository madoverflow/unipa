package model;

import java.io.Serializable;

public abstract class Documento implements Serializable {
    private static int numeroProgressivo = 1000;
    private final int id;
    private final String titolo;
    private double prezzo;

    public Documento(String titolo, double prezzo){
        this.id = ++Documento.numeroProgressivo;
        this.titolo = titolo;
        this.prezzo = prezzo;
    }

    public String getTitolo() {
        return titolo;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public int getId() {
        return id;
    }

    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    @Override
    public String toString() {
        return "Documento{" +
                "titolo='" + titolo + '\'' +
                ", prezzo=" + prezzo +
                '}';
    }
}
