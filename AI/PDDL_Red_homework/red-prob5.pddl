; red-prob5.pddl

(define (problem red-prob5) (:domain redriding) 
(:objects red wolf granny home granny-house woods fair flower
)

(:init
    (person red) (person granny) (at red home) (at wolf woods)
    (location home) (location granny-house) (location woods)  
    (know-path red woods) (at flower woods) (at granny granny-house)
    (know-path red granny-house) (alive wolf) (alive granny) (alive red)
    (hold-loc granny)
)

(:goal (and (know-path wolf granny-house)
(hold red flower) (eating wolf granny granny-house) 
(eating wolf red granny-house) (sleeping wolf)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
