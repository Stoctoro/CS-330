#include"Mesh.h"

const unsigned int windowWidth = 1920;
const unsigned int windowHeight = 1080;

float camSpeed = 0.05f;

// vertex array for light cube
Vertex lightVertices[] =
{// position, normal
	Vertex{ glm::vec3(-1.0f, -1.0f, -1.0f)},
	Vertex{ glm::vec3(1.0f, -1.0f, -1.0f)},
	Vertex{ glm::vec3(1.0f, -1.0f, 1.0f)},
	Vertex{ glm::vec3(-1.0f, -1.0f, 1.0f)},

	Vertex{ glm::vec3(-1.0f, 1.0f, -1.0f)},
	Vertex{ glm::vec3(1.0f, 1.0f, -1.0f)},
	Vertex{ glm::vec3(1.0f, 1.0f, 1.0f)},
	Vertex{ glm::vec3(-1.0f, 1.0f, 1.0f)},
};
// index array for light cube
GLuint lightIndices[] =
{
	0, 1, 2, // bottom
	3, 1, 2,

	4, 5, 6, // top
	7, 5, 6,

	0, 1, 5, // front
	0, 4, 5,

	1, 2, 6, // right
	1, 5, 6,

	2, 3, 7, // back
	2, 6, 7,

	3, 0, 4, // left
	3, 7, 4
};
// vector for light color
glm::vec4 lightColor = glm::vec4(1.0f, 0.776f, 0.361f, 1.0f);
// vector for light position
glm::vec3 lightPos = glm::vec3(-1.0f, 1.5f, -0.5f);

// vertex array for desk
Vertex deskVertices[] =
{// position, normal, color, texuv
	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 0.0f)}, // top
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 1.0f)},

	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 0.0f)}, // bottom
	Vertex{ glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 1.0f)},

	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 1.0f)}, // front
	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 1.0f)}, // right
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, 0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 1.0f)}, // back
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 1.0f)}, // left
	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.15f, 0.0f), glm::vec2(1.0f, 0.0f)},
};
// index array for desk
GLuint deskIndices[] =
{
	0, 1, 2, // top
	3, 1, 2,

	4, 5, 6, // bottom
	7, 5, 6,

	8, 9, 10, // front
	11, 9, 10,

	12, 13, 14, // right
	15, 13, 14,

	16, 17, 18, // back
	19, 17, 18,

	20, 21, 22, // left
	23, 21, 22
};

// variables for creating pencil normals
float pencilSine = glm::sin(glm::radians(90.0f - 22.5f));
float pencilCosine = glm::cos(glm::radians(90.0f - 22.5f));

