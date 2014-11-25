/*
 *纸牌游戏——小猫钓鱼
 *游戏规则：将一副扑克牌平均分成两份，没人一份。A先拿出手中第一张牌放在桌上，B也拿出自己的第一张牌，放在A所出牌的上面
 *			两人交替出牌。出牌时，若某人打出的牌与桌上的某张牌相同，则将两张牌及其中间所夹的牌取走，并放到自己手中牌的末尾。
 *			当任意一人手中的牌全部出完，游戏结束，对手获胜。
 *分析：要抓住各自的特点，结合数据结构进行分析。
 *     A、B各有两种操作，出牌、赢牌，对应出队入队操作。而桌面上的牌，从后面去牌，则类似于栈，出牌，则入栈，赢牌，则出栈。
 *问题抽象化：用两个队列，一个栈来模拟整个游戏
 
 *存在问题：
	1、赢得的牌以什么顺序插入自己的手中：以出牌顺序，还需将出栈的顺序逆序
		需问清规则
	2、可能会导致游戏无法结束。要思考如何解决游戏无法结束的问题。！！！
*/

#include <stdio.h>
struct queue
{
	int data[100];//用循环队列的话，最大为整套扑克牌的数量；但此处应该远大于扑克牌的数量！！！
	int head;
	int tail;
};

struct stack
{
	int data[10];//数组大小为花色数+1，（！！！注意，桌面上最多有花色数张牌）0保留。
	int top;
};

int main()
{
	struct queue q1,q2;
	struct stack s;
	int book[10];//book:记录、登记。用以标记桌面上已存在的花色。如，1—9,大小为最大花色+1
	int i,temp;
	
	//初始化队列
	q1.head=1;q1.tail=1;
	q2.head=1;q2.tail=1;
	//初始化栈
	s.top=0;
	//初始化用来标记的数组：用来标记已经放在桌上的牌
	for(i=0;i<10;i++)
		book[i]=0;
		
	//依次向队列中插入数据（表示出牌顺序）
	//为简化，只输入6张牌
	printf("请输入A的出牌顺序：");
	for(i=0;i<6;++i)
	{
		scanf("%d",&q1.data[q1.tail++]);//scanf使用的安全问题！！！
	}
	printf("请输入B的出牌顺序：");
	for(i=0;i<6;++i)
	{
		scanf("%d",&q2.data[q2.tail++]);
	}
	
	while(q1.head<q1.tail && q2.head<q2.tail)//当两人手中均有牌时，执行循环
	{
		temp = q1.data[q1.head];//A出牌
		//判断是否赢牌
		if(book[temp]==0)//temp没有出现在桌上
		{
			//A没有赢牌
			q1.head++;//A出牌，即出队
			s.top++;
			s.data[s.top] = temp;//牌放到桌上，即入栈
			book[temp]=1;//标记桌面已有的牌
		}
		else
		{
			//A赢牌
			q1.head++;//A已出牌，即要出队
			q1.data[q1.tail] = temp;//已出的牌放到自己手中，即要入队
			q1.tail++;
			while(s.data[s.top] != temp)
			{
				book[s.data[s.top]] = 0;//取消标记
				q1.data[q1.tail] = s.data[s.top];//入队
				q1.tail++;
				s.top--;//出栈
			}
		}
		
		temp = q2.data[q2.head];//B出牌
		//判断是否赢牌
		if(book[temp]==0)//temp没有出现在桌上
		{
			//B没有赢牌
			q2.head++;//A出牌，即出队
			s.top++;
			s.data[s.top] = temp;//牌放到桌上，即入栈
			book[temp]=1;//标记桌面已有的牌
		}
		else
		{
			//B赢牌
			q2.head++;//B已出牌，即要出队
			q2.data[q2.tail] = temp;//已出的牌放到自己手中，即要入队
			q2.tail++;
			while(s.data[s.top] != temp)
			{
				book[s.data[s.top]] = 0;//取消标记
				q2.data[q2.tail] = s.data[s.top];//入队
				q2.tail++;
				s.top--;//出栈
			}
		}
	}
	
	if(q2.head == q2.tail)
	{
		//B手中无牌，A赢
		printf("A win!\n");
		printf("A手中的牌是：");
		for(i=q1.head;i<q1.tail;++i)
			printf("%d ",q1.data[i]);
	}
	else
	{
		//B赢牌
		printf("B win!\n");
		printf("B手中的牌是：");
		for(i=q2.head;i<q2.tail;++i)
			printf("%d ",q2.data[i]);
	}
	
	if(s.top>0)//若桌上有牌，则依次输出
	{
			printf("\n桌上的牌是：");
			for(i=1;i<=s.top;++i)
				printf(" %d",s.data[i]);
			printf("\n");
	}
	else
		printf("\n桌上已经没有牌了。\n");
	
	return 0;
}