#pragma once
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include "Block.h"
#include "Player.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

float pos[] = { 0,0, 5,0,  5,-5,  0,-5};
float texture_coord[] = { 0,1,  1,1,  1,0,  0,0 };
uint32_t texture;

static void texture_load()
{
	int width, height, cnt;
	unsigned char* data = stbi_load("C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\src\\Game\\Grass.jpg", &width, &height, &cnt, 0);
	system("cls");
	std::cout << "width:" << width << std::endl;
	std::cout << "height:" << height << std::endl;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
								0, GL_RGB, GL_UNSIGNED_BYTE, data);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

static void load()
{
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, &pos);
	glTexCoordPointer(2, GL_FLOAT, 0, &texture_coord);

	glDrawArrays(GL_POLYGON, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	//glDisable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, 0);
}

static void block_draw(Block block)
{
	float pos[] = { block.x, block.y,
					block.x + block.width,block.y,
					block.x + block.width,  block.y + block.height,
					block.x,block.y + block.height,
	};
	uint32_t index[] = { 0,1,2,3,0,2 };

	glColor3f(0, 1, 1);
	glVertexPointer(2, GL_FLOAT, 0, &pos);
	glEnableClientState(GL_VERTEX_ARRAY);

	glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
}


static void player_draw(Player player)
{
	glPushMatrix();
	float pos[] = { player.x, player.y,
				   player.x + player.width, player.y,
				   player.x + player.width, player.y + player.height,
				   player.x,player.y + player.height};
	
	uint32_t index[] = { 0,1,2,3,0,2 };

	glVertexPointer(2, GL_FLOAT, 0, &pos);

	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(1, 0, 1);
	glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();

}