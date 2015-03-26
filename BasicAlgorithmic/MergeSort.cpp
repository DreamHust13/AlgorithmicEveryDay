/*
归并排序是将两个或两个以上的有序子表合并成一个新的有序表。它的基本思想是分治法。对于二路归并而言，初始时将含有n个节点的待排序序列看作由n个长度为1的有序子表组成，将它们一次两两归并得到长度为2的若干有序自编，再对它们两两合并，知道得到长度为n的有序表，排序结束。

与快速排序和堆排序相比，归并排序的最大特点是，它是一种稳定的排序。归并排序可用顺序存储结构，也易于在链表上实现。对长度为n的文件，需进行log2n趟归并排序，每趟归并的时间为O(n)，故其时间复杂度无论是在最好情况还是在最坏情况下，均是O(nlog2n)。归并排序需要一个辅助空间来暂存两个有序子文件归并的结果，故其辅助空间空间复杂度为O(n)，显然它不是就地排序。

二路归并排序的核心操作是将一维数组中前后相邻的两个有序序列归并为一个有序序列。该过程相对简单，从两个数组的头部开始，每次比较选出两个数组的最小元素，谁最小先去睡，取后将对应数组中的数删除即可。然后再进行比较，直到有数组为空，再把另一个数组中的数依次取出即可。

*/
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

void MergeOrderedArray(int data[], int start, int mid, int end ,int temp[])
{//合并有序数组：其实合并的是[start,mid]和[mid+1,end]
	int i = start, j = mid +1, pTemp = start;

	while(i <= mid && j <= end)
	{
		if(data[i] <= data[j])
			temp[pTemp++] = data[i++];
		else
			temp[pTemp++] = data[j++];
	}
	while(i <= mid)//非空
		temp[pTemp++] = data[i++];
	while(j <= end)
		temp[pTemp++] = data[j++];
	for(pTemp = start; pTemp <= end; pTemp++)
		data[pTemp]= temp[pTemp];//将辅助数组数据写回原数组
}

void MergeSortRecursively(int data[], int start, int end,int temp[])
{//对数组data中范围在[start, end]中的数据进行归并排序
	if(start >=0 && start < end)
	{
		int mid = (start + end)/2;
		MergeSortRecursively(data, start, mid,temp);//递归排序左边的数组
		MergeSortRecursively(data, mid+1, end,temp);//递归排序右边的数组
		MergeOrderedArray(data, start, mid, end,temp);//合并两个已经排序的相邻数组
	}
}

void MergeSort(int data[] ,int size)
{
	if(data == NULL || size < 2)
		return;
	int *temp = new int[size];//创建辅助空间
	MergeSortRecursively(data, 0 ,size-1, temp);
	delete[] temp;
}
int  main()
{
    int unsorted[] = {3,6,1,4,5};
    int length = sizeof(unsorted)/sizeof(int);

    for(int i=0;i<length;++i)
       cout<<unsorted[i]<<" ";
    cout<<endl;

    MergeSort(unsorted,length);

    for(int i=0;i<length;++i)
        cout<<unsorted[i]<<" ";
    cout<<endl;

    return 0;
}
