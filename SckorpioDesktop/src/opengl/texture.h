#ifndef TEXTURE_H
#define TEXTURE_H
#define GL_GLEXT_PROTOTYPES

#include <GL/glew.h>  
#include <GL/gl.h>
#include <iostream>
#include <string>

class Texture
{
   private:
   	unsigned int m_RendererID;
   	std::string m_FilePath;
   	unsigned char* m_LocalBuffer;
   	int m_Width;
   	int m_Height;
   	int m_BPP;

   	public:
   	Texture();
   	~Texture();
    void Gen(const std::string& path);
   	void Bind(unsigned int slot=0) const;
   	void UnBind() const;

   	inline int GetWidth() const { return m_Width; }
   	inline int GetHeight() const { return m_Height; }
};


#endif // TEXTURE_H