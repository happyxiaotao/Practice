//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>

#include <iostream>	// ����stdio.h��ctype.h��stdlib.h��һЩ����
using namespace std;

/*
���ַ���ת��Ϊ��������ģ��ʵ��atoi()
*/
int  StrToInt(const char* str)
{
	//��������
	if (!str)
		return 0;

	const int MAX_INT = (int)((unsigned)~0 >> 1);  //��ʾint���ֵ
	const int MIN_INT = - MAX_INT - 1;		//��ʾint��Сֵ

	//�����ո�
	while (isspace(*str))
		++str;

	//�ж�������
	int flag = 1;
	if (('+' == *str) || ('-' == *str))
		if ('-' == *str)
			flag = -1;

	int n = 0;
	//ȷ���������ַ���������
	while (isdigit(*str))
	{
		int c = *str - '0';

		//�߽紦��
		if (flag && ((MAX_INT / 10 < n) || (MAX_INT / 10 == n && MAX_INT % 10 < c)))
		{
			n = MAX_INT;
			break;
		}
		else if (!flag && (((unsigned)MIN_INT / 10 < n) || (MIN_INT / 10 == n && MIN_INT % 10 < c)))
		{
			n = MIN_INT;	//	+/-MIN_INT��ʾ�Ķ�������ͬ������Ҳ�ʺ����ķ������
			break;
		}
		
		///��֮ǰ�õ������ֳ���10���ټ��ϵ�ǰ�ַ���ʾ�����֡�
		n = n * 10 + c;
		++str;
	}

	return flag ? n : -n; //��flagΪ-1ʱ��
}