;Programmer: Kristoffer Larson
;Date: March 9, 2014
;
;Description: fsm1 is a finite state machine that evaluates if there 
;   is a series containing 0's and 1's in any pattern as long as there
;   are only two 1's in the list. floatingPt? calls fsmFP from the first
;   state, converting a string to a list of characters. fsmFP is a finite
;   state machine that evaluates if a list models a floating point number
;   of type [( +|-)]D.D+[e(+|-)(D | DD | DDD)].
;

(define fsm1 
  (lambda (x state)
     (cond
       ((= state 0)
         (cond
           ((null? x) #f)
           ((= (car x) 0) (fsm1 (cdr x) 0))
           ((= (car x) 1) (fsm1 (cdr x) 1))
           (else #f))) 
       ((= state 1) 
         (cond 
           ((null? x) #f)
           ((= (car x) 0) (fsm1 (cdr x) 1))
           ((= (car x) 1) (fsm1 (cdr x) 2))
           (else #f)))
       ((= state 2)
         (cond
           ((null? x) #t)
           ((= (car x) 0) (fsm1 (cdr x) 2))
           ((= (car x) 1) #f)
           (else #f)))
       (else #f))
    ))


(define fsmFP
  (lambda (x state)
    (cond
      ((= state 0) 
        (cond
          ((null? x) #f)
          ((equal? (car x) #\+) (fsmFP (cdr x) 1))
          ((equal? (car x) #\-) (fsmFP (cdr x) 1))
          ((char-numeric? (car x)) (fsmFP (cdr x) 2))
          (else #f)))
      ((= state 1) 
        (cond
          ((null? x) #f)
          ((char-numeric? (car x)) (fsmFP (cdr x) 2))
          (else #f)))
      ((= state 2) 
        (cond
          ((null? x) #f)
          ((equal? (car x) #\.) (fsmFP (cdr x) 3))
          (else #f)))
      ((= state 3)
        (cond
          ((null? x) #f)
          ((char-numeric? (car x)) (fsmFP (cdr x) 4))
          (else #f)))
      ((= state 4) 
        (cond
          ((null? x) #t)
          ((char-numeric? (car x)) (fsmFP (cdr x) 4))
          ((equal? (car x) #\e) (fsmFP (cdr x) 5))
          (else #f)))
      ((= state 5) 
        (cond
          ((null? x) #f)
          ((equal? (car x) #\+) (fsmFP (cdr x) 6))
          ((equal? (car x) #\-) (fsmFP (cdr x) 6))
          (else #f)))
      ((= state 6) 
        (cond
          ((null? x) #f)
          ((char-numeric? (car x)) (fsmFP (cdr x) 7))
          (else #f)))
      ((= state 7) 
        (cond
          ((null? x) #t)
          ((char-numeric? (car x)) (fsmFP (cdr x) 8))
          (else #f)))
      ((= state 8) 
        (cond
          ((null? x) #t)
          ((char-numeric? (car x)) (fsmFP (cdr x) 9))
          (else #f)))
      ((= state 9) 
        (cond
          ((null? x) #t)
          (else #f)))
      (else #f))))

(define floatingPt?
    (lambda (s)
         (fsmFP (string->list s) 0)))
