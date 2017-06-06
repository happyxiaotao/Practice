#pragma once

//判断一个数是否是2的乘方
bool isPowerOf2(int number)
{
	return 0 == (number & number - 1); //优先级顺序：-、&（逻辑与）、==
}
