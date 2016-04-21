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
	
	const unsigned int fibo_max{100000000};
	assert(fibo_max == 100000000);
	
	std::vector <unsigned int> fibo{9, 78}; //{3, 3, 3};	
	show_fibo(fibo);
	
	fibo.pop_back();	
	show_fibo(fibo);	
	
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	
	fibo.push_back(800);	
	show_fibo(fibo);
	
	fibo.push_back(fibo[1]);
	show_fibo(fibo);
	
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	fibo_fix(fibo, fibo_max);	
	show_fibo(fibo);
	
	std::cout << program_name << '\n';
	
	return 0;
}
