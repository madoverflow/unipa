package view;

import controller.RubricaController;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;

public class FrameRubrica extends JFrame {
    public final JPanel pannello = new JPanel();
    public final JMenu rubricaMenu = new JMenu("Rubrica");
    public final JMenuItem nuovaRubrica = new JMenuItem("Nuova");
    public final JMenuItem salvaRubrica = new JMenuItem("Salva");
    public final JMenu numeriMenu = new JMenu("Numeri di telefono");
    public final JMenuItem aggiungiNumero = new JMenuItem("Aggiungi numero");
    public final JMenuItem rimuoviNumero = new JMenuItem("Rimuovi numero");
    public final JMenuItem modificaNumero = new JMenuItem("Modifica numero");
    public final JMenuBar barraMenu = new JMenuBar();

    private FrameRubrica(){
        Container contentPanel = this.getContentPane();
        this.rubricaMenu.add(this.nuovaRubrica);
        this.rubricaMenu.add(this.salvaRubrica);
        this.numeriMenu.add(this.aggiungiNumero);
        this.numeriMenu.add(this.rimuoviNumero);
        this.numeriMenu.add(this.modificaNumero);
        this.barraMenu.add(rubricaMenu);
        this.barraMenu.add(numeriMenu);
        this.setJMenuBar(this.barraMenu);
        contentPanel.add(this.pannello);
    }

    public static void initGUI(){
        FrameRubrica finestra = new FrameRubrica();
        finestra.setPannello();
        finestra.nuovaRubrica.addActionListener(event -> {
            RubricaController.RUBRICA.svuotaRubrica();
            finestra.setPannello();
        });
        finestra.salvaRubrica.addActionListener(event -> {
            String dialogMessage;
            try{
                RubricaController.salvaRubrica();
                dialogMessage = "Rubrica salvata.";
            }
            catch(IOException ex){
                dialogMessage = "Qualcosa è andata storto!";
            }
            JOptionPane.showMessageDialog(null, dialogMessage);
        });
        finestra.aggiungiNumero.addActionListener(event -> FrameAggiungiNumero.initGUI(finestra));
        finestra.rimuoviNumero.addActionListener(event -> FrameRimuoviNumero.initGUI(finestra));
        finestra.modificaNumero.addActionListener(event -> FrameModificaNumero.initGUI(finestra));
        finestra.pack();
        finestra.setTitle("Rubrica");
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }
    public void setPannello(){
        this.pannello.removeAll();
        this.pannello.setLayout(new GridLayout(
                RubricaController.RUBRICA.getNumeriDiTelefono().entrySet().size(),
                1
        ));
        RubricaController.RUBRICA.getNumeriDiTelefono().entrySet().stream()
                .forEach(
                        entrata ->
                            this.pannello.add(FrameRubrica.creaPannelloNumero(entrata.getKey(),entrata.getValue()))
                        );
    }
    public static JPanel creaPannelloNumero(String numeroTelefono, String nomeTelefono){
        JPanel dataPanel = new JPanel();
        JLabel labelNumero = new JLabel("Numero di telefono");
        JTextField numero = new JTextField(numeroTelefono);
        JLabel labelNome = new JLabel("Nome");
        JTextField nome = new JTextField(nomeTelefono);
        dataPanel.add(labelNumero);
        dataPanel.add(numero);
        dataPanel.add(labelNome);
        dataPanel.add(nome);
        return dataPanel;
    }
}
