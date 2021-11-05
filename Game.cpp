#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "SDLGameObject.h"
#include "Slime.h"
#include "InputHandler.h"
#include "Background.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }

  m_bRunning = true;

  //슬라임
  if(!TheTextureManager::Instance()->load("Assets/Slime.png","slime",m_pRenderer))
  {
    return false;
  }
  //표창
  if(!TheTextureManager::Instance()->load("Assets/Ninja.png","ninja",m_pRenderer))
  {
    return false;
  }
  //타이어
  if(!TheTextureManager::Instance()->load("Assets/Tire.png","tire",m_pRenderer))
  {
    return false;
  }
  //배경화면
  if(!TheTextureManager::Instance()->load("Assets/Background.jpg","background",m_pRenderer))
  {
    return false;
  }
  //미로 맵 검정점
  if(!TheTextureManager::Instance()->load("Assets/BlackDot.png","blackDot",m_pRenderer))
  {
    return false;
  }
  //미로 맵 하얀점
  if(!TheTextureManager::Instance()->load("Assets/WhiteDot.png","whiteDot",m_pRenderer))
  {
    return false;
  }

  m_gameObjects.push_back(new Background(new LoaderParams(0,0,640,480,"background")));
  m_gameObjects.push_back(new Player(new LoaderParams(100,100,32,32,"slime")));
  m_gameObjects.push_back(new Slime(new LoaderParams(640,400,32,32,"slime")));

  return true;
}

void Game::update()
{
   for(int i = 0; i<m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  
  for(int i = 0; i<m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }

  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}