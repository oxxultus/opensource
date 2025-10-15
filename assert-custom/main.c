/*
 * my_assert.h
 */


#include <stdio.h>
#include <stdlib.h>
#include "my_assert.h"

// 함수 선언부
void foo(int num);

// 메인 함수
int main(int argc, char *argv[]){
	int num;
	if(argc < 2){
		fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <=100)\n");
		exit(1);
	}
	
	num = atoi(argv[1]);
	foo(num);
}



// 함수 구현부
void foo(int num){
	my_assert( ((num >= 0) && (num <= 100)) );

	printf("foo: num = %d", num);

}
