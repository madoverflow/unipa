package model;

import java.io.*;
import java.util.*;

public class Rubrica implements Serializable {
    @Serial
    private static final long serialVersionUID = 12345678L;
    private final Map<String,String> numeriDiTelefono;

    public Rubrica(){
        this.numeriDiTelefono = new TreeMap<>();
    }

    public void aggiungiNumero(String numero, String nomeCompleto){
        this.numeriDiTelefono.put(numero,nomeCompleto);
    }

    public void rimuoviNumero(String numero){
        this.numeriDiTelefono.remove(numero);
    }

    public Map<String, String> getNumeriDiTelefono() {
        return new TreeMap<>(numeriDiTelefono);
    }

    public void svuotaRubrica(){
        Iterator<String> iteratoreChiavi;
        iteratoreChiavi = this.numeriDiTelefono.keySet().iterator();
        while(iteratoreChiavi.hasNext()){
            iteratoreChiavi.next();
            iteratoreChiavi.remove();
        }
    }

    public boolean isEmpty(){
        return this.numeriDiTelefono.isEmpty();
    }
}
