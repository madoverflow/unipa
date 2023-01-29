package controller;

import model.CompactDisc;
import view.FrameBiblioteca;
import view.FrameModificaCompactDisc;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SubmitModificaCompactDisc implements ActionListener {
    private final FrameBiblioteca finestraBiblioteca;
    private final FrameModificaCompactDisc finestra;

    public SubmitModificaCompactDisc(FrameModificaCompactDisc finestra, FrameBiblioteca finestraBiblioteca){
        this.finestra = finestra;
        this.finestraBiblioteca = finestraBiblioteca;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String dialogMessage;
        double prezzo;
        int dimensioneGB;
        try {
            prezzo = Double.parseDouble(finestra.fieldPrezzo.getText());
            dimensioneGB = Integer.parseInt(finestra.fieldDimensioneGB.getText());
            BibliotecaController.CATALOGO_BIBLIOTECA.rimuoviDocumento(finestra.compactDisc);
            BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(new CompactDisc(
                    finestra.fieldTitolo.getText(),
                    prezzo,
                    dimensioneGB,
                    finestra.fieldTipologia.getText(),
                    finestra.fieldMarca.getText()

            ));
            finestra.cerca.setEnabled(true);
            finestra.fieldTitoloRicerca.setEnabled(true);
            finestraBiblioteca.setPannelloDocumenti();
            dialogMessage = "Compact Disc modificato correttamente";
        }
        catch(NumberFormatException ex){
            dialogMessage = "Formati numerici non validi";
        }
        JOptionPane.showMessageDialog(null, dialogMessage);
    }
}
