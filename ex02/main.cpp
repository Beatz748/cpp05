#include <iostream>
#include <unistd.h>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
    Bureaucrat  *karina = new Bureaucrat("Karina", 146);
    Bureaucrat  *pavel = new Bureaucrat("Pavel", 100);
    Form        *trees = new ShrubberyCreationForm("Vanya");

    std::cout << std::endl;
    std::cout << *trees << std::endl;;
    std::cout << *karina << std::endl;;
    karina->signForm(*trees);
    std::cout << *pavel << std::endl;;
    pavel->signForm(*trees);
    std::cout << *trees << std::endl;;

    std::cout << std::endl;
    karina->executeForm(*trees);
    pavel->executeForm(*trees);

    std::cout << std::endl;
    RobotomyRequestForm     *robot_form = new RobotomyRequestForm("Carl");
    while (karina->getGrade() > 40)
        karina->incrementGrade();
    std::cout << *robot_form << std::endl;
    std::cout << *karina << std::endl;
    karina->signForm(*robot_form);
    std::cout << *pavel << std::endl;
    pavel->executeForm(*robot_form);
    karina->executeForm(*robot_form);

    std::cout << std::endl;
    PresidentialPardonForm  *pres_form = new PresidentialPardonForm("Jim");
    while (pavel->getGrade() > 4)
        pavel->incrementGrade();
    std::cout << *pres_form << std::endl;;
    std::cout << *pavel << std::endl;;
    pavel->signForm(*pres_form);
    karina->executeForm(*pres_form);
    pavel->executeForm(*pres_form);

    delete pres_form;
    delete robot_form;
    delete pavel;
    delete karina;
    std::cout << std::endl;
    return (0);
}
