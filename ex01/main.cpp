#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
    Form        *form;
    Bureaucrat  *dima;
    Bureaucrat  *sergey;

    std::cout << std::endl;

    try
    {
        form = new Form("Paper", 211, 156);
        std::cout << "It never gets printed." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        form = new Form("Paper", -9, -57);
        std::cout << "It never gets printed." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    form = new Form("Paper", 40, 30);

    std::cout << std::endl;

    dima = new Bureaucrat("Dima", 77);
    dima->signForm(*form);

    std::cout << std::endl;

    sergey = new Bureaucrat("Sergey", 12);
    sergey->signForm(*form);

    std::cout << std::endl;
    dima->signForm(*form);

    std::cout << std::endl;
    delete sergey;
    delete dima;
    delete form;
    return (0);
}
