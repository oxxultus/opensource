# .PHONY 설정 
.PHONY = all clean setup build run

# 기본 설정
AR = ar
CC = gcc
HEADER_DIR = -I./include
CFLAG = -Wall -Wextra -g
DEBUG = -DNDBUG
PRINT = @

# 소스 파일 경로 설정
MAIN_SRC = main.c

# 빌드 헤더파일 경로
ASSERT_H = include/my_assert.h
ASSERT_C = src/my_assert.c


STATIC_APP = build/test_app
STATIC_APP_DEBUG = build/test_app_debug


# 타겟 설정

all: run

build: $(STATIC_APP)
	@echo ""
	@echo "정적 실행 파일은 아래에 실행됩니다. (./$(STATIC_APP))"
	@echo ""

# 빌드 + 실행 타겟 
run: build
	@echo ""
	@echo "정적 실행 파일은 아래에 실행됩니다. (자동 값 인자77)"
	@echo ""
	$(PRINT)./$(STATIC_APP) 77

debug: $(STATIC_APP_DEBUG)
	@echo ""
	@echo "디버그 빌드로 진행합니다. (./$(STATIC_APP_DEBUG))"
	@echo ""

# 빌드 + 실행 타겟 
run-debug: debug
	@echo ""
	@echo "정적 디버그 적용 실행파일. (자동 값 인자77)"
	@echo ""
	$(PRINT)./$(STATIC_APP_DEBUG) 101

clean:
	@rm -f $(STATIC_APP) $(STATIC_APP_DEBUG)
	
setup:
	@mkdir -p src include build/lib build/obj
	@echo ""
	@echo "초기 설정"
	@echo ""


# 빌드 설정

# 1. 매크로가 지정되지 않은 정적 실행 파일 생성
$(STATIC_APP_DEBUG): $(MAIN_SRC)
	$(PRINT)$(CC) $(CFLAG) $(HEADER_DIR) $< -o $@

# 1. 매크로 설정된 실행 파일 생성
$(STATIC_APP): $(MAIN_SRC)
	$(PRINT)$(CC) $(CFLAG) $(DEBUG) $(HEADER_DIR) $< -o $@
