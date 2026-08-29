#lang sicp

(define (factorial n)
    (if (= n 1) 1 (* n (factorial (- n 1)))))

(factorial 6)


(define (factorial2 n)
    (fact-iter 1 1 n))
(define (fact-iter product counter max-count)
    (if (> counter max-count)
        product
        (fact-iter (* counter product)
                   (+ counter 1)
                   max-count)))

(factorial2 6)


(define (factorial3 n)
    (define (iter product counter)
        (if (> counter n)
            product
            (iter (* counter product) (+ counter 1))))
    (iter 1 1))

(factorial3 6)
                  

