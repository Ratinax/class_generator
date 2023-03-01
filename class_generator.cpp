#include "include.hpp"

int	accessToFolder(std::string name)
{
	if (access(name.c_str(), W_OK) != 0)
	{
		std::cout << RED << "Error" << WHITE << " : Doesn't have the write to access " << name << WHITEENDL;
		return (0);
	}
	return (1);
}

int	createFolder(std::string name)
{
	struct stat	folderExists;

	if(stat(name.c_str(), &folderExists) != 0 && mkdir(name.c_str(), 0777) == -1)
	{
		std::cout << RED << "Error" << WHITE << " : Couldn't create folder inc" << WHITEENDL;
		return (0);
	}
	if (accessToFolder(name) == 0)
		return (0);
	return (1);
}

void	createCpp(std::string name)
{
	std::ofstream	myOutFile;

	name += ".cpp";
	name = "src/" + name;
	myOutFile.open(name.c_str());
	if (!(myOutFile.is_open()))
	{
		std::cout << RED << "Error" << WHITE << " : Unable to create file" << name << WHITEENDL;
		return ;
	}
}

void	createHpp(std::string name)
{
	std::ofstream	myOutFile;

	name += ".hpp";
	name = "inc/" + name;
	myOutFile.open(name.c_str());
	if (!(myOutFile.is_open()))
	{
		std::cout << RED << "Error" << WHITE << " : Unable to create file" << name << WHITEENDL;
		return ;
	}
}

int	main(int argc, char **argv)
{
	/*Create folders nd handle errors*/
	if (argc < 2)
	{
		std::cout << MAGENTA << "Warning " << WHITE << ": Should be used : ./class [name of first class] ... [name of last class]" << WHITEENDL;
		return (1);
	}
	if (createFolder("inc") == 0)
		return (1);
	if (createFolder("src") == 0)
		return (1);
	for (int i = 1; i < argc; i++)
	{
		createHpp(argv[i]);
		createCpp(argv[i]);
	}
}
