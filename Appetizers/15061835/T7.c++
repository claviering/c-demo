#include <iostream>
#include <cstring>
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
  m = new char[len];
  m = strcpy(m, s);

  length = len;
}

class MsgCache
{
public:
  bool Add_msg(char *s, int length); //保存长度为length的字符串作为一条新的消息
  MsgCache(int len = 0);
  void show();
  char *getMsg();

private:
  int count;  //已保存的消息数量
  int size;   //可以保存的消息数量
  Msg *cache; //保存消息的指针
};

char *MsgCache::getMsg()
{
  char *c = cache[0].GetMsg();
  for (int i = 1; i < count; i++)
  {
    strcat(c, cache[i].GetMsg());
  }
  return c;
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

bool MsgCache::Add_msg(char *s, int length)
{
  if ((count + 1) > size)
  {
    return false;
  }
  cache[count].SetMsg(s, length);
  count++;
  return true;
};
MsgCache::MsgCache(int len)
{
  count = 0;
  size = len;
  cache = new Msg[len];
}
void MsgCache::show()
{
  for (int i = 0; i < count; i++)
  {
    cout << cache[i].GetMsg() << endl;
  }
}

int main(int argc, char **argv)
{
  MsgCache m1(5); //构造一个可以保存5条消息的MsgCache对象
  MsgCache m2(3); //构造一个可以保存3条消息的MsgCache对象
  m1.Add_msg("hello", 5);
  m2.Add_msg("newmsg", 6);
  MsgCache m3 = m1 + m2;

  m3.show(); //打印输出所保存的消息
  m3 = m2;
  m3.show();

  return 0;
}
