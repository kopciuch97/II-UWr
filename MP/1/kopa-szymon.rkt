#lang racket
(define (cube-root x)
  (define (dist x y)
    (abs (- x y)))

  (define (cube x)
    (* x x x))

  (define (improve approx)
    (/ (+ (/ x (* approx approx)) (* 2 approx)) 3))

  (define (good-enough? approx)
    (< (dist x (cube approx)) 0.00000000001))

  (define (iter approx)
    (cond
      [(good-enough? approx) approx]
      [else                  (iter (improve approx))]))
  
  (iter 1.0))
