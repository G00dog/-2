#pragma once

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject 
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean() {}
  virtual ~SDLGameObject() {}

protected:
  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;
  Vector2D m_Angle;

  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;
  int m_rwidth;
  int m_rheight;
  int m_angle;
  SDL_RendererFlip m_flip;
  std::string m_textureID;
};