char get_char()
{
	struct termios old_t, new_t;
	
	char character;
  
	tcgetattr(STDIN_FILENO, &old_t);
  
	new_t = old_t;  
	new_t.c_lflag &= ~(ICANON | ECHO);
  
	tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
  
	character = getchar();
  
	tcsetattr(STDIN_FILENO, TCSANOW, &old_t);
	  
	return character;  
}

void typed_char(char& typed)
{
	typed = ' ';
	assert(typed == ' ');
	
	while (typed == ' ')
	{
		typed = get_char();
	}	
}
