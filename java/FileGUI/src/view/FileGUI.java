package view;

import controller.submitActionListener;

import javax.swing.*;
import java.awt.*;

public class FileGUI extends JFrame {
    public final JTextField fileTextField = new JTextField("Inserisci il percorso del file da aprire");
    public final JCheckBox fileAppendCheck = new JCheckBox();
    public final JButton submitBotton = new JButton("Invio");
    public final JPanel filePanel = new JPanel();
    public final JTextArea areaOutFile = new JTextArea(5,20);
    public final JScrollPane areaPanel = new JScrollPane();

    private FileGUI(){
        Container contentPanel = this.getContentPane();
        this.fileTextField.setPreferredSize(new Dimension(300,40));
        this.fileAppendCheck.setToolTipText("Spuntare questa casella se si vuole visuallizare il contenuto del file " +
                "in coda al contenuto degli altri file visualizzati.");
        this.submitBotton.setPreferredSize(new Dimension(80,20));
        this.filePanel.setLayout(new BorderLayout());
        this.filePanel.add(this.fileTextField, BorderLayout.WEST);
        this.filePanel.add(this.fileAppendCheck, BorderLayout.EAST);
        this.filePanel.add(this.submitBotton, BorderLayout.SOUTH);
        this.areaPanel.setViewportView(this.areaOutFile);
        this.areaPanel.setBorder(BorderFactory.createTitledBorder("Testo file aperto"));
        contentPanel.add(this.filePanel, BorderLayout.CENTER);
        contentPanel.add(this.areaPanel, BorderLayout.SOUTH);
    }

    public static void initGUI(){
        FileGUI finestra = new FileGUI();
        finestra.submitBotton.addActionListener(new submitActionListener(finestra));
        finestra.pack();
        finestra.setTitle("Apertura file di testo");
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);

    }
}
