# include "Form.hpp"

Form::Form() : _name("no named form"), _indicator(false), _grade_sign(42), _grade_exec(42)
{
	std::cout << "default form created" << std::endl;
}

Form::~Form()
{
	std::cout << "I'm destructor" << std::endl;
}

Form::Form(const Form & right) : _name(right.getName()), _grade_sign(right.getSignGrade()),
	_grade_exec(right.getExecGrade()), _indicator(right.getIndicator())
{
	*this = right;
}
Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name),
	_indicator(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw (Form::GradeTooHighException());
	if (_grade_sign > 150 || _grade_exec > 150)
		throw (Form::GradeTooLowException());
	std::cout << "created form with name"
		<< this->getName() << std::endl;
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

void Form::beSigned (const Bureaucrat& bur)
{
	if (bur.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	else
		this->_indicator = 1;
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Form Grade is too Low";
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Form Grade is too High";
}

std::ostream & operator<<(std::ostream & in, const Form & form)
{
	in << "FORM : \n name : " << form.getName() << " status : "
		<< form.getIndicator() << " grade to sign : " << form.getSignGrade()
		<< " grade to exec : " << form.getExecGrade() << std::endl;
	return (in);
}
