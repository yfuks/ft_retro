// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sprite.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 16:16:04 by yfuks             #+#    #+#             //
//   Updated: 2015/06/20 16:16:05 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPRITE_CLASS_HPP
# define SPRITE_CLASS_HPP

#include <iostream>
#include <string>

class Sprite {

public:
	Sprite(void);
	Sprite(std::string form, int x, int y);
	Sprite(Sprite & src);
	~Sprite(void);

	Sprite &	operator=(Sprite & src);

	int 			getX(void);
	int				getY(void);
	void			setX(int x);
	std::string 	getForm(void);
	void			moveTo(int x, int y);
	bool 			isTouching(int x, int y);
	void 			moveUp(void);
	void 			moveDown(void);
	void 			moveRight(void);
	void 			moveLeft(void);

protected:
	std::string	_form;
	int			_x;
	int 		_y;
	int 		_speed;
};

#endif