#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	f24b("24B", 24, 0);
		std::cout << f24b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	Form		f24b("24B", 24, 1);
	Bureaucrat	john("John", 10);
	Bureaucrat	mike("Mike", 50);

	std::cout << f24b << std::endl;
	mike.signForm(f24b);
	std::cout << f24b << std::endl;
	john.signForm(f24b);
	std::cout << f24b << std::endl;
	return (0);
}
