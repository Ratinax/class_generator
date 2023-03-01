#include "include.hpp"

int	main(int argc, char **argv)
{
	if(mkdir("inc") == -1)
	{
		std::cerr << RED << "Couldn't create folder inc" << WHITEENDL;
		return (1);
	}
	if(mkdir("inc") == -1)
	{
		std::cerr << RED << "Couldn't create folder src" << WHITEENDL;
		return (1);
	}
}
