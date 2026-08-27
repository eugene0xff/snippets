#lang sicp

(define (local-square x) (* x x))

(define (sqrt x)
    (sqrt-iter 1.0 x))
   
(define (sqrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x) x)))
        
(define (good-enough? guess x)
    (< (abs (- (square guess) x)) 0.001))
    
(define (improve guess x)
    (average guess (/ x guess)))
    
(define (square x) (* x x))
(define (average x y) (/ (+ x y) 2))

(sqrt 9)
(sqrt (+ 100 37))
(sqrt (+ (sqrt 2) (sqrt 3)))
(local-square (sqrt 1000))


(define (sqrt2 x)
    (define (square x) (* x x))
    (define (good-enough? guess x)
        (< (abs (- (square guess) x)) 0.001))
    (define (average x y) (/ (+ x y) 2))
    (define (sqrt-iter guess x)
        (if (good-enough? guess x)
            guess
            (sqrt-iter (improve guess x) x)))
    
    (sqrt-iter 1.0 x))

(sqrt2 9)
(sqrt2 (+ 100 37))
(sqrt2 (+ (sqrt2 2) (sqrt2 3)))
(local-square (sqrt2 1000))


(define (sqrt3 x)
    (define (square x) (* x x))
    (define (average x y) (/ (+ x y) 2))
    (define (good-enough? guess)
        (< (abs (- (square guess) x)) 0.001))
    (define (improve guess)
        (average guess (/ x guess)))
    (define (sqrt-iter guess)
        (if (good-enough? guess)
            guess
            (sqrt-iter (improve guess))))
     
     (sqrt-iter 1.0))
(sqrt3 9)
(sqrt3 (+ 100 37))
(sqrt3 (+ (sqrt3 2) (sqrt3 3)))
(local-square (sqrt3 1000))