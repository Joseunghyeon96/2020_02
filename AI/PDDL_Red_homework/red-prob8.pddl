; red-prob8.pddl

(define (problem red-prob8) (:domain redriding) 
(:objects red wolf granny home granny-house woods fair flower
huntsman granny-house-garden cake
)

(:init
    (person red) (person granny) (at red home) (at wolf woods)
    (location home) (location granny-house) (location woods)  
    (know-path red woods) (at flower woods) (at granny granny-house)
    (know-path red granny-house) (alive wolf) (alive granny) (alive red)
    (hold-loc granny) (location granny-house-garden) 
    (at huntsman granny-house-garden) (hold red cake)
    (know-path huntsman granny-house) (person huntsman) (alive huntsman)
)

(:goal (and (know-path wolf granny-house)
(hold red flower) (eating wolf granny granny-house) 
(eating wolf red granny-house) (sleeping wolf) (check huntsman wolf)
(cutting huntsman wolf) (alive red) (alive granny) (hold granny cake)
(eat-obj granny cake) (eat-obj red cake) (eat-obj huntsman cake)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
