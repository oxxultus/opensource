#include <stdio.h>
#include "calculator.h"

int main(){
    double num1, num2;
    char operator;
    
    printf("연신식을 입력하세요. (예, 3 + 4): ");\
    // 값을 입력받습니다 단 입력 받은 인자가 3개가 아닐 경우 오류 메시지를 출력하고 종료합니다.
    if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    switch (operator) {
        case '+':
            printf("결과: %.2f\n", add(num1, num2));
            break;
        case '-':
            printf("결과: %.2f\n", subtract(num1, num2));
            break;
        case '*':
            printf("결과: %.2f\n", multiply(num1, num2));
            break;
        case '/':
            if (num2 == 0) {
                printf("오류: 0으로 나눌 수 없습니다.\n");
            } else {
                printf("결과: %.2f\n", divide(num1, num2));
            }
            break;
        default:
            printf("잘못된 연산자입니다. (+, -, *, / 중 하나를 사용하세요)\n");
    }

}