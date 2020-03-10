package main

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

//尾插结点，传入前置结点，遍历到NULL，将尾部的指针域指向尾部新结点 ，完成添加
func AddItem(plist *Stu) {
	ptemp := &Stu{}
	ptemp.n_id = plist.n_id+1
	plist.p_next = ptemp
	ptemp.p_next = nil
}
//初始化链表
func InitList(num int) *Stu {
	phead := &Stu{n_id:0} //创建头结点，编号为0，不存任何数据
	ptemp := phead
	phead.p_next = nil
	for i:=1;i<=num;i++{
		AddItem(ptemp)
		ptemp = ptemp.p_next
		ptemp.n_id = i
	}
	return phead
}
//传入头指针，返回编号为num的结点位置
func SearchItem(num int,phead *Stu) *Stu{
ptemp := phead;
for ptemp != nil{
if num == ptemp.n_id {
return ptemp
} else {
ptemp = ptemp.p_next
}
}
return nil;
}