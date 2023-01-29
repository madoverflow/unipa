package view;

import model.Persona;

import javax.swing.*;
import java.awt.*;

public class FramePersona extends JFrame {
    private static final Dimension DIMENSIONE_FIELD = new Dimension(200,20);
    private final JLabel labelNome = new JLabel("Nome: ");
    private final JTextField fieldNome = new JTextField();
    private final JPanel pannelloNome = new JPanel();
    private final JLabel labelCognome = new JLabel("Cognome: ");
    private final JTextField fieldCognome = new JTextField();
    private final JPanel pannelloCognome = new JPanel();
    private final JLabel labelEta = new JLabel("Età: ");
    private final JTextField fieldEta = new JTextField();
    private final JPanel pannelloEta = new JPanel();
    private final JRadioButton uomo = new JRadioButton("Uomo", true);
    private final JRadioButton donna = new JRadioButton("Donna");

    private final ButtonGroup sceltaSesso = new ButtonGroup();
    private final JLabel labelSesso = new JLabel("Sesso: ");
    private final JPanel pannelloSesso = new JPanel();
    private final JButton submit = new JButton("Invio");

    private FramePersona(){
        Container contentPanel = this.getContentPane();
        contentPanel.setLayout(new GridLayout(5,1));
        this.fieldNome.setPreferredSize(FramePersona.DIMENSIONE_FIELD);
        this.fieldCognome.setPreferredSize(FramePersona.DIMENSIONE_FIELD);
        this.fieldEta.setPreferredSize(FramePersona.DIMENSIONE_FIELD);
        this.pannelloNome.add(this.labelNome);
        this.pannelloNome.add(this.fieldNome);
        this.pannelloCognome.add(this.labelCognome);
        this.pannelloCognome.add(this.fieldCognome);
        this.pannelloEta.add(this.labelEta);
        this.pannelloEta.add(this.fieldEta);
        this.uomo.setActionCommand("Uomo");
        this.donna.setActionCommand("Donna");
        this.sceltaSesso.add(this.uomo);
        this.sceltaSesso.add(this.donna);
        this.pannelloSesso.add(this.labelSesso);
        this.pannelloSesso.add(this.uomo);
        this.pannelloSesso.add(this.donna);
        contentPanel.add(this.pannelloNome);
        contentPanel.add(this.pannelloCognome);
        contentPanel.add(this.pannelloEta);
        contentPanel.add(this.pannelloSesso);
        contentPanel.add(this.submit);
    }

    public static void initGUI(){
        FramePersona finestra = new FramePersona();
        finestra.submit.addActionListener(
                event -> {
                    Object dialogMessage;
                    String nome, cognome;
                    Persona.Genere sesso;
                    int eta;
                    nome = finestra.fieldNome.getText();
                    cognome = finestra.fieldCognome.getText();
                    try{
                        eta = Integer.parseInt(finestra.fieldEta.getText());
                        if(finestra.sceltaSesso.getSelection().getActionCommand().equals("Uomo"))
                            sesso = Persona.Genere.UOMO;
                        else
                            sesso = Persona.Genere.DONNA;
                        dialogMessage = new Persona(nome,cognome,eta,sesso);
                    }
                    catch(NumberFormatException ex){
                        dialogMessage = "Formato età non valido.";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.setTitle("Creazione utente");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }

}
