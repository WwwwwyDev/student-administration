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
        elif key=='F':
            ScoreInput()
        else:
            print("无此功能")



def MenuOutput():  
    print('主菜单')
    print('A.添加学生')
    print('B.删除学生')
    print('C.修改学生')
    print('D.显示所有学生信息')
    print('E.输出2门以上不及格学生名单')
    print('F.输入单科成绩')


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
        print('编号%d 姓名%s 班级%s 数学成绩%d 数学排名%d 语文成绩%d 语文排名%d 英语成绩%d 英语排名%d 专业成绩%d 专业排名%d'%(i,temp['name'],temp['class'],temp['math'],Sort(1,i),temp['chinese'],Sort(2,i),temp['english'],Sort(3,i),temp['computer'],Sort(4,i)))
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

def ScoreInput():    #输入单科成绩
    print('请选择你要输入的科目')
    print('A.数学')
    print('B.语文')
    print('C.英语')
    print('D.专业')
    choice=input('请输入科目对应字母:')
    if choice=='A':
        for temp in Stu:
            print('%s的原数学成绩为%d'%(temp['name'],temp['math']))
            try:
                new_score=int(input('现改为:'))
                while new_score<0 or new_score>100:
                    new_score=int(input('输入成绩不符合逻辑,请重新输入:'))                             
            except:
                print("输入异常")
                return
            temp['math']=new_score
            SaveData()
    elif choice=='B':
        for temp in Stu:
            print('%s的原语文成绩为%d'%(temp['name'],temp['chinese']))
            try:
                new_score=int(input('现改为:'))
                while new_score<0 or new_score>100:
                    new_score=int(input('输入成绩不符合逻辑,请重新输入:'))                             
            except:
                print("输入异常")
                return
            temp['chinese']=new_score
            SaveData()
    elif choice=='C':
        for temp in Stu:
            print('%s的原英语成绩为%d'%(temp['name'],temp['english']))
            try:
                new_score=int(input('现改为:'))
                while new_score<0 or new_score>100:
                    new_score=int(input('输入成绩不符合逻辑,请重新输入:'))                             
            except:
                print("输入异常")
                return
            temp['english']=new_score
            SaveData()
    elif choice=='D':
        for temp in Stu:
            print('%s的原专业成绩为%d'%(temp['name'],temp['computer']))
            try:
                new_score=int(input('现改为:'))
                while new_score<0 or new_score>100:
                    new_score=int(input('输入成绩不符合逻辑,请重新输入:'))                             
            except:
                print("输入异常")
                return
            temp['computer']=new_score
            SaveData()
    else:
        print("无此功能")
        
def Sort(subject,num):#排名    
    sum=1
    if subject==1:
        for temp in Stu:
            if temp['math']>Stu[num-1]['math']:
                sum=sum+1
        return sum
    if subject==2:
        for temp in Stu:
            if temp['chinese']>Stu[num-1]['chinese']:
                sum=sum+1
        return sum
    if subject==3:
        for temp in Stu:
            if temp['english']>Stu[num-1]['english']:
                sum=sum+1
        return sum
    if subject==4:
        for temp in Stu:
            if temp['computer']>Stu[num-1]['computer']:
                sum=sum+1
        return sum
        
#执行功能    
while True:
    MenuOutput()
    key=input('请输入功能对应字母:')
    MenuInput(key)
