package br.com.dc.ufc.NewtonCotes;

public class NewtonCotes {

	private double error;
	private double a = -0.3;
	private double b = 3.7;
	private int order, n = 1;
	double h = (b - a);
	private double limit = 0;
	private double integralValue = 0;

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
		 return Math.pow(x, 5) - 2*(Math.pow(x, 3)) + 4*x + 5; // função
		//return Math.pow(x, 3) - 2 * (Math.pow(x, 2)) + x; // função mais simples
	}

	public double TrapeziumMethod() {
		double x, ai, bi, aux = 0;
		do {
			ai = a;
			do {
				x = (h / n) / 2;
				// limit = 6*x - 4; // segunda integral de função mais simples
				limit *= (Math.pow((h / n), 3));
				limit /= 12;
				System.out.println("bi-ai = " + h / n);
				bi = ai + (h / n);
				n++;
				aux += (bi - ai) / 2 * (fx(ai) + fx(bi));
				ai = a + (n - 1) * (h / n);
				System.out.println("limite: " + limit);
				integralValue += aux;
				System.out.println("final: " + integralValue);
			} while (bi < b);
			integralValue = aux = 0;
		} while (Math.abs(limit) > error);
		return integralValue;
	}

	public void run() {
		switch (order) {
		case 1:
			TrapeziumMethod();
			break;
		default:
			System.out.println("Bye");
			break;
		}
	}

}
