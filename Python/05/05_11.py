## 변수 선언
select, answer, numStr , num1, num2 = 0,0,"",0,0

## 메인 코드
select = int(input("1.입력한 수식 계산 2. 두 수 사이의 합계 : "))

if select ==1 :
    numStr = input("수식을 입력하세요 : ")
    answer = eval(numStr)
    print("%s = %5.1f"%(numStr, answer))
elif select == 2:
    num1 = int(input("첫 번째 숫자를 입력하세요:"))
    num2 = int(input("두 번째 숫자를 입력하세요:"))
    for i in range(num1,num2+1):
        answer = answer+i

    print("%d + ... + %d = %d"%(num1,num2,answer))
else :
    print("1이나 2 를 입력해야 합니다.")
    
    
