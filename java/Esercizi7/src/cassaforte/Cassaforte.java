package cassaforte;

public class Cassaforte {
    private final String messaggioSegreto;
    private boolean lock;
    private String password;
    private int contatore;

    public Cassaforte(String messaggioSegreto, String password){
        this.messaggioSegreto = messaggioSegreto;
        this.password = password;
        this.lock = false;
    }

    public final void stampaMessaggio(String password) throws CassaforteException{
        if(this.lock)
            throw new CassaforteException();
        if(this.password.equals(password)) {
            System.out.println("Messaggio segreto: " + this.messaggioSegreto);
            this.contatore = 0;
        }
        else {
            System.out.println("Password sbagliata");
            this.contatore++;
            if(this.contatore>=3)
                this.lock = true;
        }
    }

    public void resetPassword(String password){
        if(password.matches("((.*)\\d(.*))") && password.length()>=6) {
            this.password = password;
            System.out.println("Password reimpostata correttamente");
        }
        else
            System.out.println("Formato password non valido.");
    }
}
