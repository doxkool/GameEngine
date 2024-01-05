#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Core/Logger.h"

namespace Engine
{
	enum direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };

	class Camera
	{
		public:
			Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 worldUp)
			{
				this->ViewMatrix = glm::mat4(1.f);

				this->movementSpeed = 3.f;
				this->sensitivity = 5.f;

				this->worldUp = worldUp;
				this->position = position;
				this->right = glm::vec3(0.f);
				this->up = worldUp;

				this->pitch = 0.f;
				this->yaw = -90.f;
				this->roll = 0.f;

				this->updateCameraVectors();

				LOG_E_DEBUG("New camera has been created.");
			}

			~Camera() {}

			//Accessors
			const glm::mat4 getViewMatrix()
			{
				this->updateCameraVectors();

				this->ViewMatrix = glm::lookAt(this->position, this->position + this->front, this->up);

				return this->ViewMatrix;
			}

			const glm::vec3 getPosition() const
			{
				return this->position;
			}

			//Functions
			void move(const float& dt, const int direction)
			{
				//Update position vector
				switch (direction)
				{
				case FORWARD:
					this->position += this->front * this->movementSpeed * dt;
					break;
				case BACKWARD:
					this->position -= this->front * this->movementSpeed * dt;
					break;
				case LEFT:
					this->position -= this->right * this->movementSpeed * dt;
					break;
				case RIGHT:
					this->position += this->right * this->movementSpeed * dt;
					break;
				case UP:
					this->position += this->up * this->movementSpeed * dt;
					break;
				case DOWN:
					this->position -= this->up * this->movementSpeed * dt;
					break;
				default:
					break;
				}
			}

			void updateMouseInput(const float& dt, const double& offsetX, const double& offsetY)
			{
				//Update pitch yaw and roll
				this->pitch += static_cast<float>(offsetY) * this->sensitivity * dt;
				this->yaw += static_cast<float>(offsetX) * this->sensitivity * dt;

				if (this->pitch > 80.f)
					this->pitch = 80.f;
				else if (this->pitch < -80.f)
					this->pitch = -80.f;

				if (this->yaw > 360.f || this->yaw < -360.f)
					this->yaw = 0.f;
			}

			void updateInput(const float& dt, const int direction, const double& offsetX, const double& offsetY)
			{
				this->updateMouseInput(dt, offsetX, offsetY);
			}

		private:
			glm::mat4 ViewMatrix;

			float movementSpeed;
			float sensitivity;

			glm::vec3 worldUp;
			glm::vec3 position;
			glm::vec3 front;
			glm::vec3 right;
			glm::vec3 up;

			float pitch;
			float yaw;
			float roll;

			void updateCameraVectors()
			{
				this->front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
				this->front.y = sin(glm::radians(this->pitch));
				this->front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

				this->front = glm::normalize(this->front);
				this->right = glm::normalize(glm::cross(this->front, this->worldUp));
				this->up = glm::normalize(glm::cross(this->right, this->front));
			}
	};
}