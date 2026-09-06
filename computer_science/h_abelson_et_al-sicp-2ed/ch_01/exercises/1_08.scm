#lang sicp

;; [Exercise 1.8]
;; Newton's method for cube roots is based on the fact
;; that if y is an approximation to the cube root of x,
;; then a better approximation is given by the value
;;
;; x / (y * y) + 2y
;; ----------------
;;        3        
;;
;; Use this formula to implement a cube-root procedure
;; analogus to the square-root proceure.
 

;; [Solution]
(define (cbrt-iter guess x)
   (if (good-enough? guess x)
       guess
       (cbrt-iter (improve guess x) x)))

(define (improve guess x)
    (/ (+ (/ x (* guess guess)) (* 2 guess)) 3))

(define (good-enough? guess x)
    (< (abs (- (abs (cube guess)) (abs x))) 0.001))

(define (cube x) (* x x x))

(define (cbrt x)
    (cbrt-iter 1.0 x))
    

(cbrt 8)
(cbrt (- 8))
(cbrt 1)
(cbrt (- 1))
(cbrt 0)
(cbrt (- 0))
