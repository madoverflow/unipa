package view;

import controller.BibliotecaController;
import controller.Nominabile;
import model.Autore;

import javax.swing.*;
import java.awt.*;

public class FrameAutore extends JFrame {
    private final JLabel labelNome = new JLabel("Nome: ");
    private final JTextField fieldNome = new JTextField();
    private final JPanel pannelloNome = new JPanel();
    private final JLabel labelCognome = new JLabel("Cognome: ");
    private final JTextField fieldCognome = new JTextField();
    private final JPanel pannelloCognome = new JPanel();
    private final JButton submit = new JButton("Invio");

    private FrameAutore(){
        Container contentPanel = this.getContentPane();
        this.fieldNome.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.fieldCognome.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloNome.add(this.labelNome);
        this.pannelloNome.add(this.fieldNome);
        this.pannelloCognome.add(this.labelCognome);
        this.pannelloCognome.add(this.fieldCognome);
        contentPanel.add(this.pannelloNome, BorderLayout.NORTH);
        contentPanel.add(this.pannelloCognome, BorderLayout.CENTER);
        contentPanel.add(this.submit, BorderLayout.SOUTH);
    }

    public static void initGUI(Nominabile oggettoConAutori){
        FrameAutore finestra = new FrameAutore();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.submit.addActionListener(
                event -> {
                    oggettoConAutori.addAuthor(new Autore(finestra.fieldNome.getText(), finestra.fieldCognome.getText()));
                    JOptionPane.showMessageDialog(null, "Autore inserito.");
                });
        finestra.setTitle("Inserimento Autore");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }

}
