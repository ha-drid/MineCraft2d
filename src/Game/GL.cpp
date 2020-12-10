#include "GL.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void GL::texture_load(uint32_t* texture, std::string file)
{
	int width, height, cnt;
	unsigned char* data = stbi_load(file.c_str(), &width, &height, &cnt, 0);

	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
		0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

void GL::block_draw(Block block)
{
	;
	glEnable(GL_TEXTURE_2D);
	//Texture
	switch (block.type_block)
	{
	case(Bedrok): glBindTexture(GL_TEXTURE_2D, bedrok_texture); break;
	case(Grass): glBindTexture(GL_TEXTURE_2D, grass_texture); break;
	case(Soil): glBindTexture(GL_TEXTURE_2D, soil_texture); break;
	case(Stone): glBindTexture(GL_TEXTURE_2D, stone_texture); break;
	case(Wood): glBindTexture(GL_TEXTURE_2D, wood_texture); break;
	case(Foliage): glBindTexture(GL_TEXTURE_2D, foliage_texture); break;
	case(Iron_Ores): glBindTexture(GL_TEXTURE_2D, iron_ore_texture); break;
	case(Dimond_Ores): glBindTexture(GL_TEXTURE_2D, dimond_ore_texture); break;
	case(Gold_Ores): glBindTexture(GL_TEXTURE_2D, gold_ore_texture); break;
	default: glBindTexture(GL_TEXTURE_2D, undefined_texture); break;
	}

	float pos[] = { block.x, block.y,
					block.x + block.width, block.y,
					block.x + block.width, block.y + block.height,
					block.x,block.y + block.height,
	};
	uint32_t index[] = { 0,1,2,3,0,2 };

	glColor4f(1, 1, 1, 1);
	glVertexPointer(2, GL_FLOAT, 0, &pos);
	glTexCoordPointer(2, GL_FLOAT, 0, &texture_coord);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}



void GL::player_draw(Player player)
{
	glPushMatrix();
	float pos[] = { player.x, player.y,
				   player.x + player.width, player.y,
				   player.x + player.width, player.y + player.height,
				   player.x,player.y + player.height };
	
	uint32_t index[] = { 0,1,2,3,0,2 };

	glVertexPointer(2, GL_FLOAT, 0, &pos);

	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(1, 1, 1);
	glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();

}