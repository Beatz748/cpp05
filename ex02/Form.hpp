#pragma FORM_HPP
#import <iostream>
#import "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string 			_name;
		bool 										_indicator;
		const int 							_grade_sign;
		const int 							_grade_exec;
		const std::string 			_target;
	public:
		Form();
		~Form();

		Form(std::string name, int grade_sign, int grade_exec);
		Form(const Form & right);
		Form & operator=(const Form & right);
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIndicator() const;
		std::string getName() const;
		void beSigned (const Bureaucrat& bur);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream & right, const Form & form);

