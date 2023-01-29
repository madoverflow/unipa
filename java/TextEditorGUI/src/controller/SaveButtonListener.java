package controller;

import view.FrameEditor;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class SaveButtonListener implements ActionListener {
    private final FrameEditor finestra;

    public SaveButtonListener(FrameEditor finestra){
        this.finestra = finestra;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        File file = new File(finestra.getFilePredefinito());
        try {
            FileController.scritturaFile(file, finestra.areaFile.getText());
        }
        catch (IOException ex){
            JOptionPane.showMessageDialog(null,"Scrittura file fallita.");
        }
    }
}
