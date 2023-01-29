package briscola.v3;
import java.util.*;

public class Computer extends Giocatore{

    @Override
    public Carta<Punteggio> giocaCarta() {
        Carta<Punteggio> cartaSceltaComputer = null;

        if(super.manoVuota()){
            System.out.println("Il computer non ha abbastanza carte per buttarne una.");
            throw new NullPointerException();
        }

        List<Carta<Punteggio>> manoComputer = super.getManoGiocatore();
        cartaSceltaComputer = manoComputer.get(0);
        super.rimuoviCarta(cartaSceltaComputer);
        System.out.println("Il computer ha tirato " + cartaSceltaComputer);
        return cartaSceltaComputer;
    }
}
