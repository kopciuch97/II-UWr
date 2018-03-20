#lang racket
(define (var? t)
  (symbol? t))
 
(define (neg? t)
  (and (list? t)
       (= (length t) 2)
       (eq? 'neg (car t))))
 
(define (conj? t)       ;;koniunkcja
  (and (list? t)
       (= (length t) 3)
       (eq? 'conj (car t))))
 
(define (disj? t)       ;;alternatywa
  (and (list? t)
       (= (length t) 3)
       (eq? 'disj (car t))))
 
(define (prop? f)
  (or (var? f)
      (and (neg? f)
           (prop? (neg-subf f)))
      (and (disj? f)
           (prop? (disj-left f))
           (prop? (disj-rght f)))
      (and (conj? f)
           (prop? (conj-left f))
           (prop? (conj-rght f)))))
 
(define (neg t)
  (list 'neg t))
 
(define (conj x y)
  (list 'conj x y))
 
(define (disj x y)
  (list 'disj x y))
 
(define (neg-subf f)
  (cadr f))
 
(define (disj-left f)
  (cadr f))
 
(define (disj-rght f)
  (caddr f))
 
(define (conj-left f)
  (cadr f))
 
(define (conj-rght f)
  (caddr f))
 
(define (free-vars f)
  (define (fv f xs)
    (cond [(neg? f) (fv (neg-subf f) xs)]
          [(disj? f) (fv (disj-rght f) (fv (disj-left f) xs))]
          [(conj? f) (fv (conj-rght f) (fv (conj-left f) xs))]
          [else (append xs (list f))]))
  (fv f null))
 
;; (free-vars (neg (disj 2 (conj 10 (disj 9 11)))))        - tescik