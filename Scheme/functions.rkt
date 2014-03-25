;Programmer: Kristoffer Larson
;Date: March 24, 2014
;
;Description: Problem sets in Scheme

;Problem Set 1
;contains-digit? uses digit-test as a helper function
(define contains-digit?
  (lambda (s)
    (cond ;input must be a string
      ((string? s) (digit-test (string->list s))) ;breaks up string into a list
      (else #f) ;returns false if it's not a string
    )
  )
)
    
(define digit-test
  (lambda (lst)
    (cond
      ((null? lst) #f) ;if the list is empty then there are no digits
      ((char-numeric? (car lst)) #t) ;checks if there's a digit at the beginning of the list
      (else (digit-test (cdr lst)))  ;checks the remaining list has a digit
    )
  )
)

;getStringsWithDigits uses filter as a helper function
(define getStringsWithDigits
  (lambda (lst)
    (cond
      ((list? lst) (filter contains-digit? lst)) ;filters out any string without a digit
      (else "Invalid input. Enter a list.") ;if lst isn't a list then invalid input
    )
  )
)

;Problem Set 2
;prime? returns true if prime number
;uses   as a helper function
(define prime?
  (lambda (n)
    (if (number? n) 
        (cond
          ((= 2 n) #t)
          ((not (any-divisors 2 n)) #t)
          (else #f)
        )
    #f)
  )
)

;returns true of there is a divisor of n between x and n-1, including x and n-1, and returns false otherwise
(define any-divisors
  (lambda (x n)
    (cond
      ((> x n) (any-divisors n x))
      ((= (- n 1) x) #f)
      ((= (modulo n x) 0) #t)
      (else (any-divisors (+ x 1) n))
    )
  )
)

;returns a list of numbers from n to m, if n > m returns an empty list
(define range-
  (lambda (n m)
    (if (or (< n m) (= n m)) 
        (cons n (range- (+ 1 n) m))
        '()
    )
  )
)

;(filter prime? (range- 2 10000)) ;prints a list of prime numbers from 2 to 10000 inclusive

;(foldl + 0 (map (lambda (x) (* x x)) (filter prime? (range- 10 1000)))) ;Finds the sum of the squares of all primes between   10 and 1000


;Problem Set 3
;a two dimensional matrix may look like ((1 5 3 9) (6 17 2 1) (-1 3 5 4))

;Finds the sum of the kth row of matrix x
(define rowsum2D
  (lambda (k x)
      (if (and (matrix2D? 2 x) (list? (nth-element k x)))
          (foldl + 0 (nth-element k x))
          "index out of range"
      )
  )
)

;Finds the sum of the kth column of matrix x
(define colsum2D
  (lambda (k x)
    (if (and (matrix2D? x) (list? (nth-element k x)))
        (cond
          ((null? x) 0)
          (else (+ (nth-element k (car x)) (colsum2D k (cdr x))))
        )
        "index out of range"
    )
  )
)

(define diagsum
  (lambda (x)
    (if (sqrmatrix? (length x) x) 
        (diagadd (length x) x)
        "Not a square matrix"
    )
  )
)

(define sqrmatrix?
  (lambda (a lst)
    (cond
      ((null? lst) #t)
      ((= a (length (car lst))) (sqrmatrix? a (cdr lst)))
      (else #f)
    )
  )
)

(define diagadd
  (lambda (a lst)
    (cond
      ((= a 0) 0)
      (else (+ (nth-element a (nth-element a lst)) (diagadd (- a 1) lst)))
    )
  )
)

;checks if it's an appropriate matrix
(define matrix2D?
  (lambda (x)
    (cond
      ((= (length x) 1) #t)
      ((collength 2 x) #t)
      (else #f)
    )
  )
)
  
(define collength
  (lambda (a lst)
    (cond
      ((= (length lst) a) #t)
      ((= (length (nth-element a lst)) (length (nth-element (- a 1) lst))) 
       (collength (+ a 1) lst))
      (else #f)
    )
  )
)

;Finds nth element
(define nth-element
  (lambda ( n lst)
    (cond
      ( (or ( < n 1) (> n ( length lst) ) ) #f)
      ( ( = n 1) (car lst))
      ( else ( nth-element ( - n 1) (cdr lst)))
    )
  )
)
