#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(){
	Bureaucrat b1("Bureaucrat b1", 130);

//	OK
	Form f0("Form f0", 140, 120);
	Form f1("Form f1", 100, 120);
	std::cout << std::endl;

//	GradeTooLowException
	try{
		Form f2("Form f2", 150, 151);
	}
	catch (Form::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

//	GradeTooHighException
	try{
		Form f3("Form f3", 0, 5);
	}
	catch (Form::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

//	GradeTooHighException
	try{
		Form f4("Form f4", 0, 155);
	}
	catch (Form::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << b1 << f0 << f1 << std::endl;


	try{
		f1.beSigned(b1);
	}
	catch (Form::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		b1.signForm(f1);
	}
	catch (Form::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

	f0.beSigned(b1);
	b1.signForm(f0);

	std::cout << std::endl;

	return 0;
}
