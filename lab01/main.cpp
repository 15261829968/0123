#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "student.h"
#include <QString>


void Print(QList <student> S);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    student s[4];
        s[0].Number=1403130209; s[0].Name="鲁智深";  s[0].Score1=80;s[0].Score2=72;
        s[1].Number=1403140101; s[1].Name=" 林冲 ";  s[1].Score1=82;s[1].Score2=76;
        s[2].Number=1403140102; s[2].Name=" 宋江 ";  s[2].Score1=76;s[2].Score2=85;
        s[3].Number=1403140103; s[3].Name=" 武松 ";  s[3].Score1=88;s[3].Score2=80;
        QList <student> S;
        S<<s[0]<<s[1]<<s[2]<<s[3];
       //定义一个QList，名称为information
        qDebug("排序前为：");
        Print(S);
        qDebug("按姓名排序为：");
        std::sort(S.begin(),S.end(),Name_sort);
        Print(S);
        std::sort(S.begin(),S.end(),Score1_sort);
        qDebug("按成绩一降序为：");
        Print(S);
        std::sort(S.begin(),S.end(),Score2_sort);
        qDebug("按成绩二降序为：");
        Print(S);
        return a.exec();
}

void Print(QList <student> S)                                //输出函数实现
{
    S[0].printtitle();                                         //调用成员函数Printfirst输出
    for(int i=0;i<4;i++)
    {

        S[i].print();
    }
}
