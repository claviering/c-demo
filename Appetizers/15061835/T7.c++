#include <iostream>
using namespace std;

class Msg
{
public:
  void SetMsg(char *s, int len); //设置消息的内容为s，其中s的长度为len
  char *GetMsg() { return m; };
  int GetLen() { return length; };

private:
  char *m;    //指向消息的指针
  int length; //消息的长度
};

void Msg::SetMsg(char *s, int len)
{
  m = s;
  length = len;
}

class MsgCache
{
public:
  MsgCache(int);
  bool Add_msg(char *s, int length); //保存长度为length的字符串作为一条新的消息
  void show();
  int getCount() { return count; };
  void setCount(int c) { count = c; };
  int getSize() { return size; };
  void setSize(int s) { size = s; };
  char *getMsg();
  void operator=(MsgCache &D)
  {
    count = D.getCount();
    int l = D.getSize();
    size = l;
    cacheList = new Msg[l];
    for (int i = 0; i < count; i++)
    {
      char *s = D.cacheList[i].GetMsg();
      cacheList[i].SetMsg(s, sizeof(s));
    }
  }

private:
  int count;      //已保存的消息数量
  int size;       //可以保存的消息数量
  Msg cache;      //保存消息的指针
  Msg *cacheList; //保存消息的指针
};

void MsgCache::show()
{
  int count = this->getCount();
  for (int i = 0; i < count; i++)
  {
    cout << cacheList[i].GetMsg() << endl;
  }
}
char *MsgCache::getMsg()
{
  char *c = cacheList[0].GetMsg();
  int count = this->getCount();
  for (int i = 1; i < count; i++)
  {
    strcat(c, cacheList[i].GetMsg());
  }
  return c;
}

MsgCache::MsgCache(int l)
{
  cacheList = new Msg[l];
  count = 0;
  size = l;
  char p[] = "";
  cacheList[0].SetMsg(p, l);
}

bool MsgCache::Add_msg(char *s, int l)
{
  int count = this->getCount();
  int size = this->getSize();
  if (count >= size)
    return false;
  cacheList[count].SetMsg(s, l);
  this->setCount(count + 1);
  return true;
}

MsgCache operator+(MsgCache a, MsgCache b)
{
  MsgCache msg(1);
  char *s1 = a.getMsg();
  char *s2 = b.getMsg();
  strcat(s1, s2);
  msg.Add_msg(s1, sizeof(s1));
  return msg;
}

int main(int argc, char **argv)
{
  MsgCache m1(5); //构造一个可以保存5条消息的MsgCache对象
  MsgCache m2(3); //构造一个可以保存3条消息的MsgCache对象
  char s1[] = "hello";
  char s2[] = "newmsg";
  m1.Add_msg(s1, 5);
  m2.Add_msg(s2, 6);
  MsgCache m3 = m1 + m2;
  m3.show(); //打印输出所保存的消息
  m3 = m2;
  m3.show();
  return 0;
}
