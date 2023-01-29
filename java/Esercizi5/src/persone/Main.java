package persone;

public class Main {
    public static void main(String args[]){
        Persona p = new Persona("Micael", "Corleone");
        Persona s = new Studente("Sonny", "Corleone", "Università degli Studi" +
                " della Famiglia", 1234);
        Impiegato i = new Impiegato("Pinco", "Panco", p, 25.66);
        Dirigente d = new Dirigente("Panco", "Punco", p, 200000.9876, "Cosa nostra");
        System.out.println(p.getClass()==s.getClass());
        p.presentati();
        s.presentati();
        i.presentati();
        d.presentati();
    }
}
