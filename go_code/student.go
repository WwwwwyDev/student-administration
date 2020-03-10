package main

import "fmt"
//定义数据结构
type Stu struct{
	//定义数据域
	n_id int
	str_name string
	str_class string
	str_math string
	str_chinese string
	str_computer string
	//定义指针域
	p_next *Stu
}
//初始化链表
type InitList(num int) *Stu {
	int i;
    phead := &Stu{n_id:0} //创建头结点，编号为0，不存任何数据
struct Stu *temp = phead;
if(phead == NULL)
{
printf("空间分配失败\n");
exit(-1);
}
phead->m_pNext = NULL;
InitItem(phead);
phead->m_nSign = 0;
for(i=1;i<=num;i++)
{
AddItem(temp);
temp=NextItem(temp);
temp->m_nSign = i;
}
return phead;
}