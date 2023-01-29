package briscola;
import java.util.*;

public class Main {
    private static int punteggioGiocatore,punteggioComputer;
    private static boolean inizioGiocatore = true;

    public static void main(String... args){
        ArrayList<Carta> mazzo = new ArrayList<>();
        ArrayList<Carta> manoGiocatore;
        ArrayList<Carta> manoComputer;
        String[] seme = {"Denari","Coppe","Spade","Mazze"};
        for(int i = 0; i<4; i++)
            for(Punteggio p : Punteggio.values())
                mazzo.add(new Carta(p, seme[i]));
        Collections.shuffle(mazzo);
        for(int i=1; i<35;) {
            manoGiocatore = new ArrayList<>();
            manoComputer = new ArrayList<>();
            for (int k = 0; k < 3; k++)
                manoGiocatore.add(mazzo.get(i++));
            for (int k = 0; k < 3; k++)
                manoComputer.add(mazzo.get(i++));
            calcoloPunti(manoGiocatore,manoComputer,mazzo.get(0));
        }
        manoGiocatore = new ArrayList<>();
        manoComputer = new ArrayList<>();
        if(inizioGiocatore){
            manoGiocatore.add(mazzo.get(35));
            manoGiocatore.add(mazzo.get(36));
            manoGiocatore.add(mazzo.get(37));
            manoComputer.add(mazzo.get(38));
            manoComputer.add(mazzo.get(39));
            manoComputer.add(mazzo.get(0));
        }
        else{
            manoComputer.add(mazzo.get(35));
            manoComputer.add(mazzo.get(36));
            manoComputer.add(mazzo.get(37));
            manoGiocatore.add(mazzo.get(38));
            manoGiocatore.add(mazzo.get(39));
            manoGiocatore.add(mazzo.get(0));
        }
        calcoloPunti(manoGiocatore,manoComputer,mazzo.get(0));
        System.out.println(punteggioComputer);
        System.out.println(punteggioGiocatore);
    }

    private static void calcoloPunti(ArrayList<Carta> manoGiocatore, ArrayList<Carta> manoComputer, Carta briscola){
        Carta cartaSceltaGiocatore,cartaSceltaComputer;
        Scanner stdIn = new Scanner(System.in);
        System.out.println("Si ricorda che la briscola è: " + briscola);
        for(int k = 0; k<3; k++){
            System.out.println(punteggioComputer);
            System.out.println(punteggioGiocatore);
            cartaSceltaComputer = manoComputer.get(0);
            System.out.println("Le tue carte: ");
            for(Carta carta : manoGiocatore)
                System.out.println(carta);
            if(inizioGiocatore){
                System.out.println("Scegli quale carta tirare inserendo 0 per la prima carta, " +
                        "1 per la seconda, etc...");
                cartaSceltaGiocatore = manoGiocatore.get(stdIn.nextInt());
                System.out.println("Il computer ha tirato: " + cartaSceltaComputer);
            }
            else{
                System.out.println("Il computer ha tirato: " + cartaSceltaComputer);
                System.out.println("Scegli quale carta tirare inserendo 0 per la prima carta, " +
                        "1 per la seconda, etc...");
                cartaSceltaGiocatore = manoGiocatore.get(stdIn.nextInt());
            }
            if(cartaSceltaGiocatore.getSeme().equals(cartaSceltaComputer.getSeme())) {
                if (cartaSceltaGiocatore.getPunteggio().getValore() > cartaSceltaComputer.getPunteggio().getValore()) {
                    punteggioGiocatore += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                            cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    inizioGiocatore = true;
                }
                else{
                    punteggioComputer += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                            cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    inizioGiocatore = false;
                }
                manoGiocatore.remove(cartaSceltaGiocatore);
                manoComputer.remove(cartaSceltaComputer);
                continue;
            }
            if(cartaSceltaGiocatore.getSeme().equals(briscola.getSeme())){
                punteggioGiocatore += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                        cartaSceltaComputer.getPunteggio().getPunteggioReale();
                inizioGiocatore = true;
                manoGiocatore.remove(cartaSceltaGiocatore);
                manoComputer.remove(cartaSceltaComputer);
                continue;
            }
            if(cartaSceltaComputer.getSeme().equals(briscola.getSeme())){
                punteggioComputer += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                        cartaSceltaComputer.getPunteggio().getPunteggioReale();
                inizioGiocatore = false;
                manoGiocatore.remove(cartaSceltaGiocatore);
                manoComputer.remove(cartaSceltaComputer);
                continue;
            }
            if(inizioGiocatore)
                punteggioGiocatore += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                        cartaSceltaComputer.getPunteggio().getPunteggioReale();
            else
                punteggioComputer += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                        cartaSceltaComputer.getPunteggio().getPunteggioReale();
            manoGiocatore.remove(cartaSceltaGiocatore);
            manoComputer.remove(cartaSceltaComputer);
        }
    }
}
