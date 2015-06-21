// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Penis.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 18:14:56 by yfuks             #+#    #+#             //
//   Updated: 2015/06/20 18:14:56 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Penis.class.hpp"
#include "Window.class.hpp"

Penis::Penis(void) : Sprite(" //______\n   ____|_)\n_)_)", 0, 0) {
	for (int i = 0; i < 10; i++) {
		this->_bullets[i] = NULL;
	}
}

Penis::Penis(int x, int y) : Sprite(" //______\n   ____|_)\n_)_)", x, y) {
	for (int i = 0; i < 10; i++) {
		this->_bullets[i] = NULL;
	}
}

Penis::Penis(Penis & src) : Sprite(src) {
	*this = src;
}

Penis::~Penis(void) {
	for (int i = 0; i < 10; i++) {
		if (this->_bullets[i])
			delete this->_bullets[i];
	}
}

Penis &	Penis::operator=(Penis & src) {
	this->_x = src.getX();
	this->_y = src.getY();
	this->_form = src.getForm();
	return *this;
}

void	Penis::shootBullet() {
	if (this->_nbBullets < 10) {
		this->_bullets[Penis::_nbBullets] = new Bullet("~o", this->getX() + 10, this->getY() + 1);
		this->_nbBullets++;
	}
}

void	Penis::putBullets() {
	for (int i = 0; i < 10; i++) {
		if (this->_bullets[i])
			Window::putSprite(*this->_bullets[i]);
	}
}

int		Penis::_nbBullets = 0;