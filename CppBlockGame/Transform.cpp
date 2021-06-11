#include "Transform.h"

#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>


void Transform::decompose()
{
	glm::mat4 transformation; // your transformation matrix.
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transformation, scale, rotation, translation, skew, perspective);

	rotation = glm::conjugate(rotation);

}

glm::vec3 Transform::getPosition()
{
	return position;
}

void Transform::setPosition(glm::vec3 pos)
{
	position = pos;
}

glm::quat Transform::getRotation()
{
	return rotation;
}

void Transform::setRotation(glm::quat rot)
{
	rotation = rot;
}

void Transform::rotate(glm::vec3 axis, float angle)
{
	glm::quat rot;
	glm::vec3 xyz;
	xyz = axis * sin(angle / 2.f);

	rot.x = xyz.x;
	rot.y = xyz.y;
	rot.z = xyz.z;

	rot.w = cos(angle / 2.f);

	rotation = rotation * rot;
}

glm::vec3 Transform::getScale()
{
	return scale;
}

void Transform::setScale(glm::vec3 s)
{
	scale = s;
}

glm::mat4 Transform::getLocal()
{
	glm::mat4 s = glm::scale(glm::mat4(1.0f), scale);
	glm::mat4 rotateM(1.0);
	glm::mat4 translate = glm::translate(glm::mat4(1.0f), position);

	rotateM = glm::mat4_cast(rotation);

	glm::mat4 local = translate * rotateM * s;

	local = s * rotateM * translate;

	return local;
}

glm::mat4 Transform::getGlobal()
{
	if (parent != nullptr)
	{
		return getLocal() * parent->getGlobal();
	}
	else
	{
		return getLocal();
	}
}

void Transform::setParent(Transform* _parent)
{
	parent = _parent;
}

Transform::Transform()
{
	parent = nullptr;
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
	rotation = glm::quatLookAt(glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));
}

Transform::~Transform()
{
}
