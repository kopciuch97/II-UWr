### Zadanie 1 i 2 ###

```scheme
#lang racket
;;PREDYKATY
(define (var? t)
  (symbol? t))
 
(define (neg? t)
  (and (list? t)
       (= 2 (length t))
       (eq? 'neg (car t))))
 
(define (conj? t)
  (and (list? t)
       (= 3 (length t))
       (eq? 'conj (car t))))
 
(define (disj? t)
  (and (list? t)
       (= 3 (length t))
       (eq? 'disj (car t))))
 
(define (prop? f)
  (or (var? f)
      (and (neg? f)
           (prop? (neg-subf f)))
      (and (disj? f)
           (prop? (disj-left f))
           (prop? (disj-right f)))
      (and (conj? f)
           (prop? (conj-left f))
           (prop? (conj-right f)))))
 
;;KONSTRUKTORY
(define (neg t)
  (list 'neg t))
 
(define (conj t1 t2)
  (list 'conj t1 t2))
 
(define (disj t1 t2)
  (list 'disj t1 t2))
 
;;SELEKTORY
(define (neg-subf t)
  (second t))
 
(define (disj-left t)
  (second t))
 
(define (disj-right t)
  (third t))
 
(define (conj-left t)
  (second t))
 
(define (conj-right t)
  (third t))
 
;;free-vars
(define (free-vars f)
  (define (iter f xs)
    (cond [(neg? f) (iter (neg-subf f) xs)]
          [(disj? f) (iter (disj-right f) (iter (disj-left f) xs))]
          [(conj? f) (iter (conj-right f) (iter (conj-left f) xs))]
          [else (remove-duplicates (append xs (list f)))]))
   (if (prop? f)
      (iter f null)
      (error "coś poszło nie tak")))
 
```

*** 