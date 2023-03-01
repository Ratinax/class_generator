#include "include.hpp"

int	main(int argc, char **argv)
{
	if(mkdir("inc", 0777) == -1)
	{
		std::cout << RED << "Couldn't create folder inc" << WHITEENDL;
		return (1);
	}
	if(mkdir("src", 0777) == -1)
	{
		std::cout << RED << "Couldn't create folder src" << WHITEENDL;
		return (1);
	}
}
