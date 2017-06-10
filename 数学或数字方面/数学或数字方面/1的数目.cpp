/*
问题描述：
给定一个十进制正整数N,写下从1开始，到N的所有整数，然后数一下其中出现的所有‘1’的个数
1，写一个函数f(N)，返回1到N之间出现的'1'的个数，比如f(12)=5；
2，满足条件f(N)=N 的最大的N是多少？

*/
#include <iostream>
using namespace std;
int GetCountOf1(int n)
{
	int count = 0;
	while (n)
	{
		if (1 == n % 10)
			++count;
		n /= 10;
	} 
	return count;
}

int F(int n)
{
	if (0 >= n)
		return 0;
	if (1 == n)
		return 1;
	return F(n - 1) + GetCountOf1(n);
}

int main()
{
	//for (int i = 0; i < 30; ++i)
	//{
	//	cout << "i = " << i << "：1的个数："<<GetCountOf1(i) << endl;
	//}
	cout << "开始" << endl;
/*	for (int i = 0; i < 300000; ++i)
	{
		cout << "0到" << i << "之间所有数中数字1的个数是：" << F(i) << endl;
	}
	*/
	F(30000);
	cout << "结束" << endl;
	system("pause");
}