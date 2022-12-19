#include"texture.h"

Texture::Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType)
{
	type = texType;
	unit = slot;
	
	// change stbi so image isn't flipped
	stbi_set_flip_vertically_on_load(true);

	// load brick image
	int imgWidth, imgHeight, imgColorCh;
	unsigned char* bytes = stbi_load(image, &imgWidth, &imgHeight, &imgColorCh, 0);

	// create texture object
	glGenTextures(1, &ID);

	// access texture object
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);

	// define texture settings
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// generate texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	// delete image data
	stbi_image_free(bytes);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::texUnit(Shader shader, const char* uniform, GLuint unit)
{
	// texture unit uniform
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}