// calculator.c
#include "calculator.h"
#include <stdio.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "오류: 0으로 나눌 수 없습니다.\n");
        return 0; // 0으로 나누기 시도 시 0 반환
    }
    return a / b;
}