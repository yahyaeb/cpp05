/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:50 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/05 12:28:38 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{	
	protected:
		void performAction() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
	
		class OpenFileException : std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return "ShrubberyCreationForm: Failed to open file.";
			}
		};
		
};
