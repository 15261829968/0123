#include "iostream"
#include "QString"
#include "QDebug"
#include "algorithm"
class student
{
public:
    int Number;
    QString Name;
    int Score1;
    int Score2;
    void print()
    {
        qDebug()<<Number<<"\t"<<Name<<"\t"<<Score1<<"\t"<<Score2;
    }
    void printtitle()
    {
       qDebug()<<"  学号\t"<<"\t   姓名\t"<<"\t课程1"<<"\t课程2";
    }
};



bool Name_sort(const student t1, const student t2)                                 //实现姓名比较
{
    if (t1.Name>t2.Name)
        return 1;
    else
        return 0;
}

bool Score1_sort(const student t1, const student t2)                                //实现课程1比较
{
    if (t1.Score1>t2.Score1)
        return 1;
    else
        return 0;
}

bool Score2_sort(const student t1, const student t2)                                //实现课程2比较
{
    if (t1.Score2>t2.Score2)
        return 1;
    else
        return 0;
}
