package model;

import java.io.Serializable;

public class Cassaforte implements Serializable {
    private static final long serialVersionUID = 1000L;
    private String messaggioSegreto;
    private boolean lock;
    private String password;
    private int contatore;

    public Cassaforte(String messaggioSegreto, String password){
        this.messaggioSegreto = messaggioSegreto;
        this.password = password;
        this.lock = false;
    }

    public final String stampaMessaggio(String password) throws CassaforteException{
        if(this.lock)
            throw new CassaforteException();
        if(this.password.equals(password)) {
            this.contatore = 0;
            return this.messaggioSegreto;
        }
        this.contatore++;
        if(this.contatore>=3)
            this.lock = true;
        return "Password sbagliata";
    }

    public void setPassword(String password){
        this.password = password;
        this.contatore = 0;
        System.out.println("Password settata correttamente");
    }

    public void resetMessaggioSegreto(String messagioSegreto, String password){
        if(this.password.equals(password))
            this.messaggioSegreto = messagioSegreto;
        else
            System.out.println("Le password non coincidono");
    }

    public boolean isEqualsToPassword(String stringa){
        return stringa.equals(this.password);
    }
}
