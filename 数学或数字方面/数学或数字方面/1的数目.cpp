/*
����������
����һ��ʮ����������N,д�´�1��ʼ����N������������Ȼ����һ�����г��ֵ����С�1���ĸ���
1��дһ������f(N)������1��N֮����ֵ�'1'�ĸ���������f(12)=5��
2����������f(N)=N ������N�Ƕ��٣�

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
	for (int i = 0; i < 30; ++i)
		cout << GetCountOf1(i) << endl;

	system("pause");
}