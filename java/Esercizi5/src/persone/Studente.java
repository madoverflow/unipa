package persone;

public class Studente extends Persona {
    private String universita;
    private final int matricola;

    public Studente(String nome, String cognome, String universita, int matricola){
        super(nome,cognome);
        this.universita = universita;
        this.matricola = matricola;
    }

    @Override
    public void presentati(){
        System.out.println("Mi chiamo " + super.getNome() + " " + super.getCognome() +
                " e studio a " + this.universita);
    }

    public final String getUniversita() {
        return universita;
    }

    public final int getMatricola() {
        return matricola;
    }

    @Override
    public String toString() {
        return "Studente{" +
                "nome='" + super.getNome() + '\'' +
                "cognome='" + super.getCognome() + '\'' +
                "universita='" + universita + '\'' +
                ", matricola=" + matricola +
                '}';
    }
}
