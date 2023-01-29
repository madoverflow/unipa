package view;

import controller.CassaforteController;

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class FrameCassaforteCreazione extends JFrame {
    private final JTextArea areaMessaggio = new JTextArea("Inserisci qui il tuo messaggio",1,20);
    private final JPasswordField password = new JPasswordField();
    private final JButton bottoneInvio = new JButton("Invio");
    private final JScrollPane areaPanel = new JScrollPane();
    private final JPanel messagePanel = new JPanel();
    private final JPanel passwordPanel = new JPanel();
    private final JLabel labelMessaggio = new JLabel("Messaggio: ",JLabel.CENTER);
    private final JLabel labelSicurezzaPassword = new JLabel("Sicurezza messaggio", JLabel.CENTER);
    private final JLabel labelPassword = new JLabel("Password: ", JLabel.CENTER);

    private FrameCassaforteCreazione(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(3,1));
        this.areaPanel.setViewportView(areaMessaggio);
        this.messagePanel.setLayout(new BorderLayout());
        this.passwordPanel.setLayout(new BorderLayout());
        this.labelSicurezzaPassword.setForeground(Color.GRAY);
        this.bottoneInvio.setEnabled(false);
        this.messagePanel.add(this.labelMessaggio, BorderLayout.WEST);
        this.messagePanel.add(this.areaPanel, BorderLayout.CENTER);
        this.passwordPanel.add(this.labelPassword, BorderLayout.WEST);
        this.passwordPanel.add(this.password, BorderLayout.CENTER);
        this.passwordPanel.add(this.labelSicurezzaPassword, BorderLayout.EAST);
        contentPanel.add(this.messagePanel);
        contentPanel.add(this.passwordPanel);
        contentPanel.add(this.bottoneInvio);
    }

    public static void initGUI(){
        FrameCassaforteCreazione finestra = new FrameCassaforteCreazione();
        finestra.
                password.
                getDocument().
                addDocumentListener(new DocumentListener() {
                    @Override
                    public void insertUpdate(DocumentEvent e) {
                        CassaforteController.testSicurezzaPassword(
                                finestra.password, finestra.labelSicurezzaPassword, finestra.bottoneInvio,
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
                                finestra.password, finestra.labelSicurezzaPassword, finestra.bottoneInvio,
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
                    CassaforteController.CASSAFORTE.setPassword(String.valueOf(finestra.password.getPassword()));
                    CassaforteController.CASSAFORTE.resetMessaggioSegreto(
                            finestra.areaMessaggio.getText(),String.valueOf(finestra.password.getPassword()));
                    JOptionPane.showMessageDialog(null,"Cassaforte creata con successo");
                }
        );
        finestra.setTitle("Creazione cassaforte");
        finestra.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                FrameCassaforte.initGUI();
            }
        });
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
