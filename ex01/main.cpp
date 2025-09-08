/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:44:20 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/06 13:38:31 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try {
		Bureaucrat boss("Big Boss", 20);
		Bureaucrat peon("Lowly Peon", 50);

		Form importantForm("Classified Dossier", 30, 10);

		std::cout << importantForm << std::endl;

		// Try signing with peon (should fail, grade 40 > 30)
		peon.signForm(importantForm);

		// Try signing with boss (should succeed, grade 20 <= 30)
		boss.signForm(importantForm);

		std::cout << importantForm << std::endl;

		// Try signing an already signed form
		boss.signForm(importantForm);
		peon.signForm(importantForm);

	} catch (std::exception &e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}

	return 0;
}

