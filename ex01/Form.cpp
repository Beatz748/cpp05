# include "Form.hpp"

Form::Form() : _name("no named form"), _indicator(false), _grade_sign(42), _grade_exec(42)
{
	std::cout << "default form created" << std::endl;
}

Form::~Form()
{
	std::cout << "I'm destructor" << std::endl;
}

Form::Form(const Form & right)
{
	this = right;
}

Form::Form(std::string name, bool indicator, int grade_sign, int grade_exec) : _name(name), _indicator(indicator), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	std::cout << "created form with name"
		<< this->getName() << std::endl;
}
Form & Form::operator=(const Form & right)
{
	this->_grade_exec = right.getExecGrade();
	this->_grade_sign = right.getSignGrade();
	this->_name = right.getName();
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

void Form::beSigned (const Bureaucrat& bur)
{
	std::cout << "_grade now is 150" << std::endl;
}
