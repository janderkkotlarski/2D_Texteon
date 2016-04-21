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
	
	std::vector <unsigned int> fibo{3, 3, 3};
	
	fibo_error(fibo);
	
	return 0;
}
