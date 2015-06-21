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

Penis::Penis(void) : Sprite(" //______\n   ____|_)\n_)_)", 0, 0) {

}

Penis::Penis(int x, int y) : Sprite(" //______\n   ____|_)\n_)_)", x, y) {

}

Penis::Penis(Penis & src) : Sprite(src) {
	*this = src;
}

Penis::~Penis(void) {

}

Penis &	Penis::operator=(Penis & src) {
	this->_x = src.getX();
	this->_y = src.getY();
	this->_form = src.getForm();
	return *this;
}