package v1;
import java.util.*;

public class Main {
    public static void main(String args[]){
        boolean flag;
        Autore comodoAutore;
        String nomeAutore,cognomeAutore;
        Scanner stdIn = new Scanner(System.in);
        ArrayList<Autore> listaAutori = new ArrayList<>();
        CatalogoLibri catalogo = new CatalogoLibri();
        do{
            System.out.print("Nome autore: ");
            nomeAutore = stdIn.nextLine();
            System.out.print("Cognome autore: ");
            cognomeAutore = stdIn.nextLine();
            comodoAutore = new Autore(nomeAutore,cognomeAutore);
            listaAutori.add(comodoAutore);
            System.out.println("Vuoi inserire altri autori?\ntrue per continuare\nfalse per uscire");
            flag = stdIn.nextBoolean();
            stdIn.nextLine();
        }while(flag);
        for (int i=0; i<listaAutori.size(); i++)
            System.out.println(listaAutori.get(i) + ", numero autore: " + i);
        Menu.start(catalogo,listaAutori);
    }

    public static <T> T prova(List<T> l){
        T lol = null;
        System.out.println("Prova");
        return lol;
    }
}
