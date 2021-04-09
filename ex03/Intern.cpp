#include "Intern.hpp"

Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(const Intern & right) {
    *this = right;
}

Intern & Intern::operator=(const Intern &right) {
    (void)(right);
    return (*this);
}

Form * Intern::CreateRobotomyForm(const std::string & target){
    RobotomyRequestForm * r = new RobotomyRequestForm(target);
    return r;
}

Form * Intern::CreatePresidentialForm(const std::string & target){
    PresidentialPardonForm * r = new PresidentialPardonForm(target);
    return r;
}

Form * Intern::CreateShrubberyForm(const std::string & target){
    ShrubberyCreationForm * r = new ShrubberyCreationForm(target);
    return r;
}

const char * Intern::BadNameException::what() const throw() {
    return "Intern: There is no valid type for form";
}

Form * Intern::makeForm(const std::string & form_name, const std::string & target) {
    std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    Form * (*arr[3])(const std::string &) = {Intern::CreateRobotomyForm, Intern::CreatePresidentialForm, Intern::CreateShrubberyForm};
    int i = 0;

    while (i < 3)
    {
        if (form_name == types[i])
        {
            std::cout << "Intern creates " << types[i] << " form" << std::endl;
                return (arr[i](types[i]));
        }
        i++;
    }
    throw Intern::BadNameException();
}