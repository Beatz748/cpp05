#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no name")
{
std::cout << _name << " was successfully created!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor )=" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
std::cout << _name << " was successfully created!" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade -= 1;
	std::cout << "now grade of " << this->getName() << " is " << this->getGrade()
			<< std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade += 1;
	std::cout << "now grade of " << this->getName() << " is " << this->getGrade()
			<< std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade so high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade so low";
}

std::ostream &operator<<(std::ostream &right, const Bureaucrat & bur)
{
	right << bur.getName() << ", bureaucrat grade " << bur.getGrade()
						<< std::endl;
	return (right);
}
