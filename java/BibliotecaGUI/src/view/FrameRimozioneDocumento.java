package view;

import controller.BibliotecaController;
import model.Documento;

import javax.swing.*;
import java.awt.*;
import java.util.Collections;
import java.util.Comparator;

public class FrameRimozioneDocumento extends JFrame {
    private final JLabel labelTitolo = new JLabel("Inserisci titolo documento: ");
    private final JTextField fieldTitolo = new JTextField();
    private final JPanel pannelloTitolo = new JPanel();
    private final JButton submit = new JButton("Invio");

    private FrameRimozioneDocumento(){
        Container contentPanel = this.getContentPane();
        this.fieldTitolo.setPreferredSize(BibliotecaController.DIMENSIONE_FIELD);
        this.pannelloTitolo.add(this.labelTitolo);
        this.pannelloTitolo.add(this.fieldTitolo);
        contentPanel.add(this.pannelloTitolo, BorderLayout.NORTH);
        contentPanel.add(this.submit, BorderLayout.CENTER);
    }

    public static void initGUI(FrameBiblioteca finestraBiblioteca){
        FrameRimozioneDocumento finestra = new FrameRimozioneDocumento();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.submit.addActionListener(
                event -> {
                    int posizione;
                    String dialogMessage;
                    Documento documento;
                    posizione = Collections.binarySearch(
                            BibliotecaController.CATALOGO_BIBLIOTECA.getCatalogoDocumenti(),
                            new Documento(finestra.fieldTitolo.getText(),0){},
                            Comparator.comparing(Documento::getTitolo));
                    if(posizione >= 0){
                        documento = BibliotecaController.CATALOGO_BIBLIOTECA.getCatalogoDocumenti().get(posizione);
                        BibliotecaController.CATALOGO_BIBLIOTECA.rimuoviDocumento(documento);
                        finestraBiblioteca.setPannelloDocumenti();
                        dialogMessage = "Documento cancellato.";
                    }
                    else
                        dialogMessage = "Documento non trovato!";
                    JOptionPane.showMessageDialog(null, dialogMessage);
                }
        );
        finestra.setTitle("Rimozione documento");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
}
