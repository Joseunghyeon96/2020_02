#2단-9단

dan = 2
i = 1
print("구구단")

while dan != 10:
    print("=====%d단====="%dan)
    while i != 10:
        print("%2d * %2d = %2d"%(dan,i,dan*i))
        i+=1
    dan+=1
    i = 1
