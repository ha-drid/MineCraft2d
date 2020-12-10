#pragma once
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include "Block.h"
#include "Player.h"

class World;

class GL
{
public:
	void texture_load(uint32_t* texture, std::string file);
	void block_draw(Block block);
	void player_draw(Player player);
	friend World;
private:
	uint32_t grass_texture;
	uint32_t undefined_texture;
	uint32_t bedrok_texture;
	uint32_t stone_texture;
	uint32_t wood_texture;
	uint32_t foliage_texture;
	uint32_t iron_ore_texture;
	uint32_t dimond_ore_texture;
	uint32_t gold_ore_texture;
	uint32_t soil_texture;
};

static float texture_coord[] = { 0,1,  1,1,  1,0,  0,0 };
