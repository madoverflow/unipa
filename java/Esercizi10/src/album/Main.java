package album;
import java.util.*;
public class Main {
    public static void main(String... args){
        List<Album> albums = new ArrayList<>();
        albums.add(new Album("Pink Floyd", "The Division Bell", 1994,
                "Cluster One",
                "What Do You Want from Me",
                "Poles Apart",
                "Marooned",
                "A Great Day for Freedom",
                "Wearing the Inside Out",
                "Take It Back",
                "Coming Back to Life",
                "Keep Talking",
                "Lost for Words",
                "High Hopes")
        );
        albums.add(new Album("Pink Fl1oyd", "The Divisio", 2005,
                "Cluster One",
                "What Do You Want from Me",
                "Poles Apart",
                "Marooned",
                "A Great Day for Freedom",
                "Wearing the Inside Out",
                "Take It Back",
                "Coming Back to Life",
                "Keep Talking",
                "Lost for Words",
                "High Hopes")
        );
        albums.add(new Album("Pi1nk Floyd", "The3 Division Bell", 1990,
                "Cluster One",
                "What Do You Want from Me",
                "Poles Apart",
                "Marooned",
                "A Great Day for Freedom",
                "Wearing the Inside Out",
                "Take It Back",
                "Coming Back to Life",
                "Keep Talking",
                "Lost for Words",
                "High Hopes")
        );
        albums.add(new Album("Pink 123Floyd", "The Division Berewll", 2010,
                "Cluster One",
                "What Do You Want from Me",
                "Poles Apart",
                "Marooned",
                "A Great Day for Freedom",
                "Wearing the Inside Out",
                "Take It Back",
                "Coming Back to Life",
                "Keep Talking",
                "Lost for Words",
                "High Hopes")
        );
        albums.stream().
               filter(album -> album.getYear() < 2000).
                forEach(album -> System.out.println(album.getAuthor()));
        albums.stream()
                .filter(album -> album.getYear() < 2000)
                .flatMap(album -> album.getSongs().stream())
                .sorted()
                .forEach(System.out::println);
    }
}