// normal vectors for pencil cylinder
glm::vec3 pencilCylNormals[] =
{
	glm::vec3(0.0f, -1.0f, 0.0f), // bottom
	glm::vec3(pencilCosine, 0.0f, -pencilSine), // north-northeast
	glm::vec3(pencilSine, 0.0f, -pencilCosine), // east-northeast
	glm::vec3(pencilSine, 0.0f, pencilCosine), // east-southeast
	glm::vec3(pencilCosine, 0.0f, pencilSine), // south-southeast
	glm::vec3(-pencilCosine, 0.0f, pencilSine), // south-southwest
	glm::vec3(-pencilSine, 0.0f, pencilCosine), // west-southwest
	glm::vec3(-pencilSine, 0.0f, -pencilCosine), // west-northwest
	glm::vec3(-pencilCosine, 0.0f, -pencilSine), // north-northwest
};
// vertex array for octagonal pencil cylinder
Vertex pencilCylVertices[] =
{
	// position, normal, color, texuv

	// bottom
	Vertex{ glm::vec3(0.0f, 0.0f, 0.0f), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(0.0f, 0.0f, -0.1f), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.0f), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.5f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.0f, 0.1f), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.0f), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.5f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 1.0f)},

	// north-northeast
	Vertex{ glm::vec3(0.0f, 0.0f, -0.1f), pencilCylNormals[1], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[1], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((1.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.2f, -0.1f), pencilCylNormals[1], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.2f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[1], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((1.0f / 8.0f), 1.0f)},

	// east-northeast
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[2], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((1.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.0f), pencilCylNormals[2], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((2.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.2f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[2], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((1.0f / 8.0f), 1.0f)},
	Vertex{ glm::vec3(0.1f, 0.2f, 0.0f), pencilCylNormals[2], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((2.0f / 8.0f), 1.0f)},

	// east-southeast
	Vertex{ glm::vec3(0.1f, 0.0f, 0.0f), pencilCylNormals[3], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((2.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[3], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((3.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.1f, 0.2f, 0.0f), pencilCylNormals[3], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((2.0f / 8.0f), 1.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.2f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[3], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((3.0f / 8.0f), 1.0f)},

	// south-southeast
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[4], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((3.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.0f, 0.1f), pencilCylNormals[4], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((4.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.2f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[4], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((3.0f / 8.0f), 1.0f)},
	Vertex{ glm::vec3(0.0f, 0.2f, 0.1f), pencilCylNormals[4], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((4.0f / 8.0f), 1.0f)},

	// south-southwest
	Vertex{ glm::vec3(0.0f, 0.0f, 0.1f), pencilCylNormals[5], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((4.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[5], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((5.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.2f, 0.1f), pencilCylNormals[5], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((4.0f / 8.0f), 1.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.2f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[5], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((5.0f / 8.0f), 1.0f)},

	// west-southwest
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[6], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((5.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.0f), pencilCylNormals[6], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((6.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.2f, 0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[6], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((5.0f / 8.0f), 1.0f)},
	Vertex{ glm::vec3(-0.1f, 0.2f, 0.0f), pencilCylNormals[6], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((6.0f / 8.0f), 1.0f)},

	// west-northwest
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.0f), pencilCylNormals[7], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((6.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[7], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((7.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(-0.1f, 0.2f, 0.0f), pencilCylNormals[7], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((6.0f / 8.0f), 1.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.2f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[7], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((7.0f / 8.0f), 1.0f)},

	// north-northwest
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[8], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((7.0f / 8.0f), 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.0f, -0.1f), pencilCylNormals[8], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.2f, -0.1f * glm::sin(glm::radians(45.0f))), pencilCylNormals[8], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2((7.0f / 8.0f), 1.0f)},
	Vertex{ glm::vec3(0.0f, 0.2f, -0.1f), pencilCylNormals[8], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 1.0f)}
};
// index array for octagonal pencil cylinder
GLuint pencilCylIndices[] =
{
	// bottom
	0, 1, 2,
	0, 2, 3,
	0, 3, 4,
	0, 4, 5,
	0, 5, 6,
	0, 6, 7,
	0, 7, 8,
	0, 8, 1,

	// north-northeast
	9, 10, 11,
	12, 10, 11,

	// east-northeast
	13, 14, 15,
	16, 14, 15,

	// east-southeast
	17, 18, 19,
	20, 18, 19,

	// south-southeast
	21, 22, 23,
	24, 22, 23,

	// south-southwest
	25, 26, 27,
	28, 26, 27,

	// west-southwest
	29, 30, 31,
	32, 30, 31,

	// west-northwest
	33, 34, 35,
	36, 34, 35,

	// north-northwest
	37, 38, 39,
	40, 38, 39
};

// normal vectors for pencil cone/pyramid
glm::vec3 pencilConeNormals[] =
{
	glm::vec3(0.0f, -1.0f, 0.0f), // bottom
	glm::vec3(pencilCosine, 0.5f, -pencilSine), // north-northeast
	glm::vec3(pencilSine, 0.5f, -pencilCosine), // east-northeast
	glm::vec3(pencilSine, 0.5f, pencilCosine), // east-southeast
	glm::vec3(pencilCosine, 0.5f, pencilSine), // south-southeast
	glm::vec3(-pencilCosine, 0.5f, pencilSine), // south-southwest
	glm::vec3(-pencilSine, 0.5f, pencilCosine), // west-southwest
	glm::vec3(-pencilSine, 0.5f, -pencilCosine), // west-northwest
	glm::vec3(-pencilCosine, 0.5f, -pencilSine), // north-northwest
};

// vertex array for octagonal pencil cone
Vertex pencilConeVertices[] =
{
	// position, normal, color, texuv

	// bottom
	Vertex{ glm::vec3(0.0f, 0.0f, 0.0f), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(0.0f, 0.0f, -0.1f), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.0f), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(0.0f, 0.0f, 0.1f), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.0f), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[0], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 0.5f)},

	// north-northeast
	Vertex{ glm::vec3(0.0f, 0.0f, -0.1f), pencilConeNormals[1], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[1], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[1], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},

	// east-northeast
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[2], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.0f), pencilConeNormals[2], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[2], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},

	// east-southeast
	Vertex{ glm::vec3(0.1f, 0.0f, 0.0f), pencilConeNormals[3], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[3], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[3], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},

	// south-southest
	Vertex{ glm::vec3(0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[4], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.0f, 0.1f), pencilConeNormals[4], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[4], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},

	// south-southwest
	Vertex{ glm::vec3(0.0f, 0.0f, 0.1f), pencilConeNormals[5], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[5], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[5], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},

	// west-southwest
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, 0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[6], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.0f), pencilConeNormals[6], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[6], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},

	// west-northwest
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.0f), pencilConeNormals[7], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[7], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[7], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)},

	// north-northwest
	Vertex{ glm::vec3(-0.1f * glm::cos(glm::radians(45.0f)), 0.0f, -0.1f * glm::sin(glm::radians(45.0f))), pencilConeNormals[8], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.0f, -0.1f), pencilConeNormals[8], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(0.0f, 0.1f, 0.0f), pencilConeNormals[8], glm::vec3(0.8f, 0.5f, 0.2f), glm::vec2(0.5f, 1.0f)}
};
// index array for octagonal pencil cone
GLuint pencilConeIndices[] =
{
	// bottom
	0, 1, 2,
	0, 2, 3,
	0, 3, 4,
	0, 4, 5,
	0, 5, 6,
	0, 6, 7,
	0, 7, 8,
	0, 8, 1,

	// north-northeast
	9, 10, 11,

	// east-northeast
	12, 13, 14,

	// east-southeast
	15, 16, 17,

	// south-southeast
	18, 19, 20,

	// south-southwest
	21, 22, 23,

	// west-southwest
	24, 25, 26,

	// west-northwest
	27, 28, 29,

	// north-northwest
	30, 31, 32
};

// vertex array for phone body
Vertex phoneVertices[] =
{// position, normal, color, texuv
	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)}, // top
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},

	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)}, // bottom
	Vertex{ glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, 0.1f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},

	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)}, // front
	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, 0.1f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},

	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)}, // right
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, 0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},

	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)}, // back
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},

	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)}, // left
	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, 0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},
};
// index array for phone body
GLuint phoneIndices[] =
{
	0, 1, 2, // top
	3, 1, 2,

	4, 5, 6, // bottom
	7, 5, 6,

	8, 9, 10, // front
	11, 9, 10,

	12, 13, 14, // right
	15, 13, 14,

	16, 17, 18, // back
	19, 17, 18,

	20, 21, 22, // left
	23, 21, 22
};

