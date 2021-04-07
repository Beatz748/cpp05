#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		~Bureaucrat();
		Bureaucrat();
		std::string			getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		Bureaucrat& operator=(const Bureaucrat & right);
		Bureaucrat(Bureaucrat const& right);
		Bureaucrat(std::string name, int grade);
		void signForm(Form &form);
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

std::ostream &operator<<(std::ostream &right, const Bureaucrat & bur);

#endif
