package main

import (
	"flag"
	"fmt"
)
//初始化学生系统后，管理员输入数据层
func InitImformation(phead *Stu){
	ptemp := phead.p_next
	for ptemp != nil{
		fmt.Printf("输入学生信息(编号:%d):\n",ptemp.n_id)  //对结点写入数据
		fmt.Printf("姓名(编号:%d):",ptemp.n_id)
		fmt.Scanf("%s",&ptemp.str_name)
		fmt.Printf("班级(编号:%d):",ptemp.n_id)
		fmt.Scanf("%s",&ptemp.str_class)
		ptemp = ptemp.p_next
	}
}

func Strtodouble(str string) bool{
	num, err := strconv.ParseFloat(str, 64)
	if err != nil {
		return false
	} else if num<0||num>100{
		return flase
	}else{
		return true
	}
}
