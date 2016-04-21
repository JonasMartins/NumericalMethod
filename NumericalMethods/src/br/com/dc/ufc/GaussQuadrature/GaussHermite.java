package br.com.dc.ufc.GaussQuadrature;

import javax.swing.JOptionPane;

public class GaussHermite{
  
  private int order;
  private double integralValue=0;
  
  public GaussHermite(int order){
    
    this.order=order;
  }
  
  public double fx(double x) {
    return Math.pow(x, 2);
  }
  
  
  public double twoPoints(){
      return (fx(- 0.7071067811) * 0.8862269254)
              +(fx(0.7071067811) * 0.8862269254);
  }
  
  public double threePoints(){
      return (fx(-0.1224744871) *  0.2954089751)
              + (fx(0.1224744871) * 0.2954089751)
              + (fx(0) *  0.1181635900);  
  } 

  public double fourPoints(){
      return (fx(-0.1650680123) *  0.8131283544)
              + (fx(0.1650680123) * 0.8131283544)
              + (fx(-0.5246476232) *  0.8049140900)  
              + (fx(0.5246476232) *  0.8049140900);
  }

  public double fivePoints(){
      return (fx(-0.958572) *  0.393619)
              + (fx(0.958572) * 0.393619)
              + (fx(0) * 0.945309)
              + (fx(-2.02018) *  0.0199532)  
              + (fx(2.02018) *  0.0199532);
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