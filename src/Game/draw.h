#pragma once
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include "Block.h"
#include "Player.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

float pos[] = { 1,-8,  9,-8,  9,-1,  1,-1 };
float texture_coord[] = { 0,1,  1,1,  1,0,  0,0 };
uint32_t texture_grass;

static void texture_load(uint32_t* texture, std::string file)
{
	int width, height, cnt;
	unsigned char* data = stbi_load(file.c_str(), &width, &height, &cnt, 0);
	system("cls");
	std::cout << "width:" << width << std::endl;
	std::cout << "height:" << height << std::endl;
	std::cout << "cnt:" << cnt << std::endl;

	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width - 1, height - 1,
								0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

static void load()
{
	GLuint index[] = { 1,2,3, 3,0,1 };

	glColor4f(1, 1, 1, 1);

	glVertexPointer(2, GL_FLOAT, 0, &pos);
	glTexCoordPointer(2, GL_FLOAT, 0, &texture_coord);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

static void block_draw(Block block)
{
	glEnable(GL_TEXTURE_2D);
	if (block.type_block == Grass) {
		glBindTexture(GL_TEXTURE_2D, texture_grass);
	}

	float pos[] = { block.x, block.y,
					block.x + block.width,block.y,
					block.x + block.width,  block.y + block.height,
					block.x,block.y + block.height,
	};
	uint32_t index[] = { 0,1,2,3,0,2 };

	glColor3f(1, 1, 1);
	glVertexPointer(2, GL_FLOAT, 0, &pos);
	glTexCoordPointer(2, GL_FLOAT, 0, &texture_coord);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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