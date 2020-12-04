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

void Player::draw()
{
	float pos[] = { x,y,  x + width,y  ,x + width,   y + height,x,  y + height };
	uint32_t index[] = { 1,2,3,3,0,1 };

	glVertexPointer(2, GL_FLOAT, 0, &pos);
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glColor3f(1, 1, 1);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
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
		horizon_move(block, 0.04f);
	}

	int state_d = glfwGetKey(window, GLFW_KEY_D);
	if (state_d == GLFW_PRESS)
	{
		horizon_move(block, -0.04f);
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

	//system("cls");
	//std::cout << "cursor y gl :" << iY << std::endl;
	//std::cout << "cursor x gl :" << iX << std::endl;

	int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	if (state == GLFW_PRESS)
	{
		for (int i = 0; i < block.size(); ++i)
		{
			for (int j = 0; j < block[i].size(); ++j)
			{
				if (((int)round(block[i][j].x) == iX) && ((int)round(block[i][j].y) == -iY))
				{
					block[i][j].type_block = 1;
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
				if (((int)round(block[i][j].x) == iX) && ((int)round(block[i][j].y) == -iY))
				{
					block[i][j].type_block = 0;
					return;
				}
			}
		}
	}
}

bool Player::isColision(Block block)
{
	return ((x + width) > block.x) && (x < (block.x + block.width)) &&
		((y + height) < block.y) && (y > (block.y + block.height));
}

Player::~Player()
{
}
