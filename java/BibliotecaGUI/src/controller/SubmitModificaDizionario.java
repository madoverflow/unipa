package controller;

import model.Autore;
import model.Dizionario;
import view.FrameBiblioteca;
import view.FrameModificaDizionario;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class SubmitModificaDizionario implements ActionListener {
    private final FrameBiblioteca finestraBiblioteca;
    private final FrameModificaDizionario finestra;

    public SubmitModificaDizionario(FrameModificaDizionario finestra, FrameBiblioteca finestraBiblioteca){
        this.finestra = finestra;
        this.finestraBiblioteca = finestraBiblioteca;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String dialogMessage;
        double prezzo;
        List<Autore> listaAutori = new ArrayList<>();
        try {
            prezzo = Double.parseDouble(finestra.fieldPrezzo.getText());
            for(int i = 0; i < finestra.autori.getItemCount(); i++)
                listaAutori.add(finestra.autori.getItemAt(i));
            BibliotecaController.CATALOGO_BIBLIOTECA.rimuoviDocumento(finestra.dizionario);
            BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(new Dizionario(
                    finestra.fieldTitolo.getText(),
                    finestra.fieldLinguaMadre.getText(),
                    finestra.fieldLinguaTraduzione.getText(),
                    finestra.fieldCasaEditrice.getText(),
                    listaAutori,
                    prezzo

            ));
            finestra.cerca.setEnabled(true);
            finestra.fieldTitoloRicerca.setEnabled(true);
            finestraBiblioteca.setPannelloDocumenti();
            dialogMessage = "Dizionario modificato correttamente";
        }
        catch(NumberFormatException ex){
            dialogMessage = "Formato prezzo non valido";
        }
        JOptionPane.showMessageDialog(null, dialogMessage);
    }
}
