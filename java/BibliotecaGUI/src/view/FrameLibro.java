package view;

import controller.BibliotecaController;
import controller.Nominabile;
import model.Autore;
import model.Libro;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class FrameLibro extends JFrame implements Nominabile {
    private final JLabel labelTitolo = new JLabel("Titolo: ");
    private final JTextField fieldTitolo = new JTextField();
    private final JPanel pannelloTitolo = new JPanel();
    private final JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
    private final JTextField fieldCasaEditrice = new JTextField();
    private final JPanel pannelloCasaEditrice = new JPanel();
    private final JLabel labelPrezzo = new JLabel("Prezzo: ");
    private final JTextField fieldPrezzo = new JTextField();
    private final JPanel pannelloPrezzo = new JPanel();
    private final JButton aggiungiAutore = new JButton("Inserisci autore");
    private final JButton submit = new JButton("Invio");
    private final List<Autore> listaAutori = new ArrayList<>();

    private FrameLibro(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(5,1));
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCasaEditrice.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldPrezzo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        this.pannelloCasaEditrice.add(this.labelCasaEditrice);
        this.pannelloCasaEditrice.add(this.fieldCasaEditrice);
        this.pannelloPrezzo.add(this.labelPrezzo);
        this.pannelloPrezzo.add(this.fieldPrezzo);
        contentPanel.add(this.pannelloTitolo);
        contentPanel.add(this.pannelloCasaEditrice);
        contentPanel.add(this.pannelloPrezzo);
        contentPanel.add(this.aggiungiAutore);
        contentPanel.add(this.submit);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameLibro finestra = new FrameLibro();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.aggiungiAutore.addActionListener(event -> FrameAutore.initGUI(finestra));
        finestra.submit.addActionListener(
                event -> {
                    double prezzo;
                    String dialogMessage;
                    try{
                        prezzo = Double.parseDouble(finestra.fieldPrezzo.getText());
                        Libro libro = new Libro(
                                finestra.fieldTitolo.getText(),
                                prezzo,
                                finestra.fieldCasaEditrice.getText(),
                                finestra.listaAutori);
                        BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(libro);
                        finestraBiblioteca.setPannelloDocumenti();
                        dialogMessage = "Libro inserito.";
                    }
                    catch(NumberFormatException ex){
                        dialogMessage = "Formato prezzo non valido";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.setTitle("Inserimento libro");
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
