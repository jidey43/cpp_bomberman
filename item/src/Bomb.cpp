
#include "Bomb.hh"

Bomb::Bomb(Player *player, std::pair<int, int> pos)
{
  _floor = new Void(pos);
  _floor->initialize();
  _scale = glm::vec3(0.3, 0.3, 0.3);
  std::cout << "bomb posée en :" << std::endl;
  std::cout << this->pos.first << ";" << this->pos.second << std::endl;
  _position = glm::vec3(pos.first * 100, 0, pos.second * 100);
  this->player_id = player->getPlayerId();
  this->bomb_power = player->getBombPower();
  this->color = player->getBombColor();
  this->_smell = -10;
  time(&(this->timer));
  _what = BOMB;
}

Bomb::~Bomb()
{
}

bool		Bomb::explose()
{
  time_t	now;

  time(&now);
  if (difftime(now, (this->timer) + 3) == 0)
    return (true);
  return (false);
}

bool		Bomb::initialize()
{
  _bombModel = AssetsController::getBombModel();
  return (true);
}

void		Bomb::draw(gdl::BasicShader& shader, gdl::Clock & clock)
{
  _bombModel->draw(shader, calcTransformation(), clock.getElapsed());
  _floor->draw(shader, clock);
}

void		Bomb::update()
{
}

int		Bomb::getBombPower() const{
  return (this->bomb_power);
}
