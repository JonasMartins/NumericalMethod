package br.com.dc.ufc.main;

import javax.swing.JOptionPane;

import br.com.dc.ufc.NewtonCotes.NewtonCotes;

public class Main {

	public static void main(String[] args) {
		
		int option=0;
		double error=0;
		
		try {
			option = Integer.parseInt(JOptionPane.showInputDialog(null, "enter your degree aproximation"));
		} catch (NumberFormatException e) {
			e.printStackTrace();
		}
		try {
			error = Double.parseDouble(JOptionPane.showInputDialog(null, "enter your error limitation"));
		} catch (NumberFormatException e) {
			e.printStackTrace();
		}
		
		//NewtonCotes closedMethods = new NewtonCotes(2,0.01); //tests
		
		NewtonCotes closedMethods = new NewtonCotes(option,error);
		closedMethods.run();
		
	}

}
