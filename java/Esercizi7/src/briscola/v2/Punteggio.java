package briscola.v2;

public enum Punteggio {
    ASSO(9,11,"Asso"),DUE(0,0,"2"),TRE(8,10,"3"),
    QUATTRO(1,0,"4"),CINQUE(2,0,"5"),SEI(3,0,"6"),
    SETTE(4,0,"7"),DONNA(5,2,"D"),CAVALLO(6,3,"C"),
    RE(7,4,"R");
    private int valore;
    private int punteggioReale;
    private String simbolo;

    private Punteggio(int valore, int punteggioReale, String simbolo){
        this.valore = valore;
        this.punteggioReale = punteggioReale;
        this.simbolo = simbolo;
    }

    public int getValore() {
        return valore;
    }

    public int getPunteggioReale() {
        return punteggioReale;
    }

    public String getSimbolo() {
        return simbolo;
    }

    @Override
    public String toString() {
        return "Punteggio{" +
                "valore=" + valore +
                ", punteggioReale=" + punteggioReale +
                ", simbolo='" + simbolo + '\'' +
                '}';
    }
}
