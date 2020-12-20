##변수 선언
ch = ""
a,b = 0,0

while True:
    a = int(input("계산할 첫 번째 수를 입력해주세요 : "))
    ch = input("계산할 연산자를 입력해주세요 : ")
    b = int(input("계산할 두 번째 수를 입력해주세요 : "))

    if( ch== "+"):
        print("%d + %d = %d"%(a,b,a+b))
    elif( ch == "-"):
        print("%d - %d = %d"%(a,b,a-b))
    elif( ch == "*"):
        print("%d * %d = %d"%(a,b,a*b))
    elif( ch == "/"):
        print("%d / %d = %d"%(a,b,a/b)) 
    elif( ch == "%"):
        print("%d % %d = %d"%(a,b,a%b))
    elif( ch == "//"):
        print("%d // %d = %d"%(a,b,a//b))
    elif( ch == "**"):
        print("%d ** %d = %d"%(a,b,a**b))
    else:
        print("연산자를 잘못 입력하셨습니다.")
