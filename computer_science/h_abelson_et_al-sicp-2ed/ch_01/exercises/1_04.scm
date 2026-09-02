#lang sicp

;; Exercise 1.4
;; Observe that our model of evaluation allows for combinations
;; whose operators are compound expressions.
;; Use this observation to describe the behaviour
;; of the following procedure:
;;
;; (define (a-plus-abs-b a b)
;;    ((if (> b 0) + -) a b))


;; Solution
(define (a-plus-abs-b a b)
    ((if (> b 0) + -) a b))
    
(a-plus-abs-b 1 1)
(a-plus-abs-b 1 (- 1))

;; This procedure returns the sum
;; of the "a" parameter and
;; the absolute value of the "b" parameter
