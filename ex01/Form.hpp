#pragma FORM_HPP

# include <string>
# include <iostream>
class From
{
	private:
		const std::string _name;
		bool 							_indicator;
		const int 							_grade_sign;
		const int 							_grade_exec;
	public:
		Form();
		~Form();
		Form(std::string name, bool indicator, int grade_sign, int grade_exec);
		Form & operator=(const Form & right);
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIndicator() const;
		std::string getName() const;
		void beSigned (const Bureaucrat & bur);
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
