;red-domain

(define (domain redriding)

;remove requirements that are not needed
(:requirements :strips :negative-preconditions :equality)

; un-comment following line if constants are needed
;(:constants )

(:predicates (at ?who ?where)
            (person ?who)
            (location ?where)
            (greeting ?who1 ?who2)
            (know-path ?who ?loc)
            (hold ?who ?obj)
            (eating ?who1 ?who2 ?loc)
            (hold-loc ?who1)
            (alive ?who1)
            (sleeping ?who)
            (saving ?who1 ?who2)
            (check ?who1 ?who2)
            (cutting ?who1 ?who2)
            (eat-obj ?who1 ?obj)
            (pick-up-flower)
)

(:action goto
        :parameters (?who ?from ?to)
        :precondition (and (at ?who ?from) (know-path ?who ?to)
        (not (hold-loc ?who)) (alive ?who))
        :effect (and (not (at ?who ?from)) (at ?who ?to))
)

(:action meet
        :parameters (?who1 ?who2 ?loc)
        :precondition (and (at ?who1 ?loc) (at ?who2 ?loc))
        :effect (and (greeting ?who1 ?who2))
)

(:action tell-path
    :parameters (?who1 ?who2 ?loc ?dest)
    :precondition (and (know-path ?who1 ?dest) (not (know-path ?who2 ?dest))
        (at ?who1 ?loc) (at ?who2 ?loc) (alive ?who1) (alive ?who2)
        (greeting ?who1 ?who2)(not (pick-up-flower)))
    :effect (and (know-path ?who2 ?dest))
)

(:action pick-up
    :parameters (?who1 ?obj ?loc)
    :precondition (and (person ?who1) (alive ?who1) (not (person ?obj))
    (at ?who1 ?loc) (at ?obj ?loc)(not (pick-up-flower)))
    :effect (and (hold ?who1 ?obj)(pick-up-flower))
)

(:action eat-alive
    :parameters (?who1 ?who2 ?loc)
    :precondition (and (at ?who1 ?loc) (at ?who2 ?loc)(pick-up-flower)
    (not (person ?who1)) (person ?who2)(alive ?who1) (alive ?who2)
    (not (sleeping ?who1)))
    :effect (and (eating ?who1 ?who2 ?loc) (not (alive ?who2)))
)

(:action snore-loud
    :parameters (?who1)
    :precondition (and  (not (sleeping ?who1)))
    :effect (and (sleeping ?who1))
)

(:action check
    :parameters (?who1 ?who2 ?loc)
    :precondition (and (person ?who1) (not (person ?who2))
    (sleeping ?who2)(at ?who1 ?loc) (at ?who2 ?loc))
    :effect (and (check ?who1 ?who2))
)

(:action open-belly
    :parameters (?who1 ?who2)
    :precondition (and (check ?who1 ?who2) (sleeping ?who2)
    (alive ?who1) (alive ?who2) (person ?who1) (not (person ?who2)))
    :effect (and (not (alive ?who2)) (cutting ?who1 ?who2))
)

(:action save
    :parameters (?who1 ?who2 ?who3 ?loc)
    :precondition (and (alive ?who1) (not (alive ?who2)) (not (alive ?who3))
    (eating ?who2 ?who3 ?loc) (at ?who1 ?loc))
    :effect (and (alive ?who3)(saving ?who1 ?who3))
)

(:action deliver
    :parameters (?who1 ?who2 ?who3 ?obj )
    :precondition (and (hold ?who1 ?obj) (saving ?who3 ?who1) 
    (saving ?who3 ?who2))
    :effect (and (not (hold ?who1 ?obj)) (hold ?who2 ?obj))
)

(:action eat-together
    :parameters (?who1 ?who2 ?who3 ?obj)
    :precondition (and (hold-loc ?who1) (hold ?who1 ?obj)
    (person ?who1) (person ?who2) (person ?who3) 
    (not (= ?who1 ?who2)) (not (= ?who1 ?who3)) (not (= ?who3 ?who2))
    )
    :effect (and (eat-obj ?who1 ?obj) (eat-obj ?who2 ?obj) (eat-obj ?who3 ?obj))
)










;define actions here

)