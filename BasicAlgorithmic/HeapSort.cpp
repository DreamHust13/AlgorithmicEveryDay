/*堆排序
 *
 *堆是完全二叉树；且有大小堆之分
 *注意：数组从1开始，因为这样才满足:对于节点i，其左孩子是2*i,右孩子是2*i+1
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void MaxHeapify(int *heapdata,int i,int size)//调整堆
//heapdata为堆数组，i为当前要调整的节点，size为数组大小，即节点数
{
    int lchild = 2*i;
    int rchild = 2*i+1;//i节点左右孩子节点序号
    int max = i;       //临时变量，初始假定第i个节点是最大的

    if(i <= size/2 && i>=1)//如果i为叶节点，则不需要调整
    {
        if( lchild<=size && heapdata[lchild]>max )
        {
            max = lchild;
        }
        if( rchild<=size && heapdata[rchild]>max)
        {
            max = rchild;
        }
        if(max != i)
        {
            swap(heapdata[i],heapdata[max]);
            MaxHeapify(heapdata,max,size);//调整之后，避免以max为父节点(原heapdata[i]的值)的子树不是最大堆
        }
    }
}

void BuildMaxHeap(int *heapdata,int size)//建最大堆
{
    int i;//循环控制变量

    for(i=size/2;i>=1;--i)//从最后一个非叶节点开始调整//!!!大于号写成小于号，一直找不到!!!
        MaxHeapify(heapdata,i,size);
}

void HeapSort(int *heapdata,int size)//堆排序
{
    int i;//循环控制变量

    BuildMaxHeap(heapdata,size);//建堆

    for(i=size;i<=2;i--)
    {
        swap(heapdata[i],heapdata[1]);//交换堆顶和最后一个元素，即每次将剩余元素中的最大者放在最后
        MaxHeapify(heapdata,1,i-1);//重新调整堆顶节点，生成最大堆
    }
}

int main()
{
    int heapdata[15];// = {99,5,36,7,22,17,46,12,2,19,25,28,1,92};
    int size;

   while(scanf("%d",&size)==1 && size>0)
    {
        int i;
        for(i=1;i<=size;++i)//注意从下标1开始存数据
            cin>>heapdata[i];
        HeapSort(heapdata,size);
        for(i=1;i<=size;++i)//输出由小到大排好序的数据
            cout<<heapdata[i]<<" ";
        cout<<endl;
    }
        return 0;
}
