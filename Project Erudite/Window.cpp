#include "Window.h"

Window::Window()
{
  // Initialize SDL systems for use. I'm initializing the video and timer subsystems.
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  // Set OpenGL's attributes for the SDL window. This must be done prior to the creation of the window.
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  // Create the window and an OpenGL Context through SDL.
  m_window = SDL_CreateWindow("Project: Erudite", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_OPENGL);
  m_context = SDL_GL_CreateContext(m_window);

  // Allow GLEW to use experimental functions and init Glew.
  glewExperimental = GL_TRUE;
  glewInit();

  // Set the viewport
  glViewport(0, 0, 1000, 800);
}


Window::~Window()
{
  // Delete the context, destroy the window, and shut down SDL.
  SDL_GL_DeleteContext(m_context);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}
