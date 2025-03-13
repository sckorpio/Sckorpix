#include "texture.h"

#include "std_image\stb_image.h"

#include <iostream>

Texture::Texture()
{
	m_RendererID=0;
    
   	m_LocalBuffer=NULL;
   	m_Width=0;
   	m_Height=0;
   	m_BPP=0;
}

Texture::~Texture()
{
    glDeleteTextures(1,&m_RendererID);
}

void Texture::Gen(const std::string& path)
{
    m_FilePath=path;

    stbi_set_flip_vertically_on_load(true);
    m_LocalBuffer = stbi_load(m_FilePath.c_str(), &m_Width, &m_Height, 0, STBI_rgb_alpha);
    
    glGenTextures(1,&m_RendererID);
    glBindTexture(GL_TEXTURE_2D,m_RendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (m_LocalBuffer)
    {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
      glGenerateMipmap(GL_TEXTURE_2D);
    }

     else
    {
       std::cout << "Failed to load texture" << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D,0);

    if (m_LocalBuffer)
    stbi_image_free(m_LocalBuffer);

}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D,m_RendererID);
}

void Texture::UnBind() const
{
     glBindTexture(GL_TEXTURE_2D,0);
}