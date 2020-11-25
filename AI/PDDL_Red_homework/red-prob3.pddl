; red-prob3.pddl

(define (problem red-prob3) (:domain redriding) 
(:objects red wolf granny home granny-house woods flower
)

(:init
    (person red) (person granny) (at red home) (at wolf woods)
    (at granny granny-house)
    (at flower woods)(alive granny) (alive wolf) (alive red)
    (location home) (location granny-house) (location woods) 
    (know-path red woods) 
    (know-path red granny-house)
)

(:goal (and (eating wolf granny)(holding red flower)
(at red granny-house)(eating wolf red))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
)
