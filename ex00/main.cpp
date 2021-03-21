#include "Bureaucrat.hpp"

int main(){
//	GradeTooLowException
	try{
		Bureaucrat a("Bureaucrat a", 154);
	}
	catch (Bureaucrat::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

//	OK
	Bureaucrat b("Bureaucrat b", 100);
	try{
		b.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

//	GradeTooHighException
	try{
		Bureaucrat c("Bureaucrat c", -5);
	}
	catch (Bureaucrat::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

//	OK and then GradeTooLowException
	Bureaucrat d("Bureaucrat d", 148);
	try{
		d.decrementGrade();
		d.decrementGrade();
		d.decrementGrade();
		d.decrementGrade();
		d.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat e("Bureaucrat e", 2);
	try{
		e.incrementGrade();
		e.incrementGrade();
		e.incrementGrade();
		e.incrementGrade();
		e.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &ex){
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << b << d << e;
	std::cout << std::endl;
	return 0;
}
