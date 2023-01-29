package controller;

import model.Catalogo;

import java.awt.*;
import java.io.*;
import java.text.DecimalFormat;

public interface BibliotecaController {
    Catalogo CATALOGO_BIBLIOTECA = caricaCatalogo();
    Dimension DIMENSIONE_FIELD = new Dimension(200,20);

    static String getFormatted(double prezzo){
        return "EUR " + new DecimalFormat("0.00").format(prezzo);
    }

    private static Catalogo caricaCatalogo(){
        Catalogo catalogo;
        try(ObjectInputStream objectReader = new ObjectInputStream(new FileInputStream("biblioteca.dat"))){
            catalogo = (Catalogo) objectReader.readObject();
        }
        catch(IOException | ClassNotFoundException | RuntimeException ex){
            catalogo = new Catalogo();
        }
        return catalogo;
    }

    static void salvaBiblioteca(){
        try(ObjectOutputStream objectWriter = new ObjectOutputStream(new FileOutputStream("biblioteca.dat"))){
            objectWriter.writeObject(BibliotecaController.CATALOGO_BIBLIOTECA);
        }
        catch (IOException ex){
            System.out.println("Qualcosa è andato storto.");
        }
    }
}
