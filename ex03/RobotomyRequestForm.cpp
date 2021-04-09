#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45, "default target")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) :
		Form("RobotomyRequestForm", 72, 45, target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& right){
	this->setIndicator(right.getIndicator());
	*this = right;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm& right ){
	this->setIndicator(right.getIndicator());
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	if (!this->getIndicator())
		throw Form::NoSignedFormException();
	if (this->getExecGrade() < executor.getGrade())
	{
		throw Form::GradeTooLowForExecuteException();
	}
	srand(time(0));
	int r = rand() % 2;
	if (r == 1)
	{
		std::cout << "KHDLRBGFO;IEJ'KRP'FSV;KNLJRTG;V'ELMRLN GJKENRLFKEMRNKJFN" << std::endl;
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "Failed to robotomize " << this->getTarget() << std::endl;
	}
}
