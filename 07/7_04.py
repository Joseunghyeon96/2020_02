aList = []
bList = []
value = 0

for i in range(0,100):
    aList.append(value)
    value+=2

for i in range(0,100):
    bList.append(aList[99-i])

print("bList[0]:%d , bList[99]:%d"%(bList[0],bList[99]))
