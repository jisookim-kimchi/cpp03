/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:52:29 by jisokim2          #+#    #+#             */
/*   Updated: 2026/02/28 13:28:33 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap first("first");
    ClapTrap second("second");
    first.attack("default");
    a.takeDamage(11);
    a.attack("second");
    a.beRepaired(11);
    first.beRepaired(10);
    

    first.attack("second");
    first.attack("second");
    first.attack("second");
    first.attack("second");
    first.attack("second");
    first.attack("second");
    first.attack("second");
    first.attack("second");

    //no left energy
    first.attack("default");

    return 0;
}