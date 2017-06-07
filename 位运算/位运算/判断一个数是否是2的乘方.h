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