package model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class Catalogo implements Serializable {
    private final List<Documento> catalogoDocumenti;

    public Catalogo(){
        this.catalogoDocumenti = new ArrayList<>();
    }

    public List<Documento> getCatalogoDocumenti() {
        return new ArrayList<>(this.catalogoDocumenti);
    }

    public boolean inserisciDocumento(Documento doc){
        if(this.catalogoDocumenti.contains(doc))
            return false;
        this.catalogoDocumenti.add(doc);
        return true;
    }

    public void rimuoviDocumento(Documento doc){
        this.catalogoDocumenti.remove(doc);
    }
    public void svuotaCatalogo(){
        Iterator<Documento> iteratoreDocumenti = this.catalogoDocumenti.iterator();
        while(iteratoreDocumenti.hasNext()){
            iteratoreDocumenti.next();
            iteratoreDocumenti.remove();
        }
    }
}
