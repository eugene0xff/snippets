#lang sicp

;; Exercise 1.5
;; Ben Bitdiddle has invented a test to determine
;; whether the interpreter he is faced with
;; is using applicative-order evaluation or normal order evaluation.
;; He defines the following two procedures:
;;
;; (define (p) (p))
;; (define (test x y)
;;     (if (= x 0) 0 y))
;; 
;; Then he evaluates the expression
;;
;; (test 0 (p))
;;
;; What behavior will Ben observe with an interpreter
;; that uses applicative-order evaluation?
;; What behavior will he observe with an interpreter
;; that uses normal-order evaluation?
;; Explain your answer.
;;
;; (Assume that the evalution rule for the special form
;; is the same whether the interpreter is using normal or applicative order:
;; The predicate expression is evaluated first,
;; and the result determines wheter to evaluate the consequent
;; or the alternative expression.)


;; Solution
;; Applicative-order evalution
;; `(test 0 (p))` 
;; will become `(if (= 0 0) 0 (p))`
;; that will become `(if (= 0 0) 0 (p))` and so on
;; so this evalution will never be completed
;;
;; Normal-order evalution
;; `(test 0 (p))`
;; will becom `(if (=0 0) 0 (p))`
;; that will become `(if (#t) 0 (p))` (according to normal-order evaluation rules)
;; that will become `0`
;; so the result of `(test 0 (p))` will be `0`

