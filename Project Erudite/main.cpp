/***************************************************************************************************************************************/
/*!
\file          main.cpp
\author        Justin Cagle
\par           justin.cagle\@outlook.com
\date          5/8/2018
\brief
Project Erudite - Copyright © 2018 Justin Cagle

*/
/***************************************************************************************************************************************/

/*!
 ***************************************************************************************************************************************
 * \brief A journey of a thousand miles begins with a single step...
 * \return Return code to the OS
 ***************************************************************************************************************************************/
#include <SDL2/SDL.h>
#include "Engine.h"
#include "SplashState.h"

int main(int argc, char *argv[])
{
  Engine game;

  game.init();
  
  game.change_state(SplashState::instance ());

  while(game.is_running ())
  {
    game.update();
    game.handle_events();
    game.draw();
  }

  game.shutdown();

  return 0;
}
