#include <iostream>

#include <cstdio>
#include <stdio.h>
#include <termios.h>
#include <unistd.h> 

#include <string>
#include <vector>

#include <random>

#include <cassert>


#include "pseudo_random.h"

int show_maze_line(const std::vector <int>& line, const int side, const char symbol)
{
	if (static_cast<int>(line.size()) == side)
	{
		std::cout << symbol;
							
		for (int count{0}; count < side; ++count)
		{
			std::cout << line[count];
		}
				
		std::cout << symbol << '\n';
		
		return side;
	}
	
	std::cerr << "Line wrong!\n";
	
	return -1;
}

int show_maze_border(const std::vector <char>& line, const int side, const char symbol)
{
	if (static_cast<int>(line.size()) == side)
	{
		std::cout << symbol;
							
		for (int count{0}; count < side; ++count)
		{
			std::cout << line[count];
		}
				
		std::cout << symbol << '\n';
		
		return side;
	}
	
	std::cerr << "Border wrong!\n";
	
	return -1;
}

int show_maze(const std::vector <std::vector < int>>& maze)
{
	assert(maze.size() > 0);
	assert(maze.size() == maze[0].size());
	
	const int side_x{static_cast<int>(maze[0].size())};
	const int side_y{static_cast<int>(maze.size())};
	
	const char border_symbol{'+'};	
	const std::vector <char> border_line(side_x, '-');
	
	const char maze_symbol{'|'};
		
	if (side_x == side_y)
	{
		const int radius{(side_x - 1)/2};
		
		if (show_maze_border(border_line, side_x, border_symbol) == -1)
		{
			return -1;
		}
		
		for (int count_y{0}; count_y < side_y; ++count_y)
		{							
			if (show_maze_line(maze[count_y], side_x, maze_symbol) == -1)
			{
				return -1;
			}
		}
		
		if (show_maze_border(border_line, side_x, border_symbol) == -1)
		{
			return -1;
		}
		
		return radius;
	}
	
	return -1;
}


int create_maze(std::vector <std::vector < int>>& maze, const int radius)
{
	assert(radius > 0);
	
	if (radius > 0)
	{
		const int side{radius + 1 + radius};
		
		std::vector <int> line(side, 0);		
		std::vector <std::vector < int>> mazoid(side, line);	
		
		if ((mazoid.size() == static_cast<unsigned int>(side)) &&
			(mazoid[0].size() == static_cast<unsigned int>(side)))
		{
			maze = mazoid;
			return side;
		}
	}
	
	return -1;
}

int maze_initiate(std::vector <std::vector < int>>& maze, const int radius,
				   std::vector <unsigned int>& fibonac, const unsigned int fibo_max,
				   const float fraction, const int empty)
{
	assert(maze.size() > 0);
	assert(maze.size() == maze[0].size());
	
	const int side_x{static_cast<int>(maze[0].size())};
	const int side_y{static_cast<int>(maze.size())};
	
	if ((side_x == side_y) && ((side_x - 1)/2 == radius))
	{	
		for (int count_y{0}; count_y < side_y; ++count_y)
		{
			for (int count_x{0}; count_x < side_x; ++count_x)
			{
				if (((abs(count_x - radius) % 2) == 1) &&
					((abs(count_y - radius) % 2) == 1))
				{
					maze[count_y][count_x] = 1;
				}
			
				if ((abs(count_x - radius) > empty) ||
					(abs(count_y - radius) > empty))
				{				
					if (((abs(count_x - radius) % 2) + (abs(count_y - radius) % 2)) == 1)
					{
						if (fraction < fractionize(fibonac, fibo_max))
						{
							maze[count_y][count_x] = 1;
						}
					}		
				}				
			}
		}
		
		return radius;
	}
			
	return -1;
}


int main()
{	
	const std::string program_name{"2D Texteon V0.2"};
	assert(program_name != "");
	
	const unsigned int fibo_max{100000000};
	assert(fibo_max == 100000000);
	
	std::vector <unsigned int> fibo{random_initializer(fibo_max)};	
	show_fibo(fibo);
	
	const int radius{10};
	
	const int empty{2};
	
	const float fraction{0.35};
	
	
	
	std::vector <std::vector < int>> maze;
		
	if (create_maze(maze, radius) == -1)
	{
		return 1;
	}
	
	if (maze_initiate(maze, radius, fibo, fibo_max, fraction, empty) == -1)
	{
		return 1;
	}
	
	if (show_maze(maze) == -1)
	{
		return 1;
	}
	
	std::cout << program_name << '\n';
	
	return 0;
}
