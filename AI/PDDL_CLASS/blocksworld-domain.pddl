;; domain file: blocksworld-domain.pddl

(define (domain blocksworld)
    (:requirements :strips ) ;;strips 스타일로 pddl 작성하겠다

    (:predicates (clear ?x)
                 (on-table ?x)
                 (holding ?x)
                 (on ?x ?y)
    )
    
    (:action pickup
        :parameters (?object)
        :precondition (and (clear ?object) (on-table ?object))
        :effect (and (holding ?object) (not (clear ?object))
                     (not (on-table ?object)))
    )
    
    (:action  putdown
        :parameters (?object)
        :precondition (and (holding ?object))
        :effect (and (clear ?object) (on-table ?object) 
                (not (holding ?object)))   
    )
    
    (:action stack
        :parameters (?object ?underObject)
        :precondition (and (clear ?underObject) (holding ?object))
        :effect (and (clear ?object) (on ?object ?underObject)
                     (not (clear ?underObject)) (not (holding ?object)))
    )

    (:action unstack
        :parameters (?object ?underObject)
        :precondition (and (on ?object ?underObject) (clear ?object))
        :effect (and (holding ?object) (clear ?underObject)
                     (not (on ?object ?underObject)) (not (clear ?object)))
    )
)