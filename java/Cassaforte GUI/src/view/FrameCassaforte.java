package view;

import controller.CassaforteController;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;

public class FrameCassaforte extends JFrame {
    private final JButton creazione = new JButton("Creazione cassaforte");
    private final JButton apertura = new JButton("Apertura cassaforte");
    private final JButton resetPassword = new JButton("Reset password");
    private JMenuBar barraMenu = new JMenuBar();
    private JMenu fileMenu = new JMenu("File");
    private JMenuItem salvaCassaforte = new JMenuItem("Salva cassaforte");
    private static final Dimension dimensioneBottoni = new Dimension(300,40);

    private FrameCassaforte(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(3,1));
        this.creazione.setPreferredSize(FrameCassaforte.dimensioneBottoni);
        this.apertura.setPreferredSize(FrameCassaforte.dimensioneBottoni);
        this.resetPassword.setPreferredSize(FrameCassaforte.dimensioneBottoni);
        this.creazione.setToolTipText("Bottone creare una nuova cassaforte");
        this.apertura.setToolTipText("Apertura della cassaforte mediante messaggio segreto");
        this.resetPassword.setToolTipText("Reimpostare la password della cassaforte");
        this.fileMenu.add(this.salvaCassaforte);
        this.barraMenu.add(this.fileMenu);
        this.setJMenuBar(this.barraMenu);
        contentPanel.add(this.creazione);
        contentPanel.add(this.apertura);
        contentPanel.add(this.resetPassword);
    }

    public static void initGUI(){
        FrameCassaforte finestra = new FrameCassaforte();
        finestra.creazione.addActionListener(event -> {
            finestra.dispatchEvent(new WindowEvent(finestra, WindowEvent.WINDOW_CLOSING));
            FrameCassaforteCreazione.initGUI();
        });
        finestra.apertura.addActionListener(event -> {
            finestra.dispatchEvent(new WindowEvent(finestra, WindowEvent.WINDOW_CLOSING));
            FrameCassaforteApertura.initGUI();
        });
        finestra.resetPassword.addActionListener(event -> {
            finestra.dispatchEvent(new WindowEvent(finestra, WindowEvent.WINDOW_CLOSING));
            FrameCassafortePassword.initGUI();
        });
        finestra.salvaCassaforte.addActionListener(event -> CassaforteController.salvataggioCassaforte());
        finestra.setTitle("Gestione cassaforte");
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.pack();
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
