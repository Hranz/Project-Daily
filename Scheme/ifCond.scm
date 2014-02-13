;Programmer: Kristoffer Larson
;Date: February 13, 2014
;
;Description: A test of cond and if functions.
;

(define ifCond
  (lambda(a b)
    (cond
      ((= a 10) "10")
      ((= b 6) "6")
      ((= a b) (if (< a 2) 
                  "two" 
                  5))
      (else "else")))
)
    
(ifCond 4 5)
