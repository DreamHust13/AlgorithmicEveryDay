//ð������
//�㷨˼�룺��n�����������������n-1������ÿ�ι�Ϊһ������
//          ÿ�αȽ��������ڵ�Ԫ�أ�������ǵ�˳����󣬾Ͱ����ǽ���������
//���Ӷȣ�O(N2)

//�Ż�����¼�Ƿ���������true���ǣ�false����

#include <iostream>
using namespace std;

void BubbleSort(int unsorted[],int n)
{
    bool flag = true;
            
     while(flag)
    {
        for(int i = 1; i < n; ++i)//n-1������
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