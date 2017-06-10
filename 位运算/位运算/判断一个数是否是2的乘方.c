#pragma once
#include <assert.h>

//判断一个数是否是2的乘方 （在其二进制表示中，只有一个1，其余全是0）
bool isPowerOf2(int number)
{
	return 0 == (number & number - 1); //优先级顺序：-、&（逻辑与）、==
}

//找出一堆数中，只出现一次的唯一一个数（其余的数都出现了两次）
int getNumber_1(int arr[], size_t size)
{
	assert(arr);
	
	int number = 0; //0与任何数n异或，都等于n

	for (size_t i = 0; i < size; ++i)
	{
		number ^= arr[i];
	}
	
	return number;
}

//找出一堆数中，只出现一次的两个数（其余的数都出现了两次）
/*
	分治法，
找出两数之间二进制位上一个值不同的地方，
然后以该位为条件，将数组分为两组，分别异或，
最终结果就是求得的值
*/
void getNumber(int arr[], size_t size, int* n1, int* n2)
{
	assert(arr);
	
	int result = 0;
	
	for (size_t i = 0; i <size; ++i)
		result ^= arr[i];
	
	//此时result保存了n1与n2之间二进制序列的不同的信息
	//找出其中一个位不同的地方
	int pos = 0;
	while (result)
	{	
		if (result&1)
			break;
		++pos;
		result >>= 1;
	}
	//此时pos表示n1与n2之间在第pos位上二进制不同
	//下面将数组分为两类，分别异或得到n1与n2
	*n1 = 0;
	*n2 = 0; //先将n1,n2置为0
	
	for (size_t i = 0; i < size; ++i)
	{
		if ((arr[i] >> pos)&1)
			n1 ^= arr[i];
		else
			n2 ^= arr[i];
	}
	
	//循环结束，n1、n2结果求得。利用输入型参数性质，返回。
}