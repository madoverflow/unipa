package briscola.v3;
import java.util.*;

public class Briscola{
    public static void start(){
        boolean inizioGiocatore = true;
        int cartaVincente;
        GiocoCarteAPI<Punteggio> API = new GiocoCarteAPI<>(){};
        Umano player = new Umano("Rossi");
        Computer computer = new Computer();
        Carta<Punteggio> briscola, cartaGiocataPlayer,cartaGiocataComputer;
        List<Carta<Punteggio>> mazzo = API.creaMazzo(
                Punteggio.values(),
                List.of("Denari","Spade","Mazze","Coppe"));
        System.out.println("Inizio del gioco della briscola");
        Collections.shuffle(mazzo);
        briscola = mazzo.get(0);
        mazzo.remove(briscola);
        mazzo.add(briscola);
        player.manoIniziale(mazzo);
        computer.manoIniziale(mazzo);
        for(int i = 0; i<mazzo.size() || (!player.manoVuota() && !computer.manoVuota()); i+=2){
            System.out.println("La briscola è " + briscola);
            if(i<mazzo.size()){
                if(inizioGiocatore){
                    player.aggiungiCarta(mazzo.get(i));
                    computer.aggiungiCarta(mazzo.get(i+1));
                }
                else{
                    computer.aggiungiCarta(mazzo.get(i));
                    player.aggiungiCarta(mazzo.get(i+1));
                }
            }
            try {
                if (inizioGiocatore) {
                    cartaGiocataPlayer = player.giocaCarta();
                    cartaGiocataComputer = computer.giocaCarta();
                } else {
                    cartaGiocataComputer = computer.giocaCarta();
                    cartaGiocataPlayer = player.giocaCarta();
                }
            }
            catch(NullPointerException ex){
                System.out.println("Il giocatore o il computer sono senza carte");
                continue;
            }
            cartaVincente = API.vincitoreTurno(cartaGiocataPlayer, cartaGiocataComputer,
                    (c1,c2) ->
                    {
                        if(c1.getSeme().equals(c2.getSeme()))
                            return c1.getPunteggio().ordinal() > c2.getPunteggio().ordinal() ? 1 : -1;
                        if(c1.getSeme().equals(briscola.getSeme()))
                            return 1;
                        if(c2.getSeme().equals(briscola.getSeme()))
                            return -1;
                        return 0;
                    }
            );
            if(cartaVincente == 1){
                inizioGiocatore = true;
                player.aggiungiPunteggio(
                        cartaGiocataPlayer.getPunteggio().getValore() + cartaGiocataComputer.getPunteggio().getValore()
                );
                continue;
            }
            if(cartaVincente == -1){
                inizioGiocatore = false;
                computer.aggiungiPunteggio(
                        cartaGiocataPlayer.getPunteggio().getValore() + cartaGiocataComputer.getPunteggio().getValore()
                );
                continue;
            }
            if(inizioGiocatore)
                player.aggiungiPunteggio(
                        cartaGiocataPlayer.getPunteggio().getValore() + cartaGiocataComputer.getPunteggio().getValore()
                );
            else
                computer.aggiungiPunteggio(
                        cartaGiocataPlayer.getPunteggio().getValore() + cartaGiocataComputer.getPunteggio().getValore()
                );
        }
        System.out.println("Punteggi finali: \n" +
                player.getPunteggioGiocatore() + "\n" + computer.getPunteggioGiocatore());

    }
}
