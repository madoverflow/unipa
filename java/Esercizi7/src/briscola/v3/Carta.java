package briscola.v3;

public final class Carta<T extends Enum> {
    private final T punteggio;
    private final String seme;

    public Carta(T punteggio, String seme){
        this.punteggio = punteggio;
        this.seme = seme;
    }

    public T getPunteggio() {
        return punteggio;
    }

    public String getSeme() {
        return seme;
    }

    @Override
    public String toString() {
        return this.punteggio + " di " + this.seme;
    }
}
