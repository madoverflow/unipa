package briscola.v3;
import java.util.*;

public abstract class Giocatore {
    private final List<Carta<Punteggio>> manoGiocatore;
    private int punteggioGiocatore;

    public Giocatore(){
        this.manoGiocatore = new ArrayList<>();
    }

    public final void aggiungiCarta(Carta<Punteggio> carta){
        this.manoGiocatore.add(carta);
    }
    public final void rimuoviCarta(Carta<Punteggio> carta){
        this.manoGiocatore.remove(carta);
    }
    public final boolean manoVuota() { return this.manoGiocatore.size() == 0; }
    public void aggiungiPunteggio(int punteggio) { this.punteggioGiocatore += punteggio; }
    public final void manoIniziale(List<Carta<Punteggio>> mazzo){
        Iterator<Carta<Punteggio>> iteratoreMazzo;
        if(mazzo.size()>=2) {
            iteratoreMazzo = mazzo.iterator();
            for (int i = 0; i < 2; i++) {
                this.manoGiocatore.
                        add(iteratoreMazzo.
                                next());
                iteratoreMazzo.remove();
            }
        }
        else
            System.out.println("Non ci sono abbastanza carte del mazzo.");
    }

    public final List<Carta<Punteggio>> getManoGiocatore() {
        return new ArrayList<>(manoGiocatore);
    }

    public final int getPunteggioGiocatore() {
        return punteggioGiocatore;
    }

    public abstract Carta<Punteggio> giocaCarta();
}
