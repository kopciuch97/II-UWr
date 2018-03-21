<h3>Ważne procedury/informacje, które warto znać przed egzaminem</h3>
<ol>
<li><b>Append</b> <br>
```scheme
(define (append xs ys)
  (if (null? xs)
      ys
      (cons (car xs) (append (cdr xs) ys))))
```
</li>

<li><b>Flatten</b> <br>
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
</li>

</ol>