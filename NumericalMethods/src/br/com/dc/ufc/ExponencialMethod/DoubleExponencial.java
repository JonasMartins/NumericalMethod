package br.com.dc.ufc.ExponencialMethod;

public class DoubleExponencial {

	private double a, b, tolerance, currentArea = 0, nextArea = 0, s, n = 1, h;

	private double aux = 0, finalValue, integralValue = 0;

	public DoubleExponencial(double a, double b, double tolerance) {
		this.a = a;
		this.b = b;
		this.tolerance = tolerance;
	}

	public double fx(double x) {
		//return 1 / (1 + (25 * Math.pow(x, 2))); // adequada?
		return Math.pow(x,3) + 2*(Math.pow(x, 2)) - 10 * x;
	}

	public double ws(double s) {
		return (0.5 * Math.PI * Math.cosh(s)) / Math.pow(Math.cosh(0.5 * Math.PI * Math.sinh(s)), 2);
	}

	public double xs(double s) {
		return (a + b) / 2 + (b - a) / 2 * Math.tanh(((Math.PI) / 2) * Math.sinh(s));
	}

	/*
	 * AGORA, FAZER INTEGRAL DE -s ATÉ s DE FX(S) COM ALGUM MÉTODO DE INTEGRAÇÃO
	 * ANTERIOR
	 */
	public double DoubleExponential() {
	  
	  n=1;
	  s=a;
	  	do{
	  		h = (b-a)/n;
	  		currentArea = nextArea;
	  		do{
			 aux = ws(s) * fx(xs(s));
			 integralValue+=aux;
			 finalValue=integralValue;
			 s+=h; 
	  		}while(s<b);
	  		s=a;
	  		nextArea = finalValue;
	  		aux=integralValue=0;
	  		n+=1;
	  		
	  	}while(Math.abs(nextArea-currentArea)>tolerance);
	  	System.out.println("tolerance: "+Math.abs(nextArea-currentArea));
	  	System.out.println("N: "+n);
	  	return finalValue;
  }

	public void run() {

		System.out.println("Integral: " + DoubleExponential());
	}

}
