### Zadanie 1 ###

```racket
#lang racket
(define (arith->rpn lista)
  (define (onp xs acc)
    (cond  [ (number? xs) (cons xs acc)]
           [ else (onp (cadr xs) ( onp ( caddr xs) (cons (car xs) acc)))]
           )
    )
```
***

### Zadanie 2 ###

```racket
#lang racket
(define (stack? s)
  (list? s))

(define (push arg stack)
  (cons arg stack))

(define (pop stack)
  (cons (car stack) (cdr stack)))
```

### Zadanie 3 ###
>Gdzie 'l' jest listą, a 's' jest stosem

```racket
#lang racket
(define (push el s)
  (cons el s))
;; 3
(define (eval-rpn exp)
  (define (pom l s)
    (if (null? l)
        (car s)
        (cond [(number? (car l)) (pom (cdr l) (push (car l) s))]
              [else (pom (cdr l) (push ((op->proc (car l))  (cadr s) (car s)) (cddr s)))])))
  (pom exp null))
```
