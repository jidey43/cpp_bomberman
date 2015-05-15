//
// Bomb.hh for bomberman in /home/verove_j/rendu/cpp_bomberman/core/includes
// 
// Made by Jordan Verove
// Login   <verove_j@epitech.net>
// 
// Started on  Tue May 12 13:15:43 2015 Jordan Verove
// Last update Fri May 15 11:15:34 2015 Jordan Verove
//

#ifndef BOMB_HH_
# define BOMB_HH_

#include <time.h>

#include "AObject.hh"
#include "Player.hh"

class Bomb :	public AObject
{
private:
  int			player_id;
  int			pos_x;
  int			pos_y;
  int			bomb_power;
  t_color		color;
  time_t		timer;

public:
  Bomb(Player * const player);
  ~Bomb();
};

#endif /* !BOMB_HH */