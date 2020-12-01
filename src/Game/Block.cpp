#include "Block.h"

Block::Block()
{
	
}

void Block::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Block::init(float x, float y, float width, float height)
{
	setPos(x, y);
	this->width = width;
	this->height = height;
}

void Block::draw()
{
	float pos[] = { x, y, x + width, y, x + width, y + height, x, y + height };
	uint32_t index[] = { 1,2,3,3,0,1 };
	
	glVertexPointer(2, GL_FLOAT, 0, &pos);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(0, 0, 1);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &index);
	
	glDisableClientState(GL_VERTEX_ARRAY);
}

Block::~Block()
{
}
