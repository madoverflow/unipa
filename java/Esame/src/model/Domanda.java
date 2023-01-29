package model;

import java.util.List;

public class Domanda {
    private final String testoDomanda;
    private final String[] opzioni;
    private String opzioneCorretta;

    public static final List<Domanda> DOMANDE_PREDEFINITE = List.of(
            new Domanda("Quanto fa 15 + 18?", new String[]{"33","15","9"}, 0),
            new Domanda("Quanto fa 1 + 1?", new String[]{"2","0","1"}, 0),
            new Domanda("Quanto fa 2 x 2?", new String[]{"0","4","1"}, 1),
            new Domanda("Quanto fa 1 x 0?", new String[]{"0","3","1"}, 0),
            new Domanda("Quanto fa 1 : 1?", new String[]{"0", "10", "1"}, 2),
            new Domanda("Quanto fa 10 + 0?", new String[]{"9", "-1", "10"},2),
            new Domanda("Quanto fa 2 x 1?", new String[]{"10", "2", "1"},1),
            new Domanda("Quanto fa 3 + 3?", new String[]{"5", "6", "9"}, 1),
            new Domanda("Quanto fa 5 + 2?", new String[]{"7","4","2"}, 0)
    );

    private Domanda(String testoDomanda, String[] opzioni, int numeroOpzioneCorretta){
        this.testoDomanda = testoDomanda;
        this.opzioni = opzioni;
        try{
            this.opzioneCorretta = opzioni[numeroOpzioneCorretta];
        }
        catch (IndexOutOfBoundsException ex){
            this.opzioneCorretta = opzioni[0];
        }
    }

    public boolean isCorrect(String opzione){
        return this.opzioneCorretta.equals(opzione);
    }

    public String getTestoDomanda() {
        return testoDomanda;
    }

    public String[] getOpzioni() {
        return opzioni;
    }
}
