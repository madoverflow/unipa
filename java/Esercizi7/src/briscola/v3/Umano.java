package briscola.v3;
import java.util.*;

public class Umano extends Giocatore{
    private final String nome;
    public Umano(String nome){
        super();
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return "Umano{" +
                "nome='" + nome + '\'' +
                '}';
    }

    @Override
    public Carta<Punteggio> giocaCarta() {
        if(super.manoVuota()){
            System.out.println("Non hai abbastanza carte per buttarne una.");
            throw new NullPointerException();
        }

        boolean flag = true;
        List<Carta<Punteggio>> manoGiocatore = super.getManoGiocatore();
        Carta<Punteggio> cartaSceltaGiocatore = null;
        Scanner stdIn = new Scanner(System.in);

        System.out.println("Ecco le tue carte");
        for(Carta<Punteggio> carta : manoGiocatore)
            System.out.print(carta + " ");
        System.out.print("\n");
        System.out.println("Scegli quale carta tirare inserendo 0 per la prima carta, " +
                "1 per la seconda, etc...");
        do{
            try {
                cartaSceltaGiocatore = manoGiocatore.get(stdIn.nextInt());
                flag = false;
            }
            catch (InputMismatchException ex){
                System.out.println("Bisogna inserire un numero intero.");
                stdIn.nextLine();
            }
            catch (IndexOutOfBoundsException ex){
                System.out.println("Devi inserire il numero corretto per la carta");
                stdIn.nextLine();
            }
        }while(flag);
        super.rimuoviCarta(cartaSceltaGiocatore);
        return cartaSceltaGiocatore;
    }
}
