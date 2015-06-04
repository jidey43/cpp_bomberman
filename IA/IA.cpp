
# include <vector>
# include "Definition.hh"
# include "Player.hh"
# include "Bomb.hh"
# include "Bonus.hh"
# include "Wall.hh"
# include "Void.hh"
# include "AObject.hh"
# include "IA.hh"

IA::IA(){

}

IA::~IA(){
}


t_input		IA::FindBonus(Map &map, Player *player){
  if (CheckBonus(map, player) != 0)
    return (Move(map, player));
  else
    return (CheckPlayer(map, player));
}

t_input		IA::doAction(Map &map, Player *player){
  std::vector<std::pair<AObject*, int> >	tab;

  tab = CreateTable(map, player);
  if (CheckBomb(map, player) != 0)
    return (CheckFreeCase(map, player));
  else
    return (FindBonus(map, player));
  std::cout << "caca" << std::endl;
  return (MOVE_RIGHT);
}

t_input       	IA::CheckFreeCase(Map &map, Player *player){
  (void) map;
  (void) player;
  return (MOVE_RIGHT);
}

int       	IA::CheckBonus(Map &map, Player *player){
  (void) map;
  (void) player;
  return (1);
}

t_input       	IA::CheckPlayer(Map &map, Player *player){
  (void) map;
  (void) player;
  /*
    if (playerProche)
       ;
    else
       return ();
   */
  return (MOVE_RIGHT);
}

t_input		IA::Move(Map &map, Player *player){
  (void) map;
  (void) player;
  return (MOVE_RIGHT);
}

std::vector<std::pair<AObject*, int> >		IA::CreateTable(Map &map, Player *player){
    std::vector<std::pair<AObject*, int> >	tab;
    std::pair<AObject*, int>			pairToAdd;
    std::pair<int, int>				posPlayer;
    std::pair<int, int>				tmp;
    AObject					*obj;

    posPlayer = player->getPos();
    tmp.first = posPlayer.first - 2;
    tmp.second = posPlayer.second - 2;
    if (posPlayer.first - 2 >= 0){
      if (posPlayer.second - 2 >= 0){
	for (unsigned int y = 0; y != 5; ++y){
	  for (unsigned int x = 0; x != 5; ++x){
	    obj = map.getItemAtPos(tmp);
	    pairToAdd.second = obj->getSmell();
	    tab.push_back(pairToAdd);
	    ++tmp.first;
	  }
	  tmp.first = posPlayer.first - 2;
	  ++tmp.second;
	}
      }
    }
    return (tab);
}

int			IA::CheckBomb(Map &map, Player *player){
  int			i = 0;

  
  if ((i = checkBottom(map, player)) == 1)
    return (1);
  if ((i = checkUp(map, player)) == 1)
    return (1);
  if ((i = checkRight(map, player)) == 1)
    return (1);
  if ((i = checkLeft(map, player)) == 1)
    return (1);
  return (0);
}