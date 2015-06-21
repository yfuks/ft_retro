// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Penis.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 18:15:10 by yfuks             #+#    #+#             //
//   Updated: 2015/06/20 18:15:10 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PENIS_CLASS_HPP
# define PENIS_CLASS_HPP

#include "Sprite.class.hpp"
#include <string>

class Penis : public Sprite {

public:
	Penis(void);
	Penis(int x, int y);
	Penis(Penis & src);
	~Penis(void);

	Penis &	operator=(Penis & src);

	void 	HandleMovement();
};

#endif