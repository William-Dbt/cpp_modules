#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("Unknow") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreation",
																			145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & ref) : AForm(ref.getName(), 145, 137) {
	*this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & ref) {
	if (this != &ref) {
		AForm::operator=(ref);
		this->_target = ref._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::string		fileName(this->_target);
	std::ofstream	stream;

	AForm::execute(executor);
	fileName.append("_shrubbery");
	stream.open(fileName.c_str(), std::ofstream::out & std::ofstream::app);
	if (stream.is_open()) {
		for (int i = 0; i < 4; i++) {
			for (int l = 0; l < 9; l++) {
				for (int n = 0; n < 5; n++) {
					switch (l) {
						case 0: {
							stream << "       _-_       ";
							break ;
						}

						case 1: {
							stream << "    /~~   ~~\\    ";
							break ;
						}

						case 2: {
							stream << " /~~         ~~\\ ";
							break ;
						}

						case 3: {
							stream << "{               }";
							break ;
						}

						case 4: {
							stream << " \\  _-     -_  / ";
							break ;
						}

						case 5: {
							stream << "   ~  \\\\ //  ~   ";
							break ;
						}

						case 6: {
							stream << "_- -   | | _- _  ";
							break ;
						}

						case 7: {
							stream << "  _ -  | |   -_  ";
							break ;
						}

						case 8: {
							stream << "      // \\\\      ";
							break ;
						}
					}
				}
				stream << std::endl;
			}
			stream << std::endl;
		}
	}
	else
		throw ShrubberyCreationForm::FileNotOpenedException();
	
	stream.close();
}

const char*	ShrubberyCreationForm::FileNotOpenedException::what() const throw() {
	return ("ShrubberyCreationForm: execute: Cannot open file!");
}
