#lang racket

(require "hw.rkt")
(provide do-add)

(define (do-add x y)
  (+ x y))

(define t)

;; make-plan returns an expression from a list of code

(define (from . relation exprs)
  (foldl (lambda (a b) (a b)) relation exprs))

(define ((select expr) row)
  (for/))

(compute
  (from
   t
   (select '(a b col))
   (group-by 'a)
   (agg #:my_mean (mean 'col))))

(module+ test
  ;; Tests to be run with raco test
  (require rackunit)
  (test-equal? "bogus" (do-add 1 2) 3)
  (test-equal? "c-ext" greeting "hello"))
