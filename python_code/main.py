#调用pickle模块用于保存列表数据
import pickle
#打开数据文件，若不存在则赋空值
try:
    pickle_file = open('StudentInformation.wwy','rb')
    Stu=pickle.load(pickle_file)
    pickle_file.close()
except:
    Stu=[]

#菜单函数
def MenuInput(key):
        if key=='A':
            AddStudent()
        elif key=='B':
            Del()
        elif key=='C':
            Change()
        elif key=='D':
            Display()
        elif key=='E':
            Nopass()



def MenuOutput():  
    print('主菜单')
    print('A.添加学生')
    print('B.删除学生')
    print('C.修改学生')
    print('D.显示所有学生信息')
    print('E.输出2门不及格学生名单')


#功能函数
def AddStudent():   #添加学生
    new_name=input('请输入新学生的名字:')
    new_class=input('请输入新学生的班级:')
    new_information={}
    new_information['name']=new_name
    new_information['class']=new_class
    new_information['math']=0
    new_information['chinese']=0
    new_information['english']=0
    new_information['computer']=0
    Stu.append(new_information)
    print("添加成功")
    SaveData()

def Display():   #输出学生信息
    print('学生信息如下:')
    i=1
    for temp in Stu:
        print('编号%d 姓名%s 班级%s 数学成绩%d 语文成绩%d 英语成绩%d 专业成绩%d'%(i,temp['name'],temp['class'],temp['math'],temp['chinese'],temp['english'],temp['computer']))
        i=i+1

def Del():     #删除学生
    try:
        delnum=int(input("请输入你要删除的编号:"))-1
    except:
        print("输入异常")
        return
    if delnum<0 or delnum>len(Stu)-1:
        print('未找到这个编号')
    else:
        del Stu[delnum]
        print('删除成功')
        SaveData()

def Change():     #修改学生信息
    try:
        changenum=int(input('请输入你要修改的编号:'))-1
    except:
        print("输入异常")
        return
    if changenum<0 or changenum>len(Stu)-1:
        print('未找到这个编号')
    else:
        print('该学生信息:编号%d 姓名%s 班级%s 数学成绩%d 语文成绩%d 英语成绩%d 专业成绩%d'%(changenum+1,Stu[changenum]['name'],Stu[changenum]['class'],Stu[changenum]['math'],Stu[changenum]['chinese'],Stu[changenum]['english'],Stu[changenum]['computer']))
        change_name=input('请输入修改后学生的名字:')
        change_class=input('请输入修改后学生的班级:')
        try:
            change_math=int(input('请输入修改后学生的数学成绩:'))
            while change_math<0 or change_math>100:
                change_math=int(input('输入成绩不符合逻辑,请重新输入:'))
        except:
            print("输入异常")
            return
        try:
            change_chinese=int(input('请输入修改后学生的语文成绩:'))
            while change_chinese<0 or change_chinese>100:
                change_chinese=int(input('输入成绩不符合逻辑,请重新输入:'))
        except:
            print("输入异常")
            return
        try:
            change_english=int(input('请输入修改后学生的英语成绩:'))
            while change_english<0 or change_english>100:
                change_english=int(input('输入成绩不符合逻辑,请重新输入:'))
        except:
            print("输入异常")
            return
        try:
            change_computer=int(input('请输入修改后学生的专业成绩:'))
            while change_computer<0 or change_computer>100:
                change_computer=int(input('输入成绩不符合逻辑,请重新输入:'))
        except:
            print("输入异常")
            return
        Stu[changenum]['name']=change_name
        Stu[changenum]['class']=change_class
        Stu[changenum]['math']=change_math
        Stu[changenum]['chinese']=change_chinese
        Stu[changenum]['english']=change_english
        Stu[changenum]['computer']=change_computer
        print("修改成功")
        SaveData()
    
def SaveData():     #保存数据
    pickle_file = open('StudentInformation.wwy','wb')
    pickle.dump(Stu,pickle_file)
    pickle_file.close()

def Nopass():     #统计所有不及格学生名单
    sum =0
    i=1
    for temp in Stu:
        if temp['math']<60:
            sum=sum+1
        if temp['chinese']<60:
            sum=sum+1
        if temp['english']<60:
            sum=sum+1
        if temp['computer']<60:
            sum=sum+1
        if sum>2:
            print('不及格 编号%d 姓名%s 班级%s 数学成绩%d 语文成绩%d 英语成绩%d 专业成绩%d'%(i,temp['name'],temp['class'],temp['math'],temp['chinese'],temp['english'],temp['computer']))
        i=i+1
        sum=0


#执行功能    
while True:
    MenuOutput()
    key=input('请输入功能对应字母:')
    MenuInput(key)
