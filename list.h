#define LISH_H_
//����������ͽ�� 
struct Stu
{   //������ 
    int  m_nSign;
	char m_strName[50]; //ѧ��������Ϣ 
	char m_strClass[20];
	char  m_nMath[20]; //���Ƴɼ�����Ӧ����
	char  m_nChinese[20];
	char  m_nEnglish[20];
	char  m_nComputer[20];
	//��� 
	Stu *m_pNext;
};
//����������� 
Stu *InitList(int num); //��ʼ������ ,����ͷָ�� 
Stu *NextItem(Stu *plist);//���뵱ǰ��㣬������һ��� 
void AddItem(Stu *plist);  //β���㣬������һ��㣬����һ����ָ����ָ��β���½��
void InitItem(Stu *plist); //��ʼ����㣬��plistָ��һ������������ʼ��������
Stu *SearchItem(int num,Stu *phead);  //����ͷָ�룬���ر��Ϊnum�Ľ��λ�� 
