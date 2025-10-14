#!/bin/bash
# for 반복문을 사용한 구구단 출력

TARGET_DAN=$1

# 인자 유효성 검사
if ! [[ "$TARGET_DAN" =~ ^[0-9]+$ ]]; then
    echo "오류: 유효한 숫자(0 이상)를 인자로 입력해야 합니다."
    echo "사용법: $0 [단_수]"
    exit 1 #종료
fi

echo ""
echo "--- ${TARGET_DAN} 단 구구단 (FOR) ---"

# C 스타일의 for 반복문 사용
for (( i=1; i <= 9; i++ )); do
    # 여기서 이중 괄호를 사용하는 이유는 단일 괄호는 명령어 이중괄호는 산술연산
    RESULT=$((TARGET_DAN * i)) 
    echo "${TARGET_DAN} X ${i} = ${RESULT}"
done

# 중괄호 확장 {1..9}를 사용하여 1부터 9까지 반복
#for i in {1..9}; do
#    RESULT=$((TARGET_DAN * i))
#    echo "${TARGET_DAN} X ${i} = ${RESULT}"
#done

echo "-----------------------------------"