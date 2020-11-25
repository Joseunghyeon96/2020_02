;red-domain

(define (domain redriding)

;remove requirements that are not needed
(:requirements :strips)

; un-comment following line if constants are needed
;(:constants )

(:predicates (at ?who ?where)
            (person ?who)
            (location ?where)
            (greeting ?who1 ?who2)
            (eating ?who1 ?who2)
            (know-path ?who ?loc)
            (alive ?who)
            (holding ?who ?obj)
            (sleeping ?who)
            (feel-good ?who)
            (flower)
            (check)
            (delivery-cake)
)

(:action goto
        :parameters (?who ?from ?to)
        :precondition (and (not(sleeping ?who))(alive ?who)
        (not (= ?from ?to))
        (at ?who ?from)(know-path ?who ?to))
        :effect (and (not (at ?who ?from)) (at ?who ?to))
)

(:action meet
        :parameters (?who1 ?who2 ?loc)
        :precondition (and (at ?who1 ?loc) (at ?who2 ?loc))
        :effect (and (greeting ?who1 ?who2))
)

(:action tell-path
        :parameters (?who1 ?who2 ?to ?from)
        :precondition (and  (not(sleeping ?who1))(not(sleeping ?who2))
        (alive ?who1)(alive ?who2)
        (know-path ?who1 ?to)(not(know-path ?who2 ?to))
        (at ?who1 ?from)(at ?who2 ?from)(not(flower))) 

        :effect (and (know-path ?who2 ?to))
 )

 (:action pick-up
        :parameters (?who ?obj ?loc)
        :precondition (and (not(sleeping ?who))(alive ?who)(not (location ?obj))
        (not (person ?obj))
        (at ?who ?loc)(at ?obj ?loc)(person ?who))
        :effect (and (holding ?who ?obj)(flower))
 )


(:action eat-alive
        :parameters (?who1 ?who2 ?loc ?who3)
        :precondition (and (not(sleeping ?who1))(at ?who1 ?loc)(at ?who2 ?loc)
        (not(person ?who1))(person ?who2)(alive ?who2)(person ?who3)
        (or (not (alive ?who3))(not (at ?who3 ?loc)))(flower)
        )
        
        :effect (and (not (alive ?who2))(eating ?who1 ?who2))
)

(:action snore-loud
        :parameters (?who1 ?other1 ?other2)
        :precondition (and (eating ?who1 ?other1)(eating ?who1 ?other2)
        (not(= ?other1 ?other2))(not (check)))
        :effect (and (sleeping ?who1))
)

(:action check
    :parameters (?who1 ?who2 ?loc)
    :precondition (and (sleeping ?who1)(at ?who1 ?loc)(at ?who2 ?loc)
    (alive ?who2)(not (= ?who1 ?who2)))
    :effect (and (check))
)

(:action recovery
    :parameters (?who1 ?who2 ?who3 ?loc ?who4)
    :precondition (and (check)(not (alive ?who2))(not(alive ?who3))
    (person ?who2)(person ?who3)(alive ?who1)(not (= ?who2 ?who3))
    (sleeping ?who4) (at ?who1 ?loc) (at ?who2 ?loc) (at ?who3 ?loc) (at ?who4 ?loc)
    )
    :effect (and (alive ?who2)(alive ?who3)(not(alive ?who4)))
)

(:action delivery-cake
    :parameters (?who1 ?who2 ?loc)
    :precondition (and (at ?who1 ?loc)(at ?who2 ?loc)(check)
    (alive ?who1)(alive ?who2)(person ?who1)(person ?who2))
    :effect (and (delivery-cake))
)

(:action eat-cake
        :parameters (?who1 ?who2 ?who3 ?loc)
    :precondition (and (at ?who1 ?loc)(at ?who2 ?loc)(at ?who3 ?loc)(delivery-cake)
    (alive ?who1)(alive ?who2)(alive ?who3)
    (not(= ?who1 ?who2))(not(= ?who2 ?who3))(not(= ?who1 ?who3)))
    :effect (and (feel-good ?who1)(feel-good ?who2)(feel-good ?who3))
)








;define actions here
)