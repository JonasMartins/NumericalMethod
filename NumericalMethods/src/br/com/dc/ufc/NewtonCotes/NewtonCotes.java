package br.com.dc.ufc.NewtonCotes;

import javax.swing.JOptionPane;

public class NewtonCotes {

	private double error;
	private double a = 0;
	private double b = 1.0;
	private int order, n;
	private double h = (b - a);
	private double integralValue = 0, finalValue = 0, currentArea=0, nextArea=0;
	private double ai, bi, a2i, a3i, aux = 0;


	public NewtonCotes(int order, double error) {

		this.order = order;
		this.error = error;
	}

	public double fx(double x) {
		//return Math.pow(x, 5) - 2 * (Math.pow(x, 3)) + 4 * x + 5; // função
		return Math.pow(x,3) + 2*(Math.pow(x, 2)) - 10 * x;
		// return Math.pow(x, 3) - 2 * (Math.pow(x, 2)) + x; // função mais
		// simples
	}

	public double TrapeziumMethod() {
		
		n = 1;
		ai=a;
		do {
			currentArea = nextArea;
			do {
				bi = ai + (h / n);
				aux = Math.abs( (bi - ai) / 2 * (fx(ai) + fx(bi)) );
				ai = bi;
				integralValue += Math.abs(aux);
				finalValue = integralValue;
			} while (bi < b);
			n++;
			ai = a;
			nextArea = finalValue;
			integralValue = aux = 0;
		} while (Math.abs(nextArea-currentArea)>error);
		JOptionPane.showMessageDialog(null, "N turns: " + (n-1));
		JOptionPane.showMessageDialog(null, "Error: " + (nextArea-currentArea));
		return finalValue;
	}

	public double OneEightSimpson() {
		n = 1; 
		ai = a;
		do {
			currentArea = nextArea;
			do {
				bi = ai + (h / n);
				a2i = ai + ((h / n)/2);
				aux = Math.abs( (bi - ai) / 6 * ( fx(ai) + (4 * fx(a2i) ) + fx(bi) ) ); // formula
				ai = bi;
				integralValue += Math.abs(aux);
				finalValue = integralValue;
			} while (bi < b);
			n++;
			ai = a;
			nextArea = finalValue;
			integralValue = aux = 0;
		} while (Math.abs(nextArea-currentArea)>error);
		JOptionPane.showMessageDialog(null, "N turns: " + (n-1));
		JOptionPane.showMessageDialog(null, "Error: " + (nextArea-currentArea));
		return finalValue;
	}
	public double ThreeEightSimpson() {
		n = 1;
		ai = a;
		do {
			do {
				currentArea = nextArea;
				bi = ai + (h / n);
				a2i = ai + ((h / n)/3);
				a3i = a2i + ((h / n)/3);
				aux = Math.abs( (bi - ai) / 8 * (fx(ai) + 3 * (fx(a2i)) + 3 * (fx(a3i)) + fx(bi)) ); // formula
				ai = bi;
				integralValue += Math.abs(aux);
				finalValue = integralValue;
			} while (bi < b);
			n++;
			ai = a;
			nextArea = finalValue;
			integralValue = aux = 0;
		} while (Math.abs(nextArea-currentArea)>error);
		JOptionPane.showMessageDialog(null, "N turns: " + (n-1));
		JOptionPane.showMessageDialog(null, "Error: " + (nextArea-currentArea));
		return finalValue;
	}

	public void run() {
		switch (order) {
		case 1:
			JOptionPane.showMessageDialog(null, "Integral: " + TrapeziumMethod());
			break;
		case 2:
			JOptionPane.showMessageDialog(null, "Integral: " + OneEightSimpson());
			break;
		case 3:
			JOptionPane.showMessageDialog(null, "Integral: " + ThreeEightSimpson());
			break;
		default :
			JOptionPane.showMessageDialog(null, "Inputs Valids only 1-3! ");
			break;
		}
	}

}
/*
 * 	public double TrapeziumMethod() {
		
		n = 1;
		ai=a;
		do {
			currentArea = nextArea;
			System.out.println(" N: "+n);
			System.out.println(" dx: "+(h/n));
			do {
				System.out.print(" ai: "+ai);
				bi = ai + (h / n);
				System.out.print(" bi: "+bi);
				
				aux = Math.abs( (bi - ai) / 2 * (fx(ai) + fx(bi)) );
				System.out.print(" aux: " + aux);
				ai = bi;//a + (n - 1) * (h / n);
				integralValue += Math.abs(aux);
				finalValue = integralValue;
				
			} while (bi < b);
			n++;
			ai = a;
			nextArea = finalValue;
			System.out.println();
			System.out.println(" partial: "+finalValue+" error: "+(nextArea-currentArea));
			integralValue = aux = 0;
		} while (n<5);
		//JOptionPane.showMessageDialog(null, "N turns: " + n);
		System.out.println( "N turns: " + n);
		return finalValue;
	
	}

		public double OneEightSimpson() {
		n = 1; 
		ai = a;
		do {
			currentArea = nextArea;
			System.out.println(" N: "+n);
			System.out.println(" dx: "+(h/n));
			do {
				//JOptionPane.showMessageDialog(null, " ai: "+ai);
				bi = ai + (h / n);
				a2i = ai + ((h / n)/2);
				//JOptionPane.showMessageDialog(null, " bi: "+bi);
				//JOptionPane.showMessageDialog(null, " a2i: "+a2i);
				aux = Math.abs( (bi - ai) / 6 * ( fx(ai) + (4 * fx(a2i) ) + fx(bi) ) ); // formula
				System.out.println(" aux: " + aux);
				ai = bi;
				//a2i = bi;
				integralValue += Math.abs(aux);
				finalValue = integralValue;
			} while (bi < b);
			n++;
			ai = a;
			nextArea = finalValue;
			System.out.println(" partial: "+finalValue+" error: "+(nextArea-currentArea));
			integralValue = aux = 0;
		} while (n<4);
		JOptionPane.showMessageDialog(null, "N turns: " + n);
		return finalValue;
	}



 * 
 * */
