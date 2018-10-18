#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>


namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

typedef struct{
    QStringList student;//定义一个存放信息的student字符串
    // 请补全结构定义
} studData;

QDebug operator<< (QDebug d, const studData &data) {
    int i;
    for(i=0;i<data.student.size();i++)
        d.noquote().nospace()<<QString(data.student.at(i))<<"\t" ;
    return d;
    // 请补全运算符重载函数，使其可以直接输出studData结构

}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};
#define compare(a)   (d1.student.at(a)>=d2.student.at(a))?  1:0

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn)
        {
           case SK::col01:result=compare(1);break;
           case SK::col02:result=compare(2);break;
           case SK::col03:result=compare(3);break;
           case SK::col04:result=compare(4);break;
           case SK::col05:result=compare(5);break;
           case SK::col06:result=compare(6);break;
           case SK::col07:result=compare(7);break;
           case SK::col08:result=compare(8);break;
           case SK::col09:result=compare(9);break;
           case SK::col10:result=compare(10);break;
           case SK::col11:result=compare(11);break;
           case SK::col12:result=compare(12);break;
           case SK::col13:result=compare(13);break;
           case SK::col14:result=compare(14);break;
           case SK::col15:result=compare(15);break;
           case SK::col16:result=compare(16);break;
           case SK::col17:result=compare(17);break;
           case SK::col18:result=compare(18);break;
           case SK::col19:result=compare(19);break;
           case SK::col20:result=compare(20);break;
           case SK::col21:result=compare(21);break;
           case SK::col22:result=compare(22);break;
           case SK::col23:result=compare(23);break;
           case SK::col24:result=compare(24);break;
           case SK::col25:result=compare(25);break;
           case SK::col26:result=compare(26);break;
           case SK::col27:result=compare(27);break;
           case SK::col28:result=compare(28);break;
           case SK::col29:result=compare(29);break;
           case SK::col30:result=compare(30);break;
           case SK::col31:result=compare(31);break;
           case SK::col32:result=compare(32);break;
           default:;break;
        }
        return result;



}

//排序类
class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();//读文本
    void doSort();//执行排序
private:
    QString pathfile;
    QList<studData> data;
    studData title;//数据表头

};
// 请补全
ScoreSorter::ScoreSorter(QString dataFile)
{
   pathfile=dataFile;
}
void ScoreSorter::doSort()//排序函数
{
    for(int i=1;i<title.student.size();i++)
    {
        myCmp stducmp(i-1);    //初始化排序规则对象
        std::sort(data.begin() , data.end() , stducmp );  //排序

        qDebug()<<"排序后输出，当前排序第 "<<i+1 <<" 列：";
        qDebug() << '\t'<< (title);    //输出表头

        for(int i=0;i<data.size();i++)
            qDebug() << data.at(i);//qDebug重载输出
        qDebug()<<"-----------------------------------------------------------------------------------------------------------\n";

    }
}



void ScoreSorter::readFile(){
    QFile file(pathfile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<QString("文件打开失败");
        return;
    }
     QString TITLE(file.readLine());
    title.student = TITLE.split(" ", QString::SkipEmptyParts);
     if((title.student).last() == "\n")
         title.student.removeLast();
         studData filedata;//TXT中数据

         while(!file.atEnd())
             {
                 QByteArray line = file.readLine();
                 QString str(line);

                 filedata.student = str.split(" ", QString::SkipEmptyParts);//读取成绩数据

                 if((filedata.student).last() == "\n")  //去末尾'\n'
                     filedata.student.removeLast();
                 if(filedata.student.size()==0) continue;
                 data.append(filedata);//添加数据到data
             }
             file.close();
         }

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 输出信息至文件中（读写、追加形式）

    QFile file("Sorter_data.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream stream(&file);
    stream <<msg << endl;
    stream.setCodec("UTF-8");
    file.flush();
    file.close();
    QTextStream ts (stdout);
    ts << msg << endl;
    file.flush();
    file.close();

    // 自定义qDebug
}

int main()
{
   qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
