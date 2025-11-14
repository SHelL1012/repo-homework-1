// GLProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <learnopengl/shader_m.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <map>
#include "square.cpp"
#include "circle.cpp"


using namespace glm;  

int width = 1600;
int height = 900;

vec3 cameraPos = vec3(0.0f, 0.0f, 4.0f);
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
    const float cameraSpeed = 0.02f; 
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		cameraPos += cross(cameraFront,normalize(cross(cameraFront, cameraUp))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		cameraPos -= cross(cameraFront, normalize(cross(cameraFront, cameraUp))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		mat4 rotationMatrix = glm::rotate(mat4(1.0f), 0.001f, vec3(0.0f, 1.0f, 0.0f));
		vec4 rotatedVectorHomogeneous = rotationMatrix * vec4(cameraFront, 1.0f);
		cameraFront = vec3(rotatedVectorHomogeneous);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		mat4 rotationMatrix = glm::rotate(mat4(1.0f), 0.001f, vec3(0.0f, -1.0f, 0.0f));
		vec4 rotatedVectorHomogeneous = rotationMatrix * vec4(cameraFront, 1.0f);
		cameraFront = vec3(rotatedVectorHomogeneous);
	}
}


int main()
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(width, height, "Lecture 3", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glEnable(GL_DEPTH_TEST);

	Shader ourShader("./shaders/vs/L3.vs", "./shaders/fs/L3.fs");

	//here
	//clock box


	std::vector<vec3> svertices1 = {};
	svertices1.push_back(vec3(0.5f, -0.5f, 0.5f));
	svertices1.push_back(vec3(-0.5f, -0.5f, 0.5f));
	svertices1.push_back(vec3(-0.5f, 0.5f, 0.5f));
	svertices1.push_back(vec3(0.5f, 0.5f, 0.5f));
	square square1 = square(svertices1, vec3(0.6f, 0.6f, 0.6f));

	std::vector<vec3> svertices2 = {};
	svertices2.push_back(vec3(0.5f, -0.5f, 0.5f));
	svertices2.push_back(vec3(-0.5f, -0.5f, 0.5f));
	svertices2.push_back(vec3(-0.5f, -0.5f, -0.5f));
	svertices2.push_back(vec3(0.5f, -0.5f, -0.5f));
	square square2 = square(svertices2, vec3(0.5f, 0.5f, 0.5f));

	std::vector<vec3> svertices3 = {};
	svertices3.push_back(vec3(0.5f, -0.5f, -0.5f));
	svertices3.push_back(vec3(-0.5f, -0.5f, -0.5f));
	svertices3.push_back(vec3(-0.5f, 0.5f, -0.5f));
	svertices3.push_back(vec3(0.5f, 0.5f, -0.5f));
	square square3 = square(svertices3, vec3(0.5f, 0.5f, 0.5f));

	std::vector<vec3> svertices4 = {};
	svertices4.push_back(vec3(-0.5f, 0.5f, -0.5f));
	svertices4.push_back(vec3(0.5f, 0.5f, -0.5f));
	svertices4.push_back(vec3(0.5f, 0.5f, 0.5f));
	svertices4.push_back(vec3(-0.5f, 0.5f, 0.5f));
	square square4 = square(svertices4, vec3(0.5f, 0.5f, 0.5f));


	std::vector<vec3> svertices5 = {};
	svertices5.push_back(vec3(0.5f, -0.5f, 0.5f));
	svertices5.push_back(vec3(0.5f, -0.5f, -0.5f));
	svertices5.push_back(vec3(0.5f, 0.5f, -0.5f));
	svertices5.push_back(vec3(0.5f, 0.5f, 0.5f));
	square square5 = square(svertices5, vec3(0.5f, 0.5f, 0.5f));

	std::vector<vec3> svertices6 = {};
	svertices6.push_back(vec3(-0.5f, -0.5f, 0.5f));
	svertices6.push_back(vec3(-0.5f, -0.5f, -0.5f));
	svertices6.push_back(vec3(-0.5f, 0.5f, -0.5f));
	svertices6.push_back(vec3(-0.5f, 0.5f, 0.5f));
	square square6 = square(svertices6, vec3(0.5f, 0.5f, 0.5f));


	//clock details


	Circle clockCenter = Circle(glm::vec3(0.0f, 0.0f, 0.51f), 0.02f, glm::vec3(0.0f, 0.0f, 0.0f));


	std::vector<vec3> pointerV = {};
	pointerV.push_back(vec3(0.0f, 0.0f, 0.51f));
	pointerV.push_back(vec3(0.02f, 0.2f, 0.51f));
	pointerV.push_back(vec3(0.0f, 0.25f, 0.51f));
	pointerV.push_back(vec3(-0.02f, 0.2f, 0.51f));
	pointerV.push_back(vec3(0.0f, 0.f, 0.51f));
	square pointer = square(pointerV, glm::vec3(0.0f, 0.0f, 0.0f));

	std::vector<vec3> pointerV2 = {};
	pointerV2.push_back(vec3(0.0f, 0.0f, 0.51f));
	pointerV2.push_back(vec3(0.02f, 0.4f, 0.51f));
	pointerV2.push_back(vec3(0.0f, 0.45f, 0.51f));
	pointerV2.push_back(vec3(-0.02f, 0.4f, 0.51f));
	pointerV2.push_back(vec3(0.0f, 0.f, 0.51f));
	square pointer2 = square(pointerV2, glm::vec3(0.0f, 0.0f, 0.0f));


	//outter decoration


	std::vector<vec3> outBoxL = {};
	outBoxL.push_back(vec3(0.7f, -0.7f, 0.4f));
	outBoxL.push_back(vec3(-0.7f, -0.7f, 0.4f));
	outBoxL.push_back(vec3(-0.7f, 0.7f, 0.4f));
	outBoxL.push_back(vec3(0.7f, 0.7f, 0.4f));
	square outBox = square(outBoxL, vec3(0.62f, 0.15f, 0.15f));

	/*std::vector<vec3> outBoxU = {};
	outBoxU.push_back(vec3(1.0f, -1.0f, -0.5f));
	outBoxU.push_back(vec3(-1.0f, -1.0f, -0.5f));
	outBoxU.push_back(vec3(-1.0f, 1.0f, -0.5f));
	outBoxU.push_back(vec3(1.0f, 1.0f, -0.5f));
	square outBox2 = square(outBoxU, vec3(0.65f, 0.16f, 0.16f));*/

	std::vector<vec3> outBoxR = {};
	outBoxR.push_back(vec3(0.6f, -0.6f, 0.4f));
	outBoxR.push_back(vec3(-0.6f, -0.6f, 0.4f));
	outBoxR.push_back(vec3(-0.6f, 0.6f, 0.4f));
	outBoxR.push_back(vec3(0.6f, 0.6f, 0.4f));
	square outBox3 = square(outBoxR, vec3(0.65f, 0.16f, 0.16f));

	std::vector<vec3> outBoxD = {};
	outBoxD.push_back(vec3(0.6f, -0.6f, 0.4f));
	outBoxD.push_back(vec3(-0.6f, -0.6f, 0.4f));
	outBoxD.push_back(vec3(-0.6f, 0.6f, 0.4f));
	outBoxD.push_back(vec3(0.6f, 0.6f, 0.4f));
	square outBox4 = square(outBoxD, vec3(0.65f, 0.16f, 0.16f));


	//outter cover box witch covers the decorations

	std::vector<vec3> svertices22 = {};
	svertices22.push_back(vec3(1.0f, -1.0f, 0.6f));
	svertices22.push_back(vec3(-1.0f, -1.0f, 0.6f));
	svertices22.push_back(vec3(-1.0f, -1.0f, -0.5f));
	svertices22.push_back(vec3(1.0f, -1.0f, -0.5f));
	square square22 = square(svertices22, vec3(0.65f, 0.16f, 0.16f));

	std::vector<vec3> svertices33 = {};
	svertices33.push_back(vec3(1.0f, -1.0f, -0.5f));
	svertices33.push_back(vec3(-1.0f, -1.0f, -0.5f));
	svertices33.push_back(vec3(-1.0f, 1.0f, -0.5f));
	svertices33.push_back(vec3(1.0f, 1.0f, -0.5f));
	square square33 = square(svertices33, vec3(0.5f, 0.1f, 0.1f));

	std::vector<vec3> svertices44 = {};
	svertices44.push_back(vec3(-1.0f, 1.0f, -0.5f));
	svertices44.push_back(vec3(1.0f, 1.0f, -0.5f));
	svertices44.push_back(vec3(1.0f, 1.0f, 0.6f));
	svertices44.push_back(vec3(-1.0f, 1.0f, 0.6f));
	square square44 = square(svertices44, vec3(0.65f, 0.16f, 0.16f));

	std::vector<vec3> svertices55 = {};
	svertices55.push_back(vec3(1.0f, -1.0f, 0.6f));
	svertices55.push_back(vec3(1.0f, -1.0f, -0.5f));
	svertices55.push_back(vec3(1.0f, 1.0f, -0.5f));
	svertices55.push_back(vec3(1.0f, 1.0f, 0.6f));
	square square55 = square(svertices55, vec3(0.6f, 0.11f, 0.11f));

	std::vector<vec3> svertices66 = {};
	svertices66.push_back(vec3(-1.0f, -1.0f, 0.6f));
	svertices66.push_back(vec3(-1.0f, -1.0f, -0.5f));
	svertices66.push_back(vec3(-1.0f, 1.0f, -0.5f));
	svertices66.push_back(vec3(-1.0f, 1.0f, 0.6f));
	square square66 = square(svertices66, vec3(0.6f, 0.11f, 0.11f));


	//here is the body of the clock


	std::vector<vec3> clB = {};
	clB.push_back(vec3(-0.7f, -1.0f, -0.5f));
	clB.push_back(vec3(-0.7f, -5.0f, -0.5f));
	clB.push_back(vec3(0.7f, -5.0, -0.5f));
	clB.push_back(vec3(0.7f, -1.0f, -0.5f));
	square clkB1 = square(clB, vec3(0.5f, 0.1f, 0.1f));

	std::vector<vec3> clB2 = {};
	clB2.push_back(vec3(-0.6f, -1.0f, 0.3f));
	clB2.push_back(vec3(-0.6f, -4.9f, 0.3f));
	clB2.push_back(vec3(0.6f, -4.9, 0.3f));
	clB2.push_back(vec3(0.6f, -1.0f, 0.3f));
	square clkB2 = square(clB2, vec3(0.5f, 0.1f, 0.1f));

	std::vector<vec3> clB3 = {};
	clB3.push_back(vec3(-0.7f, -1.0f, -0.5f));
	clB3.push_back(vec3(-0.6f, -1.0f, 0.6f));
	clB3.push_back(vec3(-0.6f, -5.0, 0.6f));
	clB3.push_back(vec3(-0.7f, -5.0f, -0.5f));
	square clkB3 = square(clB3, vec3(0.65f, 0.16f, 0.16f));

	std::vector<vec3> clB4 = {};
	clB4.push_back(vec3(0.7f, -1.0f, -0.5f));
	clB4.push_back(vec3(0.6f, -1.0f, 0.6f));
	clB4.push_back(vec3(0.6f, -5.0, 0.6f));
	clB4.push_back(vec3(0.7f, -5.0f, -0.5f));
	square clkB4 = square(clB4, vec3(0.65f, 0.16f, 0.16f));


	// here is the prndulum


	std::vector<vec3> clP = {};
	clP.push_back(vec3(0.04f, -1.0f, 0.4f));
	clP.push_back(vec3(0.04f, -3.0f, 0.4f));
	clP.push_back(vec3(-0.04f, -3.0f, 0.4f));
	clP.push_back(vec3(-0.04f, -1.0f, 0.4f));
	square clkP = square(clP, vec3(0.4f, 0.4f, 0.4f));

	Circle pendulum = Circle(glm::vec3(0.0f, -3.0f, 0.4f),0.2f,glm::vec3(0.4f, 0.4f, 0.4f));



	ourShader.use();
	
	mat4 projection = mat4(1.0f);
	projection = perspective(radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	//projection = ortho(-(float)width, (float)width, -(float)height, (float)height, 0.01f, 100.0f);;
	ourShader.setMat4("projection", projection);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mat4 view = mat4(1.0f);
		//view = translate(view, vec3(0.0f, 0.0f, -4.0f)); (this is not reliable and wouldnt be used )
		view = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		ourShader.setMat4("view", view);
		
		mat4 transformation = mat4(1.0f);
		mat4 pendulum_transformation = mat4(1.0f);
		
		square1.draw(ourShader);
		square2.draw(ourShader);
		square3.draw(ourShader);
		square4.draw(ourShader);
		square5.draw(ourShader);
		square6.draw(ourShader);
		transformation = rotate(transformation, radians(45.0f), vec3(0.0f, 0.0f, 1.0f));
		outBox.transformation(transformation);
		outBox.draw(ourShader);
		//outBox2.transformation(transformation);
		//outBox2.draw(ourShader);
		transformation = rotate(transformation, radians(22.5f), vec3(0.0f, 0.0f, 1.0f));
		outBox3.transformation(transformation);
		outBox3.draw(ourShader);
		transformation = rotate(transformation, radians(45.0f), vec3(0.0f, 0.0f, 1.0f));
		outBox4.transformation(transformation);
		outBox4.draw(ourShader);
		square22.draw(ourShader);
		square33.draw(ourShader);
		square44.draw(ourShader);
		square55.draw(ourShader);
		square66.draw(ourShader);
		clkB1.draw(ourShader);
		clkB2.draw(ourShader);
		clkB3.draw(ourShader);
		clkB4.draw(ourShader);
		pendulum_transformation = rotate(pendulum_transformation, cos((float)glfwGetTime()*2)/8, glm::vec3(0.0f, 0.0f, 1.0f));
		clkP.transformation(pendulum_transformation);
		clkP.draw(ourShader);
		pendulum.transformation(pendulum_transformation);
		pendulum.draw(ourShader);
		clockCenter.draw(ourShader);
		pointer.draw(ourShader);
		transformation = rotate(transformation, radians(60.0f), vec3(0.0f, 0.0f, 1.0f));
		pointer2.transformation(transformation);
		pointer2.draw(ourShader);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}