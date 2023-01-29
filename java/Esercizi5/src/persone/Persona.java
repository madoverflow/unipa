package persone;

public class Persona {
    private final String nome;
    private final String cognome;

    public Persona(String nome, String cognome){
        this.nome = nome;
        this.cognome = cognome;
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
}
