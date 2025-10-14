#!/bin/bash
# while 반복문을 사용한 구구단 출력

TARGET_DAN=$1
i=1

# 인자 유효성 검사
if ! [[ "$TARGET_DAN" =~ ^[0-9]+$ ]]; then
    echo "오류: 유효한 숫자(0 이상)를 인자로 입력해야 합니다."
    echo "사용법: $0 [단_수]"
    exit 1
fi

echo ""
echo "--- ${TARGET_DAN} 단 구구단 (while) ---"

# while 반복문 사용 (조건식이 참이면 반복문 실행)
# $i 이 9 보다 작거나 같으면 참 (<=9 까지 반복)
while [ $i -le 9 ]; do 
    RESULT=$((TARGET_DAN * i))
    echo "${TARGET_DAN} X ${i} = ${RESULT}"

    # 증감식
    i=$((i + 1))
done

echo "-----------------------------------"