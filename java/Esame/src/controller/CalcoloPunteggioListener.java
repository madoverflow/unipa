package controller;

import model.Domanda;
import view.FrameQuiz;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalcoloPunteggioListener implements ActionListener {
    private final FrameQuiz finestra;

    public CalcoloPunteggioListener(FrameQuiz finestra){
        this.finestra = finestra;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String dialogMessage;
        int punteggioFinale = 0;
        try{
            int numeroDomanda1 = Integer.parseInt(this.finestra.testoDomanda1.getName());
            int numeroDomanda2 = Integer.parseInt(this.finestra.testoDomanda2.getName());
            int numeroDomanda3 = Integer.parseInt(this.finestra.testoDomanda3.getName());
            if(Domanda.DOMANDE_PREDEFINITE.get(numeroDomanda1).isCorrect(this.finestra.
                    gruppoOpzioniDomanda1.
                    getSelection().
                    getActionCommand()))
                ++punteggioFinale;
            if(Domanda.DOMANDE_PREDEFINITE.get(numeroDomanda2).isCorrect(this.finestra.
                    gruppoOpzioniDomanda2.
                    getSelection().
                    getActionCommand()))
                ++punteggioFinale;
            if(Domanda.DOMANDE_PREDEFINITE.get(numeroDomanda3).isCorrect(this.finestra.
                    gruppoOpzioniDomanda3.
                    getSelection().
                    getActionCommand()))
                ++punteggioFinale;
            this.finestra.punteggioCalcolato.setText(punteggioFinale + "");
            this.finestra.calcolaPunteggio.setEnabled(false);
            dialogMessage = "Punteggio calcolato!";
        }
        catch (NumberFormatException ex ){
            dialogMessage = "Le domande non sono state caricate correttamente";
        }
        catch (NullPointerException ex ){
            dialogMessage = "Devi rispondere a tutte le domande!";
        }
        JOptionPane.showMessageDialog(null, dialogMessage);
    }
}
