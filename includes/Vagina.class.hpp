// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vagina.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/21 19:21:08 by yfuks             #+#    #+#             //
//   Updated: 2015/06/21 19:21:08 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VAGINA_CLASS_HPP
# define VAGINA_CLASS_HPP

#include "Sprite.class.hpp"
#include <stdlib.h>

class Vagina : public Sprite {

public:
	Vagina(void);
	Vagina(int x, int y);
	Vagina(Vagina & src);
	~Vagina(void);

	Vagina & operator=(Vagina & src);

	void	move(void);
	void 	reset(void);

private:
	clock_t _clock;
};

#endif
