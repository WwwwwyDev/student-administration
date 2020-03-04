#define LISH_H_
//构造数据域和结点 
struct Stu
{   //数据域 
    int  m_nSign;
	char m_strName[999]; //学生基本信息 
	char m_strClass[999];
	char  m_nMath[999]; //各科成绩及对应排名
	char  m_nChinese[999];
	char  m_nEnglish[999];
	char  m_nComputer[999];
	//结点 
	Stu *m_pNext;
};
//链表操作函数 
Stu *InitList(int num); //初始化链表 ,返回头指针 
Stu *NextItem(Stu *plist);//传入当前结点，返回下一结点 
void AddItem(Stu *plist);  //尾插结点，传入头结点，遍历到NULL，将尾部的指针域指向尾部新结点 ，完成添加 
void InitItem(Stu *plist); //初始化结点，将plist指向一个空链表，并初始化数据域
Stu *SearchItem(int num,Stu *phead);  //传入头指针，返回编号为num的结点位置 
