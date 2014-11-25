/*简单链表
 *插入
*/
#include <stdio.h>
#include <stdlib.h>//malloc()

//创建结构体表示链表的结点类型
struct node 
{
	int data;
	struct node *next;
};

int main()
{
	struct node *head,*temp,*current,*newer;
	int i,num,dat;
	printf("要输入的节点数：");
	scanf("%d",&num);
	head = NULL;//头指针为空
	current = NULL;
	for(i=0;i<num;++i)
	{
		printf("请输入第%d个节点：",i+1);
		scanf("%d",&dat);
		//动态申请节点空间，并进行初始化
		newer=(struct node*)malloc(sizeof(struct node));
		newer->data=dat;
		newer->next=NULL;
		if(head==NULL)
			head=newer;
		else
			current->next=newer;
		current=newer;//!!!
	}
	
	printf("输入要插入的数据：");
	scanf("%d",&dat);
	temp=head;
	while(temp != NULL)
	{
		if(temp->next->data > dat)//若当前节点的下一个节点值大于待插入数，则将数插入中间
		{
			newer=(struct node*)malloc(sizeof(struct node));
			newer->data=dat;
			newer->next=temp->next;
			temp->next=newer;
			break;//！！！插入完毕退出循环
		}
		temp=temp->next;
	}
	
	//输出链表所有数据
	temp=head;
	// printf("链表中所有数据：");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
	return 0;
}