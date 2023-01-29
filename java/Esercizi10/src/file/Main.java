package file;

import java.io.File;
import java.util.List;
import java.util.Map;
import java.util.OptionalLong;

public class Main {
    public static void main(String... args) {
        File file = new File("prova.txt");
        OptionalLong numeroOccorrenze;
        Map<Character, List<String>> mappaLineeFile = mixInterfaceEsercizio.mappeLinee(file);
        if(mappaLineeFile!=null) {
            System.out.println(mappaLineeFile);
            System.out.println(mixInterfaceEsercizio.keyValueInverter(mappaLineeFile));
        }
        numeroOccorrenze = mixInterfaceEsercizio.occorrenzaStringaRigheFile(file,"localhost");
        if(numeroOccorrenze.isPresent())
            System.out.println(numeroOccorrenze.getAsLong());
        else
            System.out.println("Problemi coi file");

    }
}
