#include "World.h"

World::World()
{
	block.resize(200);
}

void World::init()
{
	player.init(0, 1, 1, 2);
}


void World::show()
{
	std::vector<std::string> map = {
		{"########..####"},
		{"##############"},
		{"#......#.....#"},
		{"#.....#i.#...#"},
		{"#....#.i.....#"},
		{"#..########..#"},
		{"#..########..#"},
		{"#..########..#"},
		{"#..########..#"},
		{"#............#"},
		{"#............#"},
		{"#............#"},
		{"##############"}
	};
	
	glLoadIdentity();
	glScalef(2.0f / 20, 2.0f / 15, 1);

	int block_cnt = 0;
	int* p_blockcnt = &block_cnt;

	for (int i = 0; i < map.size(); ++i)
	{
		glPushMatrix();
		for (int t = 0; t < map[i].size(); ++t)
		{
			if (map[i][t] = '#') {
				
				++* p_blockcnt;
			}

			if (map[i][t] == 'i' && (map[i + 1][t] == 'i')) {
				player.init(t, i, 1, 2);
			}
		}
		glPopMatrix();
	}

	block.resize(block_cnt);
	//for (int i = 0; i < map.size(); ++i)
	//{
	//	for (int n = 0; n < map[i].size(); ++n)
	//	{
	//		glPushMatrix();
	//		glTranslatef(n, i, 0);
	//		if (map[i][n] == '#') {
	//			block[block_size].draw();
	//			++*p_blocksize;
	//		}
	//
	//		glPopMatrix();
	//	}
	//}
	
}

void World::vertMove(float Gravity)
{
	//player.vertMove(Gravity);
}

World::~World()
{
}
