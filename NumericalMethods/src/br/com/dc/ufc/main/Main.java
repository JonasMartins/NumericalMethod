package br.com.dc.ufc.main;

import javax.swing.JOptionPane;

import br.com.dc.ufc.ExponencialMethod.DoubleExponencial;
import br.com.dc.ufc.NewtonCotes.NewtonCotes;
import br.com.dc.ufc.NewtonCotesOpen.NewtonCotesOpen;

public class Main {

	/*
	 * 	ALSO FIND AT : https://github.com/JonasMartins/NumericalMethods.git
	 *
	 *
	 *
	 * */

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

		//@SuppressWarnings("unused")
		NewtonCotes closedMethods = new NewtonCotes(option,error);
		
		closedMethods.run(); // secçã anterior...
		
		
		@SuppressWarnings("unused")
		NewtonCotesOpen openMethods = new NewtonCotesOpen(option,error);
		//openMethods.run(); // secçã anterior...

		//GaussLegendre gaussLeg = new GaussLegendre(1, 2,error, option);
		//gaussLeg.run();

		//GaussHermite gaussHer = new GaussHermite(option);
		//gaussHer.run();

		//GaussLaguerre gaussLag = new GaussLaguerre(option);
		//gaussLag.run();


		//GaussChebyshev gaussChe = new GaussChebyshev(option);
		//gaussChe.run();

		@SuppressWarnings("unused")
		DoubleExponencial de = new DoubleExponencial(-1,1,0.001);
		//de.run();


	}

}
