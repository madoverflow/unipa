package view;

import controller.*;
import model.CompactDisc;

import javax.swing.*;
import java.awt.*;

public class FrameModificaCompactDisc extends JFrame {
    public final JLabel labelTitoloRicerca = new JLabel("Titolo Compact Disc da modificare: ");
    public final JTextField fieldTitoloRicerca = new JTextField();
    public final JButton cerca = new JButton("Cerca");
    public final JPanel pannelloTitoloRicerca = new JPanel();
    public final JLabel labelTitolo = new JLabel("Titolo: ");
    public final JTextField fieldTitolo = new JTextField();
    public final JPanel pannelloTitolo = new JPanel();
    public final JLabel labelMarca = new JLabel("Marca: ");
    public final JTextField fieldMarca = new JTextField();
    public final JPanel pannelloMarca = new JPanel();
    public final JLabel labelTipologia = new JLabel("Tipologia: ");
    public final JTextField fieldTipologia= new JTextField();
    public final JPanel pannelloTipologia = new JPanel();
    public final JLabel labelDimensioneGB = new JLabel("Dimensione in GB: ");
    public final JTextField fieldDimensioneGB = new JTextField();
    public final JPanel pannelloDimensioneGB = new JPanel();
    public final JLabel labelPrezzo = new JLabel("Prezzo: ");
    public final JTextField fieldPrezzo = new JTextField();
    public final JPanel pannelloPrezzo = new JPanel();
    public final JPanel contenitore = new JPanel();
    public final JButton submit = new JButton("Invio");
    public CompactDisc compactDisc;

    private FrameModificaCompactDisc(){
        Container contentPanel = this.getContentPane();
        this.fieldTitoloRicerca.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldMarca.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldTipologia.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldDimensioneGB.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldPrezzo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitoloRicerca.add(this.labelTitoloRicerca);
        this.pannelloTitoloRicerca.add(this.fieldTitoloRicerca);
        this.pannelloTitoloRicerca.add(this.cerca);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        this.pannelloMarca.add(this.labelMarca);
        this.pannelloMarca.add(this.fieldMarca);
        this.pannelloTipologia.add(this.labelTipologia);
        this.pannelloTipologia.add(this.fieldTipologia);
        this.pannelloDimensioneGB.add(this.labelDimensioneGB);
        this.pannelloDimensioneGB.add(this.fieldDimensioneGB);
        this.pannelloPrezzo.add(this.labelPrezzo);
        this.pannelloPrezzo.add(this.fieldPrezzo);
        this.submit.setEnabled(false);
        this.contenitore.setLayout(new GridLayout(5,1));
        this.contenitore.add(this.pannelloTitolo);
        this.contenitore.add(this.pannelloTipologia);
        this.contenitore.add(this.pannelloMarca);
        this.contenitore.add(this.pannelloDimensioneGB);
        this.contenitore.add(this.pannelloPrezzo);
        contentPanel.add(this.pannelloTitoloRicerca, BorderLayout.NORTH);
        contentPanel.add(this.contenitore, BorderLayout.CENTER);
        contentPanel.add(this.submit, BorderLayout.SOUTH);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameModificaCompactDisc finestra = new FrameModificaCompactDisc();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.cerca.addActionListener(new CercaCompactDiscListener(finestra));
        finestra.submit.addActionListener(new SubmitModificaCompactDisc(finestra, finestraBiblioteca));
        finestra.setTitle("Modifica libro");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
