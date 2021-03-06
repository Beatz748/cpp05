#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form;

class Form
{
	private:
		const std::string _name;
		bool 							_indicator;
		const int 							_grade_sign;
		const int 							_grade_exec;
		const std::string _target;
	public:
		Form();
		virtual ~Form();
		Form(std::string name, int grade_sign, int grade_exec);
		Form(std::string name, int grade_sign, int grade_exec, const std::string & target);
		Form(const Form & right);
		Form & operator=(const Form & right);
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIndicator() const;
		const std::string & getTarget() const;
		std::string getName() const;
		void beSigned (const Bureaucrat& bur);
		void setIndicator(bool r);
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
		class GradeTooLowForExecuteException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class NoSignedFormException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & right, const Form & form);

#endif
