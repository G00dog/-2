#include "Slime.h"

Slime::Slime(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Slime::draw()
{
  SDLGameObject::draw();
}

void Slime::update()
{
  m_currentFrame = ((SDL_GetTicks() / 150) % 3);

  if(slimeX <= 0)
    m_velocity.setX(1);
  else if(slimeX + 32 >= 640)
    m_velocity.setX(-1);
  else
    m_velocity.setX(1);

  SDLGameObject::update();
}

void Slime::clean() {}