## Ważne procedury/informacje, które warto znać przed egzaminem ##
***
### Wykład 1 ###
```scheme
Code here
```
Opis here
***

### Wykład 2 ###
```scheme
Code here
```
Opis here
***

### Wykład 3 ###
```scheme
Code here
```
Opis here
***

### Wykład 4 ###

```scheme
Code here
```
Opis here
***

### Wykład 5 ###
```scheme
Code here
```
Opis here


***
**Append**
```scheme
(define (append xs ys)
  (if (null? xs)
      ys
      (cons (car xs) (append (cdr xs) ys))))
```
***

**Predykat list?**
```scheme
(define (list? x)
  (or (null? x)
      (and (pair? x)
           (list? (cdr x)))))
```
***

**Map**
```scheme
(define (map f xs)
  (if (null? xs)
      null
      (cons (f (car xs))
            (map f (cdr xs)))))
```
***

**Reverse**
```scheme
(define (reverse xs)
  (if (null? xs)
      null
      (append (reverse (cdr xs)) (list (car xs)))))
```
***

**Foldr**
```scheme
(define (fold-right op nval xs)
  (if (null? xs)
      nval
      (op (car xs)
          (fold-right op nval (cdr xs)))))
```
***
**Flatten**
```scheme
(define (flatten t)
  (define (flat t acc)
    (if (leaf? t)
        acc
        (flat (node-left t) (cons (node-value t) (flat (node-right t) acc)))))
  (flat t null))

;;albo z appendem
(define (flatten2 t)
  (if (leaf? t) null
      (append (flatten (node-left t)) (cons (node-value t) (flatten (node-right t))))))
```
***

**Twierdzenie o indukcji dla formuł rachunku zdań**
<ul>
<li> P(l), gdzie l to symbol, musi byc prawda. </li>
<li>Dla dowolnych x, y takich, że (prop? x) oraz (prop? y) (P(x) oraz P(y)) => ( P(neg x) oraz P(conj x y) oraz P(disj x y) )</li>

<li>Z tych dwoch warunkow wynika, że dla dowolnego t, takiego ze (prop? t) P(t) zachodzi.</li>
</ul>

***
