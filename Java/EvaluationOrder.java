/*Programmer: Kristoffer Larson
 *Date: April 21, 2014
 *
 *Description: Using side effects of parameter evaluation to
 * detect order parameters are evaluated in when passing them
 * into a method.
 */

public class EvaluationOrder 
{
   public static void subroutine(int a, int b, int c)
   {
      System.out.printf("a is %d, b is %d, c is %d\n", a, b, c);
   }
   
   public static void main(String[] args)
   {
      int d = 2;
      subroutine(d++, d * 5, d--);
      d = 1;
      subroutine(d--, d + 5, d++);
      d = 1;
      subroutine(++d, d++, --d);
      d = 1;
      subroutine(++d, --d, d++);
   
   
      int a = 1;
      ++a;
      int b = a - 1;
      int c = b + 2;
      subroutine(a, b, c);
      
      //order of evaluation is chosen right to left in subroutine parameters.
   }
}
