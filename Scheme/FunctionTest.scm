;Programmer: Kristoffer Larson
;Date: February 11, 2014
;
;Description: A test of a simple scheme program.
;

(define test 
  (lambda(a b c d e)
    (+ (/ a b) (* c d e))))
    
(test 6 13 22 5 9.2)
