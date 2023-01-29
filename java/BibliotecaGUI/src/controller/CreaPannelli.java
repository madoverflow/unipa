package controller;

import model.*;

import javax.swing.*;
import java.util.stream.Stream;

public interface CreaPannelli {
    static void creaPannelloLibri(JPanel pannello, Stream<Libro> stream){
        pannello.removeAll();
        stream.forEach(
                libro -> {
                    JLabel labelId = new JLabel("Id: ");
                    JLabel id = new JLabel(String.valueOf(libro.getId()));
                    JPanel pannelloId = new JPanel();
                    JLabel labelTitolo = new JLabel("Titolo: ");
                    JLabel titolo = new JLabel(libro.getTitolo());
                    JPanel pannelloTitolo = new JPanel();
                    JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
                    JLabel casaEditrice = new JLabel(libro.getCasaEditrice());
                    JPanel pannelloCasaEditrice = new JPanel();
                    JLabel labelPrezzo = new JLabel("Prezzo: ");
                    JLabel prezzo = new JLabel(BibliotecaController.getFormatted(libro.getPrezzo()));
                    JPanel pannelloPrezzo = new JPanel();
                    JLabel labelAutori = new JLabel("Autori: ");
                    JComboBox<Autore> listaAutori = new JComboBox<>(libro.getListaAutori().toArray(Autore[]::new));
                    JPanel pannelloAutori = new JPanel();
                    JPanel contenitore = new JPanel();
                    pannelloId.add(labelId);
                    pannelloId.add(id);
                    pannelloTitolo.add(labelTitolo);
                    pannelloTitolo.add(titolo);
                    pannelloCasaEditrice.add(labelCasaEditrice);
                    pannelloCasaEditrice.add(casaEditrice);
                    pannelloPrezzo.add(labelPrezzo);
                    pannelloPrezzo.add(prezzo);
                    pannelloAutori.add(labelAutori);
                    pannelloAutori.add(listaAutori);
                    contenitore.add(pannelloId);
                    contenitore.add(pannelloTitolo);
                    contenitore.add(pannelloCasaEditrice);
                    contenitore.add(pannelloPrezzo);
                    contenitore.add(pannelloAutori);
                    pannello.add(contenitore);
                }
        );
    }

    static void creaPannelloDizionari(JPanel pannello, Stream<Dizionario> stream){
        pannello.removeAll();
        stream.forEach(
                dizionario -> {
                    JLabel labelId = new JLabel("Id: ");
                    JLabel id = new JLabel(String.valueOf(dizionario.getId()));
                    JPanel pannelloId = new JPanel();
                    JLabel labelTitolo = new JLabel("Titolo: ");
                    JLabel titolo = new JLabel(dizionario.getTitolo());
                    JPanel pannelloTitolo = new JPanel();
                    JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
                    JLabel casaEditrice = new JLabel(dizionario.getCasaEditrice());
                    JPanel pannelloCasaEditrice = new JPanel();
                    JLabel labelLinguaMadre = new JLabel("Lingua madre: ");
                    JLabel linguaMadre = new JLabel(dizionario.getLinguaMadre());
                    JPanel pannelloLinguaMadre = new JPanel();
                    JLabel labelLinguaTraduzione = new JLabel("Lingua traduzione: ");
                    JLabel linguaTraduzione = new JLabel(dizionario.getLinguaTraduzione());
                    JPanel pannelloLinguaTraduzione = new JPanel();
                    JLabel labelPrezzo = new JLabel("Prezzo: ");
                    JLabel prezzo = new JLabel(BibliotecaController.getFormatted(dizionario.getPrezzo()));
                    JPanel pannelloPrezzo = new JPanel();
                    JLabel labelAutori = new JLabel("Autori: ");
                    JComboBox<Autore> listaAutori = new JComboBox<>(dizionario.getListaAutori().toArray(Autore[]::new));
                    JPanel pannelloAutori = new JPanel();
                    JPanel contenitore = new JPanel();
                    pannelloId.add(labelId);
                    pannelloId.add(id);
                    pannelloTitolo.add(labelTitolo);
                    pannelloTitolo.add(titolo);
                    pannelloCasaEditrice.add(labelCasaEditrice);
                    pannelloCasaEditrice.add(casaEditrice);
                    pannelloLinguaMadre.add(labelLinguaMadre);
                    pannelloLinguaMadre.add(linguaMadre);
                    pannelloLinguaTraduzione.add(labelLinguaTraduzione);
                    pannelloLinguaTraduzione.add(linguaTraduzione);
                    pannelloPrezzo.add(labelPrezzo);
                    pannelloPrezzo.add(prezzo);
                    pannelloAutori.add(labelAutori);
                    pannelloAutori.add(listaAutori);
                    contenitore.add(pannelloId);
                    contenitore.add(pannelloTitolo);
                    contenitore.add(pannelloLinguaMadre);
                    contenitore.add(pannelloLinguaTraduzione);
                    contenitore.add(pannelloCasaEditrice);
                    contenitore.add(pannelloPrezzo);
                    contenitore.add(pannelloAutori);
                    pannello.add(contenitore);
                }
        );
    }

