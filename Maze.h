#pragma once

#include "SDLGameObject.h"

class Maze : public SDLGameObject
{
public:
  Maze(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};