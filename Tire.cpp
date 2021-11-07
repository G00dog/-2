#include "Tire.h"

int tireX = 0;
int tireY = 0;

Tire::Tire(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Tire::draw()
{
  SDLGameObject::draw();
}

void Tire::update()
{
  m_Angle.setX(2);

  if(tireX <= 0)
  {
    tireXSpeed = 1;
  }
  else if(tireX + 64 >= 640)
  {
    tireXSpeed = -1;
  }

  if(tireXSpeed >= 0)
  {
    m_velocity.setX(1);
    tireX+=1;
  }
  else
  {
    m_velocity.setX(-1);
    tireX-=1;
  }

  if(tireY <= 0)
  {
    tireYSpeed = 1;
  }
  else if(tireY + 64 >= 480)
  {
    tireYSpeed = -1;
  }

  if(tireYSpeed >= 0)
  {
    m_velocity.setY(1);
    tireY+=1;
  }
  else
  {
    m_velocity.setY(-1);
    tireY-=1;
  }

  SDLGameObject::update();
}

void Tire::clean() {}