//冒泡排序
//算法思想：对n个数进行排序，需进行n-1趟排序，每次归为一个数。
//          每次比较两个相邻的元素，如果他们的顺序错误，就把它们交换过来。
//复杂度：O(N2)

//优化：记录是否发生交换（true：是，false：否）

#include <iostream>
using namespace std;

void BubbleSort(int unsorted[],int n)
{
    bool flag = true;
            
     while(flag)
    {
        for(int i = 1; i < n; ++i)//n-1次排序
        {
            flag = false;
            for(int j=1;j<n-i;j++)
            {
                if(unsorted[i-1] > unsorted[i])
                {
                    int temp = unsorted[i-1];
                    unsorted[i-1] = unsorted[i];
                    unsorted[i] = temp;
                    flag = true;
                 }
            }
            if(!flag)
                return;
         }
    }
}

int  main()
{
    int unsorted[] = {3,6,1,4,5};
    int n = sizeof(unsorted)/sizeof(int);

    for(int i=0;i<n;++i)
       cout<<unsorted[i]<<" ";
    cout<<endl;

    BubbleSort(unsorted,n);

    for(int i=0;i<n;++i)
        cout<<unsorted[i]<<" ";
    cout<<endl;

    return 0;
}