package persone;
public class Persona {
    private final String nome;
    private final String cognome;
    private final int eta;
    private Genere sesso;

    public enum Genere{
        Maschio, Femmina;
    }

    public Persona(String nome, String cognome, int eta, Genere sesso){
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.sesso = sesso;
    }

    public void presentati(){
        System.out.println("Mi chiamo " + this.nome + " " + this.cognome);
    }

    public final String getNome() {
        return nome;
    }

    public final String getCognome() {
        return cognome;
    }

    @Override
    public String toString() {
        return "Persona{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                '}';
    }

    public int getEta() {
        return eta;
    }

    public Genere getSesso() {
        return sesso;
    }
}
