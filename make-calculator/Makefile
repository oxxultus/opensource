# Makefile
# 작성자: oxxultus
# 명령어 앞에 @를 붙이면 해당 명령어가 터미널에 출력되지 않습니다 (조용한 모드).
PRINT = @ # 실행 내역을 출력하려면 @자리에 스페이스로 공백을 넣으세요.

# -------------------- 기본 설정 --------------------
CC = gcc					# 컴파일러
AR = ar						# 라이브러리 생성 도구

# 옵션 설정
CFLAGS = -Wall -Wextra 		# 컴파일러 옵션
FPIC = -fPIC				# 위치 독립 코드 옵션 (공유 라이브러리용)
SHARED = -shared			# 공유 라이브러리 옵션

# 헤더 파일 경로 설정
HEADER_DIR = -I./include 	# 추가적으로 탐색할 헤더 파일 경로

# PHONY 타겟 설정
.PHONY: all clean static shared dynamic setup run-static run-shared run-dynamic help

# -------------------- 변수 설정 --------------------

# main 소스 파일 경로
MAIN_SRC		 = main.c 			# 정적, 공유
MAIN_SRC_DYNAMIC = main_dynamic.c 	# 동적

# 공통 헤더 파일 경로
CALC_C = src/calculator.c
CALC_H = include/calculator.h

# 정적 라이브러리 빌드 설정
STATIC_CALC_OBJ = build/obj/static_calculator.o
STATIC_CALC_LIB = build/lib/static_calculator_lib.a
STATIC_CALC_APP = build/static_calculater_app

# 공유 라이브러리 빌드 설정
SHARED_CALC_OBJ = build/obj/shared_calculator.o
SHARED_CALC_LIB = build/lib/shared_calculator_lib.so
SHARED_CALC_APP = build/shared_calculater_app

# 동적 라이브러리 빌드 설정
DYNAMIC_CALC_APP = build/dynamic_calculater_app


# -------------------- 기본 타겟 --------------------

all: help

static: $(STATIC_CALC_APP) 		# 라이브러리 및 실행 파일 생성

shared: $(SHARED_CALC_APP) 		# 공유 라이브러리 및 실행 파일 생성

dynamic: $(DYNAMIC_CALC_APP) 	# 동적 라이브러리 및 실행 파일 생성

# 빌드 + 실행 타겟 
run-static: static
	@echo ""
	@echo "정적 실행 파일은 아래에 실행됩니다."
	@echo ""
	$(PRINT)./$(STATIC_CALC_APP)

run-shared: shared
	@echo ""
	@echo "공유 실행 파일은 아래에 실행됩니다."
	@echo ""
	$(PRINT)./$(SHARED_CALC_APP)

run-dynamic: dynamic
	@echo ""
	@echo "동적 실행 파일은 아래에 실행됩니다."
	$(PRINT)./$(DYNAMIC_CALC_APP)

setup:
	@mkdir -p build/lib build/obj include src
	@echo ""
	@echo "	기본 디렉토리 생성 완료"
	@echo ""

clean:
	@rm -f $(STATIC_CALC_OBJ) $(STATIC_CALC_LIB) $(STATIC_CALC_APP)
	@rm -f $(SHARED_CALC_OBJ) $(SHARED_CALC_LIB) $(SHARED_CALC_APP)
	@rm -f $(DYNAMIC_CALC_APP)
	@echo ""
	@echo "	정적 / 공유 / 동적 빌드 결과물 정리 완료"
	@echo ""

help:
	@echo "Makefile 사용법:"
	@echo "  make [target]"
	@echo ""
	@echo "타겟 목록:"
	@echo "  all            : 기본 타겟 (help)"
	@echo "  static         : 정적 라이브러리 및 실행 파일 생성"
	@echo "  shared         : 공유 라이브러리 및 실행 파일 생성"
	@echo "  dynamic        : 동적 라이브러리 및 실행 파일 생성"
	@echo "  run-static     : 정적 실행 파일 빌드 및 실행"
	@echo "  run-shared     : 공유 실행 파일 빌드 및 실행"
	@echo "  run-dynamic    : 동적 실행 파일 빌드 및 실행"
	@echo "  setup          : 기본 디렉토리 구조 생성"
	@echo "  clean          : 빌드 파일 정리"
	@echo "  help           : 도움말 출력"

# -------------------- 정적 라이브러리 생성 규칙 --------------------

# 1. 정적 오브젝트 파일 생성
$(STATIC_CALC_OBJ): $(CALC_C) $(CALC_H)
	$(PRINT)$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@
	@echo ""
	@echo "컴파일 로그:"
	@echo "  [0] 컴파일러: $(CC)"
	@echo "  [1] 정적 오브젝트 파일 생성 완료: $@"

# 2. 정적 라이브러리 생성 (.a)
$(STATIC_CALC_LIB): $(STATIC_CALC_OBJ)
	$(PRINT)$(AR) rcs $@ $<
	@echo "  [2] 정적 라이브러리 생성 완료: $@"

# 3. 정적 링크 실행 파일 생성
$(STATIC_CALC_APP): $(MAIN_SRC) $(STATIC_CALC_LIB)
	$(PRINT)$(CC) $(CFLAGS) $(HEADER_DIR) $^ -o $@
	@echo "  [3] 정적 실행 파일 생성 완료: $@"

# -------------------- 공유 라이브러리 생성 규칙 --------------------

# 1. 공유 오브젝트 파일 생성
$(SHARED_CALC_OBJ): $(CALC_C) $(CALC_H)
	$(PRINT)$(CC) $(CFLAGS) $(HEADER_DIR) $(FPIC) -c $< -o $@
	@echo ""
	@echo "컴파일 로그:"
	@echo "  [0] 컴파일러: $(CC)"
	@echo "  [1] 공유 오브젝트 파일 생성 완료: $@"

# 2. 공유 라이브러리 생성 (.so)
$(SHARED_CALC_LIB): $(SHARED_CALC_OBJ)
	$(PRINT)$(CC) $(SHARED) $< -o $@
	@echo "  [2] 공유 라이브러리 생성 완료: $@"

# 3. 공유 링크 실행 파일 생성
$(SHARED_CALC_APP): $(MAIN_SRC) $(SHARED_CALC_LIB)
	$(PRINT)$(CC) $(CFLAGS) $(HEADER_DIR) $^ -o $@
	@echo "  [3] 공유 실행 파일 생성 완료: $@"

# -------------------- 동적 라이브러리 생성 규칙 --------------------

# 공유 라이브러리의 생성 규칙을 사용해 동적 링크 실행 파일을 생성합니다.
# -ldl 옵션은 동적 라이브러리 로딩을 위해 만들어진 라이브러리를 링크할때 필요합니다.
$(DYNAMIC_CALC_APP): $(MAIN_SRC_DYNAMIC) $(SHARED_CALC_LIB)
	$(PRINT)$(CC) $(CFLAGS) $(HEADER_DIR) $^ -ldl -o $@
	@echo "[3] 동적 실행 파일 생성 완료: $@"
