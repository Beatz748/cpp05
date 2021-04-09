#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137, "Default target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) :
	Form("ShrubberyCreationForm", 145, 137, target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& right){
	this->setIndicator(right.getIndicator());
	*this = right;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm& right ){
	this->setIndicator(right.getIndicator());
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (!this->getIndicator())
		throw Form::NoSignedFormException();
	if (this->getExecGrade() < executor.getGrade()){
		throw Form::GradeTooLowForExecuteException();
	}
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (file.is_open())
	{
		file << " h      -        " << std::endl;
		file << "       ---  l    " << std::endl;
		file << "   e  -----      " << std::endl;
		file << "     -------     " << std::endl;
		file << "    ---------    " << std::endl;
		file << "   -----------   " << std::endl;
		file << "  -------------p " << std::endl;
		file << " --------------- " << std::endl;
		file << "-----------------" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Bad file or filename " << std::endl;
	}
}
