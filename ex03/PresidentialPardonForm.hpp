#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string & target);
		PresidentialPardonForm(const PresidentialPardonForm & right);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm & operator=(const PresidentialPardonForm & right);
		void execute(Bureaucrat const & executor) const;
};

#endif
