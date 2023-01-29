package view;

import controller.PostiController;
import model.Posto;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.util.Arrays;

public class FramePrenotazione extends JFrame {
    private final JLabel labelNominativo = new JLabel("Nominativo: ");
    private final JTextField fieldNominativo = new JTextField();
    private final JPanel pannelloNominativo = new JPanel();
    private final JButton submit = new JButton("Invio");

    private FramePrenotazione(){
        Container contentPanel = this.getContentPane();
        this.fieldNominativo.setPreferredSize(new Dimension(200,20));
        this.pannelloNominativo.add(this.labelNominativo);
        this.pannelloNominativo.add(this.fieldNominativo);
        this.submit.setEnabled(false);
        contentPanel.add(this.pannelloNominativo, BorderLayout.CENTER);
        contentPanel.add(this.submit, BorderLayout.SOUTH);
    }

    public static void initGUI(FramePosti finestraPosti, Posto posto){
        FramePrenotazione finestra = new FramePrenotazione();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.fieldNominativo.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                finestra.submit.setEnabled(!finestra.fieldNominativo.getText().equals(""));
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                finestra.submit.setEnabled(!finestra.fieldNominativo.getText().equals(""));
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                finestra.submit.setEnabled(!finestra.fieldNominativo.getText().equals(""));
            }
        });
        finestra.submit.addActionListener(
                event -> {
                    String dialogMessage;
                    if(PostiController.MAPPA_PRENOTAZIONI.containsKey(posto))
                        dialogMessage = "Posto già prenotato";
                    else {
                        PostiController.MAPPA_PRENOTAZIONI.put(posto, finestra.fieldNominativo.getText());
                        Arrays
                                .stream(finestraPosti.pannelloBottoni.getComponents())
                                .filter(componente -> componente.getName().equals(posto.toString()))
                                .forEach(component -> component.setEnabled(false));
                        dialogMessage = "Posto prenotato con successo!";
                    }
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.setTitle("Prenotazione posto aereo");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