// vertex array for phone screen
Vertex phoneScrVertices[] =
{
	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},
};
// index array for phone screen
GLuint phoneScrIndices[] =
{
	0, 1, 2,
	3, 1, 2
};

// vertex array for page
Vertex pageVertices[] =
{
	Vertex{ glm::vec3(-0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, -0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(0.1f, 0.0f, 0.1f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec2(1.0f, 0.0f)},
};
// index array for page
GLuint pageIndices[] =
{
	0, 1, 2,
	3, 1, 2
};

// callback function for scroll wheel, controls camera speed
void scrollCallback(GLFWwindow* window, double xOff, double yOff)
{
	if (yOff > 0.0)
		camSpeed += 0.005f;
	else if (yOff < 0.0)
		camSpeed += -0.005f;

	if (camSpeed <= 0.0f)
		camSpeed = 0.005f;
}

int main()
{	
	// Initialize GLFW
	glfwInit();

	// Specify OpenGL version & profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL Window, Stockton Toronto (clicking window toggles mouse input)", NULL, NULL);

	// Check that window was created
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Use created window
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, windowWidth, windowHeight);

	// Set scrollwheel callback function
	glfwSetScrollCallback(window, scrollCallback);
	
	// Create shaders for desk
	Shader deskShader("default.vert", "default.frag");
	Shader deskLeg1Shader("default.vert", "default.frag");
	Shader deskLeg2Shader("default.vert", "default.frag");
	Shader deskLeg3Shader("default.vert", "default.frag");
	Shader deskLeg4Shader("default.vert", "default.frag");

	// array to store desk textures
	Texture deskTextures[]
	{
		Texture("Desk.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		Texture("Desk_spec.jpg", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	// create vectors from desk-top arrays
	std::vector <Vertex> deskVerts(deskVertices, deskVertices + sizeof(deskVertices) / sizeof(Vertex));
	std::vector <GLuint> deskInds(deskIndices, deskIndices + sizeof(deskIndices) / sizeof(GLuint));
	std::vector <Texture> deskTexs(deskTextures, deskTextures + sizeof(deskTextures) / sizeof(Texture));	
	// model matrix for desk-top
	glm::mat4 deskModel = glm::mat4(1.0f);
	deskModel = glm::scale(deskModel, glm::vec3(20.0f, 3.0f, 10.0f)); // local scale
	// use vectors to create desk-top mesh object
	Mesh desk(deskVerts, deskInds, deskTexs);

	// model matrix for desk-legs
	glm::mat4 deskLegModel = glm::mat4(1.0f);
	deskLegModel = glm::scale(deskLegModel, glm::vec3(1.0f, 40.0f, 1.0f)); // local scale
	// different model for each leg
	glm::mat4 deskLeg1Model = glm::translate(deskLegModel, glm::vec3(-1.895f, -0.005f, 0.895f));
	glm::mat4 deskLeg2Model = glm::translate(deskLegModel, glm::vec3(1.895f, -0.005f, 0.895f));
	glm::mat4 deskLeg3Model = glm::translate(deskLegModel, glm::vec3(-1.895f, -0.005f, -0.895f));
	glm::mat4 deskLeg4Model = glm::translate(deskLegModel, glm::vec3(1.895f, -0.005f, -0.895f));

	// create shader for pencil cylinder
	Shader pencilCylShader("default.vert", "default.frag");
	
	// array to store pencil cylinder textures
	Texture pencilCylTextures[] =
	{
		Texture("Pencil_diffuse.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		Texture("Pencil_spec.jpg", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	// create vectors from pencil cyl arrays
	std::vector <Vertex> pencilCylVerts(pencilCylVertices, pencilCylVertices + sizeof(pencilCylVertices) / sizeof(Vertex));
	std::vector <GLuint> pencilCylInds(pencilCylIndices, pencilCylIndices + sizeof(pencilCylIndices) / sizeof(GLuint));
	std::vector <Texture> pencilCylTexs(pencilCylTextures, pencilCylTextures + sizeof(pencilCylTextures) / sizeof(Texture));
	// model matrix for pencil cylinder
	glm::mat4 pencilCylinderModel = glm::mat4(1.0f);
	pencilCylinderModel = glm::translate(pencilCylinderModel, glm::vec3(1.5f, 0.05f, 0.2f)); // world translate
	pencilCylinderModel = glm::rotate(pencilCylinderModel, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // rotate y
	pencilCylinderModel = glm::rotate(pencilCylinderModel, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate z
	pencilCylinderModel = glm::scale(pencilCylinderModel, glm::vec3(0.2f, 2.0f, 0.2f)); // local scale
	// use vectors to create pencil cylinder mesh object
	Mesh pencilCylinder(pencilCylVerts, pencilCylInds, pencilCylTexs);
	
	// create shader for pencil cone
	Shader pencilConeShader("default.vert", "default.frag");

	// array to store pencil cone textures
	Texture pencilConeTextures[] =
	{
		Texture("Pencil_tip_diffuse.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE),
		Texture("Pencil_spec.jpg", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	// create vectors from pencil cone arrays
	std::vector <Vertex> pencilConeVerts(pencilConeVertices, pencilConeVertices + sizeof(pencilConeVertices) / sizeof(Vertex));
	std::vector <GLuint> pencilConeInds(pencilConeIndices, pencilConeIndices + sizeof(pencilConeIndices) / sizeof(GLuint));
	std::vector <Texture> pencilConeTexs(pencilConeTextures, pencilConeTextures + sizeof(pencilConeTextures) / sizeof(Texture));
	// model matrix for pencil cone
	glm::mat4 pencilConeModel = glm::mat4(1.0f);
	pencilConeModel = glm::translate(pencilConeModel, glm::vec3(1.5f, 0.05f, 0.2f)); // world translate
	pencilConeModel = glm::rotate(pencilConeModel, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // rotate y
	pencilConeModel = glm::rotate(pencilConeModel, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate z
	pencilConeModel = glm::scale(pencilConeModel, glm::vec3(0.2f, 1.25f, 0.2f)); // local scale
	pencilConeModel = glm::translate(pencilConeModel, glm::vec3(0.0f, 0.32f, 0.0f)); // local translate
	// use vectors to create pencil cone mesh object
	Mesh pencilCone(pencilConeVerts, pencilConeInds, pencilConeTexs);

	// create shader for light
	Shader lightShader("light.vert", "light.frag");

	// create shader for directional light (not a light source, just a visual for the direction and color of light)
	Shader lightDirShader("light.vert", "light.frag");

	// create vectors from light arrays
	std::vector <Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector <GLuint> lightInds(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	// model matrix for light
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos); // world translate
	lightModel = glm::scale(lightModel, glm::vec3(0.1f, 0.1f, 0.1f)); // local scale
	// model matrix for directional light
	glm::mat4 lightDirModel = glm::mat4(1.0f);
	lightDirModel = glm::translate(lightDirModel, glm::vec3(10.0f, 10.0f, 10.0f)); // world translate
	lightDirModel = glm::scale(lightDirModel, glm::vec3(1.0f, 1.0f, 1.0f)); // local scale
	// use vectors to create light mesh object
	Mesh light(lightVerts, lightInds, deskTexs); // textures are placeholder and aren't used

	// create shaders for phone
	Shader phoneShader("default.vert", "default.frag");
	Shader phoneScrShader("default.vert", "default.frag");

	// array to store phone body textures
	Texture phoneTextures[] =
	{
		Texture{"hg18.png", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE},
		Texture{"hg18_spec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE}
	};

	// create vectors from phone body arrays
	std::vector <Vertex> phoneVerts(phoneVertices, phoneVertices + sizeof(phoneVertices) / sizeof(Vertex));
	std::vector <GLuint> phoneInds(phoneIndices, phoneIndices + sizeof(phoneIndices) / sizeof(GLuint));
	std::vector <Texture> phoneTexs(phoneTextures, phoneTextures + sizeof(phoneTextures) / sizeof(Texture));
	// model matrix for phone body
	glm::mat4 phoneModel = glm::mat4(1.0f);
	phoneModel = glm::translate(phoneModel, glm::vec3(-0.75f, 0.05f, -0.2f)); // world translate
	phoneModel = glm::rotate(phoneModel, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // rotate y
	phoneModel = glm::scale(phoneModel, glm::vec3(1.0f, 0.2f, 2.0f)); // local scale
	// use vectors to create phone body mesh
	Mesh phone(phoneVerts, phoneInds, phoneTexs);

	// array to store phone screen textures
	Texture phoneScrTextures[] =
	{
		Texture{"335681.png", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE},
		Texture{"screen_spec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE}
	};

	// create vectors from phone screen arrays
	std::vector <Vertex> phoneScrVerts(phoneScrVertices, phoneScrVertices + sizeof(phoneScrVertices) / sizeof(Vertex));
	std::vector <GLuint> phoneScrInds(phoneScrIndices, phoneScrIndices + sizeof(phoneScrIndices) / sizeof(GLuint));
	std::vector <Texture> phoneScrTexs(phoneScrTextures, phoneScrTextures + sizeof(phoneScrTextures) / sizeof(Texture));
	// model matrix for phone screen
	glm::mat4 phoneScrModel = glm::mat4(1.0f);
	phoneScrModel = glm::translate(phoneScrModel, glm::vec3(-0.75f, 0.0501f, -0.2f)); // world translate
	phoneScrModel = glm::rotate(phoneScrModel, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // rotate y
	phoneScrModel = glm::scale(phoneScrModel, glm::vec3(0.9f, 1.0f, 1.8f)); // local scale
	// use vectors to create phone screen mesh
	Mesh phoneScr(phoneScrVerts, phoneScrInds, phoneScrTexs);

	// create shader for page
	Shader pageShader("default.vert", "default.frag");

	// array for storing page textures
	Texture pageTextures[] =
	{
		Texture{"scribble-paper-note.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE},
		Texture{"scirbble-paper-note_spec.jpg", "specular", 1, GL_RED, GL_UNSIGNED_BYTE}
	};

	// create vectors from page arrays
	std::vector <Vertex> pageVerts(pageVertices, pageVertices + sizeof(pageVertices) / sizeof(Vertex));
	std::vector <GLuint> pageInds(pageIndices, pageIndices + sizeof(pageIndices) / sizeof(GLuint));
	std::vector <Texture> pageTexs(pageTextures, pageTextures + sizeof(pageTextures) / sizeof(Texture));
	// model matrix for page
	glm::mat4 pageModel = glm::mat4(1.0f);
	pageModel = glm::translate(pageModel, glm::vec3(0.5f, 0.001f, -0.1f)); // world translate
	pageModel = glm::scale(pageModel, glm::vec3(4.25f, 1.0f, 5.5f)); // local scale
	// use vectors to create page mesh
	Mesh page(pageVerts, pageInds, pageTexs);

	// set uniforms for desk-top shader
	deskShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(deskShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(deskModel));
	glUniform4f(glGetUniformLocation(deskShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(deskShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// set uniforms for desk-leg shaders
	deskLeg1Shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(deskLeg1Shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(deskLeg1Model));
	glUniform4f(glGetUniformLocation(deskLeg1Shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(deskLeg1Shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	deskLeg2Shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(deskLeg2Shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(deskLeg2Model));
	glUniform4f(glGetUniformLocation(deskLeg2Shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(deskLeg2Shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	deskLeg3Shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(deskLeg3Shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(deskLeg3Model));
	glUniform4f(glGetUniformLocation(deskLeg3Shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(deskLeg3Shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	deskLeg4Shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(deskLeg4Shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(deskLeg4Model));
	glUniform4f(glGetUniformLocation(deskLeg4Shader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(deskLeg4Shader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// set uniforms for pencil cylinder shader
	pencilCylShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(pencilCylShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pencilCylinderModel));
	glUniform4f(glGetUniformLocation(pencilCylShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(pencilCylShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// set uniforms for pencil cone shader
	pencilConeShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(pencilConeShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pencilConeModel));
	glUniform4f(glGetUniformLocation(pencilConeShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(pencilConeShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// set uniforms for light shader
	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	// set uniforms for directional light shader
	lightDirShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightDirShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightDirModel));
	glUniform4f(glGetUniformLocation(lightDirShader.ID, "lightColor"), 0.6f, 0.6f, 0.8f, 1.0f);

	// set uniforms for phone body
	phoneShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(phoneShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(phoneModel));
	glUniform4f(glGetUniformLocation(phoneShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(phoneShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	// set uniforms for phone screen
	phoneScrShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(phoneScrShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(phoneScrModel));
	glUniform4f(glGetUniformLocation(phoneScrShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(phoneScrShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// set uniforms for page
	pageShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(pageShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pageModel));
	glUniform4f(glGetUniformLocation(pageShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(pageShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	// needed to display primitives with proper depth
	glEnable(GL_DEPTH_TEST);
	// camera object for 3d display
	Camera camera(windowWidth, windowHeight, glm::vec3(0.0f, 0.2f, 1.0f));	
	
	// Loop for displaying created window
	while (!glfwWindowShouldClose(window))
	{
		// set color and clear buffers
		glClearColor(0.10f, 0.10f, 0.10f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// sets up camera information for shaders
		camera.updateMatrix(75.0f, 0.1f, 100.0f);
		
		// takes user input to control camera and changes speed
		camera.inputs(window, camSpeed);

		// draws objects
		desk.Draw(deskShader, camera);
		desk.Draw(deskLeg1Shader, camera);
		desk.Draw(deskLeg2Shader, camera);
		desk.Draw(deskLeg3Shader, camera);
		desk.Draw(deskLeg4Shader, camera);
		pencilCylinder.Draw(pencilCylShader, camera);
		pencilCone.Draw(pencilConeShader, camera);
		light.Draw(lightShader, camera);
		light.Draw(lightDirShader, camera);
		phone.Draw(phoneShader, camera);
		phoneScr.Draw(phoneScrShader, camera);
		page.Draw(pageShader, camera);
		
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	
	// delete shaders
	deskShader.Delete();
	deskLeg1Shader.Delete();
	deskLeg2Shader.Delete();
	deskLeg3Shader.Delete();
	deskLeg4Shader.Delete();
	pencilCylShader.Delete();
	pencilConeShader.Delete();
	lightShader.Delete();
	phoneShader.Delete();
	phoneScrShader.Delete();
	pageShader.Delete();
	
	// Kill window
	glfwDestroyWindow(window);
		
	// End GLFW
	glfwTerminate();
	return 0;
}