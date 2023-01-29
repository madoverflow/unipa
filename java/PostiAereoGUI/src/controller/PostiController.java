package controller;

import model.Posto;

import java.io.*;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.TreeMap;

public interface PostiController {
    Map<Posto, String> MAPPA_PRENOTAZIONI = new TreeMap<>();
}
