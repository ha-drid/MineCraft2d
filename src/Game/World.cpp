#include "World.h"
#include "draw.h"

World::World()
{
	block.resize(world_size_y);
	for (int i = 0; i < world_size_y; ++i)
	{
		block[i].resize(world_size_x);
	}
}

void World::init()
{
	texture_load(&texture_grass, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Grass.jpg");
	std::vector<std::string> map = {
		{"#########################################"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#...........i.........@.................#"},
		{"#...........i.........@@@...............#"},
		{"#........&&&&&&&&&&&&&&&&&&&&&&&&.......#"},
		{"#........&&&&&&&&&&&&&&&&&&&&&&&&.......#"},
		{"#........&&&&&&&&&&&&&&&&&&&&&&&&.......#"},
		{"#........&&&&&&&&&&&&&&&&&&&&&&&&.......#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#.......................................#"},
		{"#########################################"}
	};
	
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j] == '#') {
				block[i][j].init(j, -i, 1, 1, Bedrok);
			}
			else if (map[i][j] == '@') {
				block[i][j].init(j, -i, 1, 1, Grass);
			}
			else if (map[i][j] == '&') {
				block[i][j].init(j, -i, 1, 1, Stone);
			}
			else if ((map[i][j] == '.') || (map[i][j] == ' ') || (map[i][j] == 'i')) {
				block[i][j].init(j, -i, 1, 1, Empty);
			}

			if (map[i][j] == 'i' && map[i + 1][j] == 'i') {
				player.init(j + 0.1, -i - 1, 0.8f, 1.6f);
			}
		}
	}
}

void World::show()
{
	glPushMatrix();
	glScalef(2.0f / visible_part_world_by_player_x, 2.0f / visible_part_world_by_player_y, 1);

	glTranslatef(-visible_part_world_by_player_x * 0.5, (-visible_part_world_by_player_y + 2) * 0.5, 0);
	glTranslatef(0, visible_part_world_by_player_y - 2, 0);

	for (int i = 0; i < block.size(); ++i)
		for (int n = 0; n < block[i].size(); ++n) {
			if (!block[i][n].isEmpty())
				block_draw(block[i][n]);
		}
	player_draw(player);

	glPopMatrix();
}                               

void World::vertMove(float Gravity)
{
	player.vertMove(Gravity, block);
}

void World::player_move(GLFWwindow* window)
{
	player.move(window, block);
	player.put_blocks(window, block);
}

World::~World()
{
}
