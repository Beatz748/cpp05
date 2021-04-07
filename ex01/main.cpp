#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
    Form        *form;
    Bureaucrat  *dima;
    Bureaucrat  *sergey;

    // Test constructor Form
    std::cout << std::endl;

    // requiered_sign_grade and requiered_exec_grade > 150
    try
    {
        form = new Form("Paper", 211, 156);
        std::cout << "It never gets printed." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    // requiered_sign_grade and requiered_exec_grade < 1

    try
    {
        form = new Form("Paper", -9, -57);
        std::cout << "It never gets printed." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test sign Form by Bureaucrat
    form = new Form("Paper", 40, 30);

    // Bureaucrat's grade < requiered_sign_grade
    std::cout << std::endl;

    dima = new Bureaucrat("Dima", 77);
    dima->signForm(*form);

    // Bureaucrat's grade > requiered_sign_grade
    std::cout << std::endl;

    sergey = new Bureaucrat("Sergey", 12);
    sergey->signForm(*form);

    //Bureaucrat sign signed form
    std::cout << std::endl;
    dima->signForm(*form);

    std::cout << std::endl;
    delete sergey;
    delete dima;
    delete form;
    return (0);
}
