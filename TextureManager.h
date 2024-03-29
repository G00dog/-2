#ifndef __TextureManager__
#define __TextureManager__

#include "SDL.h" 
#include <map>

class TextureManager {
public:
  ~TextureManager() {}
  bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

  void draw(std::string id, int x, int y, int width, int height, 
    SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);

  void drawFrame(std::string id, int x, int y, int width, int height, 
    int rwidth, int rheight, float angle,
    int currentRow, int currentFrame,
    SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  static TextureManager* Instance()
  {
    if(s_pInstance==0)
      s_pInstance=new TextureManager();
    return s_pInstance;
  }

private:
  TextureManager() {}
  std::map<std::string, SDL_Texture*> m_textureMap;
  static TextureManager* s_pInstance;
};

typedef TextureManager TheTextureManager;

#endif