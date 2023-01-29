package controller;

import model.Autore;
@FunctionalInterface
public interface Nominabile {
    void addAuthor(Autore autore);
    default void removeAuthor(Autore autore){};
}
