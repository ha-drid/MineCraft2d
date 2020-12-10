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
		{"#########################################"},//1
		{"#.......................................#"},//2
		{"#.......................................#"},//3
		{"#.......................................#"},//4
		{"#.......................................#"},//5
		{"#.........................ffffffff......#"},//6
		{"#.......................ffffffffffff....#"},//7
		{"#...............uuuuu.........w.........#"},//8
		{"#.............................w.........#"},//9
		{"#...........p.................w.........#"},//10
		{"#...........p.................w.........#"},//11
		{"#.............................w.........#"},//12
		{"#ggggggggggggggggggggggggggggggggggggggg#"},//13
		{"#ggggggggggggggggggggggggggggggggggggggg#"},//14
		{"#sssssssssssssssssssssssssssssssssssssss#"},//15
		{"#sssssssssssssssssssssssssssssssssssssss#"},//16
		{"#.......................................#"},//17
		{"#....GGGGGGGG.......IIIIIII....DDDDDDD..#"},//18
		{"#....GGGGGGGG.......IIIIIII....DDDDDDD..#"},//19
		{"#########################################"},//20
	};
	
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			switch (map[i][j])
			{
			case(' '):
			case('.'):
			case('p'): block[i][j].init(j, -i, 1, 1, Empty); break;
			case('#'): block[i][j].init(j, -i, 1, 1, Bedrok); break;
			case('g'): block[i][j].init(j, -i, 1, 1, Grass); break;
			case('s'): block[i][j].init(j, -i, 1, 1, Stone); break;
			case('w'): block[i][j].init(j, -i, 1, 1, Wood); break;
			case('f'): block[i][j].init(j, -i, 1, 1, Foliage); break;
			case('I'): block[i][j].init(j, -i, 1, 1, Iron_Ores); break;
			case('D'): block[i][j].init(j, -i, 1, 1, Dimond_Ores); break;
			case('G'): block[i][j].init(j, -i, 1, 1, Gold_Ores); break;
			default:   block[i][j].init(j, -i, 1, 1, Undefined); break;
			}


			if (map[i][j] == 'p' && map[i + 1][j] == 'p') {
				player.init(j + 0.1, -i - 1, 0.8f, 1.6f);
			}
		}
	}
	gl.texture_load(&gl.bedrok_texture, "img\\Block\\Bedrok.bmp");
	gl.texture_load(&gl.grass_texture, "img\\Block\\Grass.bmp");
	gl.texture_load(&gl.undefined_texture, "img\\Block\\Undefined.bmp");
	gl.texture_load(&gl.stone_texture, "img\\Block\\Stone.bmp");
	gl.texture_load(&gl.wood_texture, "img\\Block\\Wood.bmp");
	gl.texture_load(&gl.foliage_texture, "img\\Block\\Foliage.bmp");
	gl.texture_load(&gl.iron_ore_texture, "img\\Block\\Iron ore.bmp");
	gl.texture_load(&gl.dimond_ore_texture, "img\\Block\\Dimond ore.bmp");
	gl.texture_load(&gl.gold_ore_texture, "img\\Block\\Gold ore.bmp");
	gl.texture_load(&gl.soil_texture, "img\\Block\\Soil.bmp");
}

void World::show()
{
	glPushMatrix();
	glScalef(2.0f / visible_part_world_by_player_x, 2.0f / visible_part_world_by_player_y, 1);

	glTranslatef(-visible_part_world_by_player_x * 0.5, (-visible_part_world_by_player_y + 2) * 0.5, 0);
	glTranslatef(0, visible_part_world_by_player_y - 2, 0);

	block_render(0, block.size());

	gl.player_draw(player);

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

void World::block_render(int begin, int end)
{
	for (int i = begin; i < end; ++i)
		for (int n = 0; n < block[i].size(); ++n) {
			if (!block[i][n].isEmpty()) {
				if ((block[i][n].type_block == Grass) && (block[i - 1][n].type_block != 0)) {
					block[i][n].type_block = Soil;
				}
				gl.block_draw(block[i][n]);
			}
		}
}
