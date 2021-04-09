#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string & target);
		RobotomyRequestForm(const RobotomyRequestForm & right);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm & operator=(const RobotomyRequestForm & right);
		void execute(Bureaucrat const & executor) const;
};

#endif
