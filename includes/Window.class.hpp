// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 15:40:55 by yfuks             #+#    #+#             //
//   Updated: 2015/06/20 15:40:56 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

#include "Sprite.class.hpp"
#include "Bullet.class.hpp"
#include "Vagina.class.hpp"
#include "Penis.class.hpp"
#include <time.h>

class Window {

public:
	Window(void);
	Window(Window & src);
	~Window();

	Window & operator=(Window & rhs);

	int	getX(void);
	int	getY(void);

	void	refreshSize(void);
	void	Clear(void);
	void	Refresh(void);
	void	putSprite(Sprite & s);
	static void	putSprite(Bullet & bullet, Vagina vagina[20]);
	void	putSprite(Vagina & s);
	void 	putSprite(Vagina vagina[20], Penis & P);
	void 	putBackground(void);
	void 	putLife(Penis & P);

	static int _x;
	static int _y;

private:
	std::string _backgroundTop;
	std::string _backgroundBot;
	static int 	_pos;
	clock_t 	_clock;
};

#endif