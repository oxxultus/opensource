// 중복로딩 방지
#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#ifdef NDBUG
// 아무런 동작도 하지 않는 코드로 정의됩니다.
#define my_assert(expression) ((void)0)

#else
#define my_assert(expression) \
    do { \
        /* 조건식이 거짓일 경우 (어설션 실패) */ \
        if (!(expression)) { \
            /* 표준 오류 스트림(stderr)에 진단 메시지 출력 */ \
            fprintf(stderr, "Assertion 실패: %s, function %s, file %s, line %d\n", \
                    /* #expression: 인자를 문자열 상수로 변환 */ \
                    /* __func__: 현재 함수 이름 (C99 이상) */ \
                    /* __FILE__: 현재 파일 이름 */ \
                    /* __LINE__: 매크로 호출 라인 번호 */ \
                    #expression, __func__, __FILE__, __LINE__); \
            /* 프로그램 즉시 종료 */ \
            abort(); \
        } \
    } while (0)
#endif

#endif // MY_ASSERT_H
