#include "include.hpp"

std::string	stringUpper(std::string str)
{
	std::string	res;

	res = str;
	for (long unsigned int i = 0; i < res.length(); i++)
		res[i] = toupper(res[i]);
	return (res);
}

void	putMessage(std::ofstream &myOutFile, std::string name, std::string message, std::string color = "")
{
	myOutFile << "	std::cout << ";
	if (color != "")
		myOutFile << "BLACK << ";
	myOutFile << "\"" << name << " " << message << "\"" << " << ";
	if (color != "")
		myOutFile << "WHITENDL;" << std::endl;
	else
		myOutFile << "std::endl;" << std::endl;
}

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

void	createCpp(std::string name, int is_color)
{
	std::ofstream	myOutFile;
	std::string		fileName;

	(void) is_color;
	fileName = "src/" + name + ".cpp";
	myOutFile.open(fileName.c_str());
	if (!(myOutFile.is_open()))
	{
		std::cout << RED << "Error" << WHITE << " : Unable to create file" << fileName << WHITEENDL;
		return ;
	}
	myOutFile << "#include \"" << name << ".hpp\"" << std::endl << std::endl;
	myOutFile << name << "::" << name << "(void)" << std::endl;
	myOutFile << "{" << std::endl;
	if (is_color != 0)
		putMessage(myOutFile, name, "default constructor called", "BLACK");
	else
		putMessage(myOutFile, name, "default constructor called");
	myOutFile << "}" << std::endl << std::endl;
	myOutFile << name << "::" << name << "(const " << name << " &" << (char)tolower(name[0]) << ")" << std::endl;
	myOutFile << "{" << std::endl;
	if (is_color != 0)
		putMessage(myOutFile, name, "copy constructor called", "BLACK");
	else
		putMessage(myOutFile, name, "copy constructor called");
	myOutFile << "}" << std::endl << std::endl;
	myOutFile << name << "	&" << name << "::operator=(const " << name << " &" << (char)tolower(name[0]) << ")" << std::endl;
	myOutFile << "{" << std::endl;
	if (is_color != 0)
		putMessage(myOutFile, name, "overload equal constructor called", "BLACK");
	else
		putMessage(myOutFile, name, "overload equal constructor called");
	myOutFile << "	return (*this);" << std::endl;
	myOutFile << "}" << std::endl << std::endl;
	myOutFile << name << "::" << "~" << name << "(void)" << std::endl;
	myOutFile << "{" << std::endl;
	if (is_color != 0)
		putMessage(myOutFile, name, "destructor called", "BLACK");
	else
		putMessage(myOutFile, name, "destructor called");
	myOutFile << "}" << std::endl;
	myOutFile.close();
}

void	createHpp(std::string name, int is_color)
{
	std::ofstream	myOutFile;
	std::string		fileName;

	fileName = "inc/" + name + ".hpp";
	myOutFile.open(fileName.c_str());
	if (!(myOutFile.is_open()))
	{
		std::cout << RED << "Error" << WHITE << " : Unable to create file" << fileName << WHITEENDL;
		return ;
	}
	myOutFile << "#ifndef " << stringUpper(name + "_hpp") << std::endl;
	myOutFile << "# define " << stringUpper(name + "_hpp") << std::endl << std::endl;
	/*Write colors*/
	if (is_color)
	{
		myOutFile << "# define WHITEENDL   std::endl << WHITE" << std::endl;
		myOutFile << "# define BLACK			\"\\033[30m\"" << std::endl;
		myOutFile << "# define RED			\"\\033[31m\"" << std::endl;
		myOutFile << "# define GREEN			\"\\033[32m\"" << std::endl;
		myOutFile << "# define YELLOW			\"\\033[33m\"" << std::endl;
		myOutFile << "# define BLUE			\"\\033[34m\"" << std::endl;
		myOutFile << "# define MAGENTA		\"\\033[35m\"" << std::endl;
		myOutFile << "# define CYAN			\"\\033[36m\"" << std::endl;
		myOutFile << "# define WHITE			\"\\033[37m\"" << std::endl;
		myOutFile << "# define BOLDBLACK		\"\\033[1m\\033[30m\"" << std::endl;
		myOutFile << "# define BOLDRED		\"\\033[1m\\033[31m\"" << std::endl;
		myOutFile << "# define BOLDGREEN		\"\\033[1m\\033[32m\"" << std::endl;
		myOutFile << "# define BOLDYELLOW		\"\\033[1m\\033[33m\"" << std::endl;
		myOutFile << "# define BOLDBLUE		\"\\033[1m\\033[34m\"" << std::endl;
		myOutFile << "# define BOLDMAGENTA	\"\\033[1m\\033[35m\"" << std::endl;
		myOutFile << "# define BOLDCYAN		\"\\033[1m\\033[36m\"" << std::endl;
		myOutFile << "# define BOLDWHITE		\"\\033[1m\\033[37m\"" << std::endl << std::endl;
	}
	/*Write*/
	myOutFile << "class	" << name << " {" << std::endl << std::endl;
	myOutFile << "	private :" << std::endl << std::endl;
	myOutFile << "	public :" << std::endl;
	myOutFile << "		" << name << "(void);" << std::endl;
	myOutFile << "		" << name << "(const " << name << " &" << (char)tolower(name[0]) << ");" << std::endl;
	myOutFile << "		" << name << " &operator=(const " << name << " &" << (char)tolower(name[0]) << ");" << std::endl;
	myOutFile << "		" << "~" << name << "(void);" << std::endl;
	myOutFile << "}" << std::endl << std::endl;
	myOutFile << "#endif" << std::endl;
	myOutFile.close();
}

