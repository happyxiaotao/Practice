#pragma once
#include <assert.h>

//�ж�һ�����Ƿ���2�ĳ˷�
bool isPowerOf2(int number)
{
	return 0 == (number & number - 1); //���ȼ�˳��-��&���߼��룩��==
}

//�ҳ�һ�����У�ֻ����һ�ε�Ψһһ������������������������Σ�
int getNumber_1(int arr[], size_t size)
{
	assert(arr);
	
	int number = 0; //0���κ���n��򣬶�����n

	for (size_t i = 0; i < size; ++i)
	{
		number ^= arr[i];
	}
	
	return number;
}

//�ҳ�һ�����У�ֻ����һ�ε���������������������������Σ