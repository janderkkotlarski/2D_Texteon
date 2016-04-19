std::vector <unsigned int> random_initializer(const unsigned int fibomax)
{
	std::random_device rand;			
	std::vector <unsigned int> ranma{0, 0};
	assert(ranma.size() == 2);
	assert(ranma[0] == 0);
	assert(ranma[1] == 0);
	
	for (int count{0}; count < 2; ++count)
	{
		while (ranma[count] == 0 ||
			   ranma[0] == ranma[1])
		{
			ranma[count] = rand() % fibomax;
		}
	}
			
	return ranma;	
}

void fibo_error(std::vector <unsigned int>& fibonac)
{
	std::cerr << "Can't fibonacci this, user!\n";
		
	while(fibonac.size() > 0);
	{
			fibonac.pop_back();
	}
}

void pseudonacci(std::vector <unsigned int>& fibonac, const unsigned int fibomax)
{
	assert(fibonac.size() == 2);
	
	if (fibonac.size() == 2)
	{	
		const unsigned int temp{fibonac[1]};
		
		fibonac[1] = (fibonac[1] + fibonac[0]) % fibomax;
		fibonac[0] = temp;	
	}
	else
	{
		fibo_error(fibonac);
	}
}

float fractionize(std::vector <unsigned int>& fibonac, const unsigned int fibomax)
{
	assert(fibonac.size() == 2);
	
	pseudonacci(fibonac, fibomax);
	return static_cast<float>(fibonac[1])/static_cast<float>(fibomax);
}


bool gamble(std::vector <unsigned int>& fibonac, const unsigned int fibomax)
{	
	const float fraction{0.60f};
	assert(fraction > 0.0f);
	assert(fraction < 1.0f);
	
	if (fractionize(fibonac, fibomax) > fraction)
	{
		return true;
	}
	
	return false;
}

void luckey(std::vector <unsigned int>& fibonac, const unsigned int fibomax,
			int& side_x, int& side_y)
{	
	assert(side_x > 0);
	assert(side_y > 0);
	
	const int radius_x{(side_x - 1)/2};
	const int radius_y{(side_y - 1)/2};
	
	const int half_radius_x{radius_x/2 + 1};
	const int half_radius_y{radius_y/2 + 1};
	
	int place_x{0};
	int place_y{0};

	while (((abs(place_x) <= half_radius_x) && (abs(place_y) <= half_radius_y)) ||
			((abs(place_x) >= radius_x) && (abs(place_y) >= radius_y)) ||
			(((abs(place_x) % 2) == 1) || ((abs(place_y) % 2) == 1)))
	{
		place_x = static_cast<int>(
			trunc(static_cast<float>(side_x)*fractionize(fibonac, fibomax))) -
			radius_x;
			
		place_y = static_cast<int>(
			trunc(static_cast<float>(side_y)*fractionize(fibonac, fibomax))) -
			radius_y;	
	}
	
	// std::cout << '[' << place_x << ':' << place_y << ']' << '\n';
	
	side_x = place_x + radius_x;
	side_y = place_y + radius_y;
}
