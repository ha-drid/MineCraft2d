#include "Block.h"

Block::Block()
{
	
}

void Block::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Block::init(float x, float y, float width, float height, int type_block)
{
	setPos(x, y);
	this->width = width;
	this->height = height;
	this->type_block = type_block;
}

bool Block::isEmpty()
{
	return (type_block == 0);
}

Block::~Block()
{
}
