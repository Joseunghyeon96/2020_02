;; problem file: blocksworld-prob1.pddl

(define (problem blocksworld-prob1)
    (:domain blocksworld)
    (:objects x y z) ;block x,y

    (:init (on-table x) (on-table y) (clear x) (on z y) (clear z))
    (:goal (and (on x y) (on z x)))
)