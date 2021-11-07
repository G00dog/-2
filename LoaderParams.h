#pragma once

#include "SDL.h"

class LoaderParams
{
public:
  LoaderParams(int x, int y, int width, int height, 
  int rwidth, int rheight, int angle, std::string textureID)
    : m_x(x),
      m_y(y),
      m_width(width),
      m_height(height),
      m_rwidth(rwidth),
      m_rheight(rheight),
      m_angle(angle),
      m_textureID(textureID){}

  int getX() const { return m_x; }
  int getY() const { return m_y; }
  int getWidth() const { return m_width; }
  int getHeight() const { return m_height; }
  int getRwidth() const { return m_rwidth;}
  int getRheight() const { return m_rheight;}
  int getAngle() const { return m_angle;}
  std::string getTextureID() const { return m_textureID; }
private:
  int m_x, m_y;
  int m_width, m_height;
  int m_rwidth, m_rheight, m_angle;
  std::string m_textureID;
};