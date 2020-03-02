#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Init.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n_num ;
    printf("请输入你要创建的学生个数:");  //初始化链表
    Stu *p_head; 
	scanf("%d",&n_num);
	if(n_num==0) 
	{   
	    p_head=Itzlink(n_num);
		printf("提示：你创建了一个空表"); 
	}
	else
	{
		p_head=Itzlink(n_num);
	}
    return 0;
}
