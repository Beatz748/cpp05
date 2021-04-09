#include <iostream>
#include <unistd.h>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
    {
        Intern lobanov;
        Form *tree;
        Form *robot_form;
        Form *pres_form;
        Form *noname_form;

        tree = lobanov.makeForm("shrubbery creation", "tree_file.out");
        robot_form = lobanov.makeForm("robotomy request", "Ivan");
        pres_form = lobanov.makeForm("presidential pardon", "Kate");

        try {
            noname_form = lobanov.makeForm("NoName", "Alex");
        }
        catch (std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }


        delete tree;
        delete robot_form;
        delete pres_form;
    }
    {
        Intern intern;
        Bureaucrat bur("Bureaucrat bur", 5);
        std::cout << std::endl;

        Form *form_presid = intern.makeForm("presidential pardon", "trees");

        std::cout << std::endl;

        try {
            Form *b;
            b = intern.makeForm("president pardon", "trees");
        }
        catch (Intern::BadNameException &ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << std::endl;

        try {
            form_presid->beSigned(bur);
            form_presid->execute(bur);
        }
        catch (Form::GradeTooHighException &ex) {
            std::cout << ex.what() << std::endl;
        }
        catch (Form::GradeTooLowException &ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << std::endl;

        Form *form_robot = intern.makeForm("robotomy request", "Cat");
        try {
            form_robot->beSigned(bur);
            form_robot->execute(bur);
        }
        catch (Form::GradeTooHighException &ex) {
            std::cout << ex.what() << std::endl;
        }
        catch (Form::GradeTooLowException &ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << std::endl;

        Form *form_shrub = intern.makeForm("shrubbery creation", "Garden");
        try {
            form_shrub->beSigned(bur);
            form_shrub->execute(bur);
        }
        catch (Form::GradeTooHighException &ex) {
            std::cout << ex.what() << std::endl;
        }
        catch (Form::GradeTooLowException &ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << std::endl;


        delete form_presid;
        delete form_robot;
        delete form_shrub;

    }
    return (0);
}
