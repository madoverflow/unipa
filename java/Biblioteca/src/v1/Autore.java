package v1;

public class Autore {
    private final String nome;
    private final String cognome;

    public Autore(String nome, String cognome){
        this.nome = nome;
        this.cognome = cognome;
    }

    public final String getNome() {
        return nome;
    }

    public final String getCognome() {
        return cognome;
    }

    @Override
    public String toString() {
        return "Autore{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                '}';
    }
}
