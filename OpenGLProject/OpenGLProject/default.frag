#version 460 core
out vec4 FragColor;

// holds current position
in vec3 crntPos;

// holds normals
in vec3 norm;

// holds colors
in vec3 color;

// holds texture co-ords
in vec2 texCoord;

// uniform for diffuse texture unit
uniform sampler2D diffuse0;

// uniform for specular texture unit
uniform sampler2D specular0;

// uniforms for diffuse lighting
uniform vec4 lightColor;
uniform vec3 lightPos;

// uniform for specular lighting
uniform vec3 camPos;

vec4 pointLight()
{
	vec3 lightVec = lightPos - crntPos;
	float dist = length(lightVec);
	float a = 3.0;
	float b = 0.7;
	float inten = 7.0f / (a * dist * dist + b * dist + 1.0f);
	
	// calculate ambient light
	float ambient = 0.0f;
	
	// calculate diffuse light
	vec3 normal = normalize(norm);
	vec3 lightDir = normalize(lightVec);
	float diffuse = max(dot(normal, lightDir), 0.0f);

	// calculate specular light
	float specLight = 0.5f;
	vec3 viewDir = normalize(camPos - crntPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float specAmp = pow(max(dot(viewDir, reflectDir), 0.0f), 16.0f);
	float specular = specAmp * specLight;
	
	return texture(diffuse0, texCoord) * lightColor * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten;
}

vec4 directLight()
{	
	// calculate ambient light
	float ambient = 0.2f;
	
	// calculate diffuse light
	vec3 normal = normalize(norm);
	vec3 lightDir = normalize(vec3(1.0f, 1.0f, 1.0f));
	float diffuse = max(dot(normal, lightDir), 0.0f);

	// calculate specular light
	float specLight = 0.2f;
	vec3 viewDir = normalize(camPos - crntPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float specAmp = pow(max(dot(viewDir, reflectDir), 0.0f), 16.0f);
	float specular = specAmp * specLight;
	
	return texture(diffuse0, texCoord) * glm::vec4(0.6f, 0.6f, 0.8f, 1.0f) * (diffuse + ambient) + texture(specular0, texCoord).r * specular;
}

vec4 spotLight()
{
	float outerCone = 0.90f;
	float innerCone = 0.95f;

	// calculate ambient light
	float ambient = 0.0f;
	
	// calculate diffuse light
	vec3 normal = normalize(norm);
	vec3 lightDir = normalize(lightPos - crntPos);
	float diffuse = max(dot(normal, lightDir), 0.0f);

	// calculate specular light
	float specLight = 0.5f;
	vec3 viewDir = normalize(camPos - crntPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float specAmp = pow(max(dot(viewDir, reflectDir), 0.0f), 16.0f);
	float specular = specAmp * specLight;

	float angle = dot(vec3(0.4f, -1.0f, 0.1f), -lightDir);
	float inten = clamp((angle - outerCone) / (innerCone - outerCone), 0.0f, 1.0f);
	
	return texture(diffuse0, texCoord) * lightColor * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten;	
}

void main()
{
	FragColor = spotLight() + directLight();
}