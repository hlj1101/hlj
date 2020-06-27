#include "stdafx.h"
#include "win32.h"

char* pchar() {
	return "从静态取得的字符串：";
}
/*
int F1::factorial(int n) {
	int sum = 1;
	for (int i = 1;i <= n;i++) {
		sum = sum*i;
	}
	return sum;
}*/

int factorial(int n) {
	int sum = 1;
	for (int i = 1;i <= n;i++) {
		sum = sum*i;
	}
	return sum;
}