package album;
import java.util.*;

public class Album {
    private String author;
    private List<String> songs;
    private int year;
    private String title;

    public Album(String author, String title, int year, String... songs){
        this.author = author;
        this.year = year;
        this.title = title;
        this.songs = new ArrayList<>(Arrays.asList(songs));
    }

    public String getAuthor() {
        return author;
    }

    public List<String> getSongs() {
        return new ArrayList<>(this.songs);
    }

    public int getYear() {
        return year;
    }

    public String getTitle() {
        return title;
    }
}
