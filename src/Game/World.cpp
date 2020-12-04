#include "World.h"

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
		{"#...........i...........................#"},
		{"#...........i...........................#"},
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
				block[i][j].init(j, -i, 1, -1, 1);
			}
			else if (map[i][j] == '@') {
				block[i][j].init(j, -i, 1, -1, 2);
			}
			else if (map[i][j] == '&') {
				block[i][j].init(j, -i, 1, -1, 3);
			}
			else if ((map[i][j] == '.') || (map[i][j] == ' ') || (map[i][j] == 'i')) {
				block[i][j].init(j, -i, 1, -1, 0);
			}

			if (map[i][j] == 'i' && map[i + 1][j] == 'i') {
				player.init(j + 0.1, -i, 0.8f, -1.6f);
			}
		}
	}
}

void World::draw_block(int begin, int end)
{
	for (int i = begin; i < end; ++i)
		for (int n = 0; n < block[i].size(); ++n)
			block[i][n].draw();
}

void World::show()
{
	glLoadIdentity();
	glScalef(2.0f / visible_part_world_by_player_x, 2.0f / visible_part_world_by_player_y, 1);

	glTranslatef(-visible_part_world_by_player_x * 0.5, (-visible_part_world_by_player_y + 2) * 0.5, 0);
	glTranslatef(0, visible_part_world_by_player_y-1, 0);

	//std::thread th1(&draw_block, 0, 5);
	//th1.detach();
	//std::thread th2(&draw_block, 0, 5);
	//th2.detach();
	//std::thread th3(&draw_block, 0, 5);
	//th3.detach();
	//std::thread th4(&draw_block, 0, 5);
	//th4.detach();
	draw_block(0, 20);

	player.draw();
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
