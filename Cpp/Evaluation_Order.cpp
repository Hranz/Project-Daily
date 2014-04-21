/*Programmer: Kristoffer Larson
 *Date: April 21, 2014
 *
 *Description: Using side effects of parameter evaluation to
 * detect order parameters are evaluated in when passing them
 * into a method.
 */

#include <iostream>


int subroutine(int a, int b, int c)
{
   std::cout << "a is " << a << " b is " << b << " c is " << c << std::endl;
   
}

int main(void)
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
   int c = b + 1;
   subroutine(a, b, c);
   //order of evaluation is chosen at random in subroutine parameters.
}
