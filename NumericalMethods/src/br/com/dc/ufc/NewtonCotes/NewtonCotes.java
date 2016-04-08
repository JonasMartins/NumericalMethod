package br.com.dc.ufc.NewtonCotes;

import javax.swing.JOptionPane;

public class NewtonCotes {

	private double error;
	private double a = -0.1;
	private double b = 3.0;
	private int order, n;
	double h = (b - a);
	private double limit = 0;
	private double integralValue = 0, finalValue = 0;
	private double x, ai, bi, a2i, a3i, aux = 0;

	/* fx = x⁵ - 2x³ + 4x +5 */
	/* f'x = 5x⁴ - 6x² + 4 */
	/* f''x = 20x³ - 12x */
	/* f'''x = 60x² -12 */
	/* f''''x = 120x */
	/* f'''''x = 120 */

	public NewtonCotes(int order, double error) {

		this.order = order;
		this.error = error;
	}

	public double fx(double x) {
		return Math.pow(x, 5) - 2 * (Math.pow(x, 3)) + 4 * x + 5; // função
		// return Math.pow(x, 3) - 2 * (Math.pow(x, 2)) + x; // função mais
		// simples
	}

	public double TrapeziumMethod() {
		n = 1; /* diferencial... */
		do {
			ai = a;
			do {
				x = (h / n) / 2;
				limit = 20 * (Math.pow(x, 3)) - 12 * x; // segunda integral
				limit *= (Math.pow((h / n), 3));
				limit /= 12;
				bi = ai + (h / n);
				n++;
				aux += (bi - ai) / 2 * (fx(ai) + fx(bi));
				ai = a + (n - 1) * (h / n);
				integralValue += aux;
				finalValue = integralValue;
				// System.out.println("final: " + integralValue);
			} while (bi < b);
			integralValue = aux = 0;
		} while (Math.abs(limit) > error);
		JOptionPane.showMessageDialog(null, "N turns: " + n);
		return finalValue;
	}

	public double OneEightSimpson() {
		n = 2; /* diferencial... */

		do {
			ai = a;
			do {
				x = (h / n) / 2;
				limit = 120 * x; //  derivada quarta
				limit *= (Math.pow((h / n), 5));
				limit /= 2880;
				bi = ai + (h / n);
				a2i = (bi - ai) / 2;
				n++;
				aux += (bi - ai) / 6 * (fx(ai) + 4 * (fx(a2i)) + fx(bi)); // formula
				ai = a + (n - 1) * (h / n);
				integralValue += aux;
				finalValue = integralValue;
				// System.out.println("final: " + integralValue);
			} while (bi < b);
			integralValue = aux = 0;
		} while (Math.abs(limit) > error);
		JOptionPane.showMessageDialog(null, "N turns: " + n);
		return finalValue;
	}
	public double ThreeEightSimpson() {
		n = 3; /* diferencial... */

		do {
			ai = a;
			do {
				x = (h / n) / 2;
				limit = 120 * x; //  derivada quarta
				limit *= (Math.pow((h / n), 5));
				limit /= 6480;
				bi = ai + (h / n);
				a2i = (bi - ai) / 3;
				a3i = 2*a2i;
				n++;
				aux += (bi - ai) / 8 * (fx(ai) + 3 * (fx(a2i)) + 3 * (fx(a3i)) + fx(bi)); // formula
				ai = a + (n - 1) * (h / n);
				integralValue += aux;
				finalValue = integralValue;
				// System.out.println("final: " + integralValue);
			} while (bi < b);
			integralValue = aux = 0;
		} while (Math.abs(limit) > error);
		JOptionPane.showMessageDialog(null, "N turns: " + n);
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
