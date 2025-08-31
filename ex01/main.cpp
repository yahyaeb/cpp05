/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:44:20 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/08/31 15:44:10 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat boss("Big Boss", 50);
        Bureaucrat peon("Lowly Peon", 50);

        Form importantForm("Classified Dossier", 60, 10);

        std::cout << importantForm << std::endl;

        // Try signing with peon (should fail)
        try {
            peon.signForm(importantForm);
        } catch (std::exception &e) {
            std::cout << "Exception caught: PEON failed to sign" << e.what() << std::endl;
        }

        // Try signing with boss (should succeed)
        try {
            boss.signForm(importantForm);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << importantForm << std::endl;

        // Try signing an already signed form with boss (should not throw, but can if you want)
        try {
            boss.signForm(importantForm);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test invalid form (grade too high)
        try {
            Form badForm("Impossible Form", 0, 1);
        } catch (std::exception &e) {
            std::cout << "Caught exception (too high): " << e.what() << std::endl;
        }

        // Test invalid form (grade too low)
        try {
            Form badForm("Useless Form", 151, 1);
        } catch (std::exception &e) {
            std::cout << "Caught exception (too low): " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Outer catch: " << e.what() << std::endl;
    }

    return 0;
}
