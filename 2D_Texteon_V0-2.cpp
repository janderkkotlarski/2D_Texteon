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

int show_maze(std::vector <std::vector < int>>& maze)
{
	assert(maze.size() > 0);
	assert(maze.size() == maze[0].size());
	
	const int side_x{static_cast<int>(maze[0].size())};
	const int side_y{static_cast<int>(maze.size())};
	
	if ((static_cast<unsigned int>(radius) == maze.size()) &&
		(static_cast<unsigned int>(radius) == maze[0].size())
	{
		const int side{radius + 1 + radius};
		
		for (int count_x{0}; count_x <
		
		return radius;
	}
	
	return -1;
}


int maze_create(std::vector <std::vector < int>>& maze, const int radius)
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

void maze_initiate(std::vector <std::vector < int>>& maze, const int radius,
				   std::vector <unsigned int>& fibonac, const unsigned int fibo_max)
{
	
}


int main()
{	
	const std::string program_name{"2D Texteon V0.2"};
	assert(program_name != "");
	
	const unsigned int fibo_max{100000000};
	assert(fibo_max == 100000000);
	
	std::vector <unsigned int> fibo{random_initializer(fibo_max)};	
	show_fibo(fibo);
	
	
		
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	
	for (int count{0}; count < 10; ++count)
	{
		pseudonacci(fibo, fibo_max);
		show_fibo(fibo);
	}
	
	std::cout << program_name << '\n';
	
	return 0;
}
