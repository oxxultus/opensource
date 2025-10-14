# 사용법

```Makefile
# 도움말을 확인하시려면 
make 
make help
# 를 터미널의 해당 디렉토리 내에서 사용하세요.
```

## 폴더 구조
```Bash
# 폴더 구조
my_calculator_project/
├── Makefile                <-- 빌드 스크립트 (모든 규칙과 변수 정의)
├── main.c                  <-- [입력] 정적/공유 링크를 위한 메인 애플리케이션
├── main_dynamic.c          <-- [입력] 동적 로딩을 위한 메인 애플리케이션 (dlopen 사용 가정)
│
├── include/                <-- [소스] 헤더 파일 (인터페이스)
│   └── calculator.h
│
├── src/                    <-- [소스] 구현 파일
│   └── calculator.c
│
└── build/                  <-- [산출물] 모든 빌드 결과물이 모이는 최상위 폴더
    ├── obj/                <-- [중간 산출물] 오브젝트 파일 저장소
    │   ├── static_calculator.o
    │   ├── shared_calculator.o
    │   └── main_dynamic.o
    │
    └── lib/                <-- [최종 산출물] 라이브러리 파일 저장소
        ├── static_calculator_lib.a     <-- 정적 라이브러리
        └── shared_calculator_lib.so    <-- 공유 라이브러리
    
    └── static_calculater_app       <-- 정적 링크 실행 파일
    └── shared_calculater_app       <-- 공유 링크 실행 파일
    └── dynamic_calculater_app      <-- 동적 로딩 실행 파일
```