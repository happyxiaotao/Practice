#pragma once

//�ж�һ�����Ƿ���2�ĳ˷�
bool isPowerOf2(int number)
{
	return 0 == (number & number - 1); //���ȼ�˳��-��&���߼��룩��==
}

//�ж�һ�����Ķ�������1�ĸ���
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