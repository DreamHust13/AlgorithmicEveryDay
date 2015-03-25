/*
快速排序
算法思想：
		快速排序采用的思想是分治思想。
		快速排序是找出一个元素（理论上可以随便找一个）作为基准(pivot),然后对数组进行分区操作,使基准左边元素的值都不大于基准值,基准右边的元素值都不小于基准值，如此作为基准的元素调整到排序后的正确位置。递归快速排序，将其他n-1个元素也调整到排序后的正确位置。最后每个元素都是在排序后的正确位置，排序完成。所以快速排序算法的核心算法是分区操作，即如何调整基准的位置以及调整返回基准的最终位置以便分治递归。
算法：
		QuickSort(A,start,end)
			if(start<end)
				then q<-Partition(A,start,end)
					QuickSort(A,start,q-1)
					QuickSort(A,q+1,end)
					
!!!		Partion(A,start,end)
			index<-random(start,end)
			exchange A[end]<->A[index]
			small<-start-1
			for index<-start to end-1
				do if A[index] < data[end]
					then small<-small+1
						if small!= index
							exchange A[index] <-> A[small]
			exchange[small+1]<->exchange[end]
			return small+1

复杂度：最坏O(N2);平均O(NlogN)
		快速排序的时间主要耗费在划分操作上，对长度为k的区间进行划分，共需k-1次关键字的比较。
		最坏情况是每次划分选取的基准都是当前无序区中关键字最小(或最大)的记录，划分的结果是基准左边的子区间为空(或右边的子区间为空)，而划分所得的另一个非空的子区间中记录数目，仅仅比划分前的无序区中记录个数减少一个。时间复杂度为O(n*n)
 		在最好情况下，每次划分所取的基准都是当前无序区的"中值"记录，划分的结果是基准的左、右两个无序子区间的长度大致相等。总的关键字比较次数：O(nlgn)
 		尽管快速排序的最坏时间为O(n2)，但就平均性能而言，它是基于关键字比较的内部排序算法中速度最快者，快速排序亦因此而得名。它的平均时间复杂度为O(nlgn)。
*/
/*
	!!!!!!!!!!!注意事项：
	1.数组大小，一定不能 void（int data[]）{int length = sizeof(data)/sizeof(int);}
		因为传进来是指针，不能判断数组大小，所以参数中要有计算好的大小
		
	2.Partition()算法理解！！！
	
*/
#include <algorithm>
#include <stdexcept>
#include <iostream>
using namespace std;

// Random Partition
int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

/*
void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
*/

int Partition(int data[], int length, int start, int end)
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
//        throw new std::exception("Invalid Parameters");
//Linux下不接受有参数的exception
        throw new logic_error("Invalid Parameters");

    int index = RandomInRange(start, end);
    swap(data[index], data[end]);

    int small = start - 1;
    for(index = start; index < end; ++ index)
    {
        if(data[index] < data[end])
        {
            ++ small;
            if(small != index)
                swap(data[index], data[small]);
        }
    }

    ++ small;
    swap(data[small], data[end]);

    return small;
}

int Partion(int data[], int length, int start, int end)
{//之前一直纠结的另一种Partition()实现方法，因为其用赋值替代了交换，所以更好。
	if(data == NULL || length <= 0 || start < 0 || end >= length)
		throw new logic_error("Invalid Parameters");
		
	int index = RandomInRange(start, end);
	swap(data[index],data[end]);
	int pleft = start;
	int pright = end;
	int temp = data[end];//保存基数的副本
	
	while(pleft < pright)
	{
		//!!注意顺序，因为基准为end，所以先从左向右遍历！！
		//从左向右遍历，直到遇到大于temp的值
		while(pleft < pright && data[pleft] <= temp)
			pleft++;
		if(pleft < pright)
			data[pright--] = data[pleft];
		//从右向左遍历，直到遇到小于temp的值
		while(pleft < pright && data[pright] >= temp)
			pright--;
		if(pleft < pright)
			data[pleft++] = data[pright];	
	}
	
	data[pleft] = temp;
	return pleft;	
}

void QuickSort(int unsorted[],int length,int start,int end)
{
	if(start < end)
	{
		int q = Partition(unsorted,length,start,end);
		QuickSort(unsorted,length,start,q-1);
		QuickSort(unsorted,length,q+1,end);
	}
}
int main()
{
	int unsorted[] = {3,6,1,4,5,11,23};
    int length = sizeof(unsorted)/sizeof(int);

    for(int i=0;i<length;++i)
       cout<<unsorted[i]<<" ";
	cout<<endl;

	QuickSort(unsorted,length,0,length-1);

	for(int i=0;i<length;++i)
        cout<<unsorted[i]<<" ";
    cout<<endl;
	return 0;
}
