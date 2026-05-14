#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
    Form form("form", 130, 130);
    Bureaucrat a("A", 125);
    Bureaucrat b("B", 135);

    std::cout << form << std::endl;
    a.signForm(form);
    b.signForm(form);

    return (0);

}