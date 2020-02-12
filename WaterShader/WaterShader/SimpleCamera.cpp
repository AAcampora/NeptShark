#include "SimpleCamera.h"

SimpleCamera::SimpleCamera(GLint basicProgramID)
{
	modelMatrixLocation = glGetUniformLocation(basicProgramID, "model");
	viewMatrixLocation = glGetUniformLocation(basicProgramID, "view");
	projectionMatrixLocation = glGetUniformLocation(basicProgramID, "projection");
	//glUniform3f(modelMatrixLocation, 1, 2, 3);
	
	position = glm::vec3(0.0f, 1.0f, 0.0f);
	//translation matrix set to identity
	translation = glm::mat4(1.0f);

	translation = glm::translate(translation, position);

	cameraPosition = glm::vec3(0.0f, 0.0f, -10.0f);
	cameraTarget = position;
	cameraUP = glm::vec3(0.0f, 1.0f, 0.0f);
	view = glm::lookAt(cameraPosition, cameraTarget, cameraUP);

	projection = glm::perspective(glm::radians(45.0f), (float)1280 / (float)720,
		0.1f, 100.0f);
}


void SimpleCamera::GenCameraUniforms()
{
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(translation));
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projection));
}
