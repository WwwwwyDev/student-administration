package main

import (

	"time"
)




func main() {
     phead := InitList(3)
     InitImformation(phead)
     for true{
		 Menu(phead)
	 }

	time.Sleep(5*time.Second)
}
//判断文件是否存在
/*func IsExist(f string) bool {
	_, err := os.Stat(f)
	return err == nil || os.IsExist(err)
}*/

/*	if IsExist("./Information.gob")==False{
	fp, err := os.OpenFile("D:/lnj.txt", os.O_APPEND | os.O_RDWR, 0666)
	if err != nil{
		fmt.Println("创建失败")
	}
	defer fp.Close()
}*/



