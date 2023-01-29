package controller;

import view.FrameEditor;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.io.UncheckedIOException;

public class OpenButtonListener implements ActionListener {
    private final FrameEditor finestra;

    public OpenButtonListener(FrameEditor finestra){
        this.finestra = finestra;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        int response;
        File fileSelezionato;
        response = finestra.dialogoSelezioneFile.showOpenDialog(null);
        if(response == JFileChooser.APPROVE_OPTION){
            fileSelezionato = finestra.dialogoSelezioneFile.getSelectedFile();
            try{
                FileController.aperturaFile(fileSelezionato, finestra.areaFile);
                finestra.bordoArea.setTitle(fileSelezionato.getName());
                finestra.setFilePredefinito(fileSelezionato.getPath());
                finestra.labelLinguaggioProgrammazione.setText(
                        FileController.verificaLinguaggio(fileSelezionato.getName())
                );
            }
            catch (IOException | UncheckedIOException ex){
                JOptionPane.showMessageDialog(null,"Apertura file fallita.");
            }
        }
    }
}
