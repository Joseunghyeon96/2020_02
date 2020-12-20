import random

numbers = []

for num in range(1,10):
    numbers.append(random.randrange(0,10))

print("생성된 리스트 : ",numbers)

for num in range(1,10):
    if num not in numbers:
        print("숫자 %d는 리스트에 없습니다.",num)
