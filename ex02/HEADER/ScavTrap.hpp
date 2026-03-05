/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:34:55 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/04 16:16:36 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    explicit ScavTrap(const std::string &name);
    virtual ~ScavTrap();
    ScavTrap(const ScavTrap &other);
    ScavTrap& operator=(const ScavTrap &other); // << this hmm 
    void guardGate();
    
private:
    bool _isGateKeeperMode;
};

#endif