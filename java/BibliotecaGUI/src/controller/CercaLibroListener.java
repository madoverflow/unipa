package controller;

import model.Libro;
import view.FrameModificaLibro;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class CercaLibroListener implements ActionListener {
    private final FrameModificaLibro finestra;

    public CercaLibroListener(FrameModificaLibro finestra){
        this.finestra = finestra;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int posizione;
        List<Libro> listaLibri = BibliotecaController.CATALOGO_BIBLIOTECA.getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == Libro.class)
                .map(documento -> (Libro) documento)
                .toList();
        posizione = Collections.binarySearch(listaLibri, new Libro(
                        finestra.fieldTitoloRicerca.getText(),
                        0,
                        null,
                        new ArrayList<>()),
                Comparator.comparing(Libro::getTitolo));
        if(posizione >= 0){
            finestra.libro = listaLibri.get(posizione);
            finestra.fieldTitolo.setText(finestra.libro.getTitolo());
            finestra.fieldCasaEditrice.setText(finestra.libro.getCasaEditrice());
            finestra.libro.getListaAutori().forEach(autore -> finestra.autori.addItem(autore));
            finestra.fieldPrezzo.setText(String.valueOf(finestra.libro.getPrezzo()));
            finestra.fieldTitoloRicerca.setEnabled(false);
            finestra.cerca.setEnabled(false);
            finestra.aggiungiAutore.setEnabled(true);
            finestra.rimuoviAutore.setEnabled(true);
            finestra.submit.setEnabled(true);
        }
        else {
            JOptionPane.showMessageDialog(null, "Libro non trovato!");
            finestra.aggiungiAutore.setEnabled(false);
            finestra.rimuoviAutore.setEnabled(false);
            finestra.submit.setEnabled(false);
        }
    }
}
