package v2;

import java.io.Serializable;

public abstract class Documento implements Serializable {
    public static int id = 1000;
    public abstract String getInfo();
}
