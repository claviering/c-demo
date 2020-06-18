#include <iostream>
#include <cmath>
using namespace std;

class CCreature
{
public:
  CCreature(int hit, int dam)
  {
    hitpoint = hit;
    damage = dam;
  }
  virtual void Attack(CCreature &other) = 0;
  virtual void FightBack(CCreature &other) = 0;
  virtual void Hurted(CCreature &other) = 0;

protected:
  int hitpoint;
  int damage;
};

class CDragon : public CCreature
{
public:
  CDragon(int hit, int dam) : CCreature(hit, dam)
  {
  }
  virtual void Attack(CCreature &other)
  {
  }
  virtual void FightBack(CCreature &other)
  {
  }
  virtual void Hurted(CCreature &other)
  {
  }
};
