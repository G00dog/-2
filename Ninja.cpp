#include "Ninja.h"

Ninja::Ninja(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Ninja::draw()
{
  SDLGameObject::draw();
}

void Ninja::update()
{
  m_Angle.setX(2);
  SDLGameObject::update();
}

void Ninja::clean() {}