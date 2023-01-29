package briscola.v2;
import java.util.*;

public class Main {

    public static void main(String... args){
        boolean inizioGiocatore = true,flag = false;
        int punteggioGiocatore = 0,punteggioComputer = 0, win;
        ArrayList<Carta> mazzo = new ArrayList<>();
        ArrayList<Carta> manoGiocatore = new ArrayList<>();
        ArrayList<Carta> manoComputer = new ArrayList<>();
        Carta cartaSceltaGiocatore = null,cartaSceltaComputer = null;
        String[] seme = {"Denari","Coppe","Spade","Mazze"};
        Scanner stdIn = new Scanner(System.in);

        for(int i = 0; i<4; i++)
            for(Punteggio p : Punteggio.values())
                mazzo.add(new Carta(p, seme[i]));
        Collections.shuffle(mazzo);
        manoGiocatore.add(mazzo.get(1));
        manoComputer.add(mazzo.get(2));
        manoGiocatore.add(mazzo.get(3));
        manoComputer.add(mazzo.get(4));
        for(int i = 5; i<mazzo.size()-1; i += 2){
            System.out.println(punteggioGiocatore + "\n" + punteggioComputer);
            System.out.println("Si ricorda che la briscola è: " + mazzo.get(0));
            cartaSceltaComputer = manoComputer.get(0);
            if(inizioGiocatore){
                manoGiocatore.add(mazzo.get(i));
                manoComputer.add(mazzo.get(i+1));
                System.out.println("Le tue carte: ");
                for(Carta carta : manoGiocatore)
                    System.out.println(carta);
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
                        flag = true;
                    }
                    catch (IndexOutOfBoundsException ex){
                        System.out.println("Devi inserire il numero corretto per la carta");
                        stdIn.nextLine();
                        flag = true;
                    }
                }while(flag);
                System.out.println("Il computer ha tirato: " + cartaSceltaComputer);
            }
            else{
                manoComputer.add(mazzo.get(i));
                manoGiocatore.add(mazzo.get(i+1));
                System.out.println("Le tue carte: ");
                for(Carta carta : manoGiocatore)
                    System.out.println(carta);
                System.out.println("Il computer ha tirato: " + cartaSceltaComputer);
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
                        flag = true;
                    }
                    catch (IndexOutOfBoundsException ex){
                        System.out.println("Devi inserire il numero corretto per la carta");
                        stdIn.nextLine();
                        flag = true;
                    }
                }while(flag);
            }
            win = vincitore(cartaSceltaGiocatore,cartaSceltaComputer,mazzo.get(0).getSeme());
            switch(win){
                case 0:
                    if(inizioGiocatore)
                        punteggioGiocatore += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                                cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    else
                        punteggioComputer += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                                cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    break;
                case 1:
                    inizioGiocatore = true;
                    punteggioGiocatore += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                            cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    break;
                case -1:
                    inizioGiocatore = false;
                    punteggioComputer += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                            cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    break;
            }
            manoGiocatore.remove(cartaSceltaGiocatore);
            manoComputer.remove(cartaSceltaComputer);
        }
        if(inizioGiocatore){
            manoGiocatore.add(mazzo.get(39));
            manoComputer.add(mazzo.get(0));
        }
        else{
            manoGiocatore.add(mazzo.get(0));
            manoComputer.add(mazzo.get(39));
        }
        for(int i = 0; i<3; i++){
            System.out.println(punteggioGiocatore + "\n" + punteggioComputer);
            System.out.println("Si ricorda che la briscola è: " + mazzo.get(0));
            cartaSceltaComputer = manoComputer.get(0);
            if(inizioGiocatore){
                System.out.println("Le tue carte: ");
                for(Carta carta : manoGiocatore)
                    System.out.println(carta);
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
                        flag = true;
                    }
                    catch (IndexOutOfBoundsException ex){
                        System.out.println("Devi inserire il numero corretto per la carta");
                        stdIn.nextLine();
                        flag = true;
                    }
                }while(flag);
                System.out.println("Il computer ha tirato: " + cartaSceltaComputer);
            }
            else{
                System.out.println("Le tue carte: ");
                for(Carta carta : manoGiocatore)
                    System.out.println(carta);
                System.out.println("Il computer ha tirato: " + cartaSceltaComputer);
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
                        flag = true;
                    }
                    catch (IndexOutOfBoundsException ex){
                        System.out.println("Devi inserire il numero corretto per la carta");
                        stdIn.nextLine();
                        flag = true;
                    }
                }while(flag);
            }
            win = vincitore(cartaSceltaGiocatore,cartaSceltaComputer,mazzo.get(0).getSeme());
            switch(win){
                case 0:
                    if(inizioGiocatore)
                        punteggioGiocatore += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                                cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    else
                        punteggioComputer += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                                cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    break;
                case 1:
                    inizioGiocatore = true;
                    punteggioGiocatore += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                            cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    break;
                case -1:
                    inizioGiocatore = false;
                    punteggioComputer += cartaSceltaGiocatore.getPunteggio().getPunteggioReale() +
                            cartaSceltaComputer.getPunteggio().getPunteggioReale();
                    break;
            }
            manoGiocatore.remove(cartaSceltaGiocatore);
            manoComputer.remove(cartaSceltaComputer);
        }
    }

    private static int vincitore(Carta cartaSceltaGiocatore, Carta cartaSceltaComputer, String seme){
        if(cartaSceltaGiocatore.getSeme().equals(cartaSceltaComputer.getSeme()))
            return cartaSceltaGiocatore.getPunteggio().getValore() > cartaSceltaComputer.getPunteggio().getValore()
                    ? 1 : -1;
        if(cartaSceltaGiocatore.getSeme().equals(seme)){
            return 1;
        }
        if(cartaSceltaComputer.getSeme().equals(seme)){
            return -1;
        }
        return 0;
    }
}
