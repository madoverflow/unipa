package persone;

public class Dirigente extends Impiegato{
    private String dipartimento;

    public Dirigente(String nome, String cognome, Persona datoreLavoro, double salario, String dipartimento){
        super(nome,cognome,datoreLavoro,salario);
        this.dipartimento = dipartimento;
    }

    @Override
    public void presentati(){
        System.out.println("Mi chiamo " + super.getNome() + " " + super.getCognome() +
                " e guadagno " + super.getSalario() + ". Sono il dirigente del dipartimento " + this.dipartimento);
    }

    public final String getDipartimento() {
        return dipartimento;
    }

    @Override
    public String toString() {
        return "Dirigente{" +
                "nome='" + super.getNome() + '\'' +
                "cognome='" + super.getCognome() + '\'' +
                "datoreLavoro=" + super.getDatoreLavoro().toString() +
                ", salario=" + super.getSalario() +
                "dipartimento='" + this.dipartimento + '\'' +
                '}';
    }
}
