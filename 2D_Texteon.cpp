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

int main()
{	
	const std::string program_name{"2D Texteon V0.1"};
	assert(program_name != "");
	
	std::vector <unsigned int> fibo{3, 3, 3};
	
	fibo_error(fibo);
	
	std::cout << program_name << '\n';
	
	return 0;
}
