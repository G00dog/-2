#include "Slime.h"

int slimeX = 0;

Slime::Slime(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Slime::draw()
{
  SDLGameObject::draw();
}

void Slime::update()
{
  m_currentFrame = ((SDL_GetTicks() / 150) % 3);

  if(slimeX <= 0)
  {
    slimeSpeed = 1;
  }
  else if(slimeX + 64 >= 640)
  {
    slimeSpeed = -1;
  }

  if(slimeSpeed >= 0)
  {
    m_velocity.setX(1);
    slimeX+=1;
    SDLGameObject::m_flip = SDL_FLIP_NONE;
  }
  else
  {
    m_velocity.setX(-1);
    slimeX-=1;
    SDLGameObject::m_flip = SDL_FLIP_HORIZONTAL;
  }

  SDLGameObject::update();
}

void Slime::clean() {}