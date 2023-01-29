package view;

import controller.BibliotecaController;
import controller.Nominabile;
import model.Autore;
import model.Dizionario;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class FrameDizionario extends JFrame implements Nominabile {
    private final JLabel labelTitolo = new JLabel("Titolo: ");
    private final JTextField fieldTitolo = new JTextField();
    private final JPanel pannelloTitolo = new JPanel();
    private final JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
    private final JTextField fieldCasaEditrice = new JTextField();
    private final JPanel pannelloCasaEditrice = new JPanel();
    private final JLabel labelPrezzo = new JLabel("Prezzo: ");
    private final JTextField fieldPrezzo = new JTextField();
    private final JPanel pannelloPrezzo = new JPanel();
    private final JLabel labelLinguaMadre = new JLabel("Lingua madre: ");
    private final JTextField fieldLinguaMadre = new JTextField();
    private final JPanel pannelloLinguaMadre = new JPanel();
    private final JLabel labelLinguaTraduzione = new JLabel("Lingua traduzione: ");
    private final JTextField fieldLinguaTraduzione = new JTextField();
    private final JPanel pannelloLinguaTraduzione = new JPanel();
    private final JButton aggiungiAutore = new JButton("Inserisci autore");
    private final JButton submit = new JButton("Invio");
    private final List<Autore> listaAutori = new ArrayList<>();

    private FrameDizionario(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(7,1));
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCasaEditrice.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldPrezzo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldLinguaMadre.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldLinguaTraduzione.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        this.pannelloCasaEditrice.add(this.labelCasaEditrice);
        this.pannelloCasaEditrice.add(this.fieldCasaEditrice);
        this.pannelloPrezzo.add(this.labelPrezzo);
        this.pannelloPrezzo.add(this.fieldPrezzo);
        this.pannelloLinguaMadre.add(this.labelLinguaMadre);
        this.pannelloLinguaMadre.add(this.fieldLinguaMadre);
        this.pannelloLinguaTraduzione.add(this.labelLinguaTraduzione);
        this.pannelloLinguaTraduzione.add(this.fieldLinguaTraduzione);
        contentPanel.add(this.pannelloTitolo);
        contentPanel.add(this.pannelloLinguaMadre);
        contentPanel.add(this.pannelloLinguaTraduzione);
        contentPanel.add(this.pannelloCasaEditrice);
        contentPanel.add(this.pannelloPrezzo);
        contentPanel.add(this.aggiungiAutore);
        contentPanel.add(this.submit);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameDizionario finestra = new FrameDizionario();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.aggiungiAutore.addActionListener(event -> FrameAutore.initGUI(finestra));
        finestra.submit.addActionListener(
                event -> {
                    double prezzo;
                    String dialogMessage;
                    try{
                        prezzo = Double.parseDouble(finestra.fieldPrezzo.getText());
                        Dizionario dizionario = new Dizionario(
                                finestra.fieldTitolo.getText(),
                                finestra.fieldLinguaMadre.getText(),
                                finestra.fieldLinguaTraduzione.getText(),
                                finestra.fieldCasaEditrice.getText(),
                                finestra.listaAutori,
                                prezzo);
                        BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(dizionario);
                        finestraBiblioteca.setPannelloDocumenti();
                        dialogMessage = "Dizionario inserito.";
                    }
                    catch(NumberFormatException ex){
                        dialogMessage = "Formato prezzo non valido";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.setTitle("Inserimento dizionario");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
    @Override
    public void addAuthor(Autore autore){
        if(!this.listaAutori.contains(autore))
            this.listaAutori.add(autore);
    }
}