int	remove(int argc, char **argv)
{
	int			status;
	int			worstCase;
	std::string	fileName;
	std::string	fileNameC;
	std::string	fileNameH;

	worstCase = 0;
	for (int i = 2; i < argc; i++)
	{
		fileName = argv[i];
		fileNameC = "src/" + fileName + ".cpp";
		fileNameH = "inc/" + fileName + ".hpp";
		status = remove(fileNameC.c_str());
		if (status != 0)
		{
			worstCase  = status;
			std::cout << RED << "Error" << WHITE << " : couldn't delete " << fileNameC << WHITEENDL;
		}
		status = remove(fileNameH.c_str());
		if (status != 0)
		{
			worstCase  = status;
			std::cout << RED << "Error" << WHITE << " : couldn't delete " << fileNameH << WHITEENDL;
		}
	}
	return (worstCase);
}

int	removeFolders()
{
	int	status;
	int	worstCase;

	worstCase = 0;
	status = 0;
	if (std::filesystem::exists("inc/") == 1 && access("inc/", W_OK) == 0)
		status = std::filesystem::remove_all("inc/");
	else
		status = 255;
	if (status != 2)
	{
		worstCase  = status;
		std::cout << RED << "Error" << WHITE << " : couldn't delete inc/" << WHITEENDL;
	}
	if (std::filesystem::exists("src/") == 1 && access("src/", W_OK) == 0)
		status = std::filesystem::remove_all("src/");
	else
		status = 255;
	if (status != 2)
	{
		worstCase  = status;
		std::cout << RED << "Error" << WHITE << " : couldn't delete src/" << WHITEENDL;
	}
	return (worstCase);
}

int	main(int argc, char **argv)
{
	int	is_hcolor;
	int	is_ccolor;
	/*Create folders and handle errors*/
	if (argc < 2)
	{
		std::cout << MAGENTA << "Warning " << WHITE << ": Should be used : ./class [[-rmf]||[-rm]||[-hc][-cc]] [name of first class] ... [name of last class]" << WHITEENDL;
		return (1);
	}
	if (argc == 2 && strcmp(argv[1], "-rmf") == 0)
		return (removeFolders());
	is_hcolor = 0;
	is_ccolor = 0;
	if (argc > 2)
	{
		if (strcmp(argv[1], "-rm") == 0)
			return (remove(argc, argv));
		if (strcmp(argv[1], "-hc") == 0 || (strcmp(argv[2], "-hc") == 0 && strcmp(argv[1], "-cc") == 0))
			is_hcolor = 1;
		if (strcmp(argv[1], "-cc") == 0 || (strcmp(argv[2], "-cc") == 0 && strcmp(argv[1], "-hc") == 0))
			is_ccolor = 1;
	}
	if (createFolder("inc") == 0)
		return (1);
	if (createFolder("src") == 0)
		return (1);
	for (int i = 1 + is_hcolor + is_ccolor; i < argc; i++)
	{
		createHpp(argv[i], is_hcolor);
		createCpp(argv[i], is_ccolor);
	}
}
