#include <iostream>
#include <cstring>
using namespace std;
class mystring
{
  char *str;

public:
  mystring(char *a = NULL)
  {
    if (a != NULL)
    {
      str = new char[strlen(a) + 1];
      strcpy(str, a);
    }
    else
      str = NULL;
  }
  ~mystring()
  {
    if (str != NULL)
    {
      delete[] str;
    }
  };
  mystring &operator=(const mystring &B)
  {
    if (B.str != NULL)
    {
      if (str != NULL)
      {
        if (this == &B)
        {
          return *this;
        }
        delete[] str;
        str = new char[strlen(B.str) + 1];
        strcpy(str, B.str);
      }
      else
      {
        str = new char[strlen(B.str) + 1];
        strcpy(str, B.str);
      }
    }
    else
    {
      delete[] str;
      str = NULL;
    }
  }

  mystring &operator+=(mystring &B)
  {
    if (str != NULL)
    {
      if (B.str != NULL)
      {
        int length = strlen(B.str) + strlen(str);
        char *p = new char[length + 1];
        for (int i = 0; i < strlen(str); i++)
        {
          p[i] = str[i];
        }
        int j = 0;
        for (int i = strlen(str); i < length; i++)
        {
          p[i] = B.str[j++];
        }
        p[length] = '\0';
        delete[] str;
        str = p;
        return *this;
      }
    }
  }
  char operator[](int i)
  {
    return str[i];
  }

  friend ostream &operator<<(ostream &out, mystring &A)
  {
    out << A.str;
    return out;
  }
};

int main()
{
  mystring a("hello ");
  mystring b("World!");

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  a += b;
  cout << "a+b: " << a << endl;

  cout << "(a+b)[1]: " << a[1] << endl;
}