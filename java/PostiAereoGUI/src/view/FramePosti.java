package view;

import controller.PostiController;
import model.Posto;

import javax.swing.*;
import java.awt.*;
import java.util.stream.IntStream;

public class FramePosti extends JFrame {
    private static final Dimension DIMENSIONE = new Dimension(80,80);
    public final JPanel pannelloBottoni = new JPanel();
    private final JMenu menuFile = new JMenu("File");
    private final JMenuItem visualizzaPrenotazioni = new JMenuItem("Visualizza prenotazione");
    private final JMenuItem rimuoviPrenotazione = new JMenuItem("Cancella prenotazione");
    private final JMenuBar menuBar = new JMenuBar();

    public FramePosti(){
        Container contentPanel = this.getContentPane();
        this.pannelloBottoni.setLayout(new GridLayout(8,3));
        IntStream.range(0,24).forEach(i -> {
            JButton bottone = new JButton();
            Posto posto = new Posto(i/3 + 1, Posto.LETTERE_PREDEFINITE[i%3]);
            bottone.setPreferredSize(FramePosti.DIMENSIONE);
            bottone.setName(posto.toString());
            bottone.setText(posto.toString());
            bottone.addActionListener(event -> FramePrenotazione.initGUI(this, posto));
            this.pannelloBottoni.add(bottone);
        });
        this.menuFile.add(this.visualizzaPrenotazioni);
        this.menuFile.add(this.rimuoviPrenotazione);
        this.menuBar.add(this.menuFile);
        this.setJMenuBar(this.menuBar);
        contentPanel.add(this.pannelloBottoni);
    }

    public static void initGUI(){
        FramePosti finestra = new FramePosti();
        finestra.visualizzaPrenotazioni.addActionListener(event -> FrameVisualizzaPrenotazioni.initGUI());
        finestra.rimuoviPrenotazione.addActionListener(event -> FrameRimozionePrenotazione.initGUI(finestra));
        finestra.setTitle("Gestione posti aereo");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
