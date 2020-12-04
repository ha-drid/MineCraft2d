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

void Block::draw()
{
	if (!isEmpty()) 
	{

		glPushMatrix();
		float pos[] = { x,y,  x + width,y  ,x + width,y + height,  x,y + height };
		uint32_t index[] = { 1,2,3,3,0,1 };

		glVertexPointer(2, GL_FLOAT, 0, &pos);

		glEnableClientState(GL_VERTEX_ARRAY);

		if (type_block == 1)
			glColor3f(0.1f, 0.1f, 0.1f);
		else if (type_block == 2)
			glColor3f(0.1f, 1.f, 0.1f);
		else if (type_block == 3)
			glColor3f(0.1f, 0.2f, 0.3f);
		
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &index);

		glDisableClientState(GL_VERTEX_ARRAY);
		glPopMatrix();
	}
}

bool Block::isEmpty()
{
	return (type_block == 0);
}

Block::~Block()
{
}
