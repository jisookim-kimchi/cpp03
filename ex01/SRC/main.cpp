/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:52:29 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/03 14:41:49 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ScavTrap.hpp"

int main(void)
{
    ScavTrap *scav = new ScavTrap("scav");
    ClapTrap *clap = new ClapTrap("clap");
    
    clap->attack("a");
    clap->takeDamage(10);
    clap->beRepaired(10);
    scav->guardGate();
    delete clap;
    delete scav;
    
    return 0;
}