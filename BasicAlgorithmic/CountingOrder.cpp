/*
基于比较的排序算法是不能突破O(NlogN)的，而非基于比较的排序，如计数排序、桶排序和计数排序，则可以突破O(NlogN)的时间下限。但要注意的是，非基于比较的排序算法的使用都是有条件限制的，例如元素的大小限制，而基于比较的排序则没有这种限制（在一定范围内）。对特定场合有着特殊性质的数据，非基于比较的排序算法则能够巧妙解决。
计数排序的优势是对已知范围的数组进行排序，其基本思想就是对每一个输入元素x，确定出小于x的个数，这样就可以直接把x放到它在最终数组中的位置上。
算法思路为：
1.	扫描序列A，以A中每个元素的值为索引，将C中对应位置的次数统计加1，即C[i]为A中i出现的次数。
2.	将C从头开始累加，使C[i]为A中值不大于i的元素的个数
3.	按照统计出的值，输出结果。
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

void CountingSort(int data[], int size, int range)
{//数据范围为[0,range]
	if(data == NULL || range <= 0 || size < 0)
		return;

	int *ordered = new int[size];//存放排序结果<不会初始化！！>
	int *count = new int[range+1];//临时存储区，存放统计次数

	int i;
	for(i=0; i<=range; i++)//注意范围！！
		count[i] = 0;//因为不会默认初始化为0
	for(i=0; i<size; i++)
		count[data[i]]++;//此时，C[i]为data中i的个数
		
	//对于形成最后排序数字，两个注释部分的效果是一样的，二选一即可
/*法一：
	int j=0;
	for(i=0; i<=range; i++)
	{
		while(count[i] != 0)
		{
			ordered[j++] = i;
			count[i]--;
		}
	}
*/
/*法二：
	for(i=1; i<=range; i++)
		count[i] += count[i-1];//此时，C[i]为data中不大于i的个数
	for(i=size-1; i>=0; i--)
	{//对data数组，从后向前确定每个数字所在的最终位置;也可以反向进行
		ordered[count[data[i]]-1] = data[i];//!!注意需要减1，因为数组从0开始
		count[data[i]]--;
	}
*/
	for(i=0;i<size;++i)
        cout<< ordered[i] <<" ";
    cout<<endl;
}

int  main()
{
    int unsorted[] = {3,6,1,4,5,5,8,4,9,9,10};
    int length = sizeof(unsorted)/sizeof(int);

    for(int i=0;i<length;++i)
       cout<<unsorted[i]<<" ";
    cout<<endl;

    CountingSort(unsorted,length,10);

    for(int i=0;i<length;++i)
        cout<<unsorted[i]<<" ";
    cout<<endl;

    return 0;
}
