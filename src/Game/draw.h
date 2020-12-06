#pragma once
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include "Block.h"
#include "Player.h"

static void block_draw(Block block)
{
	glPushMatrix();
	float pos[] = { block.x, block.y,
				    block.x + block.width,block.y,
				    block.x + block.width,  block.y + block.height,
				    block.x,block.y + block.height,
	};
	uint32_t index[] = { 0,1,2,3,0,2 };

	glVertexPointer(2, GL_FLOAT, 0, &pos);

	glEnableClientState(GL_VERTEX_ARRAY);

	if (block.type_block == 1)
		glColor3f(0.1f, 0.1f, 0.1f);
	else if (block.type_block == 2)
		glColor3f(0.1f, 1.f, 0.1f);
	else if (block.type_block == 3)
		glColor3f(0.1f, 0.2f, 0.3f);

	glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}


static void player_draw(Player player)
{
	glPushMatrix();
	float pos[] = { player.x, player.y,
				   player.x + player.width,player.y,
				   player.x + player.width,  player.y + player.height,
				   player.x,player.y + player.height};
	
	uint32_t index[] = { 0,1,2,3,0,2 };

	glVertexPointer(2, GL_FLOAT, 0, &pos);

	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(1, 1, 1);
	glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();

}