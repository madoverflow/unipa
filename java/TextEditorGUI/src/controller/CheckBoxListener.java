package controller;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class CheckBoxListener implements ChangeListener {
    private final JCheckBox check1;
    private final JCheckBox check2;

    public CheckBoxListener(JCheckBox check1, JCheckBox check2){
        this.check1 = check1;
        this.check2 = check2;
    }
    @Override
    public void stateChanged(ChangeEvent e) {
        if(this.check1.isSelected())
            check2.setEnabled(false);
        else
            check2.setEnabled(true);
    }
}
