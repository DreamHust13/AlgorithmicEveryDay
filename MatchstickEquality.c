/*火柴棍等式
 *《啊哈》
 *规则：用火柴棍拼出形如A+B=C的等式，式中A、B、C均为用火柴棍拼出的整数（若该数非零，最高位不为0）
 *数字0~9的拼法如下图所示：
 *不好画，但需要的火柴棍依次为6,2,5,5,4,5,6,3,7,6
 *注意：1.等号和加号各自需要两根火柴棍；2.若A！=B，则A+B=C与B+A=C为不同等式（A、B、C都大于0）；所有火柴棍都必须用上
 *规定时限1秒，火柴棍数m<=24
 *思考：出去加号和等号，剩下火柴m-4根，最多剩20根火柴，而0~9中，1需要的火柴棍最少，为两根，即最多能组成10个1,。
 *      故，A+B=C等式中，任意一个数不超过11111//！！！未想到多位数
 *  而最简单的枚举，若枚举A.B.C，O(N3)~~1000多秒，而只枚举A.B，C可以通过计算得出，O(N2)~~1秒
 *
 *别样思路：int numCost[1000]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};   
			for(i=10;i<100;i++)  
				numCost[i]=numCost[i%10]+numCost[i/10];  
			for(i=100;i<1000;i++)  
				numCost[i]=numCost[i/100]+numCost[i%10]+numCost[i%100/10];  
 			for(i=0;i<1000;i++)  
				for(j=0;j<1000;j++)  
					if(i+j<1000&&numCost[i]+numCost[j]+numCost[i+j]+4==n)  
						ans++;
 *问题：对于注意中的1.2,貌似并未验证。另，最高位不为0，貌似并不冲突
*/

#include <stdio.h>
const int OriginalMatchStick[10] = {6,2,5,5,4,5,6,3,7,6};//计数每个数字需要多少火柴棍的数组

//返回参数x需要的火柴棍总数
int MatchStickOfNumber(int x)
{
    int count=0;//计数火柴棍的变量，必须初始化
    while(x/10 != 0)//说明至少还有两位
    {
        //将x末尾数字对应的火柴棍数累加到count中
        count += OriginalMatchStick[x%10];
        x=x/10;//去掉x的末尾数字
    }
    //最后加上原始x的最高位需要的火柴棍数！！！勿忘
    count += OriginalMatchStick[x];
    return count;
}

int main()
{
    int a,b,c,m,sum=0;//sum用来计数，一定要初始化
    printf("请输入火柴棍总数：");
    scanf("%d",&m);

    //开始枚举a和b
    for(a=0;a<=11111;a++)
    {
        for(b=0;b<=11111;b++)
        {
            c = a + b;//计算出c，而不是通过枚举
            if(MatchStickOfNumber(a)+MatchStickOfNumber(b)+MatchStickOfNumber(c) == m-4)
            {
                sum++;
                printf("%d. %d+%d=%d\n",sum,a,b,c);
            }
        }
    }

    printf("一共可拼出%d个不同的等式。",sum);

    return 0;
}
