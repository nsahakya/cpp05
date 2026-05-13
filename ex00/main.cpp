#include <bits/stdc++.h>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
    try //too low error
    {
        Bureaucrat a("Narek", 151);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    try //no error
    {
        Bureaucrat a("Narek", 100);
        std::cout << "No error\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    try //too high error
    {
        Bureaucrat a("Narek", 0);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    try  //too low error
    {
        Bureaucrat a("Narek", 150);
        a.decrementGrade();

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    try  //too high
    {
        Bureaucrat a("Narek", 1);
        a.incrementGrade();

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

}