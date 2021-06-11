#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

class Transform
{
private:
	Transform* parent;
	std::vector <Transform*> children;
	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;
public:
	void decompose();

	glm::vec3 getPosition();
	void setPosition(glm::vec3 pos);

	glm::quat getRotation();
	void setRotation(glm::quat rot);

	void rotate(glm::vec3 axis, float angle);

	glm::vec3 getScale();
	void setScale(glm::vec3 pos);

	glm::mat4 getLocal();
	glm::mat4 getGlobal();

	void setParent(Transform* parent);

	Transform();
	~Transform();
};

