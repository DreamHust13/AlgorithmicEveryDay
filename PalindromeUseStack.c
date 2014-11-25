/*
 * 用栈判断是否为回文
*/

#include <stdio.h>
#include <string.h>//!!!

int main()
{
	char data[101],stack[101];
	int i,len,mid,next,top;
	
	gets(data);
	len = strlen(data);
	if(len == 0)
    {
        printf("You don't input anything.\n");
        return 1;
    }
    mid = len/2-1;//求中点
    //!!!其实并不是真正意义上的中点，而是要比较的最后一个字符
	
	top = 0;//初始化栈
	//将中点前的字符以此入栈
	for(i=0;i<=mid;++i)//!!!注意包括等号！！！
		stack[++top]=data[i];
		
	//根据字符串长度是奇数还是偶数，找出需进行的字符串匹配的起始下标
	if((len & 1) == 0)//奇数
		next = mid+1;
	else
		next = mid+2;
	
	//开始匹配
	for(i=next;i<len;++i)
	{
		if(data[i] != stack[top])
			break;
        top--;
        //!!!不能写成一体的stack[top--]，只有匹配，才能出栈！！！
	}
	
	//如果栈为空（即top=0),说明一一匹配，为回文
	if(top==0)
		printf("Yes,it's a palindrome.\n");
	else
		printf("No,it's not palindrome.\n");
		
	return 0;		
}
