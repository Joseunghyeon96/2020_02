a = int(input("점수를 입력하세요"))

if a>=60:
    if a>=70:
        if a>=80:
            if a>=90:
                print("A입니다")
            else:
                print("B입니다")
        else:
            print("C입니다")
    else:
        print("D입니다")
else:
    print("F")
