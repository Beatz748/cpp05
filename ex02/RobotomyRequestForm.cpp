#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 25, 5, "default target")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) :
		Form("RobotomyRequestForm", 25, 5, target)
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
	if (this->getExecGrade() < executor.getGrade()){
		throw Form::GradeTooLowForExecuteException();
	}
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
