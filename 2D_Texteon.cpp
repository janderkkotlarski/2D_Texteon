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

std::vector <std::vector <int>>

int main()
{	
	const std::string program_name{"2D Texteon V0.1"};
	assert(program_name != "");
	
	const unsigned int fibo_max{100000000};
	assert(fibo_max == 100000000);
	
	std::vector <unsigned int> fibo{};	
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
