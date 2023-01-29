package view;

import controller.CassaforteController;

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class FrameCassafortePassword extends JFrame {
    private final JPasswordField vecchiaPassword = new JPasswordField();
    private final JLabel labelVecchiaPassword = new JLabel("Vecchia password: ");
    private final JPanel panelVecchiaPassword = new JPanel();
    private final JPasswordField nuovaPassword = new JPasswordField();
    private final JLabel labelNuovaPassword = new JLabel("Nuova password: ");
    private final JLabel labelSicurezzaPassword = new JLabel("Sicurezza password");
    private final JPanel panelNuovaPassword = new JPanel();
    private final JButton bottoneInvio = new JButton("Invio");

    private FrameCassafortePassword(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(3,1));
        this.panelVecchiaPassword.setLayout(new BorderLayout());
        this.panelVecchiaPassword.add(this.labelVecchiaPassword, BorderLayout.WEST);
        this.panelVecchiaPassword.add(this.vecchiaPassword, BorderLayout.CENTER);
        this.panelNuovaPassword.setLayout(new BorderLayout());
        this.nuovaPassword.setPreferredSize(new Dimension(150,30));
        this.panelNuovaPassword.add(this.labelNuovaPassword,BorderLayout.WEST);
        this.panelNuovaPassword.add(this.nuovaPassword, BorderLayout.CENTER);
        this.panelNuovaPassword.add(this.labelSicurezzaPassword,BorderLayout.EAST);
        this.bottoneInvio.setEnabled(false);
        contentPanel.add(this.panelVecchiaPassword);
        contentPanel.add(this.panelNuovaPassword);
        contentPanel.add(this.bottoneInvio);
    }

    public static void initGUI(){
        FrameCassafortePassword finestra = new FrameCassafortePassword();
        finestra.
                nuovaPassword.
                getDocument().
                addDocumentListener(new DocumentListener() {
                    @Override
                    public void insertUpdate(DocumentEvent e) {
                        CassaforteController.testSicurezzaPassword(
                                finestra.nuovaPassword, finestra.labelSicurezzaPassword, finestra.bottoneInvio,
                                x -> String.valueOf(x.getPassword()).length()>=6,
                                y -> String.valueOf(y.getPassword()).matches("((.*)\\d(.*))"),
                                (z,k) -> {
                                    z.setText("Poco sicura");
                                    z.setForeground(Color.ORANGE);
                                    k.setEnabled(false);
                                },
                                (t,s) -> {
                                    t.setText("Sicura");
                                    t.setForeground(Color.GREEN);
                                    s.setEnabled(true);
                                },
                                (l,m) -> {
                                    l.setText("Non sicura");
                                    l.setForeground(Color.RED);
                                    m.setEnabled(false);
                                }
                        );
                    }

                    @Override
                    public void removeUpdate(DocumentEvent e) {
                        CassaforteController.testSicurezzaPassword(
                                finestra.nuovaPassword, finestra.labelSicurezzaPassword, finestra.bottoneInvio,
                                x -> String.valueOf(x.getPassword()).length()>=6,
                                y -> String.valueOf(y.getPassword()).matches("((.*)\\d(.*))"),
                                (z,k) -> {
                                    z.setText("Poco sicura");
                                    z.setForeground(Color.ORANGE);
                                    k.setEnabled(false);
                                },
                                (t,s) -> {
                                    t.setText("Sicura");
                                    t.setForeground(Color.GREEN);
                                    s.setEnabled(true);
                                },
                                (l,m) -> {
                                    l.setText("Non sicura");
                                    l.setForeground(Color.RED);
                                    m.setEnabled(false);
                                }
                        );
                    }
                    @Override
                    public void changedUpdate(DocumentEvent e) {}
                });
        finestra.bottoneInvio.addActionListener(
                event -> {
                    String dialogMessage;
                    if(CassaforteController.CASSAFORTE.isEqualsToPassword(
                            new String(finestra.vecchiaPassword.getPassword()))) {
                        CassaforteController.
                                CASSAFORTE.
                                setPassword(String.valueOf(finestra.nuovaPassword.getPassword()));
                        dialogMessage = "Password reimpostata correttamente";
                    }
                    else
                        dialogMessage = "Le password non coincidono";
                    JOptionPane.showMessageDialog(null,dialogMessage);
                }
        );
        finestra.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                FrameCassaforte.initGUI();
            }
        });
        finestra.setTitle("Reset password");
        finestra.pack();
        finestra.setLocationRelativeTo(null);
        finestra.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        finestra.setVisible(true);
    }
}
