; red-prob1.pddl

(define (problem red-prob1) (:domain redriding) 
(:objects red wolf granny home granny-house woods fair
)

(:init
    (person red) (person granny) (at red home) (at wolf woods)
    (location home) (location granny-house) (location woods)  
    (know-path red woods) (alive wolf) (alive granny) (alive red)
    (know-path red granny-house)
)

(:goal (and (greeting red wolf) (at red granny-house)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
