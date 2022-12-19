#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec3 aColor;
layout (location = 3) in vec2 aTexUV;

// position output for frag shader
out vec3 crntPos;

// normal output for frag shader
out vec3 norm;

// color output for frag shader
out vec3 color;

// texture output for frag shader
out vec2 texCoord;

// camera matrix
uniform mat4 camMatrix;

// model matrix
uniform mat4 model;

void main()
{
	crntPos = vec3(model * vec4(aPos, 1.0f));
	gl_Position = camMatrix * vec4(crntPos, 1.0);
	
	norm = aNorm;
	
	color = aColor;
	texCoord = aTexUV;
}