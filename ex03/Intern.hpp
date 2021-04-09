//
// Created by UGF3ZWwgTW9za2Fsw7xr TW9za2Fsw7xr on 4/9/21.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:

public:
    Intern();
    virtual ~Intern();
    Intern(const Intern & right);
    Intern & operator=(const Intern & right);
    static Form * CreateShrubberyForm(const std::string & target);
    static Form * CreateRobotomyForm(const std::string & target);
    static Form * CreatePresidentialForm(const std::string & target);
    static Form * makeForm(const std::string & form_name, const std::string & target);

    class BadNameException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

};

#endif //CPP05_INTERN_HPP
