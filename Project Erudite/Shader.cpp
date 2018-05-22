#include "Shader.h"
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& filepath) : m_rendererID(0), m_filepath(filepath)
{
  ShaderSource source = parse_shader(filepath);
  m_rendererID = create_shader(source.vSource, source.fSource);
}


Shader::~Shader()
{
  glDeleteProgram(m_rendererID);
}

void Shader::bind ( ) const
{
  glUseProgram(m_rendererID);
}

void Shader::unbind ( ) const
{
  glUseProgram(0);
}

void Shader::set_uniform4f ( const std::string& name, float v0, float v1, float v2, float v3 )
{
  glUniform4f(get_uniform_location(name), v0, v1, v2, v3);
}

ShaderSource Shader::parse_shader ( const std::string& filepath )
{
  std::ifstream stream(filepath);

  enum class ShaderType
  {
    NONE = -1,
    VERTEX = 0,
    FRAGMENT = 1
  };

  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;
  while(getline(stream, line))
  {
    if(line.find("#shader") != std::string::npos)
    {
      if (line.find("vertex") != std::string::npos)
        type = ShaderType::VERTEX;
      else if (line.find("fragment") != std::string::npos)
        type = ShaderType::FRAGMENT;
    }
    
    else
    {
      ss[(int)type] << line << '\n';
    }
  }

  return { ss[0].str(), ss[1].str() };
}

unsigned Shader::get_uniform_location ( const std::string& name )
{
  if (m_location.find(name) != m_location.end())
    return m_location[name];
  int location = glGetUniformLocation(m_rendererID, name.c_str());
  if (location == -1)
    // TODO: convert to tracelog message.
    std::cout << "Warning: uniform " << name << "does not exist." << std::endl;
  else
    m_location[name] = location;
  return location;
}

unsigned Shader::compile_shader ( unsigned int type, const std::string& source )
{
  unsigned int ID = glCreateShader(type);
  const char* cSource = source.c_str();
  glShaderSource(ID, 1, &cSource, nullptr);
  glCompileShader(ID);

  int result;
  glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
  if(result == GL_FALSE)
  {
    int length;
    glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &length);
    // TODO: change this to a C++-style cast.
    char* message = (char*)alloca(length * sizeof(char));
    glGetShaderInfoLog(ID, length, &length, message);
    // TODO: Add this as a tracelog entry.
    std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
    std::cout << message << std::endl;
    glDeleteShader(ID);
    return 0;
  }

  return ID;
}

unsigned Shader::create_shader ( const std::string& vShader, const std::string& fShader )
{
  unsigned int program = glCreateProgram();

  unsigned int vertex = compile_shader(GL_VERTEX_SHADER, vShader);
  unsigned int frag = compile_shader(GL_FRAGMENT_SHADER, fShader);

  glAttachShader(program, vertex);
  glAttachShader(program, frag);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vertex);
  glDeleteShader(frag);

  return program;
}
