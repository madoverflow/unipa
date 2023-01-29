package view;

import controller.*;
import model.Quotidiano;

import javax.swing.*;
import java.awt.*;

public class FrameModificaQuotidiano extends JFrame {
    public final JLabel labelTitoloRicerca = new JLabel("Titolo quotidiano da modificare: ");
    public final JTextField fieldTitoloRicerca = new JTextField();
    public final JButton cerca = new JButton("Cerca");
    public final JPanel pannelloTitoloRicerca = new JPanel();
    public final JLabel labelTitolo = new JLabel("Titolo: ");
    public final JTextField fieldTitolo = new JTextField();
    public final JPanel pannelloTitolo = new JPanel();
    public final JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
    public final JTextField fieldCasaEditrice = new JTextField();
    public final JPanel pannelloCasaEditrice = new JPanel();
    public final JLabel labelCitta = new JLabel("Città: ");
    public final JTextField fieldCitta = new JTextField();
    public final JPanel pannelloCitta = new JPanel();
    public final JLabel labelPrezzo = new JLabel("Prezzo: ");
    public final JTextField fieldPrezzo = new JTextField();
    public final JPanel pannelloPrezzo = new JPanel();
    public final JPanel contenitore = new JPanel();
    public final JButton submit = new JButton("Invio");
    public Quotidiano quotidiano;

    private FrameModificaQuotidiano(){
        Container contentPanel = this.getContentPane();
        this.fieldTitoloRicerca.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCasaEditrice.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCitta.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldPrezzo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitoloRicerca.add(this.labelTitoloRicerca);
        this.pannelloTitoloRicerca.add(this.fieldTitoloRicerca);
        this.pannelloTitoloRicerca.add(this.cerca);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        this.pannelloCasaEditrice.add(this.labelCasaEditrice);
        this.pannelloCasaEditrice.add(this.fieldCasaEditrice);
        this.pannelloCitta.add(this.labelCitta);
        this.pannelloCitta.add(this.fieldCitta);
        this.pannelloPrezzo.add(this.labelPrezzo);
        this.pannelloPrezzo.add(this.fieldPrezzo);
        this.submit.setEnabled(false);
        this.contenitore.setLayout(new GridLayout(4,1));
        this.contenitore.add(this.pannelloTitolo);
        this.contenitore.add(this.pannelloCasaEditrice);
        this.contenitore.add(this.pannelloCitta);
        this.contenitore.add(this.pannelloPrezzo);
        contentPanel.add(this.pannelloTitoloRicerca, BorderLayout.NORTH);
        contentPanel.add(this.contenitore, BorderLayout.CENTER);
        contentPanel.add(this.submit, BorderLayout.SOUTH);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameModificaQuotidiano finestra = new FrameModificaQuotidiano();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.cerca.addActionListener(new CercaQuotidianoListener(finestra));
        finestra.submit.addActionListener(new SubmitModificaQuotidiano(finestra, finestraBiblioteca));
        finestra.setTitle("Modifica libro");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
