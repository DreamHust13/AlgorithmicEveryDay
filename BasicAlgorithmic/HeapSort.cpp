/*堆排序
 *时间复杂度：O(NlogN)
 *堆是完全二叉树；且有大小堆之分
 *注意：数组从1开始，因为这样才满足;对于节点i，其左孩子是2*i,右孩子是2*i+1
 *应用：最大堆排序用来从小到大排序数列
 *扩展：堆经常被用来求一个数列中的第K大的数，只需要建立一个大小为K的最小堆，堆顶就是第K大的数；
 *		(如：选前k个数建最小堆，若后面的数比堆顶小，舍弃；若比堆顶大，舍弃堆顶，将数据插入
 *			调整最小堆)！！！想清楚
 *			求数列中第K小的数，建立大小为K的最大堆，堆顶就是第K小的数。复杂度为O(NlogK)
 *			//参见《编程之美》Chapter5的第五节
*/

#include "stdafx.h"
#include <algorithm>//std::swap()
#include <iostream>

using namespace std;

void HeapAdjust(int a[], int i, int size)
//a为堆数组，i为当前要调整的节点，以下标i为堆顶，将剩余size个元素调整为堆(即节点数为size)

{
	int lchild = 2 * i;//i节点左右孩子节点序号
	int rchild = 2 * i + 1;
	int max = i;//临时变量,记录最大值的下标

	if(i <= size / 2)//对叶节点i进行调整
	{
		if(lchild <= size && a[lchild] > a[max])//注意边界检查，包括size
			max = lchild;
		if(rchild <= size && a[rchild] > a[max])
			max = rchild;
		if(max != i)//需调整
		{
			swap(a[i], a[max]);
			HeapAdjust(a, max, size); //避免调整后以下标max为父节点的子树不是堆
		}
	}
}

void BuildHeap(int a[], int size)//建堆
{
	for(int i = size/2; i >= 1; --i)//非叶节点最大序号值为size/2 
		HeapAdjust(a, i, size);
}

void HeapSort(int a[],int size)//堆排序
{
	BuildHeap(a,size);
	for(int i=size;i>=2;--i)//到2！
	{
		swap(a[1],a[i]);//交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
		HeapAdjust(a,1,i-1);//重新调整，将余下元素调成大顶堆
	}
}

int main(int argc, char *argv[])
{
	//int a[] = {0,16,20,3,11,17,8};
	int a[100];
	cout << "请输入要排序的数字个数：" ;
	int size;
	while(cin >> size && size>0 && size < 100)
	{
		for(int i=1; i <= size; ++i)//注意从下标1开始存数据
			cin >> a[i];
		HeapSort(a,size);
		for(int i=1; i <= size; ++i)
			cout << a[i] << " ";
		cout << endl;
		cout << "请输入要排序的数字个数：" ;
	}
	return 0;
}

