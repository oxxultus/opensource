# .PHONY 설정 
.PHONY = all clean setup build run

# 기본 설정
AR = ar
CC = gcc
HEADER_DIR = -I./include
CFLAG = -Wall -Wextra -g
PRINT = @

# 소스 파일 경로 설정
MAIN_SRC = main.c

# 빌드 헤더파일 경로
ASSERT_H = include/my_assert.h
ASSERT_C = src/my_assert.c


STATIC_APP = build/test_app


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

clean:
	@rm -r $(STATIC_APP)
	
setup:
	@mkdir -p src include build/lib build/obj
	@echo ""
	@echo "초기 설정"
	@echo ""


# 빌드 설정

# 1. 정적 실행 파일 생성
$(STATIC_APP): $(MAIN_SRC)
	$(PRINT)$(CC) $(CFLAG) $(HEADER_DIR) $< -o $@
