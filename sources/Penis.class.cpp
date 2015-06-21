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
#include <unistd.h>

Penis::Penis(void) : Sprite(" //______\n   ____|_)\n_)_)", 0, 0), _life(3), _isShoot(true) {
	for (int i = 0; i < 50; i++) {
		this->_bullets[i] = NULL;
	}
}

Penis::Penis(int x, int y) : Sprite(" //______\n   ____|_)\n_)_)", x, y), _life(3), _isShoot(true) {
	for (int i = 0; i < 50; i++) {
		this->_bullets[i] = NULL;
	}
}

Penis::Penis(Penis & src) : Sprite(src) {
	*this = src;
}

Penis::~Penis(void) {
	for (int i = 0; i < 50; i++) {
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
	if (Penis::_isId >= 0) {
		if (this->_bullets[Penis::_isId]) {
			this->_bullets[Penis::_isId] = NULL;
			Penis::_isId = -1;
			this->_nbBullets--;
		}
	}
	if (this->_nbBullets < 50 && this->_isShoot) {
		for (int i = 0; i < 50; i++) {
			if (this->_bullets[i] == NULL) {
				this->_bullets[i] = new Bullet("~o", this->getX() + 10, this->getY() + 1, i);
				this->_nbBullets++;
				return;
			}
		}
	}
}

void	Penis::putBullets() {
	for (int i = 0; i < 50; i++) {
		if (this->_bullets[i])
			Window::putSprite(*this->_bullets[i]);
	}
}

int 	Penis::getLife(void) {
	return this->_life;
}

void 	Penis::minuslife(void) {
	this->_life -= 1;
}

int		Penis::_nbBullets = 0;
int		Penis::_isId = -1;