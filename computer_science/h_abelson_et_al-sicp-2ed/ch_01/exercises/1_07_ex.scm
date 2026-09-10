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
;; source alg
(define (sqrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x) x)))

(define (improve guess x)
    (average guess (/ x guess)))

(define (average x y)
    (/ (+ x y) 2))

(define (good-enough? guess x)
    (< (abs (- (square guess) x)) 0.001))

(define (square x) (* x x))

(define (sqrt x)
    (sqrt-iter 1.0 x))


;; utils region
(define (empty-string? str) (= (string-length str) 0))

(define (are-equal? x y)
    (< (abs (- x y)) 0.00001))

(define (TEST f num msg msg-ex)
    (cond ((empty-string? msg-ex) 
              (if (are-equal? (square (f num)) num)
                  (display "[ ok ]")
                  (display "[fail]"))
              (display " ") (display msg) (display "\n") (display "       ")
              (display "root: ") (display (f num)) (display ", ")
              (display "actual square: ") (display (square (f num))) (display ", ")
              (display "expected square: ") (display num) (display "\n\n"))
          (else 
              (display "[ ?? ]") (display " ") (display msg) (display "\n")
              (display "       ") (display msg-ex) (display "\n\n"))))


;; testing
;; some numbers are taken from here:
;; https://eli.thegreenplace.net/2007/06/21/sicp-section-11
(TEST sqrt 0.0005 "default alg for small numbers" "")

(TEST sqrt 9240000000000000000000000 "default alg for very large numbers"
    "(will run infinitely)")

;; new impl
;; has taken from here: https://eli.thegreenplace.net/2007/06/21/sicp-section-11
(define (sqrt-ex-iter guess x)
    (define improved-guess (improve-ex guess x))
    (if (close-enough? guess improved-guess)
        improved-guess
        (sqrt-ex-iter improved-guess x)))

(define (improve-ex guess x) (average guess (/ x guess)))

(define (average-ex x y) (/ (+ x y) 2))

(define (close-enough? x y)
    (define ratio (/ x y))
    (and (< ratio 1.001) (> ratio 0.999)))

(define (square-ex x) (* x x))

(define (sqrt-ex x) (sqrt-ex-iter 1.0 x))


;; testing for the new impl
(TEST sqrt-ex 0.0005 "ex alg for small numbers" "")
(TEST sqrt-ex 9240000000000000000000000 "ex alg for large numbers" "")
