package lettere;

public enum NumeriPari {
    ZERO("zero",0),
    DUE("due",2),
    QUATTRO("quattro",4),
    SEI("sei",6),
    OTTO("otto",8),
    DIECI("dieci",10),
    DODICI("dodici",12),
    QUATTORDICI("quattordici",14),
    SEDICI("sedici",16),
    DICIOTTO("diciotto",18),
    VENTI("venti",20),
    VENTIDUE("ventidue",22),
    VENTIQUATTRO("ventiquattro",24),
    VENTISEI("ventisei",26),
    VENTOTTO("ventotto",28);
    private final String numero;
    private final int valore;

    private NumeriPari(String numero, int valore){
        this.numero = numero;
        this.valore = valore;
    }

    public String getNumero() {
        return numero;
    }

    public int getValore() {
        return valore;
    }
}
