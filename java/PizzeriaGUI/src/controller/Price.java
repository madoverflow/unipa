package controller;

import java.text.DecimalFormat;

public interface Price {
    static String getFormatted(double prezzo){
        return "EUR " + new DecimalFormat("0.00").format(prezzo);
    }
}
