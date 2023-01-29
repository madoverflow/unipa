package cassaforte;

public final class CassaforteException extends RuntimeException{

    public CassaforteException(){
        super("La cassaforte è stata bloccata per i troppi tentativi falliti");
    }
}
