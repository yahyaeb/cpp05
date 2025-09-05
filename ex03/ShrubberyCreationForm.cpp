/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:47 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/05 12:21:46 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::performAction() const
{
	std::ofstream outFile((_target + std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "    /\\    \n";
		outFile << "   /  \\   \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "/________\\\n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";

		outFile.close();
	}
	else
		throw OpenFileException();
		
}
