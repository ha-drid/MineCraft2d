#include "Player.h"

Player::Player()
{
}

void Player::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Player::init(float x, float y, float width, float height)
{
	setPos(x, y);
	this->width = width;
	this->height = height;
	vertSpeed = 0;
}

void Player::vertMove(float Gravity, std::vector<std::vector<Block>> block)
{
	isFly = true;
	vertSpeed += Gravity;

	for (int i = 0; i < block.size(); ++i)
	{
		for (int j = 0; j < block[i].size(); ++j)
		{
			if (!block[i][j].isEmpty()) {
				if (isColision(block[i][j]))
				{
					isFly = false;
					y += vertSpeed;
					vertSpeed = 0;
					break;
				}
			}
		}
	}
	setPos(x, y - vertSpeed);
}

void Player::move(GLFWwindow* window, std::vector<std::vector<Block>>& block)
{
	int state_space = glfwGetKey(window, GLFW_KEY_SPACE);
	if (state_space == GLFW_PRESS && !isFly)
	{
		vertSpeed = -0.03f;
	}

	int state_a = glfwGetKey(window, GLFW_KEY_A);
	if (state_a == GLFW_PRESS)
	{
		horizon_move(block, 0.01f);
	}

	int state_d = glfwGetKey(window, GLFW_KEY_D);
	if (state_d == GLFW_PRESS)
	{
		horizon_move(block, -0.01f);
	}
}

void Player::horizon_move(std::vector<std::vector<Block>>& block, float dx)
{
	x -= dx;
	for (int i = 0; i < block.size(); ++i)
	{
		for (int j = 0; j < block[i].size(); ++j) {
			if (!block[i][j].isEmpty()) 
			{
				if (isColision(block[i][j]))
				{
					x += dx;
					return;
				}
			}
		}
	}
	x += dx;

	for (int i = 0; i < block.size(); ++i)
	{
		for (int j = 0; j < block[i].size(); ++j) {
			block[i][j].x += dx;
		}
	}
}

void Player::put_blocks(GLFWwindow* window, std::vector<std::vector<Block>>& block)
{
	double y_pos, y_GL;
	double x_pos, x_GL;
	glfwGetCursorPos(window, &x_pos, &y_pos);
	y_GL = y_pos / height_window * visible_part_world_by_player_y;
	x_GL = x_pos / width_window * visible_part_world_by_player_x;

	int iY = (int)trunc(y_GL);
	int iX = (int)trunc(x_GL);

	int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	if (state == GLFW_PRESS)
	{
		for (int i = 0; i < block.size(); ++i)
		{
			for (int j = 0; j < block[i].size(); ++j)
			{
				if (((int)round(block[i][j].x) == iX) && 
					((int)round(block[i][j].y) == -iY) && 
					(block[i][j].isEmpty()))
				{
					block[i][j].type_block = Grass;
					return;
				}
			}
		}
	}
	state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
	if (state == GLFW_PRESS)
	{
		for (int i = 0; i < block.size(); ++i)
		{
			for (int j = 0; j < block[i].size(); ++j)
			{
				if (((int)round(block[i][j].x) == iX) && ((int)round(block[i][j].y) == -iY) && (block[i][j].type_block != Bedrok))
				{
					block[i][j].type_block = Empty;
					return;
				}
			}
		}
	}
}

bool Player::isColision(Block block)
{
	return ((x + width) > block.x) && (x < (block.x + block.width)) &&
		((y + height) >= block.y) && (y <= (block.y + block.height));
}

Player::~Player()
{
}
