/*
����������Ѱ�������е����ֵMax����СֵMin

��Ҫ������ǱȽϴ���
�ⷨһ:
	�ֱ�Ѱ�� ʱ�临�Ӷ�O(2*N)

�ⷨ��:
	����һ�飬���ϴ��������ż��λ������С������������λ��Ȼ������żΪ���ҵ�Min��Max��
	ʱ�临�Ӷ�O��1.5*N�����ƻ���ԭ����

�ⷨ��:
	�Ƚ�Max��Min��ֵ��Ȼ�����ýⷨ�������Ʋ��衣
	ʱ�临�Ӷ�O��1.5*N��

�ⷨ��:
	���η���
	�����������Max��Min������ǰ��N/2������Max��Min�����Ƚ�һ�¡�
	ʱ�临�Ӷ���O��1.5*N -2��
*/

#include <iostream>
#include <cassert>
using namespace std;


//�ⷨ�Ĵ���
//���ü�ֵ�Դ洢Max��Min
//�ڳ������±�Ϊend��ֵ�ǿ�ȡ��
pair<int, int> SearchMaxMin(int arr[], int begin, int end)
{
	assert(arr);
	if (1 >= end - begin)
	{
		if (arr[begin] > arr[end])
			return make_pair(arr[begin], arr[end]);
		return make_pair(arr[end], arr[begin]);
	}

	pair<int, int> kvL = SearchMaxMin(arr, begin, begin + ((end - begin) >> 1));
	pair<int, int> kvR = SearchMaxMin(arr, begin + ((end - begin) >> 1) + 1, end);
	
	//������������Max����Min����kvL�У�Ȼ�󷵻�
	kvL.first = (kvL.first > kvR.first) ? kvL.first : kvR.first;
	kvL.second = (kvL.second < kvR.second) ? kvL.second : kvR.second;

	return kvL;
}

int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
	pair<int, int> kv = SearchMaxMin(arr, 0, 10);

	cout << "Max = " << kv.first << endl;
	cout << "Min = " << kv.second << endl;
	system("pause");
	return 0;
}