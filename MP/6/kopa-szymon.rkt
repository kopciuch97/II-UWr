#lang racket

(define (const? t)
  (number? t))

(define (binop? t)
  (and (list? t)
       (= (length t) 3)
       (member (car t) '(+ - * /))))

(define (binop-op e)
  (car e))

(define (binop-left e)
  (cadr e))

(define (binop-right e)
  (caddr e))

(define (binop-cons op l r)
  (list op l r))

(define (op->proc op)
  (cond [(eq? op '+) +]
        [(eq? op '*) *]
        [(eq? op '-) -]
        [(eq? op '/) /]))

(define (let-def? t)
  (and (list? t)
       (= (length t) 2)
       (symbol? (car t))))

(define (let-def-var e)
  (car e))

(define (let-def-expr e)
  (cadr e))

(define (let-def-cons x e)
  (list x e))

(define (let? t)
  (and (list? t)
       (= (length t) 3)
       (eq? (car t) 'let)
       (let-def? (cadr t))))

(define (let-def e)
  (cadr e))

(define (let-expr e)
  (caddr e))

(define (let-cons def e)
  (list 'let def e))

(define (var? t)
  (symbol? t))

(define (var-var e)
  e)

(define (var-cons x)
  x)

(define (hole? t)
  (eq? t 'hole))

(define (arith/let/holes? t)
  (or (hole? t)
      (const? t)
      (and (binop? t)
           (arith/let/holes? (binop-left  t))
           (arith/let/holes? (binop-right t)))
      (and (let? t)
           (arith/let/holes? (let-expr t))
           (arith/let/holes? (let-def-expr (let-def t))))
      (var? t)))

(define (num-of-holes t)
  (cond [(hole? t) 1]
        [(const? t) 0]
        [(binop? t)
         (+ (num-of-holes (binop-left  t))
            (num-of-holes (binop-right t)))]
        [(let? t)
         (+ (num-of-holes (let-expr t))
            (num-of-holes (let-def-expr (let-def t))))]
        [(var? t) 0]))

(define (arith/let/hole-expr? t)
  (and (arith/let/holes? t)
       (= (num-of-holes t) 1)))

(define (hole-context e)
  (define (ext-hole-context e context)
    (cond
      [(not (arith/let/hole-expr? e))
       (error "e must be arith/let/hole-expr")]
      [(hole? e) context]
      [(let? e)
       (cond
         [(arith/let/hole-expr? (let-def-expr (let-def e)))
          (ext-hole-context (let-def-expr (let-def e)) context)]
         [else (ext-hole-context (let-expr e) (remove-duplicates (cons (let-def-var (let-def e)) context)))])]
      [(and
       (binop? e)
       (arith/let/hole-expr? (binop-left e)))
       (ext-hole-context e context)]
      [else (ext-hole-context (binop-right e) context)]))
  (ext-hole-context e null))
  



(define (test)
  (define (sort-symbol xs)
    (sort xs symbol<?))

  (define (true-assert xs)
    (equal? (sort-symbol ( car xs)) (sort-symbol ( cdr xs ))))

  (define (make-test arg res)
    (true-assert ( cons arg res)))

  (write (make-test ( hole-context '( let ( x 3) ( let ( y 7) (+ x hole ) ) ) ) '(x y)))
  (newline)
  (write (make-test  ( hole-context '(+ 10 hole)) '()))
  (newline)
  (write (make-test  ( hole-context '( let ( x hole ) ( let ( y 7) (+ x 3) ) ) ) '() ))
  (newline)
  (write (make-test ( hole-context '( let ( piesek 1)
                                ( let ( kotek 7)
                                   ( let ( piesek 9)
                                      ( let ( chomik 5)
                                         hole ) ) ) ) )
             '(chomik kotek piesek)))
  (newline)
  (write (make-test  ( hole-context '(+ ( let ( x 4) 5) hole ) ) '()))

)

(test)