    static void creaPannelloQuotidiani(JPanel pannello, Stream<Quotidiano> stream){
        pannello.removeAll();
        stream.forEach(
                quotidiano -> {
                    JLabel labelId = new JLabel("Id: ");
                    JLabel id = new JLabel(String.valueOf(quotidiano.getId()));
                    JPanel pannelloId = new JPanel();
                    JLabel labelTitolo = new JLabel("Titolo: ");
                    JLabel titolo = new JLabel(quotidiano.getTitolo());
                    JPanel pannelloTitolo = new JPanel();
                    JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
                    JLabel casaEditrice = new JLabel(quotidiano.getCasaEditrice());
                    JPanel pannelloCasaEditrice = new JPanel();
                    JLabel labelCitta= new JLabel("Città: ");
                    JLabel citta = new JLabel(quotidiano.getCitta());
                    JPanel pannelloCitta = new JPanel();
                    JLabel labelPrezzo = new JLabel("Prezzo: ");
                    JLabel prezzo = new JLabel(BibliotecaController.getFormatted(quotidiano.getPrezzo()));
                    JPanel pannelloPrezzo = new JPanel();
                    JPanel contenitore = new JPanel();
                    pannelloId.add(labelId);
                    pannelloId.add(id);
                    pannelloTitolo.add(labelTitolo);
                    pannelloTitolo.add(titolo);
                    pannelloCasaEditrice.add(labelCasaEditrice);
                    pannelloCasaEditrice.add(casaEditrice);
                    pannelloCitta.add(labelCitta);
                    pannelloCitta.add(citta);
                    pannelloPrezzo.add(labelPrezzo);
                    pannelloPrezzo.add(prezzo);
                    contenitore.add(pannelloId);
                    contenitore.add(pannelloTitolo);
                    contenitore.add(pannelloCitta);
                    contenitore.add(pannelloCasaEditrice);
                    contenitore.add(pannelloPrezzo);
                    pannello.add(contenitore);
                }
        );
    }

    static void creaPannelloCompatDisc(JPanel pannello, Stream<CompactDisc> stream){
        pannello.removeAll();
        stream.forEach(
                compactDisc -> {
                    JLabel labelId = new JLabel("Id: ");
                    JLabel id = new JLabel(String.valueOf(compactDisc.getId()));
                    JPanel pannelloId = new JPanel();
                    JLabel labelTitolo = new JLabel("Titolo: ");
                    JLabel titolo = new JLabel(compactDisc.getTitolo());
                    JPanel pannelloTitolo = new JPanel();
                    JLabel labelTipologia = new JLabel("Tipologia: ");
                    JLabel tipologia = new JLabel(compactDisc.getTipologia());
                    JPanel pannelloTipologia = new JPanel();
                    JLabel labelMarca = new JLabel("Marca: ");
                    JLabel marca = new JLabel(compactDisc.getMarca());
                    JPanel pannelloMarca = new JPanel();
                    JLabel labelDimensione = new JLabel("Dimensione in GB: ");
                    JLabel dimensione = new JLabel(String.valueOf(compactDisc.getDimensioneGB()));
                    JPanel pannelloDimensione = new JPanel();
                    JLabel labelPrezzo = new JLabel("Prezzo: ");
                    JLabel prezzo = new JLabel(BibliotecaController.getFormatted(compactDisc.getPrezzo()));
                    JPanel pannelloPrezzo = new JPanel();
                    JPanel contenitore = new JPanel();
                    pannelloId.add(labelId);
                    pannelloId.add(id);
                    pannelloTitolo.add(labelTitolo);
                    pannelloTitolo.add(titolo);
                    pannelloTipologia.add(labelTipologia);
                    pannelloTipologia.add(tipologia);
                    pannelloMarca.add(labelMarca);
                    pannelloMarca.add(marca);
                    pannelloDimensione.add(labelDimensione);
                    pannelloDimensione.add(dimensione);
                    pannelloPrezzo.add(labelPrezzo);
                    pannelloPrezzo.add(prezzo);
                    contenitore.add(pannelloId);
                    contenitore.add(pannelloTitolo);
                    contenitore.add(pannelloTipologia);
                    contenitore.add(pannelloMarca);
                    contenitore.add(pannelloDimensione);
                    contenitore.add(pannelloPrezzo);
                    pannello.add(contenitore);
                }
        );
    }
}
