package v2;

import java.io.Serializable;
import java.util.ArrayList;

public class LibroPrestabile extends Libro implements Prestabile, Serializable {
    private boolean disponibilita = true;

    public LibroPrestabile(String titolo, double prezzo, String casaEditrice, ArrayList<Autore> autori){
        super(titolo, prezzo, casaEditrice, autori);
    }

    @Override
    public boolean isAvailable(){
        return disponibilita==true;
    }

    @Override
    public void prenotazione(){
        if(this.isAvailable()) {
            System.out.println("Prenotazione effettuata con successo");
            this.disponibilita = false;
        }
        else
            System.out.println("Libro momentaneamente non disponibile");
    }

    @Override
    public void restituzione(){
        this.disponibilita = true;
    }
}
