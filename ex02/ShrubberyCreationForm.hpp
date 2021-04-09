#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <ofstream>
#include "Form.hpp"

class  ShrubberyCreationForm : public Form
{
	private:
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const  std::string & target);
		ShrubberyCreationForm(const ShrubberyCreationForm & right);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & right);
		void execute(Bureaucrat const & executor) const;
};

#endif
