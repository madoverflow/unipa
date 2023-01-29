package view;

import controller.BibliotecaController;
import model.CompactDisc;
import javax.swing.*;
import java.awt.*;

public class FrameCompactDisc extends JFrame {
    private final JLabel labelTitolo = new JLabel("Titolo: ");
    private final JTextField fieldTitolo = new JTextField();
    private final JPanel pannelloTitolo = new JPanel();
    private final JLabel labelMarca = new JLabel("Marca: ");
    private final JTextField fieldMarca = new JTextField();
    private final JPanel pannelloMarca = new JPanel();
    private final JLabel labelTipologia = new JLabel("Tipologia: ");
    private final JTextField fieldTipologia = new JTextField();
    private final JPanel pannelloTipologia = new JPanel();
    private final JLabel labelPrezzo = new JLabel("Prezzo: ");
    private final JTextField fieldPrezzo = new JTextField();
    private final JPanel pannelloPrezzo = new JPanel();
    private final JLabel labelDimensioneGB = new JLabel("Dimensione GB: ");
    private final JTextField fieldDimensioneGB = new JTextField();
    private final JPanel pannelloDimensioneGB = new JPanel();
    private final JButton submit = new JButton("Invio");

    private FrameCompactDisc(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(6,1));
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldMarca.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldTipologia.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldDimensioneGB.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldPrezzo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        this.pannelloMarca.add(this.labelMarca);
        this.pannelloMarca.add(this.fieldMarca);
        this.pannelloTipologia.add(this.labelTipologia);
        this.pannelloTipologia.add(this.fieldTipologia);
        this.pannelloPrezzo.add(this.labelPrezzo);
        this.pannelloPrezzo.add(this.fieldPrezzo);
        this.pannelloDimensioneGB.add(this.labelDimensioneGB);
        this.pannelloDimensioneGB.add(this.fieldDimensioneGB);
        contentPanel.add(this.pannelloTitolo);
        contentPanel.add(this.pannelloMarca);
        contentPanel.add(this.pannelloTipologia);
        contentPanel.add(this.pannelloDimensioneGB);
        contentPanel.add(this.pannelloPrezzo);
        contentPanel.add(this.submit);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameCompactDisc finestra = new FrameCompactDisc();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.submit.addActionListener(
                event -> {
                    double prezzo;
                    int dimensioneGB;
                    String dialogMessage;
                    try{
                        prezzo = Double.parseDouble(finestra.fieldPrezzo.getText());
                        dimensioneGB = Integer.parseInt(finestra.fieldDimensioneGB.getText());
                        CompactDisc compactDisc = new CompactDisc(
                                finestra.fieldTitolo.getText(),
                                prezzo,
                                dimensioneGB,
                                finestra.fieldTipologia.getText(),
                                finestra.fieldMarca.getText());
                        BibliotecaController.CATALOGO_BIBLIOTECA.inserisciDocumento(compactDisc);
                        finestraBiblioteca.setPannelloDocumenti();
                        dialogMessage = "Compact Disc inserito.";
                    }
                    catch(NumberFormatException ex){
                        dialogMessage = "Formato prezzo non valido";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.setTitle("Inserimento Compact Disc");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
