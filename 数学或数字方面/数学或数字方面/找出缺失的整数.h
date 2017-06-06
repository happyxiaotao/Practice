#pragma once

//例题：找出1-100中，缺失的某一个整数（将1-100中的数全部相加，然后减去存在的99个数）
int findInt(int arr[], size_t size) //arr表示包含存在数字的数组（size = 99）
{
	int sum = 0;

	for (int i = 1; i <= 100; ++i) //1-100的和
		sum += i;

	for (int i = 0; i < size; ++i) //减去存在的数字
		sum -= arr[i];

	return sum; //返回缺失的数字
}