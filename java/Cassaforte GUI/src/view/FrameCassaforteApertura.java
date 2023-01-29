package view;

import controller.CassaforteController;
import model.CassaforteException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FrameCassaforteApertura extends JFrame {
    private final JPasswordField password = new JPasswordField();
    private final JLabel labelPassword = new JLabel("Password: ");
    private final JPanel panelPassword = new JPanel(new BorderLayout());
    private final JButton bottoneInvio = new JButton("Invio");

    private FrameCassaforteApertura(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(2,1));
        this.bottoneInvio.setPreferredSize(new Dimension(300,30));
        this.panelPassword.add(this.labelPassword, BorderLayout.WEST);
        this.panelPassword.add(this.password, BorderLayout.CENTER);
        contentPanel.add(this.panelPassword);
        contentPanel.add(this.bottoneInvio);
    }

    public static void initGUI(){
        FrameCassaforteApertura finestra = new FrameCassaforteApertura();
        finestra.bottoneInvio.addActionListener(
                event -> {
                    String testoFinestraDialogo;
                    try {
                        testoFinestraDialogo = CassaforteController.
                                CASSAFORTE.
                                stampaMessaggio(new String(finestra.password.getPassword()));
                    }
                    catch (CassaforteException ex) {
                        testoFinestraDialogo = "Hai sbagliato troppe volte. La cassaforte è bloccata\n" +
                                "Si consiglia di reimpostare la password per azzerare i tentativi.";
                    }
                    JOptionPane.showMessageDialog(null,testoFinestraDialogo);
                }
        );
        finestra.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                FrameCassaforte.initGUI();
            }
        });
        finestra.setTitle("Apertura cassaforte");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
