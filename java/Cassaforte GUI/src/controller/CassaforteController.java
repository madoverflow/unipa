package controller;

import model.Cassaforte;

import java.io.*;
import java.util.function.*;

public interface CassaforteController {
    static final Cassaforte CASSAFORTE = returnCassaforte();
    static <T,U,V> void testSicurezzaPassword(
            T parametro1, U parametro2, V parametro3,
            Predicate<T> filtro1, Predicate<T> filtro2,
            BiConsumer<U,V> accettatoreFiltro1, BiConsumer<U,V> accettatoreFiltro2, BiConsumer<U,V> accettatore){
        if(filtro2.test(parametro1)) {
            accettatoreFiltro2.accept(parametro2, parametro3);
            return;
        }
        if(filtro1.test(parametro1)) {
            accettatoreFiltro1.accept(parametro2, parametro3);
            return;
        }
        accettatore.accept(parametro2,parametro3);
    }

    static Cassaforte returnCassaforte() {
        Cassaforte cassaforte = null;
        try(ObjectInputStream readerObject = new ObjectInputStream(new FileInputStream("cassaforte.dat"))){
            cassaforte = (Cassaforte) readerObject.readObject();
        }
        catch (RuntimeException | IOException | ClassNotFoundException ex){
            System.out.println("Qualcosa è andata storto coi file\n Creazione cassaforte vuota");
            cassaforte = new Cassaforte("","");
        }
        return cassaforte;
    }

    static void salvataggioCassaforte(){
        try(ObjectOutputStream writerObject = new ObjectOutputStream(new FileOutputStream("cassaforte.dat"))){
            writerObject.writeObject(CASSAFORTE);
        }
        catch (IOException ex){
            System.out.println("Non è stato possibile salvare la cassaforte in un file");
        }
    }
}
