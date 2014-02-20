//    Programmers: Kristoffer Larson
//    Date: February 19, 2014
//    
//    Description: A translation of a fortran linear regression program.
//
//
//
//    Irvin Levy (Gordon College) Linear Regression Package
//    
//    *  *  *  *  VARIABLE LIST  *  *  *  *
//             S1 - Sum of X values
//             S2 - Sum of Y values
//             S3 - Sum of X * Y
//             S4 - Sum of X * X
//             S5 - Sum of Y * Y
//             D  - Sum of Y(obs) - Y(calc) squared
//             S  - Slope
//             B  - Y-intercept
//             E1 - Error in the slope
//             E2 - Error in the intercept
//             T  - Beta function for linear regression
//             R  - Correlation coefficient
//    
//    Error function uses (N-2) weigthing
// 
// 
// 
import java.util.Scanner;

public class LinearRegression {
   public static void main(String[] args) {
      double[] x = new double[52]; double[][] y = new double[2][50]; String in, sign;
      double S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0, T = 0, S = 0; 
      double B = 0, D = 0, R = 0, E1 = 0, E2 = 0, BBAR = 0;
      
      Scanner input = new Scanner(System.in);
      System.out.printf("0 *   *   *   LINEAR REGRESSION ANALYSIS   *   *   *\n\n");
      System.out.printf(" HOW MANY PAIRS TO BE ANALYZED?");
      int n = input.nextInt();
      input.nextLine();
      
      if (n > 50) {
      System.out.printf(" At present this program can only handle 50 data pairs.");
      System.exit(1);
      }
      
      System.out.printf("\n\n Enter one pair at a time");
      System.out.printf("\n and separate X from Y with a comma.\n\n");
      System.out.printf(" Enter pair number one : ");
      String point = input.nextLine();
      String[] splits = point.split(",");
      x[0] = Double.parseDouble(splits[0]);
      y[0][0] = Double.parseDouble(splits[1]);
      
      for (int i = 1; i < n; i++) {
         System.out.printf(" Enter pair number %d : ", i + 1); 
         point = input.nextLine();
         splits = point.split(",");
         x[i] = Double.parseDouble(splits[0]);
         y[0][i] = Double.parseDouble(splits[1]);
      }
      
      boolean test = true;
      while (test) {
         System.out.printf(" Would you like to review the data?");
         in = input.next();
         if (!(in.compareTo("N") == 0)) {
            for (int i = 0; i < n; i++) {
            System.out.printf(" DATA PAIR %d).%20.10f%20.10f\n", i + 1, x[i],y[0][i]);
            }
         }
         System.out.printf(" Would you like to make any changes?");
         in = input.next();
         if (!(in.compareTo("N") == 0)) {
            System.out.printf(" To change a data pair, enter the\n");
            System.out.printf(" Pair Number and the new X, Y pair.\n");
            System.out.printf("0 How many changes shall we make?");
            int iChang = input.nextInt();
            input.nextLine();
            int change;
            for (int i = 0; i < iChang; i++) {
               System.out.printf("CHANGE NUMBER\n");
               change = input.nextInt();
               point = input.nextLine();
               splits = point.split(",");
               x[change - 1] = Double.parseDouble(splits[0]);
               y[0][change - 1] = Double.parseDouble(splits[1]);
            }
         } else 
            test = false;
      }
      for (int i = 0; i < n; i++) {
         S1 = S1 + x[i];
         S2 = S2 + y[0][i];
         S3 = S3 + x[i] * y[0][i];
         S4 = S4 + x[i] * x[i];
         S5 = S5 + y[0][i] * y[0][i];
      }
      T = n * S4 - S1 * S1;
      S = (n * S3 - S1 * S2) / T;
      B = (S4 * S2 - S1 * S3) / T;
      for (int i = 0; i < n; i++) {
         y[1][i] = S * x[i] + B;
         D = D + Math.pow((y[1][i] - y[0][i]), 2);
      }
      D = D / (n - 2);
      E1 = Math.sqrt(D * n / T);
      E2 = Math.sqrt(D / n * (1 + S1 * S1 / T));
      double R1 = (n * S4 - Math.pow(Math.abs(S1), 2));
      double R2 = (n * S5 - Math.pow(Math.abs(S2), 2));
      R = (n * S3 - S1 * S2) / (Math.sqrt(Math.abs(R1 * R2)));
      
      System.out.printf("\n\n\n\n%10s%20s%22s\n","X-VALUE","Y-OBS","Y-CALC");
      System.out.printf("%10s%20s%22s\n", "=======", "=====", "======");
      
      for (int i = 0; i < n; i++) {
         System.out.printf("%15.10f %21.10f %20.10f\n", x[i], y[0][i], y[1][i]);
      }
      
      System.out.printf("\n\n SLOPE = %22.16f\n", S);
      System.out.printf(" THE ERROR IN THE SLOPE IS +/- %22.16f\n", E1);
      System.out.printf("\n\n INTERCEPT = %22.16f\n", B);
      System.out.printf(" THE ERROR IN THE INTERCEPT IS +/- %22.16f\n", E2);
      
      sign = "+";
      if(Math.abs(B) != B) sign = "-";
      
      System.out.printf("\n\n EQUATION FOR THE BEST LINEAR FIT IS : \n");
      BBAR = Math.abs(B);
      System.out.printf(" Y(X) = %25.16f * X %s %25.16f\n\n\n", S, sign, BBAR);
      System.out.printf(" LINEAR CORRELATION COEFFICIENT = %22.16f\n", R);
      System.out.print("LINEAR... Execution completed");
   }
}
