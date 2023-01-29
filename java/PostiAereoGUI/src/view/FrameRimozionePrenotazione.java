package view;

import controller.PostiController;
import model.Posto;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.util.Arrays;

public class FrameRimozionePrenotazione extends JFrame {
    private final JLabel labelPosto = new JLabel("Posto: ");
    private final JTextField fieldPosto = new JTextField("(es: 1A)");
    private final JPanel pannelloPosto = new JPanel();
    private final JButton submit = new JButton("Invio");

    private FrameRimozionePrenotazione(){
        Container contentPanel = this.getContentPane();
        this.fieldPosto.setPreferredSize(new Dimension(200,20));
        this.pannelloPosto.add(this.labelPosto);
        this.pannelloPosto.add(this.fieldPosto);
        this.submit.setEnabled(false);
        contentPanel.add(this.pannelloPosto, BorderLayout.CENTER);
        contentPanel.add(this.submit, BorderLayout.SOUTH);
    }

    public static void initGUI(FramePosti finestraPosti){
        FrameRimozionePrenotazione finestra = new FrameRimozionePrenotazione();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.fieldPosto.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                finestra.submit.setEnabled(!finestra.fieldPosto.getText().equals(""));
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                finestra.submit.setEnabled(!finestra.fieldPosto.getText().equals(""));
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                finestra.submit.setEnabled(!finestra.fieldPosto.getText().equals(""));
            }
        });
        finestra.submit.addActionListener(
                event -> {
                    String dialogMessage;
                    try{
                        int numero = Integer.parseInt(finestra.fieldPosto.getText().substring(0,1));
                        Posto posto = new Posto(numero, finestra.fieldPosto.getText().substring(1));
                        if(!PostiController.MAPPA_PRENOTAZIONI.containsKey(posto))
                            throw new RuntimeException();
                        PostiController.MAPPA_PRENOTAZIONI.remove(posto);
                        Arrays.stream(finestraPosti.pannelloBottoni.getComponents())
                                .filter(component -> component.getName().equals(posto.toString()))
                                .forEach(component -> component.setEnabled(true));
                        dialogMessage = "Cancellazione prenotazione avvenuta con successo";
                    }
                    catch (NumberFormatException | IndexOutOfBoundsException ex){
                        dialogMessage = "Formato posto non valido";
                    }
                    catch (RuntimeException ex ){
                        dialogMessage = "Nessuna prenotazione trovata per quel posto";
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
