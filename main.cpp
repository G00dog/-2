//https://drive.google.com/file/d/1ZswoT7HsYnkEbHOuJxXeMh9NYw-V1glW/view?usp=sharing

#include "Game.h"
#include "InputHandler.h"
#include <iostream>

Game* g_game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
  {
    Uint32 frameStart, frameTime;
    while(TheGame::Instance()->running())
    {
      frameStart = SDL_GetTicks();
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      frameTime = SDL_GetTicks() - frameStart;
      if(frameTime < DELAY_TIME)
      {
        SDL_Delay((int)(DELAY_TIME - frameTime));
      }
    }
  }
  else
  {
    std::cout<<"game init failure "<<SDL_GetError()<<"\n";
    return -1;
  }
  TheGame::Instance()->clean();
  TheInputHandler::Instance()->clean();
  return 0;
}