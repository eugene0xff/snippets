#lang sicp

;; [Exercise 1.7]       
;; The 'good-enough?' test use in computing square roots
;; will not be very effective for finding the square roots
;; of very small numbers.
;; Also, in real computers, arithmetic operations are almost always
;; performed with limited precision.
;; This makes our test inadequate for very large numbers.
;; Explain these statements, with examples showing
;; how the test fails for small and large numbers.
;; An alternative strategy for implementing 'good-enough?'
;; is to watch how 'guess' changes from one iteration to the next
;; and to stop when the change is a very small fraction of the 'guess'
;; Design a square-root procedure that uses this kind of end test.
;; Does this work better for small and large numbers?


;; [Solution]
;; DEFAULT
(define (sqrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x) x)))

(define (improve guess x)
    (average guess (/ x guess)))

(define (average x y) (/ (+ x y) 2))

(define (good-enough? guess x)
    (< (abs (- (square guess) x)) 0.001))

(define (square x) (* x x))

(define (sqrt x)
    (sqrt-iter 1.0 x))


;; MAIN CONST
(define K-EXP-INDEX 101)

;; UTILITY
(define (max x y) (if (> x y) x y))

(define (pow10 x)
    (define (pow-pos-iter counter accum)
        (if (= 0 counter)
            accum
            (pow-pos-iter (- counter 1) (* accum 10))))
            
    (define (pow-neg-iter counter accum)
        (if (= 0 counter)
            accum
            (pow-neg-iter (+ counter 1) (/ accum 10))))
    
    (if (> x 0)
        (pow-pos-iter x 1.0)
        (pow-neg-iter x 1.0)))

(define K-EPSILON (pow10 (- (+ K-EXP-INDEX 1))))

(define (are-equal x y)
    (< (abs (- x y)) K-EPSILON))
(define (are-large-equal x y)
    (< (/ (abs (- x y)) (abs (max x y))) 0.001))

(define (ASSERT condition str)
    (display (if condition "[ ok ]" "[fail]")) (display " ") (display str) (display "\n"))

(define num1 (pow10 (- K-EXP-INDEX))) ;; small
(define num2 (pow10 K-EXP-INDEX))     ;; large


;; FAIL
;; small numbers
(ASSERT (are-equal (square (sqrt num1)) num1) "default alg for small nums")
(display "       actual: ") (display (sqrt num1))
(display ", actual square: ") (display (square (sqrt num1)))
(display ", expected square: ") (display num1) (display "\n\n")

;; large numbers
;; will run infinitely
;; (sqrt num2)
(display "[fail] default alg for large nums\n")
(display "       (will run infinitely)\n\n")


;; OK
(define (good-enough-ex? prev-guess guess x)
    (if (< (/ (abs (- prev-guess guess)) (abs (max prev-guess guess))) K-EPSILON)
        #t
        (< (abs (- (square guess) x)) K-EPSILON)))


(define (sqrt-ex-iter prev-guess guess x)
    (if (good-enough-ex? prev-guess guess x)
        guess
        (sqrt-ex-iter guess (improve guess x) x)))
(define (sqrt-ex x)
    (sqrt-ex-iter 2.0 1.0 x))

(define actual1 (sqrt-ex num1))
(ASSERT (are-equal (square actual1) num1) "ex alg for small nums")
(display "       actual: ") (display actual1)
(display ", actual square: ") (display (square actual1))
(display ", expected square: ") (display num1) (display "\n\n")

;; small large numbers
(define actual2 (sqrt-ex num2))
(ASSERT (are-large-equal (square actual2) num2) "ex alg for large nums")
(display "       actual: ") (display actual2)
(display ", actual square: ") (display (square actual2))
(display ", expected square: ") (display num2) (display "\n")
