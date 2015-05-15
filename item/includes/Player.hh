#ifndef PLAYER_HH_
# define PLAYER_HH_

#include "AObject.hh"

typedef enum			e_where
  {
    NORTH,
    SOUTH,
    EAST,
    WEST,
  }				t_where;

typedef enum			e_color
  {
    ORANGE,
    BLUE,
  }				t_color;

class Player :	public AObject
{
private:
  std::pair<int, int>	pos;
  int			bomb_nb;
  int			bomb_power;
  int			p_speed;
  t_color		bomb_color;
  t_where		orientation;
  int			player_id;

public:
  Player();
  ~Player();
  std::pair<int, int>			getPos() const;
  void				setPos(std::pair<int, int>);
  int				getBombNb() const;
  void				setBombNb(int nb);
  int				getBombPower() const;
  void				setBombPower(int power);
  int				getPSpeed() const;
  void				setPSpeed(int speed);
  t_where			getOrientation() const;
  void				setOrientation(t_where direction);
  int				getPlayerId() const;
  t_color			getBombColor() const;
  void				setBombColor(t_color color);
  void				putBomb();
=======
  int			getPosX() const;
  void			setPosX(int x);
  int			getPosY() const;
  void			setPosY(int y);
  int			getBombNb() const;
  void			setBombNb(int nb);
  int			getBombPower() const;
  void			setBombPower(int power);
  int			getPSpeed() const;
  void			setPSpeed(int speed);
  t_where		getOrientation() const;
  void			setOrientation(t_where direction);
  int			getPlayerId() const;
  t_color		getBombColor() const;
  void			setBombColor(t_color color);
  void			putBomb();

public:
  bool                  initalize();
  void                  update();
};

#endif /* !PLAYER_HH_ */
