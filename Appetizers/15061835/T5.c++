#include <iostream>
#include <string.h>
using namespace std;

class Person
{
private:
  string name;
  int age;

public:
  Person(string n, int a)
  {
    name = n;
    age = a;
  }
  void show()
  {
    cout << "姓名: " << name << endl;
    cout << "年龄: " << age << endl;
  }
};

class Student : public Person
{
private:
  string id;
  int scoreNumber;
  int score[100];

public:
  Student(string n, int a, string i, int s) : Person(n, a)
  {
    id = i;
    scoreNumber = s;
  };
  void show()
  {
    Person::show();
    cout << "学号" << id << endl;
  }
  void inputScore()
  {
    cout << "请输入学生成绩" << endl;
    cout << "scoreNumber" << scoreNumber << endl;
    for (int i = 0; i < scoreNumber; i++)
    {
      cin >> score[i];
    }
  }
};

int main(int argc, char **argv)
{
  Person *p1;
  Person zhangsan("zhangsan", 18); //Person对象的姓名为zhangsan，年龄为18
  p1 = &zhangsan;
  p1->show();                                  //展示zhangsan的姓名和年龄
  p1 = new Student("lisi", 19, "20190001", 2); // Student对象的姓名为lisi，年龄为19，学号为20190001，总共有两个成绩
  ((Student *)p1)->inputScore();               //输入Student对象的两个成绩的分数
  p1->show();                                  //展示Student对象的姓名、年龄和学号
  delete p1;
  return 0;
}