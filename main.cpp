#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Init.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n_num ;
    printf("��������Ҫ������ѧ������:");  //��ʼ������
    Stu *p_head; 
	scanf("%d",&n_num);
	if(n_num==0) 
	{   
	    p_head=Itzlink(n_num);
		printf("��ʾ���㴴����һ���ձ�"); 
	}
	else
	{
		p_head=Itzlink(n_num);
	}
    return 0;
}
