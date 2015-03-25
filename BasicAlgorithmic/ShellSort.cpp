/*
Shell����Ļ���˼���ǣ����������зָ�Ϊ���ɸ������зֱ���в�������Ȼ��ı���飬�ٽ��в��룻�������п�Ϊd={n/2, n/4, n/8, �� ,11}��ֱ�Ӳ���������ʵ��d=1��ϣ������
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

template<typename T>
void ShellInsert(T unsorted[], int size ,int dk)
{//dkΪ����;��ֱ�Ӳ�������Աȼ���
	for(int i = dk; i < size; ++i)
	{
		if(unsorted[i] < unsorted[i-dk])
		{
			int j = i - dk;
			int temp = unsorted[i];
			while(j >= 0 && temp < unsorted[j])
			{
				unsorted[j+dk] = unsorted[j];
				j -= dk;
			}
			unsorted[j+dk] = temp;
		}
	}
}

template<typename T>
void ShellSort(T unsorted[], int size)
{
	int dk = size/2;
	while(dk >=1)
	{
		ShellInsert(unsorted, size ,dk);
		dk = dk/2;
	}
}
int main(int argc, char *argv[])
{
	int data[] = {12,4,1,6,3,9,10};
	ShellSort(data,7);
	for(int i=0;i<7;i++)
		cout << data[i] << " ";
	return 0;
}
