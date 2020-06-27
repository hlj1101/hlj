// L32D.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "L32D.h"


// 这是导出变量的一个示例
L32D_API int nL32D=0;

// 这是导出函数的一个示例。
L32D_API int fnL32D(void)
{
    return 42;
}

L32D_API int factorial(int n)
{
	int sum = 1;
	for (int i = 1;i <= n;i++) {
		sum = sum*i;
	}
	return sum;
}

L32D_API float FAC::convert(float deg) {
	float n;
	n = deg*3.14 / 180;
	return n;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 L32D.h
CL32D::CL32D()
{
    return;
}
