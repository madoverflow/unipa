package view;

import controller.RubricaController;

import javax.swing.*;
import java.awt.*;

public class FrameAggiungiNumero extends JFrame {
    public final JLabel labelNumero = new JLabel("Numero di telefono: ");
    public final JLabel labelNome = new JLabel("Nome: ");
    public final JTextField numero = new JTextField();
    public final JTextField nome = new JTextField();
    public final JButton submit = new JButton("Invio");
    public final JPanel pannelloNumero = new JPanel();
    public final JPanel pannelloNome = new JPanel();

    private FrameAggiungiNumero(){
        Container contentPanel = this.getContentPane();
        this.numero.setPreferredSize(new Dimension(200,20));
        this.pannelloNumero.add(this.labelNumero);
        this.pannelloNumero.add(this.numero);
        this.nome.setPreferredSize(new Dimension(200,20));
        this.pannelloNome.add(this.labelNome);
        this.pannelloNome.add(this.nome);
        contentPanel.add(this.pannelloNumero, BorderLayout.NORTH);
        contentPanel.add(this.pannelloNome, BorderLayout.CENTER);
        contentPanel.add(this.submit, BorderLayout.SOUTH);
    }

    public static void initGUI(FrameRubrica frameRubrica){
        FrameAggiungiNumero finestra = new FrameAggiungiNumero();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.submit.addActionListener(
                event -> {
                    String dialogMessage;
                    if(finestra.numero.getText().equals(""))
                        dialogMessage = "Il campo del numero non può essere vuoto!";
                    else {
                        RubricaController.RUBRICA.aggiungiNumero(finestra.numero.getText(), finestra.nome.getText());
                        frameRubrica.setPannello();
                        dialogMessage = "Numero aggiunto correttamente";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.pack();
        finestra.setTitle("Inserimento numero di telefono");
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
