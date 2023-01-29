package view;

import controller.PostiController;

import javax.swing.*;
import java.awt.*;

public class FrameVisualizzaPrenotazioni extends JFrame {
    private final JPanel pannelloPrenotazioni = new JPanel();

    private FrameVisualizzaPrenotazioni(){
        Container contentPanel = this.getContentPane();
        this.pannelloPrenotazioni.setLayout(new GridLayout(PostiController.MAPPA_PRENOTAZIONI.size(),2));
        PostiController.MAPPA_PRENOTAZIONI.forEach((key, value) -> {
            JLabel nominativo = new JLabel(value);
            JLabel posto = new JLabel(key.toString());
            this.pannelloPrenotazioni.add(nominativo);
            this.pannelloPrenotazioni.add(posto);
        });
        contentPanel.add(this.pannelloPrenotazioni);
    }

    public static void initGUI(){
        FrameVisualizzaPrenotazioni finestra = new FrameVisualizzaPrenotazioni();
        finestra.setTitle("Lista prenotazioni posti aereo");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
