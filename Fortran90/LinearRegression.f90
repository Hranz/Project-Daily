!Programmer:Kristoffer Larson
!Date: February 2, 2014
!
!Description: This was originally given in one of my classes
!  and I decided to adjust it so that it would run as a 
!  Fortran90 program. There are some adjustments that need 
!  to be made before it's fully functional.


      DIMENSION X(52), Y(2,50), LITERL(2)
      DOUBLE PRECISION S1,S2,S3,S4,S5,T,S,B,D,R,E1,E2,BBAR
      WRITE (*,10)
10    FORMAT('0',1X,'*   *   *  LINEAR REGRESSION ANALYSIS  *   *   *',//)
      WRITE (*,20)
20    FORMAT(1X,'HOW MANY PAIRS TO BE ANALYZED?'$)
      READ (5,*) N
      IF (N.GT.50) GOTO 70
      WRITE (*,30)
30    FORMAT(//1X,'Enter one pair at a time')
      WRITE (*,40)
40    FORMAT(1X,'and separate X from Y with a comma.'//)
      WRITE (*,50)
50    FORMAT(1X,'Enter pair number one : '$)
      READ (5,*) X(1), Y(1,1)
         DO 60 I=2,N
         WRITE (*,55) I
55       FORMAT(1X,'Enter pair number',I3,' : '$)
         READ (5,*) X(I), Y(1,I)
60       CONTINUE
      GOTO 90
70    WRITE (*,80)
80    FORMAT(1X,'At present this program can only handle 50 data pairs.')
      STOP
90    WRITE (*,100)
100   FORMAT(1X,'Would you like to review the data?'$)
      READ (5,110) LITERL(1)
110   FORMAT(A1)
      IF (LITERL(1) == 78) GOTO 140
         DO 130 I=1,N
         WRITE (*,120) I, X(I), Y(1,I)
120      FORMAT(1X,'DATA PAIR',I3,').  ',2F20.10)
130      CONTINUE
140   WRITE (*,150)
150   FORMAT(1X,'Would you like to make any changes?'$)
      READ (5,110) LITERL(1)
      !IF (LITERL(1) == 78) GOTO 200
      WRITE (*,160)
160   FORMAT(1X,'To change a data pair, enter the')
      WRITE (*,165)
165   FORMAT(1X,'Pair Number and the new X, Y pair.')
      WRITE (*,180)
180   FORMAT('0',1X,'How many changes shall we make?'$)
      READ (5,*) ICHANG
         DO 190 I=1, ICHANG
         WRITE (*,185)
185      FORMAT(1X,'CHANGE NUMBER',I4,' : '$)
         READ (5,*) C1, C2, C3
!         X(C1)=C2
!         Y(1,C1)=C3
190      CONTINUE
      GOTO 90
200      DO 210 I=1,N
         S1=S1+X(I)
         S2=S2+Y(1,I)
         S3=S3+X(I)*Y(1,I)
         S4=S4+X(I)*X(I)
         S5=S5+Y(1,I)+Y(1,I)
210      CONTINUE
      T=N*S4-S1*S1
      S=(N*S3-S1*S2)/T
      B=(S4*S2-S1*S2)/T
         DO 220 I=1,N
         Y(2,I)=S*X(I)+B
         D=D+(Y(2,I)-Y(1,I))**2
220      CONTINUE
      D=D/(N-2)
      E1=DSQRT(D*N/T)
      E2=DSQRT(D/N*(1+S1*S1/T))
      R=(N*S3-S1*S2)/(DSRT(ABS(((N*S4-ABS(S1)**2))*(N*S5-ABS(S2)**2))))
      WRITE (*,230)
230   FORMAT(////,10X,'X-VALUE',20X'Y-OBS',22X,'Y-CALC')
      WRITE (*,235)
235   FORMAT(10X,'=======',20X,'=====',22X,'======')
         DO 250 I=1,N
         WRITE (*,240) X(I), Y(1,I), Y(2,I)
240      FORMAT(F22.10,2F27.10)
250      CONTINUE
      WRITE (*,260) S
260   FORMAT(//,1X,'SLOPE = ',D22.16)
      WRITE (*,270) E1
270   FORMAT(1X,'THE ERROR IN THE SLOPE IS +/- ',D22.16)
      WRITE (*,280) B
280   FORMAT(//,1X,'INTERCEPT = ',D22.16)
      WRITE (*,285) E2
285   FORMAT(1X,'THE ERROR IN THE INTERCEPT IS +/- ',D22.16)
      !LITERL(2)='+'
      !IF (ABS(B).NE.B) LITERL(2)='-'
      WRITE (*,290)
290   FORMAT(//,1X,'EQUATION FOR THE BEST LINEAR FIT IS : ')
      BBAR=ABS(B)
      WRITE (*,295) S,LITERL(2),BBAR
295   FORMAT(1X,'Y(X) =',D25.16,' * X ',A1,D25.16,///)
      WRITE (*,296) R
296   FORMAT(' LINEAR CORRELATION COEFFICIENT =',D22.16)
      STOP 'LINEAR... Execution completed'
      End
