#pragma once

#include "SDLGameObject.h"

class Ninja : public SDLGameObject
{
public:
  Ninja(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};