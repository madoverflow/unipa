package view;

import controller.CheckBoxListener;

import javax.swing.*;
import javax.swing.text.JTextComponent;
import java.awt.*;

public class FrameFindReplace extends JFrame {
    private static final Dimension DIMENSIONE_STRINGHE = new Dimension(200,20);
    public final JTextField fieldStringaCercata = new JTextField();
    public final JLabel labelStringaCercata = new JLabel("Parola da cercare: ");
    public final JPanel panelStringaCercata = new JPanel();
    public final JTextField fieldStringaSostituzione = new JTextField();
    public final JLabel labelStringaSostituzione = new JLabel("Sostituisci con: ");
    public final JPanel panelStringaSostituzione = new JPanel();
    public final JPanel panelInput = new JPanel();
    public final JCheckBox checkSostituisci = new JCheckBox();
    public final JLabel labelCheckSostituisci = new JLabel("Sostituisci");
    public final JCheckBox checkSostituisciTutto = new JCheckBox();
    public final JLabel labelCheckSostituisciTutto = new JLabel("Sostituisci tutte le occorrenze");
    public final JPanel panelCheckBox = new JPanel();
    public final JButton submit = new JButton("Invio");
    public final JPanel panelSubmit = new JPanel();

    private FrameFindReplace(){
        Container contentPanel = this.getContentPane();
        this.fieldStringaCercata.setPreferredSize(FrameFindReplace.DIMENSIONE_STRINGHE);
        this.panelStringaCercata.add(this.labelStringaCercata);
        this.panelStringaCercata.add(this.fieldStringaCercata);
        this.fieldStringaSostituzione.setPreferredSize(FrameFindReplace.DIMENSIONE_STRINGHE);
        this.panelStringaSostituzione.add(this.labelStringaSostituzione);
        this.panelStringaSostituzione.add(this.fieldStringaSostituzione);
        this.panelInput.setLayout(new GridLayout(2,1));
        this.panelInput.add(this.panelStringaCercata);
        this.panelInput.add(this.panelStringaSostituzione);
        this.panelCheckBox.setLayout(new GridLayout(2,2));
        this.panelCheckBox.add(this.checkSostituisci);
        this.panelCheckBox.add(this.labelCheckSostituisci);
        this.panelCheckBox.add(this.checkSostituisciTutto);
        this.panelCheckBox.add(this.labelCheckSostituisciTutto);
        this.submit.setPreferredSize(FrameFindReplace.DIMENSIONE_STRINGHE);
        this.panelSubmit.add(this.submit);
        contentPanel.add(this.panelInput, BorderLayout.NORTH);
        contentPanel.add(this.panelCheckBox, BorderLayout.CENTER);
        contentPanel.add(this.panelSubmit, BorderLayout.SOUTH);
    }

    public static void initGUI(JTextComponent textComponent){
        FrameFindReplace finestra = new FrameFindReplace();
        finestra.checkSostituisci.addChangeListener(new CheckBoxListener(
                finestra.checkSostituisci,finestra.checkSostituisciTutto));
        finestra.checkSostituisciTutto.addChangeListener(new CheckBoxListener(
                finestra.checkSostituisciTutto,finestra.checkSostituisci));
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.submit.addActionListener(
                event ->{
                    int lunghezza;
                    int start, begin = 0;
                    int count = 0;
                    String dialogMessage = "Parola trovata";
                    String stringaCercata = finestra.fieldStringaCercata.getText();
                    String stringaSostituzione = finestra.fieldStringaSostituzione.getText();
                    StringBuilder testo = new StringBuilder(textComponent.getText());
                    if(testo.indexOf(stringaCercata) == -1){
                        JOptionPane.showMessageDialog(null,"La parola non è stata trovata");
                        return;
                    }
                    lunghezza = stringaCercata.length();
                    if(finestra.checkSostituisci.isSelected()) {
                        testo.replace(
                                testo.indexOf(stringaCercata),
                                testo.indexOf(stringaCercata) + lunghezza,
                                stringaSostituzione);
                        dialogMessage = "Parola sostituita";
                    }
                    if(finestra.checkSostituisciTutto.isSelected()){
                        while( (start = testo.indexOf(stringaCercata, begin) ) != -1){
                            testo.replace(
                                    start,
                                    start + lunghezza,
                                    stringaSostituzione);
                            begin = start + stringaSostituzione.length();
                            count++;
                        }
                        dialogMessage = "Parola sostituita. Numero occorrenze: " + count;
                    }
                    textComponent.setText(String.valueOf(testo));
                    JOptionPane.showMessageDialog(null,dialogMessage);
                }
        );
        finestra.pack();
        finestra.setTitle("Cerca e sostituisci");
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
