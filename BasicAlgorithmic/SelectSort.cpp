/*
�㷨˼�룺ÿ����δ����������������������������δ�������е����λ�ã��ظ��ù��̣�֪������Ԫ��������ϡ�
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void SelectSort(T data[], int size)
{
	int temp,max;
	for(int i = size-1; i > 0 ; --i)
	{
		max = i;
		for(int j=0; j < i ; j++)
		{
			if(data[j] > data[max])
				max = j;
		}
		if(max != i)
			swap(data[i],data[max]);
	}
}
int main(int argc, char *argv[])
{
	int data[] = {12,4,1,6,3,9,10};
	SelectSort(data,7);
	for(int i=0;i<7;i++)
		cout << data[i] << " ";
	return 0;
}
