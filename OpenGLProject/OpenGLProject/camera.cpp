#include"camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{	
	Camera::width = width;
	Camera::height = height;
	Camera::position = position;
}

// Sends matrix data to shader
void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	view = glm::lookAt(position, position + orientation, up);

	if (ortho) // creates orthographic projection
	{
		float sizePerDepth = glm::atan(glm::radians(FOVdeg / 2.0f) * 2.0f);
		auto distance = glm::length(glm::vec3(0.0f, 0.0f, 0.0f) - position); // distance from camera to origin
		float aspect = (float)(width / height);
		float sizeY = sizePerDepth * distance;
		float sizeX = sizePerDepth * distance * aspect;
		proj = glm::ortho(-sizeX, sizeX, -sizeY, sizeY, nearPlane, farPlane);
	}		
	else // creates perspective projection
		proj = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);

	cameraMatrix = proj * view;
}

void Camera::matrix(Shader& shader, const char* uniform)
{
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

// Function for controlling camera
void Camera::inputs(GLFWwindow* window, float newSpeed)
{	
	// mouse controls (left click toggles)
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && mouseReleased)
	{
		mouseReleased = 0;
		mouseToggle = !mouseToggle;
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE && !mouseReleased)
	{
		mouseReleased = 1;
	}
	if (mouseToggle)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// set speed
		speed = newSpeed;
		
		// prevents view from "jumping" when first clicking the window
		if (firstClick)
		{
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// set rotation amount
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		// check X rotation and prevent camera from doing flips
		glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));
		if (!((glm::angle(newOrientation, up) <= glm::radians(5.0f)) || (glm::angle(newOrientation, -up) <= glm::radians(5.0f))))
		{
			// apply X rotation
			orientation = newOrientation;
		}

		// apply Y rotation
		orientation = glm::rotate(orientation, glm::radians(-rotY), up);

		// move cursor to the centor of the window
		glfwSetCursorPos(window, (width / 2), (height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
	
	// keyboard controls
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // close window
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) // move forward
	{
		position += speed * orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) // move left
	{
		position += speed * -glm::normalize(glm::cross(orientation, up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) // move backward
	{
		position += speed * -orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) // move right
	{
		position += speed * glm::normalize(glm::cross(orientation, up));
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) // move up (relative to world)
	{
		position += speed * up;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) // move down (relative to world)
	{
		position += speed * -up;
	}
	if ((glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) && (keyRelease)) // toggles orthographic view on and off
	{
		ortho = !ortho;
		keyRelease = false;
	}
	else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE) // prevents ortho view from repeatedly toggling
	{
		keyRelease = true;
	}
}
