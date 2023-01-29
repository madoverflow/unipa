package controller;

import model.Autore;
import model.Libro;
import view.FrameBiblioteca;
import view.FrameModificaLibro;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class SubmitModificaLibro implements ActionListener {
    private final FrameBiblioteca finestraBiblioteca;
    private final FrameModificaLibro finestra;

    public SubmitModificaLibro(FrameModificaLibro finestra, FrameBiblioteca finestraBiblioteca){
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
            BibliotecaController.CATALOGO_BIBLIOTECA.rimuoviDocumento(finestra.libro);
            BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(new Libro(
                    finestra.fieldTitolo.getText(),
                    prezzo,
                    finestra.fieldCasaEditrice.getText(),
                    listaAutori

            ));
            finestra.cerca.setEnabled(true);
            finestra.fieldTitoloRicerca.setEnabled(true);
            finestraBiblioteca.setPannelloDocumenti();
            dialogMessage = "Libro modificato correttamente";
        }
        catch(NumberFormatException ex){
            dialogMessage = "Formato prezzo non valido";
        }
        JOptionPane.showMessageDialog(null, dialogMessage);
    }
}
