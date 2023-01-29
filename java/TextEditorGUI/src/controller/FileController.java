package controller;

import javax.swing.text.JTextComponent;
import java.io.*;
import java.nio.file.Files;
import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Stream;

public interface FileController{

    public static void aperturaFile(File file, JTextComponent textComponent) throws IOException, UncheckedIOException {
        try(Stream<String> lineeFile = Files.lines(file.toPath())){
            textComponent.setText("");
            lineeFile.forEach(
                    linea -> textComponent.setText(textComponent.getText() + linea + "\n")
            );
        }
    }

    public static void scritturaFile(File file, String text) throws IOException {
        PrintWriter writer = new PrintWriter(new FileWriter(file));
        try(writer){
            writer.write(text);
        }
    }

    public static String verificaLinguaggio(String nomeFile){
        String nomeLinguaggio = "Non riconosciuto";
        Optional<Map.Entry<String,String>> entryLinguaggio;
        Map<String,String> mappaLinguaggi = new HashMap<>();
        mappaLinguaggi.put(".class","Java");
        mappaLinguaggi.put(".java","Java");
        mappaLinguaggi.put(".c","C");
        mappaLinguaggi.put(".cpp","C++");
        entryLinguaggio = mappaLinguaggi.entrySet().stream()
                .filter(optional -> optional.getKey().equals(nomeFile))
                .findFirst();
        if(!nomeFile.contains("."))
            return nomeLinguaggio;
        entryLinguaggio = mappaLinguaggi.entrySet().stream()
                .filter(optional -> optional.getKey().equals(nomeFile.substring(nomeFile.indexOf("."))))
                .findFirst();
        if(entryLinguaggio.isPresent())
            return entryLinguaggio.get().getValue();
        return nomeLinguaggio;
    }
}
