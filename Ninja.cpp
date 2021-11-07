#include "Ninja.h"
#include "Game.h"
#include <iostream>

float ninjaAngle = 0.0f;

Ninja::Ninja(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Ninja::draw()
{
  SDLGameObject::draw();
}

void Ninja::update()
{
  ninjaAngle += 1.0f;
  SDLGameObject::update();
}

void Ninja::clean() {}