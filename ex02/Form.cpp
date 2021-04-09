# include "Form.hpp"
#include <ostream>

Form::Form() : _name("no named form"), _indicator(false), _grade_sign(42), _grade_exec(42)
{
	if (_grade_exec > 150)
			throw Form::GradeTooLowException();
	if (this->_grade_exec < 1)
		throw Form::GradeTooHighException();
	if (_grade_sign > 150)
			throw Form::GradeTooLowException();
	if (this->_grade_sign < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
}

Form::Form(const Form & right) :
	_name(right.getName()), _indicator(getIndicator()), _grade_sign(getSignGrade()), _grade_exec(getExecGrade()), _target(getTarget())

{
	*this = right;
}

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _target("default")
{
	if (_grade_exec > 150)
			throw Form::GradeTooLowException();
	if (this->_grade_exec < 1)
		throw Form::GradeTooHighException();
	if (_grade_sign > 150)
			throw Form::GradeTooLowException();
	if (this->_grade_sign < 1)
		throw Form::GradeTooHighException();
}

Form::Form(std::string name, int grade_sign, int grade_exec, const std::string & target) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _target(target)
{
	if (_grade_exec > 150)
			throw Form::GradeTooLowException();
	if (this->_grade_exec < 1)
		throw Form::GradeTooHighException();
	if (_grade_sign > 150)
			throw Form::GradeTooLowException();
	if (this->_grade_sign < 1)
		throw Form::GradeTooHighException();
}

Form & Form::operator=(const Form & right)
{
	this->_indicator = right.getIndicator();
	return *this;
}
int Form::getSignGrade() const
{
	return this->_grade_sign;
}
int Form::getExecGrade() const
{
	return this->_grade_exec;
}

bool Form::getIndicator() const
{
	return this->_indicator;
}

std::string Form::getName() const
{
	return this->_name;
}

const std::string & Form::getTarget() const
{
	return this->_target;
}


void Form::setIndicator(bool r) 
{
	this->_indicator = r;
}

void Form::beSigned (const Bureaucrat& bur)
{
	if (bur.getGrade() < this->getSignGrade())
		this->_indicator = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & in, const Form & form)
{
	in << form.getName() << " form status : " << form.getIndicator() << " sign grade : " << form.getSignGrade()
		<< " exec grade " << form.getExecGrade() << std::endl;
	return (in);
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("too low");
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("too high");
}

const char * Form::NoSignedFormException::what() const throw()
{
	return ("no signed form, sry");
}

const char * Form::GradeTooLowForExecuteException::what() const throw()
{
	return ("TooLowForExecute )= ");
}
