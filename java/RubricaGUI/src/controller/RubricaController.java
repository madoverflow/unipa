package controller;

import model.Rubrica;

import java.io.*;

public interface RubricaController {
    static final Rubrica RUBRICA = RubricaController.caricaRubrica();
    private static Rubrica caricaRubrica(){
        try(ObjectInputStream reader = new ObjectInputStream(new FileInputStream("rubrica.dat"))){
            return (Rubrica) reader.readObject();
        } catch (IOException | ClassNotFoundException | RuntimeException ex) {
            return new Rubrica();
        }
    }
    public static void salvaRubrica() throws IOException{
        try(ObjectOutputStream writer = new ObjectOutputStream(new FileOutputStream("rubrica.dat"))){
            writer.writeObject(RubricaController.RUBRICA);
        }
    }
}
