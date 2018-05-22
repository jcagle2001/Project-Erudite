/***************************************************************************************************************************************/
/*!
\file          Engine.cpp
\author        Justin Cagle
\par           justin.cagle\@outlook.com
\date          5/8/2018
\brief
  Project Erudite - Copyright © 2018 Justin Cagle
  
*/
/***************************************************************************************************************************************/

#include "Engine.h"
#include <GL/glew.h>
#include "Window.h"

Engine::Engine() : running_(true), window(new Window()) {}

/*!
 ***************************************************************************************************************************************
 * \brief Initialize the engine object.
 ***************************************************************************************************************************************/
void Engine::init()
{

}

/*!
 ***************************************************************************************************************************************
 * \brief Clean up the engine to prepare for game exit.
 ***************************************************************************************************************************************/
void Engine::shutdown ()
{
  // Check if the stack is empty
  while(!states_.empty ())
  {
    // If not, shut down the state on the top and pop that state off until no states remain.
    states_.back()->shutdown();
    states_.pop_back();
  }
  // Do this last. Add any other cleanup above this item.
 
  delete window;
}

/*!
 ***************************************************************************************************************************************
 * \brief Switch to a new gamestate. Pause the current state and push the new state to the top of the stack.
 * \param state New state to push to the top of the stack.
 ***************************************************************************************************************************************/
void Engine::change_state (GameState* state)
{
  // Make sure the stack has at least one state.
  if(!states_.empty ())
  {
    // If it does, shut the active state down and pop it off the stack.
    states_.back()->shutdown();
    states_.pop_back();
  }

  // Push the new state on to the stack as the active and run it.
  states_.push_back(state);
  states_.back()->init();
}

/*!
 ***************************************************************************************************************************************
 * \brief Pause the current state and push a new state on to the stack.
 * \param state This is the state you want to push on to the stack.
 ***************************************************************************************************************************************/
void Engine::push_state (GameState* state)
{
  // If there is an active state...
  if(!states_.empty ())
  {
    // Pause it.
    states_.back()->pause();
  }

  // Push the new state on to the top of the stack and run it.
  states_.push_back(state);
  states_.back()->init();
}

/*!
 ***************************************************************************************************************************************
 * \brief Shutdown and pop the current state off the stack and resume the state below it. Be careful not to use this if no lower state 
 * exists.
 ***************************************************************************************************************************************/
void Engine::pop_state ()
{
  // If there is currently an active state...
  if (!states_.empty())
  {
    // Shut it down, pop it off the stack, and resume the next state.
    states_.back()->shutdown();
    states_.pop_back();
    states_.back()->resume();
  }
}

/*!
 ***************************************************************************************************************************************
 * \brief Allow the state to handle events at it's level.
 ***************************************************************************************************************************************/
void Engine::handle_events ()
{
  states_.back()->handle_events(this);
}

/*!
 ***************************************************************************************************************************************
 * \brief Call the update function of the top level state on the stack.
 ***************************************************************************************************************************************/
void Engine::update ()
{
  states_.back()->update(this);
}

/*!
 ***************************************************************************************************************************************
 * \brief Call the draw function of the top level state on the stack.
 ***************************************************************************************************************************************/
void Engine::draw ()
{
  states_.back()->draw(this);
}
