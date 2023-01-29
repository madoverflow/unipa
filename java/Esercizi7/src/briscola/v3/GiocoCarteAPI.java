package briscola.v3;
import java.util.*;
import java.util.function.*;

public interface GiocoCarteAPI<T extends Enum> {
    default List<Carta<T>> creaMazzo(T[] facce, List<String> semi){
        ArrayList<Carta<T>> mazzo = new ArrayList<>();
        for(String seme : semi)
            for(T faccia : facce)
                mazzo.add(new Carta<T>(faccia,seme));
        return mazzo;
    }

    default int vincitoreTurno(Carta<T> c1, Carta<T> c2, Comparator<Carta<T>> comparatore){
        return comparatore.compare(c1,c2);
    }
}
