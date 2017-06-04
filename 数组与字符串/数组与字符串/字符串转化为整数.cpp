//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>

#include <iostream>	// 包含stdio.h、ctype.h和stdlib.h的一些功能
using namespace std;

/*
将字符串转化为整数，即模拟实现atoi()
*/
int  StrToInt(const char* str)
{
	//参数处理
	if (!str)
		return 0;

	const int MAX_INT = (int)((unsigned)~0 >> 1);  //表示int最大值
	const int MIN_INT = - MAX_INT - 1;		//表示int最小值

	//跳过空格
	while (isspace(*str))
		++str;

	//判断正负号
	int flag = 1;
	if (('+' == *str) || ('-' == *str))
		if ('-' == *str)
			flag = -1;

	int n = 0;
	//确定是数字字符再做处理
	while (isdigit(*str))
	{
		int c = *str - '0';

		//边界处理
		if (flag && ((MAX_INT / 10 < n) || (MAX_INT / 10 == n && MAX_INT % 10 < c)))
		{
			n = MAX_INT;
			break;
		}
		else if (!flag && (((unsigned)MIN_INT / 10 < n) || (MIN_INT / 10 == n && MIN_INT % 10 < c)))
		{
			n = MIN_INT;	//	+/-MIN_INT表示的二进制相同，所以也适合最后的返回语句
			break;
		}
		
		///把之前得到的数字乘以10，再加上当前字符表示的数字。
		n = n * 10 + c;
		++str;
	}

	return flag ? n : -n; //当flag为-1时，
}