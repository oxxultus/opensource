// main.c
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> // 동적 로딩 함수 (dlopen, dlsym, dlclose) 사용

#define CALC_SO "./build/lib/shared_calculator_lib.so" // 동적 라이브러리 파일 경로

// 1. 함수 포인터 타입 정의: 모든 사칙연산 함수는 이 형식을 따름
typedef double (*calc_func_t)(double, double);

int main() {
    void *handle = NULL;
    char *error = NULL;
    double num1, num2;
    char operator;
    
    // 2. 함수 포인터 변수 선언
    calc_func_t add_func = NULL;
    calc_func_t subtract_func = NULL;
    calc_func_t multiply_func = NULL;
    calc_func_t divide_func = NULL;

    // --- 1단계: 라이브러리 로드 ---
    printf("--- 동적 로딩 시작: libcalc.so 로드 중 ---\n");
    handle = dlopen(CALC_SO, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "dlopen 실패: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    // --- 2단계: 함수 주소 찾기 (심볼 매핑) ---
    // dlsym으로 각 함수의 주소를 찾고 함수 포인터에 저장
    *(void **)(&add_func) = dlsym(handle, "add");
    *(void **)(&subtract_func) = dlsym(handle, "subtract");
    *(void **)(&multiply_func) = dlsym(handle, "multiply");
    *(void **)(&divide_func) = dlsym(handle, "divide");

    // dlsym 후 dlerror() 호출을 통해 오류 확인
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "dlsym 오류: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }
    printf("라이브러리 로드 및 함수 주소 매핑 성공.\n\n");


    // --- 3단계: 사용자 입력 및 함수 호출 ---
    printf("연산식을 입력하세요. (예, 3 + 4): ");
    if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
        printf("잘못된 입력입니다.\n");
        dlclose(handle);
        return 1;
    }

    double result = 0.0;
    int success = 1;
    
    switch (operator) {
        case '+':
            result = add_func(num1, num2);
            break;
        case '-':
            result = subtract_func(num1, num2);
            break;
        case '*':
            result = multiply_func(num1, num2);
            break;
        case '/':
            result = divide_func(num1, num2); 
            break;
        default:
            printf("잘못된 연산자입니다. (+, -, *, / 중 하나를 사용하세요)\n");
            success = 0;
    }

    if (success) {
        printf("결과: %.2f\n", result);
    }
    
    // --- 4단계: 라이브러리 해제 ---
    dlclose(handle);
    printf("\n동적 라이브러리 사용 종료 및 해제.\n");

    return 0;
}