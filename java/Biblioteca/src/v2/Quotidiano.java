package v2;

import java.io.Serializable;

public class Quotidiano extends Documento implements Serializable {
    private final int id;
    private final String nome;
    private final String casaEditrice;
    private String citta;
    private double prezzo;

    public Quotidiano(String nome, String casaEditrice, String citta, double prezzo){
        this.id = ++ Documento.id;
        this.nome = nome;
        this.casaEditrice = casaEditrice;
        this.citta = citta;
        this.prezzo = prezzo;
    }

    @Override
    public String getInfo(){
        return "Quotidiano";
    }

    public final int getId() {
        return id;
    }

    public final String getNome() {
        return nome;
    }

    public final String getCasaEditrice() {
        return casaEditrice;
    }

    public final String getCitta() {
        return citta;
    }

    public final double getPrezzo() {
        return prezzo;
    }

    @Override
    public String toString() {
        return "Quotidiano{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", casaEditrice='" + casaEditrice + '\'' +
                ", citta='" + citta + '\'' +
                ", prezzo=" + prezzo +
                '}';
    }
}
