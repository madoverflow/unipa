package controller;

import view.FrameEditor;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class SaveAsButtonListener implements ActionListener {
    private final FrameEditor finestra;

    public SaveAsButtonListener(FrameEditor finestra){
        this.finestra = finestra;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        int response;
        File fileSelezionato;
        response = finestra.dialogoSelezioneFile.showSaveDialog(null);
        if(response == JOptionPane.OK_OPTION){
            try{
                fileSelezionato = finestra.dialogoSelezioneFile.getSelectedFile();
                FileController.scritturaFile(fileSelezionato, finestra.areaFile.getText());
                finestra.bordoArea.setTitle(fileSelezionato.getName());
                finestra.setFilePredefinito(fileSelezionato.getPath());
                finestra.labelLinguaggioProgrammazione.setText(FileController
                        .verificaLinguaggio(fileSelezionato.getName()));
            }
            catch(IOException | NullPointerException ex){
                JOptionPane.showMessageDialog(null,"Errore scrittura file");
            }
        }
    }
}
