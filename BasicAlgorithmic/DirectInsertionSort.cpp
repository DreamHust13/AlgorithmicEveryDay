/*
	插入排序的基本思想是：每次选择待排序的记录序列的第一个记录，按照排序值的大小将其插入到已排序的记录序列中的适当位置，直到所有记录全部排序完毕。
直接插入排序是一种最简单的排序方法，整个排序过程为：先将第一个记录看做一个有序记录序列，然后从第二个记录开始，依次将为排序的记录插入这个有序的记录序列中，直到整个文件中的全部记录排序完毕。

*/
#include "stdafx.h"
#include <iostream>
using namespace std;

template<typename T>
void DirectInsertSort(T unsorted[], int size)
{
	for(int i=1; i < size; ++i)
	{
		if(unsorted[i] < unsorted[i-1])//大于，无需操作；小于，需后移
		{
			int j = i-1;
			int temp = unsorted[i];//复制为哨兵，即存储为待排序元素
			while(j >= 0 && temp < unsorted[j])//查找在有序表中的插入位置
			{
				unsorted[j+1] = unsorted[j];//右移
				j--;
			}
			//找到位置，将temp插入
			unsorted[j+1] = temp;
		}
	}
}

int main(int argc, char *argv[])
{
	int data[] = {12,4,1,6,3,9,10};
	DirectInsertSort(data,7);
	for(int i=0;i<7;i++)
		cout << data[i] << " ";
	return 0;
}