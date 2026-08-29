#lang sicp

(define (abs x)
    (cond ((> x 0) x)
          ((= x 0) 0)
          ((< x 0) (- x))))
(abs 1)
(abs (- 1))
(abs 0)


(define (abs2 x)
    (cond ((< x 0) (- x))
          (else x)))
(abs2 1)
(abs2 (- 1))
(abs2 0)


(define (abs3 x)
    (if (< x 0)
        (- x)
        x))
(abs3 1)
(abs3 (- 1))
(abs3 0)


(define x 7)
(and (> x 5) (< x 10))


(define (gt-or-eq1 x y) (or (> x y) (= x y)))
(gt-or-eq1 1 1)
(gt-or-eq1 1 0)
(gt-or-eq1 0 1)


(define (gt-or-eq2 x y) (not (< x y)))
(gt-or-eq2 1 1)
(gt-or-eq2 1 0)
(gt-or-eq2 0 1)