#lang sicp

;; Exercise 1.3
;; Define a procedure that takes three numbers as arguments
;; and returns the sum of the sequares of the two larger numbers


;; Solution
(define (square x) (* x x))
(define (sum-of-squares x y) (+ (square x) (square y))) 
(define (min2 x y) (if (< x y) x y))
(define (min3 x y z) (min2 (min2 x y) z))
(define (max2 x y) (if (> x y) x y))
(define (max3 x y z) (max2 (max2 x y) z))
(define (first-largest x y z) (max3 x y z))
(define (second-largest x y z) (- (+ x y z) (first-largest x y z) (min3 x y z)))
(define (f x y z)
    (sum-of-squares (first-largest x y z) (second-largest x y z)))

(f 1 2 3)
