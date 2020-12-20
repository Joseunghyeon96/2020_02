i,sum = 0,0

start = int(input("시작 값을 입력해주세요"))
end = int(input("끝 값을 입력해주세요"))

for i in range(start,end+1):
    sum += i

print("%d에서 %d까지의 합은 %d 입니다." %(start,end,sum))
