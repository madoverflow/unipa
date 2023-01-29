package view;

import controller.CalcoloPunteggioListener;
import model.Domanda;

import javax.swing.*;
import java.awt.*;
import java.util.random.RandomGenerator;

public class FrameQuiz extends JFrame {
    private static final Dimension DIMENSIONE_LABEL_DOMANDE = new Dimension(200,20);
    public final ButtonGroup gruppoOpzioniDomanda1 = new ButtonGroup();
    public final ButtonGroup gruppoOpzioniDomanda2 = new ButtonGroup();
    public final ButtonGroup gruppoOpzioniDomanda3 = new ButtonGroup();
    public final JLabel testoDomanda1 = new JLabel();
    public final JLabel testoDomanda2 = new JLabel();
    public final JLabel testoDomanda3 = new JLabel();
    private final JPanel pannelloDomanda1 = new JPanel(new BorderLayout());
    private final JPanel pannelloDomanda2 = new JPanel(new BorderLayout());
    private final JPanel pannelloDomanda3 = new JPanel(new BorderLayout());
    private final JPanel pannelloOpzioni1 = new JPanel();
    private final JPanel pannelloOpzioni2 = new JPanel();
    private final JPanel pannelloOpzioni3 = new JPanel();

    private final JPanel pannelloDomande = new JPanel();
    private final JLabel labelPunteggio = new JLabel("Punteggio totale: ");
    public final JLabel punteggioCalcolato = new JLabel();
    public final JButton calcolaPunteggio = new JButton("Calcola punteggio");
    private final JPanel pannelloPunteggio = new JPanel();

    private FrameQuiz(){
        Container contentPanel = this.getContentPane();
        this.pannelloDomande.setLayout(new GridLayout(3,1));
        this.caricaDomande();
        this.pannelloPunteggio.add(this.calcolaPunteggio);
        this.pannelloPunteggio.add(this.labelPunteggio);
        this.pannelloPunteggio.add(this.punteggioCalcolato);
        contentPanel.add(this.pannelloDomande, BorderLayout.CENTER);
        contentPanel.add(this.pannelloPunteggio, BorderLayout.SOUTH);
    }

    public static void initGUI(){
        FrameQuiz finestra = new FrameQuiz();
        finestra.getRootPane().setDefaultButton(finestra.calcolaPunteggio);
        finestra.calcolaPunteggio.addActionListener(new CalcoloPunteggioListener(finestra));
        finestra.setTitle("Quiz");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }

    private void caricaDomande(){
        int numeriDomande[] = RandomGenerator.getDefault()
                .ints(20,0,Domanda.DOMANDE_PREDEFINITE.size()-1)
                .distinct()
                .limit(3)
                .toArray();
        Domanda domanda1 = Domanda.DOMANDE_PREDEFINITE.get(numeriDomande[0]);
        Domanda domanda2 = Domanda.DOMANDE_PREDEFINITE.get(numeriDomande[1]);
        Domanda domanda3 = Domanda.DOMANDE_PREDEFINITE.get(numeriDomande[2]);
        this.testoDomanda1.setName(String.valueOf(numeriDomande[0]));
        this.testoDomanda1.setText(domanda1.getTestoDomanda());
        this.caricaOpzioni(domanda1, this.gruppoOpzioniDomanda1, this.pannelloOpzioni1);
        this.testoDomanda2.setName(String.valueOf(numeriDomande[1]));
        this.testoDomanda2.setText(domanda2.getTestoDomanda());
        this.caricaOpzioni(domanda2, this.gruppoOpzioniDomanda2, this.pannelloOpzioni2);
        this.testoDomanda3.setName(String.valueOf(numeriDomande[2]));
        this.testoDomanda3.setText(domanda3.getTestoDomanda());
        this.caricaOpzioni(domanda3, this.gruppoOpzioniDomanda3, this.pannelloOpzioni3);
        this.pannelloDomanda1.add(this.testoDomanda1, BorderLayout.WEST);
        this.pannelloDomanda1.add(this.pannelloOpzioni1, BorderLayout.CENTER);
        this.pannelloDomanda2.add(this.testoDomanda2, BorderLayout.WEST);
        this.pannelloDomanda2.add(this.pannelloOpzioni2, BorderLayout.CENTER);
        this.pannelloDomanda3.add(this.testoDomanda3, BorderLayout.WEST);
        this.pannelloDomanda3.add(this.pannelloOpzioni3, BorderLayout.CENTER);
        this.pannelloDomande.add(this.pannelloDomanda1);
        this.pannelloDomande.add(this.pannelloDomanda2);
        this.pannelloDomande.add(this.pannelloDomanda3);
    }

    private void caricaOpzioni(Domanda domanda, ButtonGroup gruppoOpzioni, JPanel pannelloOpzioni){
        JRadioButton bottoneOpzione1 = new JRadioButton("Risposta: " + domanda.getOpzioni()[0]);
        JRadioButton bottoneOpzione2 = new JRadioButton("Risposta: " + domanda.getOpzioni()[1]);
        JRadioButton bottoneOpzione3 = new JRadioButton("Risposta: " + domanda.getOpzioni()[2]);
        bottoneOpzione1.setActionCommand(domanda.getOpzioni()[0]);
        bottoneOpzione2.setActionCommand(domanda.getOpzioni()[1]);
        bottoneOpzione3.setActionCommand(domanda.getOpzioni()[2]);
        gruppoOpzioni.add(bottoneOpzione1);
        gruppoOpzioni.add(bottoneOpzione2);
        gruppoOpzioni.add(bottoneOpzione3);
        pannelloOpzioni.add(bottoneOpzione1);
        pannelloOpzioni.add(bottoneOpzione2);
        pannelloOpzioni.add(bottoneOpzione3);
    }
}
