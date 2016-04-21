package br.com.dc.ufc.GaussQuadrature;
/*
 * 		Implementar e testar as quadraturas de Gauss-Legendre
 *  	para integração de funções. O método que retorna o valor da
 *   	função para um dado x deve ser programado e incorporado ao
 *    	código. A entrada de dados deve ser: 1) Valor do início do
 *     	intervalo de integração; 2) Valor do final do intervalo de
 *      integração; 3) Valor da tolerância (potência negativa de 10). 
 *      O output deve ser o valor da integral da função para os limites
 *      de integração fornecidos. O usuário deve ter a opção de escolher
 *      o número de pontos de Legendre a serem usados no somatório:1 a 5. 
 *      Anexe também um arquivo pdf com os seguintes desenvolvimentos: 
 *       
 *      1) O polinômio de Legendre de grau 4; 
 *      2) O cálculo das raízes do 
 *      polinômio do ítem 1); 
 *      3) Os polinômios de interpolação de Lagrange 
 *      associados aos pontos amostrais do item 2);
 *      e o cálculo dos pesos associados aos pontos amostrais do item 2).
 *      
 * 	
 * */

import javax.swing.JOptionPane;

	/*
	 * 	Funcão usada: f(x) = 5x⁹ - x⁵ + x³ -10 
	 * 
	 * */
	
public class GaussLegendre {

	private double xa;
	private double xb;
	@SuppressWarnings("unused")
	private double error;
	private int order;
	private double integralValue=0;

	public GaussLegendre(double a, double b, double tolerance, int degree){
		this.xa=a;
		this.xb=b;
		this.error=tolerance;
		this.order=degree;
	}
	
	
	public double fx(double x) {
		return Math.pow(x, 9)*5 - Math.pow(x, 5) + Math.pow(x, 3) - 10;
		//return 1/x;
	}
	
	public double tx(double t){
		
		return ((xb-xa)*t + (xb+xa))/2;
	}
	
	public double tx(){
		return (xb-xa)/2;
		
	}
	
	public double twoPoints(){/*	weights = 1 */
		 
		integralValue = fx(tx(-0.5773502))+fx(tx(0.5773502));
		
		return integralValue;
	}
	
	public double threePoints(){
		 
		integralValue = (fx(tx(-0.7745966)) * 0.5555) + (fx(tx(0)) * 0.8888) + ( fx(tx(0.7745966) * 0.5555));
		
		return integralValue;
	}
	public double fourPoints(){
		 
		integralValue = (fx(tx(-0.861136)) * 0.3478) + (fx(tx(-0.339981)) * 0.6521) + 
				(fx(tx(0.861136)) * 0.3478) + (fx(tx(0.339981)) * 0.6521);
		
		return integralValue;
	}
	public double fivePoints(){
		 
		integralValue = (fx(tx(-0.906179)) * 0.2369) + (fx(tx(-0.538469)) * 0.4786) + 
				(fx(tx(0)) * 0.5688) + (fx(tx(0.906179)) * 0.2369) + (fx(tx(0.538469)) * 0.4786);
		
		return integralValue;
	}
	
	public void run() {
		switch (order) {
		case 2:
			JOptionPane.showMessageDialog(null, "Integral: " + twoPoints());
			break;
		case 3:
			JOptionPane.showMessageDialog(null, "Integral: " + threePoints());
			break;	
		case 4:
			JOptionPane.showMessageDialog(null, "Integral: " + fourPoints());
			break;	
		case 5:
			JOptionPane.showMessageDialog(null, "Integral: " + fivePoints());
			break;
		default :
			JOptionPane.showMessageDialog(null, "Inputs Valids only 2-5! ");
			break;
		}
	}

	
	
}
