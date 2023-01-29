package v2;

import java.io.Serializable;

public class CompactDisc extends Documento implements Serializable {
    private final int id;
    private final int dimensioneGB;
    private final String tipologia;
    private boolean scrivibile;
    private final String marca;

    public CompactDisc(int dimensioneGB, String tipologia, String marca, boolean scrivibile){
        this.id = ++ Documento.id;
        this.dimensioneGB = dimensioneGB;
        this.tipologia = tipologia;
        this.marca = marca;
        this.scrivibile = scrivibile;
    }

    @Override
    public String getInfo(){
        return "CompactDisc";
    }

    public final int getId() {
        return id;
    }

    public final int getDimensioneGB() {
        return dimensioneGB;
    }

    public final String getTipologia() {
        return tipologia;
    }

    public final boolean isScrivibile() {
        return scrivibile;
    }

    public final String getMarca() {
        return marca;
    }

    @Override
    public String toString() {
        return "CompactDisc{" +
                "id=" + id +
                ", dimensioneGB=" + dimensioneGB +
                ", tipologia='" + tipologia + '\'' +
                ", scrivibile=" + scrivibile +
                ", marca='" + marca + '\'' +
                '}';
    }
}
