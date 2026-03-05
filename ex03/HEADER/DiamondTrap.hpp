/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:12:49 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/05 08:16:37 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap ,public FragTrap
{
public:
    DiamondTrap();
    ~DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap &other);
    
    void attack(const std::string& target);
    void whoAmI();
    
private:
    std::string _name;
};

#endif