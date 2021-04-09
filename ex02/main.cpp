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
    Bureaucrat  *nina = new Bureaucrat("Nina", 100);
    Form        *trees = new ShrubberyCreationForm("tree.output.file");

    // Test sign form ShrubberyCreationForm
    std::cout << std::endl;
    std::cout << *trees << std::endl;;
    std::cout << *karina << std::endl;;
    karina->signForm(*trees);
    std::cout << *nina << std::endl;;
    nina->signForm(*trees);
    std::cout << *trees << std::endl;;

    // Test execute form ShrubberyCreationForm
    std::cout << std::endl;
    karina->executeForm(*trees);
    nina->executeForm(*trees);

    // Test execute form RobotomyRequestForm
    std::cout << std::endl;
    RobotomyRequestForm     *robot_form = new RobotomyRequestForm("Bob");
    while (karina->getGrade() > 40)
        karina->incrementGrade();
    std::cout << *robot_form << std::endl;
    std::cout << *karina << std::endl;
    karina->signForm(*robot_form);
    std::cout << *nina << std::endl;
    nina->executeForm(*robot_form);
    karina->executeForm(*robot_form);

    // Test execute form PresidentialPardonForm
    std::cout << std::endl;
    PresidentialPardonForm  *pres_form = new PresidentialPardonForm("Jim");
    while (nina->getGrade() > 4)
        nina->incrementGrade();
    std::cout << *pres_form << std::endl;;
    std::cout << *nina << std::endl;;
    nina->signForm(*pres_form);
    karina->executeForm(*pres_form);
    nina->executeForm(*pres_form);

    delete pres_form;
    delete robot_form;
    delete nina;
    delete karina;
    std::cout << std::endl;
    return (0);
}
