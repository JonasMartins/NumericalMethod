package br.com.dc.ufc.ExponencialMethod;

public class DoubleExponencial{

  private double a,b,tolerance,currentArea=0, nextArea=0,ai,bi;
  private final double m = 9*(Math.pow(10,15)); //example of N
  private final double s = Math.log( (Math.log(4*m) * (2/Math.PI)));


  private double aux=0,finalValue, integralValue=0;

  public DoubleExponencial(double a, double b, double tolerance){
    this.a=a;
    this.b=b;
    this.tolerance=tolerance;
  }

  /* fx = x⁵ - 10x³ + sen(x) -5x */

  public double fx(double x){
    //return Math.pow(x,5) - 10*( (Math.pow(x,3) + Math.sin(x)) - 5*x );
    return 1/(1+(25*Math.pow(x,2)));
    //return 1/Math.sqrt(x);
    //return Math.sqrt(1-Math.pow(x,2));
  }


  public double xs(double s){
      //return (a+b)/2 + ( (b-a)/2 * (Math.tanh( ((Math.PI)/a) * Math.sinh(s)) ) );
    return  (a+b)/2 + (b-a)/2 * Math.tanh( ((Math.PI)/a) * Math.sinh(s)) *
    ( Math.cosh(s)/Math.pow(Math.cosh(s),2) * (Math.PI/2 * Math.sinh(s)) );

  }

  /*  AGORA, FAZER INTEGRAL DE -s ATÉ s DE FX(S) COM ALGUM MÉTODO DE INTEGRAÇÃO ANTERIOR  */
  public double TrapeziumMethod() {
    //b=xs(b); // s positivo
    double h = s+s; // -s e s do gráfico dinossauro.
    int n = 1; /* diferencial... */
    do {
      currentArea = nextArea;
      ai = (-s); // parte de -s
      do {
        bi = ai + (h / n);
        n++;
        aux += (bi - ai) / 2 * (fx(xs(ai)) + fx(xs(bi))); // formula f(s(x))
        ai = a + (n - 1) * (h / n);
        integralValue += aux;
        finalValue = integralValue;
      } while (bi < s);
      nextArea = finalValue;
      System.out.println("-> "+finalValue);
      integralValue = aux = 0;
      if (n==30)
        tolerance = 1000;
    } while ( Math.abs(nextArea - currentArea) > tolerance); //limite de erro (Math.abs(nextArea - currentArea) > tolerance )
    System.out.println("N turns: " + n);
    System.out.println("tolerance: " + Math.abs(nextArea - currentArea));
    System.out.println("\n");
    return finalValue;
  }

  public void run(){

    double dxs_ds = (b-a)/4 * (Math.PI); // dx(s)/ds .....

    System.out.println("N "+m);
    System.out.println("-s "+(s*(-1)));
    System.out.println("+s "+s);

    System.out.println("Variação das Áreas: "+"\n");


    //System.out.println("Integral: "+ dxs_ds * Math.round(OneEightSimpson())) ;
    System.out.println("Integral: "+ dxs_ds *TrapeziumMethod()) ;
  }


}



















