package v1;
import java.util.*;

public class CatalogoLibri {
    private final ArrayList<Libro> libri;

    public CatalogoLibri(){
        this.libri = new ArrayList<>();
    }

    public void aggiungiLibro(Libro l){
        this.libri.add(l);
    }

    public void stampaCatalogo(){
        for (Libro l : this.libri)
            System.out.println(l);
    }

    public ArrayList<Libro> ricerca(String nome, String cognome){
        ArrayList<Libro> libriAutore = new ArrayList<>();
        for (Libro l : this.libri)
            for (Autore author : l.getAutori())
                if(author.getNome().equals(nome) && author.getCognome().equals(cognome))
                    libriAutore.add(l);
        return libriAutore;
    }

    public final ArrayList<Libro> getCatalogo() {
        return new ArrayList<Libro>(this.libri);
    }
}
