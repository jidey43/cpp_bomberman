#ifndef BOMB_HH_
# define BOMB_HH_

#include <time.h>
#include <unistd.h>
# include <iostream>

#include "AObject.hh"
#include "Player.hh"
#include "Void.hh"

class Player;

// typedef enum e_color 
//   {
//     ORANGE,
//     BLUE
//   }	     t_color ;

class Bomb :	public AObject
{
private:
  int			player_id;
  std::pair<int, int>	pos;
  int			bomb_power;
  int			color;
  time_t		timer;

private:
  gdl::Model		*_bombModel;
  Void			*_floor;

public:
  Bomb(Player  *player, std::pair<int, int> pos);
  ~Bomb();

  bool			explose();
public:
  int			getBombPower() const;
  bool			initialize();
  void			update();
  void			draw(gdl::BasicShader&, gdl::Clock &);
};

#endif /* !BOMB_HH */
