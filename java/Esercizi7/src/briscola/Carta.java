package briscola;

public final class Carta {
    private Punteggio punteggio;
    private String seme;

    public Carta(Punteggio punteggio, String seme){
        this.punteggio = punteggio;
        this.seme = seme;
    }

    public Punteggio getPunteggio() {
        return punteggio;
    }

    public String getSeme() {
        return seme;
    }

    @Override
    public String toString() {
        return this.punteggio.getSimbolo() + " di " + this.seme;
    }
}
