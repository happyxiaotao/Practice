/*
问题描述：寻找数组中的最大值Max与最小值Min

主要计算的是比较次数
解法一:
	分别寻找 时间复杂度O(2*N)

解法二:
	两两一组，将较大的数放在偶数位，将较小的数放在奇数位。然后在奇偶为上找到Min与Max。
	时间复杂度O（1.5*N），破坏了原数组

解法三:
	先将Max与Min赋值，然后利用解法二的类似步骤。
	时间复杂度O（1.5*N）

解法四:
	分治法：
	求整个数组的Max与Min。先求前后N/2个数的Max与Min，最后比较一下。
	时间复杂度是O（1.5*N -2）
*/

#include <iostream>
#include <cassert>
using namespace std;


//解法四代码
//利用键值对存储Max与Min
//在程序中下标为end的值是可取的
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
	
	//将满足条件的Max，与Min放在kvL中，然后返回
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