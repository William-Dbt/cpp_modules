#include <iostream>
#include <cstring>

int	main(int argc, char const *argv[])
{
	int		n;
	char	c;

	if (argc <= 1)
	{
		std::cout << "Shrrrrronnnc Rrr Shiiiiiiii Poc." << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		for (n = 0; n < (int)strlen(argv[i]); n++)
		{
			if (argv[i][n] >= 'a' and argv[i][n] <= 'z')
			{
				c = toupper(argv[i][n]);
				std::cout << c;
			}
			else
				std::cout << argv[i][n];
		}
		if (i + 1 != argc)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}