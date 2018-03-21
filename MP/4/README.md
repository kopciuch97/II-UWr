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
