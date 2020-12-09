#include "Mob.h"

Mob::Mob(int type_mob)
{
	this->type_mob = type_mob;
}

void Mob::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Mob::init(float x, float y, float width, float height)
{
	setPos(x, y);
	this->width = width;
	this->height = height;
}

void Mob::vertMove(float Gravity, std::vector<std::vector<Block>> block)
{

}

void Mob::move(GLFWwindow* window, std::vector<std::vector<Block>>& block)
{
}

Mob::~Mob()
{
}
