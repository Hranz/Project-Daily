!Programmer: Kristoffer Larson
!Date: February 18, 2014
!
!Description: Places values in array X, reverses the
!  order of the values from X into Y.
!
program SwapArray
   dimension X(5), Y(5)
   integer J
   do 10 I = 1, 5, 1
      X(I) = I
10 continue
   
   J = 5
   do 20 I = 1, 5, 1
      Y(I) = X(J)
      J = J - 1
20 continue

   do 30 I = 1, 5, 1
      write(*,*) X(I),Y(I)
30 continue
end program SwapArray
