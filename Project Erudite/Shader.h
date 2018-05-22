#pragma once
#include <string>
#include <unordered_map>

struct ShaderSource
{
  std::string vSource;
  std::string fSource;
};

class Shader
{
  public:
    Shader(const std::string& filepath);
    ~Shader();

    void bind() const;
    void unbind() const;

    // Set Uniforms
    void set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3);

  private:
    unsigned int m_rendererID;
    std::string m_filepath;
    std::unordered_map<std::string, int> m_location;
    ShaderSource parse_shader(const std::string& filepath);
    unsigned int get_uniform_location(const std::string& name);
    unsigned int compile_shader(unsigned int type, const std::string& source);
    unsigned int create_shader(const std::string& vShader, const std::string& fShader);
};

