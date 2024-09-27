list = []

for i in range(0,4):
    list.append(0)

hap = 0

for i in range(0,4):
    list[i] = int(input(str(i+1)+"번째 숫자:"))


hap = list[0]+list[1]+list[2]+list[3]

print("합 : %d"% hap)
