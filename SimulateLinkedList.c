/*简单模拟链表
 *用数组模拟链表：两个数组：data数据数组；right数据数组对应位置的右侧数据
*/
#include <stdio.h>

int main()
{
    int data[101],right[101];
    int i,num,current,len;

    //读入已有数据
    printf("要输入的数据个数：");
    scanf("%d",&num);
    for(i=1;i<=num;++i)//数组都要从1开始，因为下标0有特殊意义：右边无数据！！！
        scanf("%d",&data[i]);
    len=num;
    //初始化数组right
    for(i=1;i<=num;++i)
    {
        if(i!=num)//!!!
            right[i]=i+1;
        else
            right[i]=0;
    }

    //直接在数组data尾部插入数据
    len++;
    printf("要插入的数据：");
    scanf("%d",&data[len]);
    
    //从链表头部开始遍历
    current=1;
    while(current!=0)
    {
        if(data[right[current]] > data[len])//若当前节点的下一节点值大于要插入的节点，将其插入中间
        {
            right[len]=right[current];//!!!画图
            right[current]=len;
            break;
        }
        current=right[current];
    }

    //输出链表中的所有数据
    current=1;
    while(current!=0)
    {
        printf("%d ",data[current]);
        current=right[current];
    }
    printf("\n");

    return 0;
}
