//
//  mainLoop.cpp
//  shaders
//
//  Created by David Khudaverdyan on 17/09/2018.
//  Copyright © 2018 David Khudaverdyan. All rights reserved.
//
#include <sdl.h>

#include "context/contextManager.h"
#include "eventsManager.h"
#include "mainLoop.h"

MainLoop::MainLoop(const ContextManager& contextProvider):
  contextProvider_(contextProvider)
{
}

void MainLoop::run()
{
  SDL_Event event;
  
  bool quit = false;
  while (!quit)
  {
    while (EventsManager::popEvent(event))
    {
      contextProvider_.notifyEvent(event);
      if (event.type == SDL_QUIT)
      {
        quit = true;
      }
    }
  }
}





