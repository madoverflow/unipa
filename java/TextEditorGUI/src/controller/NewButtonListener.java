package controller;

import view.FrameEditor;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NewButtonListener implements ActionListener {
    private final FrameEditor finestra;

    public NewButtonListener(FrameEditor finestra){
        this.finestra = finestra;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        finestra.areaFile.setText("");
        finestra.bordoArea.setTitle("esempio.txt");
        finestra.labelLinguaggioProgrammazione.setText("Non riconosciuto");
        finestra.setFilePredefinito("esempio.txt");
    }
}
