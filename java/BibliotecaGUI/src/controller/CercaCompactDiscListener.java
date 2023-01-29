package controller;

import model.CompactDisc;
import view.FrameModificaCompactDisc;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class CercaCompactDiscListener implements ActionListener {
    private final FrameModificaCompactDisc finestra;

    public CercaCompactDiscListener(FrameModificaCompactDisc finestra){
        this.finestra = finestra;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int posizione;
        List<CompactDisc> listaCompactDisc = BibliotecaController.CATALOGO_BIBLIOTECA.getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == CompactDisc.class)
                .map(documento -> (CompactDisc) documento)
                .toList();
        posizione = Collections.binarySearch(listaCompactDisc, new CompactDisc(
                        finestra.fieldTitoloRicerca.getText(),
                        0,
                        0,
                        null,
                        null),
                Comparator.comparing(CompactDisc::getTitolo));
        if(posizione >= 0){
            finestra.compactDisc = listaCompactDisc.get(posizione);
            finestra.fieldTitolo.setText(finestra.compactDisc.getTitolo());
            finestra.fieldMarca.setText(finestra.compactDisc.getMarca());
            finestra.fieldTipologia.setText(finestra.compactDisc.getTipologia());
            finestra.fieldDimensioneGB.setText(String.valueOf(finestra.fieldDimensioneGB.getText()));
            finestra.fieldPrezzo.setText(String.valueOf(finestra.compactDisc.getPrezzo()));
            finestra.fieldTitoloRicerca.setEnabled(false);
            finestra.cerca.setEnabled(false);
            finestra.submit.setEnabled(true);
        }
        else {
            JOptionPane.showMessageDialog(null, "Compact Disc non trovato!");
            finestra.submit.setEnabled(false);
        }
    }
}
