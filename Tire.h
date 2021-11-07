#pragma once

#include "SDLGameObject.h"

class Tire : public SDLGameObject
{
public:
  Tire(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();

private:
  int tireXSpeed = 0;
  int tireYSpeed = 0;
};