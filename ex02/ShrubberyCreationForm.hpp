#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class	ShrubberyCreationForm : public 	Form
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& right);
	ShrubberyCreationForm(ShrubberyCreationForm const& right);
};

#endif
