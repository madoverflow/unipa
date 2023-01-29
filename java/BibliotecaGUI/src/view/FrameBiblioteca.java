package view;

import controller.BibliotecaController;
import controller.CreaPannelli;
import model.*;

import javax.swing.*;
import java.awt.*;

public class FrameBiblioteca extends JFrame {
    private final JPanel pannelloLibri = new JPanel();
    private final JPanel pannelloDizionari = new JPanel();
    private final JPanel pannelloQuotidiani = new JPanel();
    private final JPanel pannelloCompactDisc = new JPanel();
    private final JPanel pannelloDocumenti = new JPanel();
    private final JMenu menuFile = new JMenu("File");
    private final JMenuItem nuovoFile = new JMenuItem("Nuovo");
    private final JMenuItem salvaFile = new JMenuItem("Salva");
    private final JMenu menuDocumento = new JMenu("Documento");
    private final JMenu menuAggiungere = new JMenu("Aggiungi");
    private final JMenuItem aggiungiLibro = new JMenuItem("Libro");
    private final JMenuItem aggiungiDizionario = new JMenuItem("Dizionario");
    private final JMenuItem aggiungiQuotidiano = new JMenuItem("Quotidiano");
    private final JMenuItem aggiugniCompactDisc = new JMenuItem("Compact Disc");
    private final JMenuItem rimuoviDocumento = new JMenuItem("Rimuovi");
    private final JMenu menuModificare = new JMenu("Modifica");
    private final JMenuItem modificaLibro = new JMenuItem("Libro");
    private final JMenuItem modificaDizionario = new JMenuItem("Dizionario");
    private final JMenuItem modificaQuotidiano = new JMenuItem("Quotidiano");
    private final JMenuItem modificaCompactDisc = new JMenuItem("Compact Disc");
    private final JMenuBar menuBar = new JMenuBar();

    private FrameBiblioteca(){
        Container contentPanel = this.getContentPane();
        this.menuAggiungere.add(this.aggiungiLibro);
        this.menuAggiungere.add(this.aggiungiDizionario);
        this.menuAggiungere.add(this.aggiungiQuotidiano);
        this.menuAggiungere.add(this.aggiugniCompactDisc);
        this.menuModificare.add(this.modificaLibro);
        this.menuModificare.add(this.modificaDizionario);
        this.menuModificare.add(this.modificaQuotidiano);
        this.menuModificare.add(this.modificaCompactDisc);
        this.menuFile.add(this.nuovoFile);
        this.menuFile.add(this.salvaFile);
        this.menuDocumento.add(this.menuAggiungere);
        this.menuDocumento.add(this.rimuoviDocumento);
        this.menuDocumento.add(this.menuModificare);
        this.menuBar.add(this.menuFile);
        this.menuBar.add(this.menuDocumento);
        this.setJMenuBar(this.menuBar);
        this.pannelloDocumenti.setLayout(new GridLayout(4,1));
        this.pannelloDocumenti.add(this.pannelloLibri);
        this.pannelloDocumenti.add(this.pannelloDizionari);
        this.pannelloDocumenti.add(this.pannelloQuotidiani);
        this.pannelloDocumenti.add(this.pannelloCompactDisc);
        contentPanel.add(this.pannelloDocumenti,BorderLayout.CENTER);
    }

    public static void initGUI(){
        FrameBiblioteca finestra = new FrameBiblioteca();
        finestra.setPannelloDocumenti();
        finestra.nuovoFile.addActionListener(
                event -> {
                    BibliotecaController.CATALOGO_BIBLIOTECA.svuotaCatalogo();
                    finestra.setPannelloDocumenti();
                }
        );
        finestra.salvaFile.addActionListener(event -> BibliotecaController.salvaBiblioteca());
        finestra.aggiungiLibro.addActionListener(event -> FrameLibro.initGUI(finestra));
        finestra.aggiungiDizionario.addActionListener(event -> FrameDizionario.initGUI(finestra));
        finestra.aggiungiQuotidiano.addActionListener(event -> FrameQuotidiano.initGUI(finestra));
        finestra.aggiugniCompactDisc.addActionListener(event -> FrameCompactDisc.initGUI(finestra));
        finestra.rimuoviDocumento.addActionListener(event -> FrameRimozioneDocumento.initGUI(finestra));
        finestra.modificaLibro.addActionListener(event -> FrameModificaLibro.initGUI(finestra));
        finestra.modificaDizionario.addActionListener(event -> FrameModificaDizionario.initGUI(finestra));
        finestra.modificaQuotidiano.addActionListener(event -> FrameModificaQuotidiano.initGUI(finestra));
        finestra.modificaCompactDisc.addActionListener(event -> FrameModificaCompactDisc.initGUI(finestra));
        finestra.setTitle("Catalogo biblioteca");
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }

    public void setPannelloDocumenti(){
        int dimensionePannelli = BibliotecaController.CATALOGO_BIBLIOTECA.getCatalogoDocumenti().size();
        this.pannelloLibri.setLayout(new GridLayout(dimensionePannelli,1));
        this.pannelloDizionari.setLayout(new GridLayout(dimensionePannelli,1));
        this.pannelloCompactDisc.setLayout(new GridLayout(dimensionePannelli,1));
        this.pannelloQuotidiani.setLayout(new GridLayout(dimensionePannelli,1));
        CreaPannelli.creaPannelloLibri(this.pannelloLibri, BibliotecaController.CATALOGO_BIBLIOTECA
                .getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == Libro.class)
                .map(documento -> (Libro) documento)
        );
        CreaPannelli.creaPannelloDizionari(this.pannelloDizionari, BibliotecaController.CATALOGO_BIBLIOTECA
                .getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == Dizionario.class)
                .map(documento -> (Dizionario) documento)
        );
        CreaPannelli.creaPannelloQuotidiani(this.pannelloQuotidiani, BibliotecaController.CATALOGO_BIBLIOTECA
                .getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == Quotidiano.class)
                .map(documento -> (Quotidiano) documento)
        );
        CreaPannelli.creaPannelloCompatDisc(this.pannelloCompactDisc, BibliotecaController.CATALOGO_BIBLIOTECA
                .getCatalogoDocumenti()
                .stream()
                .filter(documento -> documento.getClass() == CompactDisc.class)
                .map(documento -> (CompactDisc) documento)
        );
    }
}
