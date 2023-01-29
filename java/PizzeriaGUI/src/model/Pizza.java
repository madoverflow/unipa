package model;

import java.util.ArrayList;
import java.util.List;

public class Pizza {
    public enum Ingrediente{
        NESSUNO(0.0),
        POMODORO(0.0),
        ORIGANO(0.0),
        WURSTEL(0.5),
        OLIVE(0.7),
        PROSCIUTTO_COTTO(1.0),
        MOZZARELLA(1.5),
        MOZZARELLA_BUFALA(2.5),
        FUNGHI(0.8),
        SALAME(0.5),
        MORTADELLA(0.5),
        PROSCIUTTO_CRUDO(2.0),
        ACCIUGHE(1.0),
        CARCIOFI(0.6);
        private double prezzo;
        private Ingrediente(double prezzo){
            this.prezzo = prezzo;
        }

        public double getPrezzo() {
            return prezzo;
        }
    }
    private final String nome;
    private final List<Ingrediente> listaIngredienti;
    private static final double PREZZO_BASE = 4.0;
    public static final List<Pizza> pizzePredefinite = List.of(
            new Pizza("Margherita", List.of(
                    Ingrediente.POMODORO,
                    Ingrediente.MOZZARELLA)),
            new Pizza("Romana", List.of(
                    Ingrediente.POMODORO,
                    Ingrediente.MOZZARELLA,
                    Ingrediente.PROSCIUTTO_COTTO)),
            new Pizza("Biancaneve", List.of(
                    Ingrediente.MOZZARELLA)),
            new Pizza("Napoli", List.of(
                    Ingrediente.POMODORO,
                    Ingrediente.MOZZARELLA,
                    Ingrediente.ACCIUGHE,
                    Ingrediente.ORIGANO)),
            new Pizza("Capricciosa", List.of(
                    Ingrediente.POMODORO,
                    Ingrediente.MOZZARELLA,
                    Ingrediente.PROSCIUTTO_COTTO,
                    Ingrediente.OLIVE,
                    Ingrediente.FUNGHI,
                    Ingrediente.CARCIOFI))
    );

    public Pizza(String nome, List<Ingrediente> listaIngredienti){
        this.nome = nome;
        this.listaIngredienti = listaIngredienti;
    }

    public String getNome() {
        return nome;
    }

    public List<Ingrediente> getListaIngredienti() {
        return new ArrayList<>(this.listaIngredienti);
    }

    public double calcolaPrezzo(){
        return this.getListaIngredienti().stream()
                .mapToDouble(Ingrediente::getPrezzo)
                .sum() + Pizza.PREZZO_BASE;
    }

    @Override
    public String toString() {
        return this.getNome();
    }
}
