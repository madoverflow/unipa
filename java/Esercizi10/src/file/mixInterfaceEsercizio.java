package file;
import java.nio.file.Files;
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public interface mixInterfaceEsercizio {
    public static Map<Character, List<String>> mappeLinee(File file) {
        try (Stream<String> lineeFile = Files.lines(file.toPath())){
            return lineeFile.collect(Collectors.groupingBy(linea -> linea.charAt(0)));
        }
        catch(IOException ex){
            return null;
        }
    }

    public static OptionalLong occorrenzaStringaRigheFile(File file, String stringa){
        try (Stream<String> lineeFile = Files.lines(file.toPath())){
            return OptionalLong.of(lineeFile
                    .filter(riga -> riga.contains(stringa))
                    .count());
        }
        catch(IOException ex){
            return null;
        }
    }

    public static <K,V> Map<V,List<K>> keyValueInverter(Map<K,V> mappa){
        return mappa.entrySet().stream()
                .collect(Collectors.groupingBy(
                        Map.Entry::getValue,
                        HashMap::new,
                        Collectors.mapping(Map.Entry::getKey, Collectors.toList())
                        ));

    }
}
