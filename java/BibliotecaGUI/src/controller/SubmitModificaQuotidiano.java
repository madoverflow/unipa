package controller;

import model.Quotidiano;
import view.FrameBiblioteca;
import view.FrameModificaQuotidiano;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SubmitModificaQuotidiano implements ActionListener {
    private final FrameBiblioteca finestraBiblioteca;
    private final FrameModificaQuotidiano finestra;

    public SubmitModificaQuotidiano(FrameModificaQuotidiano finestra, FrameBiblioteca finestraBiblioteca){
        this.finestra = finestra;
        this.finestraBiblioteca = finestraBiblioteca;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String dialogMessage;
        double prezzo;
        try {
            prezzo = Double.parseDouble(finestra.fieldPrezzo.getText());
            BibliotecaController.CATALOGO_BIBLIOTECA.rimuoviDocumento(finestra.quotidiano);
            BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(new Quotidiano(
                    finestra.fieldTitolo.getText(),
                    prezzo,
                    finestra.fieldCasaEditrice.getText(),
                    finestra.fieldCitta.getText()

            ));
            finestra.cerca.setEnabled(true);
            finestra.fieldTitoloRicerca.setEnabled(true);
            finestraBiblioteca.setPannelloDocumenti();
            dialogMessage = "Quotidiano modificato correttamente";
        }
        catch(NumberFormatException ex){
            dialogMessage = "Formato prezzo non valido";
        }
        JOptionPane.showMessageDialog(null, dialogMessage);
    }
}
