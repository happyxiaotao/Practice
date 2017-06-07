#pragma once

//判断一个数是否是2的乘方
bool isPowerOf2(int number)
{
	return 0 == (number & number - 1); //优先级顺序：-、&（逻辑与）、==
}

//判断一个数的二进制中1的个数
int getCountOf1(int number)
{
	int count = 0;
	
	whlie (number)
	{
		++count;
		
		number &= number-1;
	}
	
	return count;
}

//找出一堆数中，只出现一次的唯一一个数（其余的数都出现了两次）
int getNumber_1(int arr[], size_t size)
{
	assert(arr);
	
	int number = 0; //0与任何数n异或，都等于n

	for (size i = 0; i < size; ++i)
	{
		number ^= arr[i];
	}
	
	return number;
}
//找出一堆数中，只出现一次的两个数（其余的数都出现了两次）