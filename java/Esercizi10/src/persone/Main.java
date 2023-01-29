package persone;
import java.util.*;

public class Main {
    public static void main(String... args){
        OptionalDouble mediaEta;
        List<Persona> listaPersone = List.of(
                new Persona("Mario", "Rossi", 10, Persona.Genere.Maschio),
                new Persona("Benedetto", "Pupella", 22, Persona.Genere.Maschio),
                new Persona("Ajeje", "Brazzorf", 30, Persona.Genere.Maschio),
                new Persona("Creatura", "Pupella's Property", 21, Persona.Genere.Femmina)
        );
        mediaEta = listaPersone.stream()
                .filter(persona -> persona.getSesso().equals(Persona.Genere.Maschio))
                .mapToInt(Persona::getEta)
                .average();
        if(mediaEta.isPresent())
            System.out.println("Media età : " + mediaEta.getAsDouble());
        else
            System.out.println("Non è stato possibile determinare la media");
    }
}
