#pragma once

#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader
{
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	std::unordered_map < std::string, unsigned int> m_UniformLocatiobCache;


	unsigned int GetUniformLocation(const std::string& name);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	ShaderProgramSource ParseShader(std::string& filePath);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};
