//判断一个数的二进制中1的个数
int getCountOf1(int number)
{
	int count = 0;

	while (number)
	{
		++count;

		number &= number - 1;
	}

	return count;
}

//求正整数A、B的二进制序列中有多少是不同的（把A变成B需要改变多少bit位）
int Count(int A, int B)
{
	int C = A^B;

	return getCountOf1(C);
}