#pragma once

#include "SDLGameObject.h"

class Slime : public SDLGameObject
{
public:
  Slime(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();

private:
  float slimeX = m_position.getX();
  float slimeY = m_position.getY();
  int slimeXSpeed = 1;
};