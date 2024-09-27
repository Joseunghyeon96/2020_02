import random

def GetNumber():
    return random.randrange(1,46)

lotto = []
num = 0

print("** 로또추첨을 시작합니다.**")

while True:
    num = GetNumber()
    if lotto.count(num) == 0:
        lotto.append(num)

    if len(lotto)>=6:
        break

print("추첨된 로또 번호 : ",end ='')
lotto.sort()
for i in range(6):
    print(lotto[i],end= ' ')
