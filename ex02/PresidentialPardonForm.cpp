#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5, "default target")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) :
		Form("PresidentialPardonForm", 25, 5, target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& right){
	this->setIndicator(right.getIndicator());
	*this = right;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm& right ){
	this->setIndicator(right.getIndicator());
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	if (!this->getIndicator())
		throw Form::NoSignedFormException();
	if (this->getExecGrade() < executor.getGrade()){
		throw Form::GradeTooLowForExecuteException();
	}
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
