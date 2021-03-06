### Zadanie 1 i 2 ###

```racket
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
### Zadanie 3 ###
>W zadaniu 1-2 znajdują się procedury potrzebne do poprawnego działania programu.
```scheme
(define (gen-vals xs)
   (if (null? xs)
       (list null)
       (let*
           ((vss (gen-vals (cdr xs)))
            (x (car xs))
            (vst (map (lambda (vs) (cons (list x true) vs)) vss))
            (vsf (map (lambda (vs) (cons (list x false) vs)) vss)))
         ( append vst vsf))))

(define (eval-formula t vals)
  (cond [(var? t) (find-var t vals)]
        [(neg?  t) (not (eval-formula (neg-subf t) vals))]
        [(conj? t) (and (eval-formula (conj-left t) vals) (eval-formula (conj-right t) vals))]
        [(disj? t) (or  (eval-formula (disj-left t) vals) (eval-formula (disj-right t) vals))]))

(define (find-var var values)
  (cond [(null? values) (error (string-append "Zmienna nie jest zdefiniowana: " (symbol->string var)))]
        [(eq? (caar values) var) (car (cdar values))]
        [else (find-var var (cdr values))]))

(define (falsifable-eval? t)
  (define (iter vals)
    (if (null? vals)
        false
        (if (eval-formula t (car vals))
            (iter (cdr vals))
            (car vals))))
    (iter (gen-vals (free-vars t))))



```

*** 
### Zadanie 4 ###
```racket
(define (literal?)
(or 
(var? f)
(and (neg? f) (var? (cadr f)))))

(define (literal? isNeg v)
  (if (eq? isNeg 'neg)
  (list isNeg v)
  (list '() v )))

(define (nnf? f)
  (cond [(conj? f) (and (nnf? (conj-rght f)) (nnf? (conj-left f)))]
        [(disj? f) (and (nnf? (disj-rght f)) (nnf? (disj-left f)))]
        [else #f]))
```

### Zadanie 5 ###
>W zadaniu 1-2 znajdują się procedury potrzebne do poprawnego działania programu.
```racket
(define (convert-to-nnf t)
  (define (neg-ct-nnf t)
    (cond
      [(var? t)
       (make-neg t)]
      [(neg? t)
       (convert-to-nnf (neg-subf t))]
      [(disj? t)
           (make-conj (neg-ct-nnf (disj-left t)) (neg-ct-nnf (disj-right t)))]
      [(conj? t)
           (make-disj (neg-ct-nnf (disj-left t)) (neg-ct-nnf (disj-right t)))]
    ))
  (cond
    [(var? t) t]
    [(neg? t) (neg-ct-nnf (neg-subf t))]
    [(disj? t) (make-disj (convert-to-nnf (disj-left t)) (convert-to-nnf (disj-right t)))]
    [(conj? t) (make-conj (convert-to-nnf (conj-left t)) (convert-to-nnf (conj-right t)))]))

(define t (make-neg (make-conj (make-neg 'p) (make-disj 'q (make-disj (make-neg 'r) 'r)))))
(convert-to-nnf t)
```
***