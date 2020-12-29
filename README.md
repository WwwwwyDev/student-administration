# **程序设计报告**

姓名：吴文益    班级：软件193    学号：2019082323

#### 题目

学生成绩管理程序 

#### 代码及版本管理地址

[gitee码云版本地址(点击跳转)](https://gitee.com/wu_wen_yi/StudentAdministration)

#### 要求

本程序用于教学单位（院/系）的学生成绩管理。要求程序能够实现学生信息录入（可以实现增加、删除、修改学生的基本信息）、单科学习成绩的录入；班级内单科成绩排名；成绩查询：查询某个学生的各科成绩、统计所有不及格科目超过2科的学生名单。

#### 设计思路

按照要求设计多种功能函数，并利用主函数实现功能，添加可视化操作提示。

#### 数据结构

利用链式线性结构体Stu数据域存储学生信息，学生姓名、班级、年级、学生各科成绩为字符串型，学生编号为整型，指针域存储下一个指针地址。

#### 流程图

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Tree.jpg)

#### 功能及函数介绍

##### 链表操作函数

###### （1）尾插法

```c
void AddItem(Stu *plist) ;//尾插添加结点：传入需要添加结点的数量和头指针，从头指针遍历到尾结点，并从尾结点开始用malloc函数添加结点，添加完后将尾结点的指针域指向NULL
```

###### （2）遍历结点

```c
Stu *NextItem(Stu *plist) ;//传入当前结点，传出下一结点
```

###### （3）链表初始化

```c
Stu *InitList(int num);//初始化链表：利用malloc函数创建头指针，并将头指针编号为0，将头指针指针域指向NULL，并向后添加num个结点，并返回头指针
```

###### （4）寻找结点

```c
Stu *SearchItem(int num,Stu *phead);//寻找结点：传入头指针，返回编号为num的结点位置
```

##### 功能函数

###### （1）输出所有学生信息

```c
 void ShowItem(Stu *p_list,Stu *p_head);//传入指针，输出其数据域学生信息
```

###### （2） 初始化程序

```c
void InitSys(Stu *p_head);//初始化学生系统后，管理员输入数据层
```

###### （3） 保存文件(二进制)

```c
void SaveFile(Stu *p_head);//保存文件，用wb打开文件，并利用fwrite函数写入fwrite(1,2,3,4); 参数说明：1.要写入的数据的地址，2.一次要写多少字节，3.写多少次，4.写到哪里
```

###### （4） 学生总排名

```c
int Sort(Stu *p_head,int n_ID,int n_subject) ;//院系总排名，传入头指针、学生编号、所要排名的数据类型，用SearchItem()函数检索该编号数据地址，并从头遍历链表到NULL，对每一个结点该数据值进行检索，遇到比被排序结点数值大时sum+1
```

###### （5）学生所在班级排名

```c
 int ClassSort(Stu *p_head,int n_ID,int n_subject) ;//班级排名，传入头指针、学生编号、所要排名的数据类型，同（4）类似，只是判断了班级是否相等，利用了strcmp()库函数，包含了<string.h>头文件
```

###### （6）查找学生

```c
 void Search(Stu *p_head,char *name);  //搜索学生信息，传入头指针，传入学生姓名，遍历链表，找到该学生（考虑了重名情况）
```

###### （7）删除学生信息

```c
 void Del(Stu *p_head,int n_ID); //删除表，传入头指针，传入删除学生编号。用free（）释放内存，包含头文件<stdlib>,并将前后结点相连，利用了SearchItem()函数找到3个结点地址
```

###### （8）将字符串转为double型

```c
 double Strtodouble(char *str) ;//传入0-100的字符串返回double型函数，若传入其他字符串，则返回-1。主要用于符合成绩逻辑，利用了atof()函数，包含头文件<stdlib>
```

###### （9）添加学生

```c
 void AddList(Stu *p_head) ;//尾部添加新同学
```

###### （10）修改学生信息

```c
void Change(Stu *p_head);//修改学生信息，利用SearchItem（）函数
```

###### （11）统计所有不及格科目超过2科的学生名单

```c
void NoPass(Stu *p_head);//传入头指针，输出所有不及格科目超过2科的学生名单，从头开始遍历判断
```

###### （12）单科学习成绩的录入

```c
void InputScore(Stu *start , Stu *end , Stu *p_head ,char *subject);//单科学习成绩录入，传入开始录入位置和结束录入位置，传入头指针 ,传入需要录入的学科
```

###### （13）保存文件(txt)

```c
void Fprint(Stu *p_head);//将数据导出到当前路径下的StudentInformation.txt，导出为txt便于使用者阅读
```

###### （14）输出单个学生信息

```c
void ShowItem(Stu *p_list,Stu *p_head) ;//传入结点地址，输出其数据域学生信息
```

###### （15）班级内单科成绩排名

```c
void ClassSortOutput(Stu *p_head,char *str_class,int subject);//传入头指针，传入班级，传入学科 利用了桶排序思想
```

###### （16）插入学生

```c
void Insert(Stu *p_head) ;//在中间插入一个表，找到前后结点，free()并将前中后结点关联，并将后续结点编号加一
```

#### 功能测试

###### （1）存在数据文件时对数据读取并进入主菜单

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/MainMenu.PNG)

###### （2）不存在数据时初始化系统

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Init.PNG)

###### （3）学生菜单

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/StudentMenu.PNG)

###### （4）管理员菜单（需输入密匙）

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/AdminMenu.PNG)

###### （5）输出所有学生信息

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/PutOut.PNG)

###### （6）查找学生

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Search.PNG)

###### （7）输出两门以上不及格学生名单

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Nopass.PNG)

###### （8）输出班级单科排名

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Sort.PNG)

###### （9）添加学生

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Add.PNG)

###### （10）删除学生

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Del.PNG)

###### （11）修改学生信息

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Change.PNG)

###### （12）单科成绩录入

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/ScoreInput.PNG)

###### （13）插入学生

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Insert.PNG)

###### （14）保存为txt

![图床链接过期](https://gitee.com/wu_wen_yi/student-administration/raw/master/img-folder/Save.PNG)

#### 遇到的问题和异常处理方法

###### （1）对输入int型变量的控制:

```c
if(scanf("%d",&num)!=1)  
{
printf("提示：你没有输入正确值，请重新输入:");
fflush(stdin);//while(getchar()!='\n'); 
}
```

能解决输入非int型变量时，程序崩溃问题

###### （2）对输入字符串的问题：

利用gets()函数输入，可以读入空格，防止缓冲区同时读入多个数据。

###### （3）

```c
fflush(stdin);
```

读入int型等变量时会将换行符读入，利用这个函数可以将缓冲区换行符清除。Stdin指缓冲区

###### （4）对成绩判断问题:

```c
while(Strtodouble(p_new->m_nMath) == -1)
{    
printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
gets(p_new->m_nMath);
}
```

利用Strtodouble函数对成绩输入判断，如果错误则重新输入

###### （5）对指针的判断：

遇到指针为NULL时，设置返回值，防止异常

#### 总结

​     通过这一次课设活动，我获得了很多实战编程经验，并且更深一步地理解了语言的应用和函数式编程概念。正所谓实践出真知，在编程过程中，我遇到了很多问题，但我通过网络等途径解决了问题，这让我非常高兴，通过不断地解决问题发现问题，我获得了很多新的见解。在老师的指导下，我将程序不断完善和规范，使我的编程素养得到了进一步的提升。编程改变世界，只有通过不断地实践，才能使能力不断提升，才能真正地将知识运用到实战，本次课设是一个非常好的平台，感谢学校老师为我们付出的努力。