package controller;

import javax.swing.text.JTextComponent;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SubmitListener implements ActionListener {
    private final JTextComponent textComponent;
    private final String stringaCercata;
    private final String stringaSostituzione;

    public SubmitListener(JTextComponent textComponent, String stringaCercata, String stringaSostituzione){
        this.textComponent = textComponent;
        this.stringaCercata = stringaCercata;
        this.stringaSostituzione = stringaSostituzione;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        StringBuilder testoModificato = new StringBuilder(this.textComponent.getText());
        final int lunghezzaOccorrenza = this.stringaCercata.length();

    }
}
