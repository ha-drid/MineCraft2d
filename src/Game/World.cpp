#include "World.h"
#include "GL.h"

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
		{"#.............................w.........#"},//8
		{"#.............................w.........#"},//9
		{"#...........p.................w.........#"},//10
		{"#...........p.................w.........#"},//11
		{"#.............................w.........#"},//12
		{"#ggggggggggggggggggggggggggggggggggggggg#"},//13
		{"#sssssssssssssssssssssssssssssssssssssss#"},//14
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
			//if (map[i][j] == '#') {
			//	block[i][j].init(j, -i, 1, 1, Bedrok);
			//}
			//else if (map[i][j] == 'g') {
			//	block[i][j].init(j, -i, 1, 1, Grass);
			//}
			//else if (map[i][j] == 's') {
			//	block[i][j].init(j, -i, 1, 1, Stone);
			//}
			//else if (map[i][j] == 't') {
			//	block[i][j].init(j, -i, 1, 1, Wood);
			//}
			//else if (map[i][j] == 'f') {
			//	block[i][j].init(j, -i, 1, 1, Foliage);
			//}
			//else if (map[i][j] == 'I') {
			//	block[i][j].init(j, -i, 1, 1, Iron_Ores);
			//}
			//else if ((map[i][j] == '.') || (map[i][j] == ' ') || (map[i][j] == 'i')) {
			//	block[i][j].init(j, -i, 1, 1, Empty);
			//}
			switch (map[i][j])
			{
			case('#'): block[i][j].init(j, -i, 1, 1, Bedrok); break;
			case('g'): block[i][j].init(j, -i, 1, 1, Grass); break;
			case('s'): block[i][j].init(j, -i, 1, 1, Stone); break;
			case('w'): block[i][j].init(j, -i, 1, 1, Wood); break;
			case('f'): block[i][j].init(j, -i, 1, 1, Foliage); break;
			case('I'): block[i][j].init(j, -i, 1, 1, Iron_Ores); break;
			case('D'): block[i][j].init(j, -i, 1, 1, Dimond_Ores); break;
			case('G'): block[i][j].init(j, -i, 1, 1, Gold_Ores); break;
			default:   block[i][j].init(j, -i, 1, 1, Empty); break;
			}


			if (map[i][j] == 'p' && map[i + 1][j] == 'p') {
				player.init(j + 0.1, -i - 1, 0.8f, 1.6f);
			}
		}
	}
	texture_load(&bedrok_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Bedrok.jpg");
	texture_load(&grass_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Grass.jpg");
	texture_load(&undefined_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Undefined.jpg");
	texture_load(&stone_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Stone.jpg");
	texture_load(&wood_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Wood.jpg");
	texture_load(&foliage_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Foliage.png");
	texture_load(&iron_ore_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Iron ore.png");
	texture_load(&dimond_ore_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Dimond ore.jpg");
	texture_load(&gold_ore_texture, "C:\\Users\\User\\Documents\\c project\\repos\\MineCraft2d\\img\\Gold ore.png");
}

void World::show()
{
	glPushMatrix();
	glScalef(2.0f / visible_part_world_by_player_x, 2.0f / visible_part_world_by_player_y, 1);

	glTranslatef(-visible_part_world_by_player_x * 0.5, (-visible_part_world_by_player_y + 2) * 0.5, 0);
	glTranslatef(0, visible_part_world_by_player_y - 2, 0);



	block_render(0, block.size());
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

void World::block_render(int begin, int end)
{
	for (int i = begin; i < end; ++i)
		for (int n = 0; n < block[i].size(); ++n) {
			if (!block[i][n].isEmpty())
				block_draw(block[i][n]);
		}
}
