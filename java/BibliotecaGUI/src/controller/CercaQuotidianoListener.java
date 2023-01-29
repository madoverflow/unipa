package controller;

import model.Quotidiano;
import view.FrameModificaQuotidiano;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class CercaQuotidianoListener implements ActionListener {
    private final FrameModificaQuotidiano finestra;

    public CercaQuotidianoListener(FrameModificaQuotidiano finestra){
        this.finestra = finestra;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int posizione;
        List<Quotidiano> listaQuotidiani = BibliotecaController.CATALOGO_BIBLIOTECA.getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == Quotidiano.class)
                .map(documento -> (Quotidiano) documento)
                .toList();
        posizione = Collections.binarySearch(listaQuotidiani, new Quotidiano(
                        finestra.fieldTitoloRicerca.getText(),
                        0,
                        null,
                        null),
                Comparator.comparing(Quotidiano::getTitolo));
        if(posizione >= 0){
            finestra.quotidiano = listaQuotidiani.get(posizione);
            finestra.fieldTitolo.setText(finestra.quotidiano.getTitolo());
            finestra.fieldCasaEditrice.setText(finestra.quotidiano.getCasaEditrice());
            finestra.fieldCitta.setText(finestra.quotidiano.getCitta());
            finestra.fieldPrezzo.setText(String.valueOf(finestra.quotidiano.getPrezzo()));
            finestra.fieldTitoloRicerca.setEnabled(false);
            finestra.cerca.setEnabled(false);
            finestra.submit.setEnabled(true);
        }
        else {
            JOptionPane.showMessageDialog(null, "Quotidiano non trovato!");
            finestra.submit.setEnabled(false);
        }
    }
}
