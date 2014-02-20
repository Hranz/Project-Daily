;Programmer: Kristoffer Larson
;Date: February 20, 2014
;
;Description: Sorts three comparable values.
; Returns a list of the sorted values.

(define sortStuff
  (lambda(x y z)
    (cond 
      ((<= x y z) (list x y z))
      ((<= x z y) (list x z y))
      ((<= y x z) (list y x z))
      ((<= y z x) (list y z x))
      ((<= z x y) (list z x y))
      ((<= z y x) (list z y x))
    )
  )
)
    
(sortStuff 2 1 5)
