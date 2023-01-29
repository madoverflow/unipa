package persone;

public class Impiegato extends Persona{
    private Persona datoreLavoro;
    private double salario;

    public Impiegato(String nome, String cognome, Persona datoreLavoro, double salario){
        super(nome,cognome);
        this.datoreLavoro = datoreLavoro;
        this.salario = salario;
    }

    @Override
    public void presentati(){
        System.out.println("Mi chiamo " + super.getNome() + " " + super.getCognome() +
                " e guadagno " + this.salario);
    }

    public final Persona getDatoreLavoro() {
        return new Persona(datoreLavoro.getNome(),datoreLavoro.getCognome());
    }

    public final double getSalario() {
        return salario;
    }

    @Override
    public String toString() {
        return "Impiegato{" +
                "nome='" + super.getNome() + '\'' +
                "cognome='" + super.getCognome() + '\'' +
                "datoreLavoro=" + datoreLavoro.toString() +
                ", salario=" + salario +
                '}';
    }
}
