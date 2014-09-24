/*求子数组的最大和

题目：输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，
每个子数组都有一个和。求所有子数组的和的最大值。要求时间复杂度为O(n)。
 
例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
因此输出为该子数组的和18。
 
因为是O(N)的复杂度，因此需采用的DP的思想，记录下当前元素之和（为其最优状态，既最大），
将其与目前所得的最大和比较，若大于则更新，否则继续。
状态的累加遵循这个过程：如果当前和小于0，则放弃该状态，将其归零
*/

/*求子数组的最大和
利用的是dp的思想，依次遍历数组中的每个元素，把他们相加，如果加起来小于0，则
把当前元素之和清为0，否则则和最大和比较，更新最大和，最后得到必是子数组的
最大和
*/
#include <iostream>
using namespace std;

/*法一：
int findGreatestSubSum(const int a[],const int size) 
{
	if(size<=0)
	{
		cout<<"error array size"<<endl;
		return 0;
	}
	int curSum=0;
	int maxSum=0;
	int i=0;
	for(i=0;i<size;i++)
	{
		curSum += a[i];
		if(curSum<0)//放弃这个阶段，重新开始
			curSum=0;
		if(curSum>maxSum)//更新最大和
			maxSum=curSum;
	}
	if(0==maxSum)//若数组中的元素均为负数，则输出里面的最大元素
	{            //这步也可以写到上一循环中
		maxSum=a[0];
		for(i=1;i<size;i++)
		{
			if(maxSum<a[i])
				maxSum=a[i];
		}
	}
	return maxSum;
}

void main()
{
	//int a[10]={1,-2,3,10,-4,7,2,-5};
	int b[5]={-1,-2,0,-5,-10};
	cout<<findGreatestSubSum(b,0)<<endl;


}
*/
//另一种解决特殊情况的巧妙方法在于max初始值的设置，
//我们可以通过赋初值max==-(1<<31)；就可以很轻松的搞定特殊情况了。
//因为此时即使数组元素都为负，那么其中的元素也一定大于等于max，
//所以就避免了上面所述的特殊情况。代码如下：

/*
bool maxSubarray(int data[], int size,int &max) 
{
    if (size<=0) 
    {
        printf("error array size\n");
        return false;
    }
    int sum = 0;

    max=-(1<<31);
	
    for(int i=0;i<size;i++)
    {

       sum +=data[i];
       if(sum>max)
       {
             max=sum;
       }
       else if(sum<0)
      {
           sum=0;
      }
   }
   return true;
}
int main()
{
 int data[]={1, -2, 3, 10, -4, 7, 2, -5};
 int max;
 if( maxSubarray(data,8,max))
         printf("%d\n",max);

 int data2[]={-1, -2, -3, -10, -4, -7, -2, -5};
 if( maxSubarray(data2,8,max) )
         printf("%d\n",max);
 
 getchar();
 return 0;
}


*/
//可见，代码简约了不少^_^

//另外，类似的问题还有：有一个数组a[n],里面的数只有两种：-1或1。i，j是两个整数，
//假设0<=i<=j<=n-1，找出a[i]到a[j]中连续数之和最大的部分（
//如果最大部分存在相等的则优先找最短的）。问题的解法是类似的，
//至于寻找最短的也比较简单，就不多说了。


