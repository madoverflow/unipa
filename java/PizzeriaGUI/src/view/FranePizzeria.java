package view;

import controller.Price;
import model.Pizza;

import javax.swing.*;
import java.awt.*;

public class FranePizzeria extends JFrame{
    private final JPanel pannelloMenu = new JPanel();
    private final JComboBox<Pizza> listaPizzePredefinite;
    private final JComboBox<Pizza.Ingrediente> listaIngredienti;
    private final JPanel pannelloSelezioneScelte = new JPanel();
    private final JButton submit = new JButton("Invio");
    private final JLabel labelPrezzoFinale = new JLabel("Prezzo totale: ");
    private final JTextField fieldPrezzoFinale = new JTextField();
    private final JPanel pannelloPrezzoFinale = new JPanel();

    private FranePizzeria(){
        Container contentPanel = this.getContentPane();
        this.listaPizzePredefinite = new JComboBox<>(Pizza.pizzePredefinite.toArray(Pizza[]::new));
        this.listaIngredienti = new JComboBox<>(Pizza.Ingrediente.values());
        this.pannelloSelezioneScelte.add(this.listaPizzePredefinite);
        this.pannelloSelezioneScelte.add(this.listaIngredienti);
        this.fieldPrezzoFinale.setPreferredSize(new Dimension(200,20));
        this.pannelloPrezzoFinale.add(this.submit);
        this.pannelloPrezzoFinale.add(this.labelPrezzoFinale);
        this.pannelloPrezzoFinale.add(this.fieldPrezzoFinale);
        contentPanel.add(this.pannelloMenu,BorderLayout.NORTH);
        contentPanel.add(this.pannelloSelezioneScelte, BorderLayout.CENTER);
        contentPanel.add(this.pannelloPrezzoFinale, BorderLayout.SOUTH);
    }
    public static void initGUI(){
        FranePizzeria finestra = new FranePizzeria();
        finestra.creaMenuPizze();
        finestra.addController();
        finestra.getRootPane().setDefaultButton(finestra.submit);
        finestra.pack();
        finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        finestra.setLocationRelativeTo(null);
        finestra.setVisible(true);
    }

    private void creaMenuPizze(){
        this.pannelloMenu.removeAll();
        this.pannelloMenu.setLayout(new GridLayout(Pizza.pizzePredefinite.size(),1));
        Pizza.pizzePredefinite.stream()
                .forEach(pizza -> {
                    JLabel labelNomePizza = new JLabel("Pizza: ");
                    JLabel labelPrezzoPizza = new JLabel("Prezzo: ");
                    JLabel labelIngredientiPizza = new JLabel("Ingredienti: ");
                    JTextField fieldNomePizza = new JTextField(pizza.getNome());
                    JTextField fieldPrezzoPizza = new JTextField(Price.getFormatted(pizza.calcolaPrezzo()));
                    JComboBox<Pizza.Ingrediente> ingredientiPizza = new JComboBox<>(pizza
                            .getListaIngredienti()
                            .toArray(Pizza.Ingrediente[]::new)
                    );
                    this.pannelloMenu.add(labelNomePizza);
                    this.pannelloMenu.add(fieldNomePizza);
                    this.pannelloMenu.add(labelIngredientiPizza);
                    this.pannelloMenu.add(ingredientiPizza);
                    this.pannelloMenu.add(labelPrezzoPizza);
                    this.pannelloMenu.add(fieldPrezzoPizza);
                });
    }

    private void addController(){
        this.submit.addActionListener(event -> {
            Pizza pizzaScelta;
            Pizza.Ingrediente ingredienteScelto;
            pizzaScelta = (Pizza) this.listaPizzePredefinite.getSelectedItem();
            ingredienteScelto = (Pizza.Ingrediente) this.listaIngredienti.getSelectedItem();
            this.fieldPrezzoFinale.setText(Price
                    .getFormatted(pizzaScelta.calcolaPrezzo() + ingredienteScelto.getPrezzo()));
        });
    }

}
