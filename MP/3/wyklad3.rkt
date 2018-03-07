#lang racket


;; definiujemy reprezentację liczb wymiernych
(define (make-rat n d)
  (let ((c (gcd n d)))
    (cons (/ n c) (/ d c))))

(define (rat-numer l)
  (car l))

(define (rat-denum l)
  (cdr l))

(define (rat? l)
  (and (pair? l)
       (not (= (rat-denum l) 0))
       (= 1 (gcd (rat-numer l) (rat-denum l)))))


;; i pakiet operacji dla użytkownika; wykorzystujemy konstruktory *nie patrząc* na to jak są zaimplementowane

(define (integer->rational n)
  (make-rat n 1))

(define (div-rat l1 l2)
  (let ((n (* (rat-numer l1) (rat-denum l2)))
        (d (* (rat-denum l1) (rat-numer l2))))
    (make-rat n d)))

;; wypisywanie liczb wymiernych w formie czytelnej dla człowieka
(define (print-rat l)
  (display (rat-numer l))
  (display "/")
  (display (rat-denum l)))

;; cz. 2. Listy

;; predykat definiujący przyjętą przez nas reprezentację list
(define (list? x)
  (or (null? x)
      (and (pair? x)
           (list? (cdr x)))))

;; procedura obliczająca długość listy
(define (length xs)
  (if (null? xs)
      0
      (+ 1 (length (cdr xs)))))

;; procedura łącząca (konkatenująca) dwie listy
(define (append xs ys)
  (if (null? xs)
      ys
      (cons (car xs) (append (cdr xs) ys))))


;; procedura accumulate (z ćwiczeń) jest skomplikowana: rozbijmy ją na mniejsze
(define (accumulate op null-val term start next end)
  (if (> start end)
      null-val
      (op (term start)
          (accumulate op null-val term (next start) next end))))


;; gen-sequence generuje ciąg liczb od start do end
;; procedura next determinuje kolejny element ciągu
(define (gen-sequence start next end)
  (if (> start end)
      null
      (cons start (gen-sequence (next start) next end))))

(define (square x) (* x x))

;; podnoszenie wszystkich elementów listy do kwadratu
(define (square-list xs)
  ;; zamiast poniższego wystarczy napisać (map square xs)!
  (if (null? xs)
      null
      (cons (square (car xs))
            (square-list (cdr xs)))))

;; i sumowanie wszystkich elementów listy
(define (sumlist xs)
  ;; zamiast poniższego wystarczy (fold_right + 0 xs)
  ;; możemy też powiedzieć (apply + xs), gdyż + jest procedurą która działa dla
  ;; dowolnej liczby argumentów. apply jest procedurą wbudowaną
  (if (null? xs)
      0
      (+ (car xs) (sumlist (cdr xs)))))

;; map aplikuje procedurę f do każdego z elementów listy i zwraca listę otrzymanych wyników
(define (map f xs)
  (if (null? xs)
      null
      (cons (f (car xs))
            (map f (cdr xs)))))

;; fold-right jest esencją accumulate z ćwiczeń: aplikuje operator op do
;; elementu listy i wyniku swojego wywołania na reszcie ciągu — a w przypadku gdy
;; ciąg się skończył zwraca nval
(define (fold-right op nval xs)
  (if (null? xs)
      nval
      (op (car xs)
          (fold-right op nval (cdr xs)))))