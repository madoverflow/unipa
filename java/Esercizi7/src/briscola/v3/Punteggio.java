package briscola.v3;

public enum Punteggio {
    DUE(0,"2"),
    QUATTRO(0,"4"),
    CINQUE(0,"5"),
    SEI(0,"6"),
    SETTE(0,"7"),
    DONNA(2,"D"),
    CAVALLO(3,"C"),
    RE(4,"R"),
    TRE(10,"3"),
    ASSO(11,"Asso");
    private int valore;
    private String simbolo;

    private Punteggio(int valore, String simbolo){
        this.valore = valore;
        this.simbolo = simbolo;
    }

    public int getValore() {
        return valore;
    }

    public String getSimbolo() {
        return simbolo;
    }

    @Override
    public String toString() {
        return this.simbolo;
    }
}
