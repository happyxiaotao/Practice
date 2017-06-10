#pragma once
#include <assert.h>

//�ж�һ�����Ƿ���2�ĳ˷� ����������Ʊ�ʾ�У�ֻ��һ��1������ȫ��0��
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
/*
	���η���
�ҳ�����֮�������λ��һ��ֵ��ͬ�ĵط���
Ȼ���Ը�λΪ�������������Ϊ���飬�ֱ����
���ս��������õ�ֵ
*/
void getNumber(int arr[], size_t size, int* n1, int* n2)
{
	assert(arr);
	
	int result = 0;
	
	for (size_t i = 0; i <size; ++i)
		result ^= arr[i];
	
	//��ʱresult������n1��n2֮����������еĲ�ͬ����Ϣ
	//�ҳ�����һ��λ��ͬ�ĵط�
	int pos = 0;
	while (result)
	{	
		if (result&1)
			break;
		++pos;
		result >>= 1;
	}
	//��ʱpos��ʾn1��n2֮���ڵ�posλ�϶����Ʋ�ͬ
	//���潫�����Ϊ���࣬�ֱ����õ�n1��n2
	*n1 = 0;
	*n2 = 0; //�Ƚ�n1,n2��Ϊ0
	
	for (size_t i = 0; i < size; ++i)
	{
		if ((arr[i] >> pos)&1)
			n1 ^= arr[i];
		else
			n2 ^= arr[i];
	}
	
	//ѭ��������n1��n2�����á����������Ͳ������ʣ����ء�
}