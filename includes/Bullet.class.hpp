// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/21 17:07:53 by spariaud          #+#    #+#             //
//   Updated: 2015/06/21 17:07:54 by spariaud         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

#include "Sprite.class.hpp"
#include <string>
#include "time.h"

class Bullet : public Sprite {

public:
	Bullet(void);
	Bullet(std::string form, int x, int y, int id);
	Bullet(Bullet & src);
	~Bullet(void);

	Bullet &	operator=(Bullet & src);

	void		move();
	int			getId() const;

private:

	clock_t		_clock;
	int			_id;
};

#endif