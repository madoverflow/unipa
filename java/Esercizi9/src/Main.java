import java.util.*;
public class Main {
    public static void main(String[] args) {
        Set<Integer> numeri = Set.of(8,1,2,-5,11);
        System.out.println(Main.consecutivi2(numeri));
    }

    private static boolean consecutivi(Set<Integer> s){
        Iterator<Integer> iteratore = s.iterator();
        Integer numero;
        while(iteratore.hasNext()){
            numero = iteratore.next();
            if(s.contains(numero+1))
                return true;
        }
        return false;
    }

    private static boolean consecutivi2(Set<Integer> s){
        Iterator<Integer> iteratore = s.iterator();
        for(Integer numero : s)
            if(s.contains(numero+1))
                return true;
        return false;
    }
}