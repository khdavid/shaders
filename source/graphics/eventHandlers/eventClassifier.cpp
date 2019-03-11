//
//  eventClassifier.cpp
//  shaders
//
//  Created by David Khudaverdyan on 21/09/2018.
//  Copyright © 2018 David Khudaverdyan. All rights reserved.
//

#include "eventClassifier.h"
#include <iostream>

namespace
{
EventType classifyKeyDown(const SDL_KeyboardEvent& event)
{
  if (event.repeat == 0)
  {
    return EventType::KeyDown;
  }

  return EventType::Unknown;
}

EventType classifyMouseButton(const SDL_MouseButtonEvent& event)
{
  if (event.button == SDL_BUTTON_LEFT)
  {
    if (event.state == SDL_PRESSED)
    {
      return EventType::MouseClick;
    }
    else
    {
      return EventType::MouseRelease;
    }
  }
  return EventType::Unknown;
}

EventType classifyMouseMotion()
{
  bool leftKeyPressed = SDL_BUTTON(SDL_GetMouseState(nullptr, nullptr)) &
    SDL_BUTTON_LMASK;

  if (leftKeyPressed)
  {
    return EventType::MouseMove;
  }

  return EventType::MouseMovePassive;
}

EventType classifyWindowEvent(const SDL_WindowEvent& event)
{
  if (event.event == SDL_WINDOWEVENT_RESIZED)
  {
    return EventType::WindowsResized;
  }

  return EventType::Unknown;
}

EventType classifyMouseWheel()
{
  return EventType::MouseScrolling;
}
}//end of empty namespace

EventType EventClassifier::classify(const SDL_Event& event)
{
  switch (event.type)
  {
  case SDL_WINDOWEVENT:
    return classifyWindowEvent(event.window);
  case SDL_KEYDOWN:
    return classifyKeyDown(event.key);
  case SDL_MOUSEBUTTONDOWN:
  case SDL_MOUSEBUTTONUP:
    return classifyMouseButton(event.button);
  case SDL_MOUSEMOTION:
    return classifyMouseMotion();
  case SDL_MOUSEWHEEL:
    return classifyMouseWheel();
  default:
    return EventType::Unknown;
  }
}

