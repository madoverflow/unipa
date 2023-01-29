package controller;

import view.FileGUI;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.util.stream.Stream;

public class submitActionListener implements ActionListener {
    private final FileGUI finestra;

    public submitActionListener(FileGUI finestra){
        this.finestra = finestra;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        File file = new File(finestra.fileTextField.getText());
        String dialogMessage;
        try(Stream<String> lineeFile = Files.lines(file.toPath())){
            if(!finestra.fileAppendCheck.isSelected())
                finestra.areaOutFile.setText("");
            lineeFile.forEach(linea -> finestra.areaOutFile.setText(
                    finestra
                            .areaOutFile
                            .getText() + linea + "\n"));
            dialogMessage = "File aperto correttamente.";
        }
        catch(IOException | UncheckedIOException ex){
            dialogMessage = "Errore apertura file!";
        }
        JOptionPane.showMessageDialog(null, dialogMessage);
    }
}
