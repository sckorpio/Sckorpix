#ifndef CAMERA_H
#define CAMERA_H
#define GL_GLEXT_PROTOTYPES

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	// camera
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	// timing
	float deltaTime;	// time between current frame and last frame
	float lastFrame;

	//Looking
	bool firstMouse;
	double lastX;
	double lastY;
	float yaw;
	float pitch;
	float roll;

	Camera();
	~Camera();
	void InitCamera();
	glm::mat4 CameraTransformation();
	void KeyInput(GLFWwindow* window);
	void MouseInput(GLFWwindow* window, double xpos, double ypos);
};

#endif // CAMERA_H