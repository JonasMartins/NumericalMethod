package br.com.dc.ufc.GaussQuadrature;

import javax.swing.JOptionPane;

public class GaussChebshev{

  private int order;

  public GaussChebshev(int order){

    this.order=order;
  }

  public double fx(double x) {
	  return Math.pow(x,3) + 2*(Math.pow(x, 2)) - 10 * x;
  }


  public double twoPoints(){
      return (fx(0.707107) * 1.5708)
              +(fx(0.707107) * 1.5708);
  }

  public double threePoints(){
      return (fx(-0.92388) *  1.0472)
              + (fx(0) * 1.0472)
              + (fx(0.92388) * 1.0472);
  }

  public double fourPoints(){
      return (fx(-0.382683) *  0.785398)
              + (fx(-0.92388) * 0.785398)
              + (fx(0.382683) *  0.785398)
              + (fx(0.92388) *  0.785398);
  }

  public double fivePoints(){
      return (fx(-0.587785) *  0.628319)
              + (fx(0.951057) * 0.628319)
              + (fx(0) * 0.628319)
              + (fx(0.587785) *  0.628319)
              + (fx(0.951057) *  0.628319);
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