# opensource

SUB-1의 과제 코드를 모아둔 리포지토리 입니다.

## 폴더별 설명
> 번호는 실제 문제 번호

> 우측 shell-program은 폴더명 입니다

### 5번. shell-program
1. file-cound.sh: 파일 수 세기
2. multiplication-for.sh: 
3. multiplication-until.sh
4. multiplication-while.sh
5. fibonacci.sh: 피보나치 수열
6. half-trangle.sh: 반으로 뒤집어져 잘린 직각삼각형

- 문제 정보 아래 참고
```
bash 쉘 스크립트가 익숙해지도록 사용해 보고, 다음 조건을 만족하는 bash 쉘 스크립트를 작성해 본다.
```

---

### 6번. calculator
- 문제 정보 아래 참고
```
사칙연산 (덧셈 add, 뺄셈 subtract, 곱셈 multiply, 나눗셈 divide) 에 대한 함 수와 이 함수들을 이용하는 예제 프로그램을 각각 작성하고, 정적 라이브러리, 공유 라이브러리, 동적 라이브러리 방식을 각각 이용하여 예제 프로그램을 실행시킨 결과를 보이시오
```

---

### 7번. make-calculator
- 문제 정보 아래 참고
```
위 문제에 대하여, C 소스 파일들을 목적 파일로 만들고, 또한 이 파일들을 이 용하여 라이브러리 또는 실행 파일로 만들어 주는 Makefile을 작성하여 실행 시켜 보시오. 이 때, 라이브러리 관련 파일들은 서브디렉토리에 두도록 한다.
```

---

#### make-calculator-gdb (비고)
- make-calculator-gdb 라는 폴더가 있는데 해당 폴더는 7번 프로젝트를 vscode에서 gdb로 디버깅할 수 있게 설정해둔 프로젝트 폴더입니다.
- tasks.json과, launch.json 에 Makefile기반 디버깅 구조를 설정하였습니다.
- 사용방법
    - 일단 프로젝트를 해당 폴더로 다시 열어야합니다.
    - vscode 의 상단 검색줄에서 디버깅시작(debug)를 선택하면 3가지 커스텀 디버깅 항목이 나옵니다.
    - 클릭해서 사용하면 됩니다. 주 main.c 혹은 main-dynamic.c 에서 종단점을 선택하고 디버깅을하면 잘 적용됩니다.

---

#### make-calculator-gprof (실행 프로파일링 도구)
- 정적 라이브러리 분석
    - make run-static -> gmon.out 파일이 나옵니다.
    - gprof ./build/static_calculater_app gmon.out
    - make clean <- 필수로 실행 해주세요
- 공유 라이브러리 분석
    - make run-shared -> gmon.out 파일이 나옵니다.
    - gprof ./build/shared_calculater_app gmon.out
    - make clean <- 필수로 실행 해주세요
- 동적 라이브러리 분석
    - make run-dynamic -> gmon.out 파일이 나옵니다.
    - gprof ./build/dynamic_calculater_app gmon.out
    - make clean <- 필수로 실행 해주세요

> 주의: 결과도출물인 gmon.out이라는 이름이 동일해 여러개를 한꺼번에 하면 오류가 발생할 수 있습니다.

> 개별적으로 분석을 진행 해 주세요

---

#### make-calculator-valgrind (메모리 손상 검사 도구)
- 정적 라이브러리 분석
    - make static
    - valgrind—leak-check=full ./build/static_calculator_app
- 공유 라이브러리 분석
    - make shared
    - valgrind—leak-check=full ./build/shared_calculator_app
- 동적 라이브러리 분석
    - make dynamic
    - valgrind—leak-check=full ./build/dynamic_calculator_app

> 원본과는 다른게 거의 없지만 오브젝트 생성과 실행파일 생성 부분에 -g 명령이 추가되어 있어야만 사용 가능

---

#### assert-custom (수정한 assert-custom)
- make build
- 실행파일을 컴파일할 때 -NDEBUG 옵션을 추가하면됩니다.
	- 예: gcc -DNDEBUG -I./include main.c -o build/test.app
	- -DNDEBUG: -D매크로이름 의 형식으로 사용합니다.
	- 헤더파일에서 선언한 매크로이름을 사용하면 됩니다.

> 컴파일 명령어는 Makefile을 확인하세요

- 실행파일을 컴파일할 때 -NDEBUG 옵션을 추가하면됩니다.

---
