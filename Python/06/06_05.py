i,sum = 0,0

start = int(input("시작 값을 입력해주세요"))
end = int(input("끝 값을 입력해주세요"))
increase = int(input("증가 값을 입력해주세요."))

for i in range(start,end+1,increase):
    sum += i

print("%d에서 %d까지 %d만큼 증가시킨 값의 합은 %d 입니다."
      %(start,end,increase,sum))
