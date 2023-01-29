package view;

import controller.*;

import javax.swing.*;
import javax.swing.border.TitledBorder;
import javax.swing.text.BadLocationException;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class FrameEditor extends JFrame {
    public static final Dimension DIMENSIONE = new Dimension(32,32);
    private String filePredefinito = "esempio.txt";
    public TitledBorder bordoArea = BorderFactory.createTitledBorder("esempio.txt");
    public final JFileChooser dialogoSelezioneFile = new JFileChooser();
    public final JTextArea areaFile = new JTextArea(35,97);
    public final JScrollPane areaPanel = new JScrollPane();
    public final JButton newFile = new JButton();
    public final JButton openFile = new JButton();
    public final JButton saveFile = new JButton();
    public final JButton saveAsFile = new JButton();
    public final JButton findAndReplaceFile = new JButton();
    public final JPanel panelToolBar = new JPanel();
    public final JToolBar toolBar = new JToolBar();
    public final JLabel labelLinguaggioProgrammazione = new JLabel("Nessuno");
    public final JLabel labelLinea = new JLabel("Ln");
    public final JLabel labelNrLinea = new JLabel("1,");
    public final JLabel labelColonna = new JLabel("Col");
    public final JLabel labelNrColonna = new JLabel("1");
    public final JPanel panelDettagliFile = new JPanel();
    public final JMenu menuFile = new JMenu("File");
    public final JMenuItem menuNewFile = new JMenuItem("Nuovo");
    public final JMenuItem menuOpenFile = new JMenuItem("Apri");
    public final JMenuItem menuSaveFile = new JMenuItem("Salva");
    public final JMenuItem menuSaveAsFile = new JMenuItem("Salva come");
    public final JMenuItem menuFindAndReplaceFile = new JMenuItem("Cerca e sostituisci");
    public final JMenu menuView = new JMenu("View");
    public final JMenuItem menuAumentaCarattere = new JMenuItem("Aumenta grandezza caratteri");
    public final JMenuItem menuDiminiusciCarattere = new JMenuItem("Diminuisci grandezza caratteri");
    public final JMenuBar menuBar = new JMenuBar();


    private FrameEditor(){
        Container contentPanel = this.getContentPane();
        this.dialogoSelezioneFile.setMultiSelectionEnabled(false);
        this.dialogoSelezioneFile.setFileSelectionMode(JFileChooser.FILES_ONLY);
        this.areaFile.setBorder(this.bordoArea);
        this.areaPanel.setViewportView(this.areaFile);
        this.newFile.setPreferredSize(FrameEditor.DIMENSIONE);
        this.newFile.setIcon(new ImageIcon("newFile.png"));
        this.newFile.setBorderPainted(false);
        this.newFile.setFocusPainted(false);
        this.newFile.setContentAreaFilled(false);
        this.newFile.setOpaque(false);
        this.openFile.setPreferredSize(FrameEditor.DIMENSIONE);
        this.openFile.setIcon(new ImageIcon("openFile.png"));
        this.openFile.setBorderPainted(false);
        this.openFile.setFocusPainted(false);
        this.openFile.setContentAreaFilled(false);
        this.openFile.setOpaque(false);
        this.saveFile.setPreferredSize(FrameEditor.DIMENSIONE);
        this.saveFile.setIcon(new ImageIcon("saveFile.png"));
        this.saveFile.setBorderPainted(false);
        this.saveFile.setFocusPainted(false);
        this.saveFile.setContentAreaFilled(false);
        this.saveFile.setOpaque(false);
        this.saveAsFile.setPreferredSize(FrameEditor.DIMENSIONE);
        this.saveAsFile.setIcon(new ImageIcon("saveAsFile.png"));
        this.saveAsFile.setBorderPainted(false);
        this.saveAsFile.setFocusPainted(false);
        this.saveAsFile.setContentAreaFilled(false);
        this.saveAsFile.setOpaque(false);
        this.findAndReplaceFile.setPreferredSize(FrameEditor.DIMENSIONE);
        this.findAndReplaceFile.setIcon(new ImageIcon("findAndReplaceFile.png"));
        this.findAndReplaceFile.setBorderPainted(false);
        this.findAndReplaceFile.setFocusPainted(false);
        this.findAndReplaceFile.setContentAreaFilled(false);
        this.findAndReplaceFile.setOpaque(false);
        this.panelToolBar.setBackground(Color.WHITE);
        this.panelToolBar.add(this.newFile);
        this.panelToolBar.add(this.openFile);
        this.panelToolBar.add(this.saveFile);
        this.panelToolBar.add(this.saveAsFile);
        this.panelToolBar.add(this.findAndReplaceFile);
        this.toolBar.setLayout(new FlowLayout(FlowLayout.LEFT));
        this.toolBar.setBackground(Color.WHITE);
        this.toolBar.add(this.panelToolBar);
        this.panelDettagliFile.setLayout(new FlowLayout(FlowLayout.LEFT));
        this.panelDettagliFile.add(labelLinguaggioProgrammazione);
        this.panelDettagliFile.add(labelLinea);
        this.panelDettagliFile.add(labelNrLinea);
        this.panelDettagliFile.add(labelColonna);
        this.panelDettagliFile.add(labelNrColonna);
        this.menuFile.add(this.menuNewFile);
        this.menuFile.add(this.menuOpenFile);
        this.menuFile.add(this.menuSaveFile);
        this.menuFile.add(this.menuSaveAsFile);
        this.menuFile.add(this.menuFindAndReplaceFile);
        this.menuView.add(this.menuAumentaCarattere);
        this.menuView.add(this.menuDiminiusciCarattere);
        this.menuBar.add(this.menuFile);
        this.menuBar.add(this.menuView);
        this.setJMenuBar(this.menuBar);
        contentPanel.add(this.toolBar, BorderLayout.NORTH);
        contentPanel.add(this.areaPanel, BorderLayout.CENTER);
        contentPanel.add(this.panelDettagliFile, BorderLayout.SOUTH);
    }

    public static void initGUI(){
        FrameEditor finestra = new FrameEditor();
        finestra.areaFile.addCaretListener(
                event -> {
                    int caret, linea, colonna;
                    caret = finestra.areaFile.getCaretPosition();
                    try{
                        linea = finestra.areaFile.getLineOfOffset(caret);
                        colonna = caret - finestra.areaFile.getLineStartOffset(linea);
                    }
                    catch (BadLocationException ex){
                        linea = 0;
                        colonna = 0;
                    }
                    finestra.labelNrLinea.setText(++linea + ",");
                    finestra.labelNrColonna.setText(String.valueOf(++colonna));
                }
        );
        finestra.areaFile.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
                if(e.getKeyCode() == KeyEvent.VK_F11)
                    finestra.areaFile.setFont(finestra
                            .areaFile
                            .getFont()
                            .deriveFont(finestra.areaFile.getFont().getSize() + 2.0f));
                if(e.getKeyCode() == KeyEvent.VK_F9)
                    finestra.areaFile.setFont(finestra
                            .areaFile
                            .getFont()
                            .deriveFont(finestra.areaFile.getFont().getSize() - 2.0f));
            }
        });
        finestra.newFile.addActionListener(new NewButtonListener(finestra));
        finestra.openFile.addActionListener(new OpenButtonListener(finestra));
        finestra.saveFile.addActionListener(new SaveButtonListener(finestra));
        finestra.saveAsFile.addActionListener(new SaveAsButtonListener(finestra));
        finestra.findAndReplaceFile.addActionListener(event -> FrameFindReplace.initGUI(finestra.areaFile));
        finestra.menuNewFile.addActionListener(new NewButtonListener(finestra));
        finestra.menuOpenFile.addActionListener(new OpenButtonListener(finestra));
        finestra.menuSaveFile.addActionListener(new SaveButtonListener(finestra));
        finestra.menuSaveAsFile.addActionListener(new SaveAsButtonListener(finestra));
        finestra.menuFindAndReplaceFile.addActionListener(event -> FrameFindReplace.initGUI(finestra.areaFile));
        finestra.menuAumentaCarattere.addActionListener(
                event -> finestra.areaFile.setFont(finestra
                        .areaFile
                        .getFont()
                        .deriveFont(finestra.areaFile.getFont().getSize() + 2.0f))
        );
        finestra.menuDiminiusciCarattere.addActionListener(
                event -> finestra.areaFile.setFont(finestra
                        .areaFile
                        .getFont()
                        .deriveFont(finestra.areaFile.getFont().getSize() - 2.0f))
        );
        finestra.pack();
        finestra.setTitle("Editor di testo");
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }

    public String getFilePredefinito() {
        return filePredefinito;
    }

    public void setFilePredefinito(String filePredefinito) {
        this.filePredefinito = filePredefinito;
    }
}
