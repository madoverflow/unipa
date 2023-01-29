package view;

import controller.BibliotecaController;
import controller.CercaLibroListener;
import controller.Nominabile;
import controller.SubmitModificaLibro;
import model.Autore;
import model.Libro;

import javax.swing.*;
import java.awt.*;

public class FrameModificaLibro extends JFrame implements Nominabile {
    public final JLabel labelTitoloRicerca = new JLabel("Titolo libro da modificare: ");
    public final JTextField fieldTitoloRicerca = new JTextField();
    public final JButton cerca = new JButton("Cerca");
    public final JPanel pannelloTitoloRicerca = new JPanel();
    public final JLabel labelTitolo = new JLabel("Titolo: ");
    public final JTextField fieldTitolo = new JTextField();
    public final JPanel pannelloTitolo = new JPanel();
    public final JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
    public final JTextField fieldCasaEditrice = new JTextField();
    public final JPanel pannelloCasaEditrice = new JPanel();
    public final JLabel labelAutori = new JLabel("Autori: ");
    public JComboBox<Autore> autori = new JComboBox<>();
    public final JPanel pannelloAutori = new JPanel();
    public final JLabel labelPrezzo = new JLabel("Prezzo: ");
    public final JTextField fieldPrezzo = new JTextField();
    public final JPanel pannelloPrezzo = new JPanel();
    public final JPanel contenitore = new JPanel();
    public final JButton aggiungiAutore = new JButton("Inserisci autore");
    public final JButton rimuoviAutore = new JButton("Rimuovi autore");
    public final JButton submit = new JButton("Invio");
    public final JPanel pannelloBottoni = new JPanel();
    public Libro libro;

    private FrameModificaLibro(){
        Container contentPanel = this.getContentPane();
        this.fieldTitoloRicerca.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCasaEditrice.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldPrezzo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitoloRicerca.add(this.labelTitoloRicerca);
        this.pannelloTitoloRicerca.add(this.fieldTitoloRicerca);
        this.pannelloTitoloRicerca.add(this.cerca);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        this.pannelloCasaEditrice.add(this.labelCasaEditrice);
        this.pannelloCasaEditrice.add(this.fieldCasaEditrice);
        this.pannelloAutori.add(this.labelAutori);
        this.pannelloAutori.add(this.autori);
        this.pannelloPrezzo.add(this.labelPrezzo);
        this.pannelloPrezzo.add(this.fieldPrezzo);
        this.pannelloBottoni.setLayout(new GridLayout(3,1));
        this.aggiungiAutore.setEnabled(false);
        this.rimuoviAutore.setEnabled(false);
        this.submit.setEnabled(false);
        this.pannelloBottoni.add(this.aggiungiAutore);
        this.pannelloBottoni.add(this.rimuoviAutore);
        this.pannelloBottoni.add(this.submit);
        this.contenitore.setLayout(new GridLayout(4,1));
        this.contenitore.add(this.pannelloTitolo);
        this.contenitore.add(this.pannelloCasaEditrice);
        this.contenitore.add(this.pannelloAutori);
        this.contenitore.add(this.pannelloPrezzo);
        contentPanel.add(this.pannelloTitoloRicerca, BorderLayout.NORTH);
        contentPanel.add(this.contenitore, BorderLayout.CENTER);
        contentPanel.add(this.pannelloBottoni, BorderLayout.SOUTH);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameModificaLibro finestra = new FrameModificaLibro();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.cerca.addActionListener(new CercaLibroListener(finestra));
        finestra.aggiungiAutore.addActionListener(event -> FrameAutore.initGUI(finestra));
        finestra.rimuoviAutore.addActionListener(event -> FrameRimuoviAutore.initGUI(finestra));
        finestra.submit.addActionListener(new SubmitModificaLibro(finestra, finestraBiblioteca));
        finestra.setTitle("Modifica libro");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
    @Override
    public void addAuthor(Autore autore) {
        int i;
        for(i = 0; i < this.autori.getItemCount() && !this.autori.getItemAt(i).equals(autore); i++);
        if (this.autori.getItemAt(i) == null || !this.autori.getItemAt(i).equals(autore))
            this.autori.addItem(autore);
    }
    @Override
    public void removeAuthor(Autore autore){
        this.autori.removeItem(autore);
    }
}


