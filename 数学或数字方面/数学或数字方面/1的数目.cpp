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



Hash Tables
哈希表
While not all problems can be solved with hash tables, a shocking number of interview problems can be Before your interview, make sure to practice both using and implementinghash tables
尽管哈希表不能解决所有的问题，但是面试中的大部分问题能用它解决。在面试之前一定要好好准备下哈希表的使用和实现。
1 public HashMap buildMap(Student[] students) {2 HashMap map = new HashMap();3 for (Student s : students) map.put(s.getId(), s);4 return map;5 }

ArrayList (Dynamically Resizing Array):
数组链表
An ArrayList, or a dynamically resizing array, is an array that resizes itself as needed whilestill providing O(1) access A typical implementation is that when a vector is full, the arraydoubles in size Each doubling takes O(n) time, but happens so rarely that its amortized timeis still O(1)
数组链表(大小可动态变化的数组)在使用中能够根据需要扩大数组的容量，并且能够提供O(1)的随机访问效率。数组链表典型的一种实现方法就是：当达到数组上限，就将数组容量扩大一倍。虽然在扩大容量时候的时间复杂度为O(n)，但是这样情况都较少发生，所以总的时间开销可近似为O(1)。
1 public ArrayList merge(String[] words, String[] more) {2 ArrayList sentence = new ArrayList();3 for (String w : words) sentence.add(w);4 for (String w : more) sentence.add(w);5 return sentence;6 }

StringBuffer / StringBuilder
字符串
Question: What is the running time of this code?
1 public String makeSentence(String[] words) {2 StringBuffer sentence = new StringBuffer();3 for (String w : words) sentence.append(w);4 return sentence.toString();5 }
问：下面这段代码的时间复杂度？
Answer: O(n^2), where n is the number of letters in sentence Here’s why: each time youappend a string to sentence, you create a copy of sentence and run through all the letters insentence to copy them over If you have to iterate through up to n characters each time in the loop, and you’re looping at least n times, that gives you an O(n^2) run time Ouch! With StringBuffer (or StringBuilder) can help you avoid this problem 1 public String makeSentence(String[] words) {2 StringBuffer sentence = new StringBuffer();3 for (String w : words) sentence.append(w);4 return sentence.toString();5 }
答：O(n^2)，这里的n为字符串sentence中的字符的个数。理由如下：每次你在向字符串sentence串中才追加一个数组的时候，就需要重新复制一次sentence中的字符，每次复制都需要从头到尾遍历一次sentence。这样的话把所有的单词追加到sentence中的时间复杂度为O(n^2)。
1.1 Implement an algorithm to determine if a string has all unique characters What if you can not use additional data structures? 
For simplicity, assume char set is ASCII (if not, we need to increase the storage size The rest of the logic would be the same) NOTE: This is a great thing to point out to your interviewer!
1 public static boolean isUniqueChars2(String str) { 
2 boolean[] char_set = new boolean[256]; 
3 for (int i = 0; i < str.length(); i++) { 
4 int val = str.charAt(i); 
5 if (char_set[val]) return false; 
6 char_set[val] = true; 
7 } 
8 return true; 
9 } 
We can reduce our space usage a little bit by using a bit vector We will assume, in the below code, that the string is only lower case ‘a’ through ‘z’ This will allow us to use just a single int
Alternatively, we could do the following: 

1 Check every char of the string with every other char of the string for duplicate occurrences This will take O(n^2) time and no space
2 If we are allowed to destroy the input string, we could sort the string in O(n log n) time and then linearly check the string for neighboring characters that are identical Careful, though - many sorting algorithms take up extra space 
1.1 设计算法判断一个字符串中字符都是否唯一的。如果不能使用额外的数据结构呢？
解答1.1：先假设字符串中的字符均为ASCII码(如果不是的可以增大存储空间，而算法的逻辑是相同的)。“假设”在你的面试中非常的重要。

算法的时间空间复杂度均为O(n)，n为字符串的长度。
采用bit序列来代替数组可以为我们进一步节省空间。这里我们需要假设字符串中的字符为'a'-'z'。这样只要用一个int型的变量就能记录字符是否出现了。
