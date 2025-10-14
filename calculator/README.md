# 사용법

> 해당 폴더에는 자동화가 되어있지 않고 폴더 분류도 되어있지않은 상태의 계산기 입니다.

> 분류가 완료되어 있고 자동화가 되어있는 폴더는 make-calculator 폴더를 확인해 주세요.

## 정적 라이브러리 방식
```Makefile
# 오브젝트 파일 생성
gcc -c calculator.c -o calculator.o

# 정적 라이브러리 생성
gcc rcs static_calc_lib.a calculator.o

# 프로그램 컴파일 및 링크
gcc main.c static_calc_lib.a -o static_calculator_app

# 실행
./static_calculator_app
```

## 공유 라이브러리 방식
```Makefile
# Position Independent Code(PIC)를 포함하는 오브젝트 파일 생성
gcc -c -fpic calculator.c -o shared_calculator.o

# 공유 라이브러리 생성
gcc -shared shared_calculator.o -o shared_calc_lib.so 

# 프로그램 컴파일 및 링크
gcc main.c ./shared_calc_lib.so -o shared_calculator_app

# 실행
./shared_calculator_app
```

## 동적 라이브러리 방식
```Makefile
# Position Independent Code(PIC)를 포함하는 오브젝트 파일 생성
gcc -c -fpic calculator.c -o shared_calculator.o

# 공유 라이브러리 생성
gcc -shared shared_calculator.o -o shared_calc_lib.so 

# 프로그램 컴파일 및 링크
# 동적 방식을 사용하려면 main 함수 수정이 필요해서 수정된 main 파일을 인자로 링크 합니다
gcc main_dynamic.c -ldl -o dynamic_calculator_app

# 실행
./dynamic_calculator_app
```