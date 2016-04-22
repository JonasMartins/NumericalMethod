package br.com.dc.ufc.GaussQuadrature;

import javax.swing.JOptionPane;

public class GaussLaguerre{

  private int order;

  public GaussLaguerre(int order){

    this.order=order;
  }

  public double fx(double x) {
    return Math.sin(x);
  }


  public double twoPoints(){
      return (fx(0.58578) * 0.85355)
              +(fx(34142) * 0.14644);
  }

  public double threePoints(){
      return (fx(0.415775) *  0.711093)
              + (fx(2.29428) * 0.278518)
              + (fx(6.28995) *  0.0103893);
  }

  public double fourPoints(){
      return (fx(0.322548) *  0.603154)
              + (fx(1.74576) * 0.357419)
              + (fx(4.53662) *  0.0388879)
              + (fx(9.39507) *  0.000539295);
  }

  public double fivePoints(){
      return (fx(0.26356) *  0.521756)
              + (fx(1.4134) * 0.398667)
              + (fx(3.59643) * 0.0759424)
              + (fx(7.08581) *  0.00361176)
              + (fx(12.6408) *  0.00002337);
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