//�ж�һ�����Ķ�������1�ĸ���
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

//��������A��B�Ķ������������ж����ǲ�ͬ�ģ���A���B��Ҫ�ı����bitλ��
int Count(int A, int B)
{
	int C = A^B;

	return getCountOf1(C);
}