/*
如果是正数的话，还是原值。
如果是负数的话，就取反加1.
下面代码，功能类似。
*/
int ABS(int n)
{	
	int temp = n >> 31;
	
	//负数，取反 加1
	//return i == 0? a:(~n + 1)
	
	//或者，下面
	//temp为0或0xffffffff
	//temp^n为n或者~n。
	//-temp为0或者1
	return (temp^n - temp); 
}