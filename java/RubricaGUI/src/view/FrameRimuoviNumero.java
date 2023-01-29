package view;

import controller.RubricaController;

import javax.swing.*;
import java.awt.*;

public class FrameRimuoviNumero extends JFrame {
    public final JLabel labelNumero = new JLabel("Numero di telefono: ");
    public final JTextField numero = new JTextField();
    public final JButton submit = new JButton("Invio");
    public final JPanel pannelloNumero = new JPanel();

    private FrameRimuoviNumero(){
        Container contentPanel = this.getContentPane();
        this.numero.setPreferredSize(new Dimension(200,20));
        this.pannelloNumero.add(this.labelNumero);
        this.pannelloNumero.add(this.numero);
        contentPanel.add(this.pannelloNumero, BorderLayout.CENTER);
        contentPanel.add(this.submit, BorderLayout.SOUTH);
    }

    public static void initGUI(FrameRubrica frameRubrica){
        FrameRimuoviNumero finestra = new FrameRimuoviNumero();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.submit.addActionListener(
                event -> {
                    String dialogMessage;
                    if(finestra.numero.getText().equals(""))
                        dialogMessage = "Il campo del numero non può essere vuoto!";
                    else {
                        RubricaController.RUBRICA.rimuoviNumero(finestra.numero.getText());
                        frameRubrica.setPannello();
                        dialogMessage = "Se il numero è presente, è stato cancellato correttamente";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.pack();
        finestra.setTitle("Rimozione numero di telefono");
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
