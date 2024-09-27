num1 = input('숫자 1 -> ')
num2 = input('숫자 2 -> ')

try :
    num1 = int(num1)
    num2 = int(num2)
    while True:
        res = num1/num2

except:
    print('오류 발생')

else:
    print(num1 , '/', num2 ,'=',num1/num2)

finally :
    print('이 부분은 무조건 나옵니다.')
