package view;

import controller.BibliotecaController;
import model.Quotidiano;

import javax.swing.*;
import java.awt.*;

public class FrameQuotidiano extends JFrame {
    private final JLabel labelTitolo = new JLabel("Titolo: ");
    private final JTextField fieldTitolo = new JTextField();
    private final JPanel pannelloTitolo = new JPanel();
    private final JLabel labelCasaEditrice = new JLabel("Casa editrice: ");
    private final JTextField fieldCasaEditrice = new JTextField();
    private final JPanel pannelloCasaEditrice = new JPanel();
    private final JLabel labelCitta = new JLabel("Città: ");
    private final JTextField fieldCitta = new JTextField();
    private final JPanel pannelloCitta = new JPanel();
    private final JLabel labelPrezzo = new JLabel("Prezzo: ");
    private final JTextField fieldPrezzo = new JTextField();
    private final JPanel pannelloPrezzo = new JPanel();
    private final JButton submit = new JButton("Invio");

    private FrameQuotidiano(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(5,1));
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCasaEditrice.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCitta.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldPrezzo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        this.pannelloCasaEditrice.add(this.labelCasaEditrice);
        this.pannelloCasaEditrice.add(this.fieldCasaEditrice);
        this.pannelloCitta.add(this.labelCitta);
        this.pannelloCitta.add(this.fieldCitta);
        this.pannelloPrezzo.add(this.labelPrezzo);
        this.pannelloPrezzo.add(this.fieldPrezzo);
        contentPanel.add(this.pannelloTitolo);
        contentPanel.add(this.pannelloCasaEditrice);
        contentPanel.add(this.pannelloCitta);
        contentPanel.add(this.pannelloPrezzo);
        contentPanel.add(this.submit);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameQuotidiano finestra = new FrameQuotidiano();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.submit.addActionListener(
                event -> {
                    double prezzo;
                    String dialogMessage;
                    try{
                        prezzo = Double.parseDouble(finestra.fieldPrezzo.getText());
                        Quotidiano quotidiano = new Quotidiano(
                                finestra.fieldTitolo.getText(),
                                prezzo,
                                finestra.fieldCasaEditrice.getText(),
                                finestra.fieldCitta.getText()
                        );
                        BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(quotidiano);
                        finestraBiblioteca.setPannelloDocumenti();
                        dialogMessage = "Quotidiano inserito.";
                    }
                    catch(NumberFormatException ex){
                        dialogMessage = "Formato prezzo non valido";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.setTitle("Inserimento quotidiano");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
