#pragma once
#include "sprites/triangleSprite.h"
#include "listeners/mouseEventListener.h"


class SDL_Window;
class SpriteManager : public MouseEventListener
{
public:
  SpriteManager(SDL_Window& window);
  virtual void onMouseMovePassive(int x, int y) override;
private:
  SDL_Window& window_;
  TriangleSprite sprite_;

};

