; red-prob7.pddl

(define (problem red-prob7) (:domain redriding) 
(:objects red wolf granny home granny-house woods flower hunt near-granny-house
)

(:init
    (person red) (person granny)
    (at red home) (at wolf woods) (at granny granny-house) (at hunt near-granny-house)
    (at flower woods)(alive granny) (alive wolf) (alive red) (alive hunt)
    (location home) (location granny-house) (location woods)  
    (know-path red woods) (know-path hunt granny-house)
    (know-path red granny-house)
)

(:goal (and (eating wolf granny)(holding red flower)
(at red granny-house)(eating wolf red)(sleeping wolf)
(alive red)(alive granny)(not (alive wolf))
(feel-good hunt)(feel-good granny)(feel-good red))
)

;un-comment the following line if metric is needed
;(:metric minimize (???))
)

