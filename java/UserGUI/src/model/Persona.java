package model;

public class Persona {
    public enum Genere{
        UOMO,
        DONNA;
    }
    private final String nome;
    private final String cognome;
    private Genere sesso;
    private int eta;

    public Persona(String nome, String cognome, int eta, Genere sesso){
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.sesso = sesso;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public Genere getSesso() {
        return sesso;
    }

    public int getEta() {
        return eta;
    }

    @Override
    public String toString() {
        return "Persona{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                ", sesso=" + sesso +
                ", eta=" + eta +
                '}';
    }
}
