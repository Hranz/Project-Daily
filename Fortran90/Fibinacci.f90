!Programmer: Kristoffer Larson
!Date: February 17, 2014
!
!Description: Calculates and prints numbers in the fibinacci sequence.
!  After 45 numbers the calculations get strange because they go outside
!  the limit of integers in fortran90.
!
program Fibinacci
   integer first,second,temp
   first = 0
   second = 1
   write (*,*) 'How many numbers in the Fibinacci Sequence do you want?'
   read (5,*) IN
   write (*,*) first
   write (*,*) second
      do 10 I=0,IN
      write (*,*) first + second
      temp = first
      first = second
      second = temp + second
10    continue
  
end program Fibinacci


