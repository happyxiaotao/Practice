#pragma once

//�ж�һ�����Ƿ���2�ĳ˷�
bool isPowerOf2(int number)
{
	return 0 == (number & number - 1); //���ȼ�˳��-��&���߼��룩��==
}
