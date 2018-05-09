/***************************************************************************************************************************************/
/*!
\file          SplashState.cpp
\author        Justin Cagle
\par           justin.cagle\@outlook.com
\date          5/8/2018
\brief
Project Erudite - Copyright © 2018 Justin Cagle

*/
/***************************************************************************************************************************************/

#include "SplashState.h"
#include "glew.h"

SplashState SplashState::splashstate;

void SplashState::init ( )
{
  SDL_Window* window = SDL_GL_GetCurrentWindow();
  glClearColor(1, 1, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
}

void SplashState::shutdown ( )
{
  
}

void SplashState::pause ( )
{
  
}

void SplashState::resume ( )
{
  
}

void SplashState::handle_events ( Engine* engine )
{
  if(SDL_PollEvent(&event))
  {
    if (event.key.keysym.sym == SDLK_ESCAPE || event.window.event == SDL_WINDOWEVENT_CLOSE)
      engine->quit();
  }
}

void SplashState::update ( Engine* engine )
{

}

void SplashState::draw ( Engine* engine )
{
  
}

