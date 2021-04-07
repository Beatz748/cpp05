#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat() : _name("no name")
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
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
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade += 1;
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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat & right)
{
	this->_grade = right.getGrade();
	return *this;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch (std::exception & excep)
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because " << excep.what() << std::endl;
	}
}
