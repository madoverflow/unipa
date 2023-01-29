package controller;

import model.Dizionario;
import view.FrameModificaDizionario;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class CercaDizionarioListener implements ActionListener {
    private final FrameModificaDizionario finestra;

    public CercaDizionarioListener (FrameModificaDizionario finestra){
        this.finestra = finestra;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int posizione;
        List<Dizionario> listaDizionari = BibliotecaController.CATALOGO_BIBLIOTECA.getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == Dizionario.class)
                .map(documento -> (Dizionario) documento)
                .toList();
        posizione = Collections.binarySearch(listaDizionari, new Dizionario(
                        finestra.fieldTitoloRicerca.getText(),
                        null,
                        null,
                        null,
                        new ArrayList<>(),
                        0),
                Comparator.comparing(Dizionario::getTitolo));
        if(posizione >= 0){
            finestra.dizionario = listaDizionari.get(posizione);
            finestra.fieldTitolo.setText(finestra.dizionario.getTitolo());
            finestra.fieldCasaEditrice.setText(finestra.dizionario.getCasaEditrice());
            finestra.fieldLinguaMadre.setText(finestra.dizionario.getLinguaMadre());
            finestra.fieldLinguaTraduzione.setText(finestra.dizionario.getLinguaTraduzione());
            finestra.dizionario.getListaAutori().forEach(autore -> finestra.autori.addItem(autore));
            finestra.fieldPrezzo.setText(String.valueOf(finestra.dizionario.getPrezzo()));
            finestra.fieldTitoloRicerca.setEnabled(false);
            finestra.cerca.setEnabled(false);
            finestra.aggiungiAutore.setEnabled(true);
            finestra.rimuoviAutore.setEnabled(true);
            finestra.submit.setEnabled(true);
        }
        else {
            JOptionPane.showMessageDialog(null, "Dizionario non trovato!");
            finestra.aggiungiAutore.setEnabled(false);
            finestra.rimuoviAutore.setEnabled(false);
            finestra.submit.setEnabled(false);
        }
    }
}
