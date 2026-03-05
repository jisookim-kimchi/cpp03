/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:52:29 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/05 08:14:06 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/DiamondTrap.hpp"

int main(void)
{
    DiamondTrap a;
    
    ClapTrap *parent = &a;
    parent->attack("kimchi");
    a.attack("kimbap");
    // DiamondTrap test("test");
    // DiamondTrap *dia = new DiamondTrap("diamond");
    
    // dia->whoAmI();
    // dia->ScavTrap::attack("check");
    // delete dia;
    // return 0;
}