#ifndef GAMEENGINE

# define GAMEENGINE

# include <Game.hh>
# include <SdlContext.hh>
# include <BasicShader.hh>

# include <iostream>

# include "Param.hh"
# include "Screen.hh"
# include "AObject.hh"
# include "Wall.hh"
# include "Player.hh"
# include "Map.hh"
# include "Definition.hh"
# include "AssetsController.hh"
# include "IA.hh"

class GameEngine;

typedef void (GameEngine::*inputFuncptr)(int player, t_input input);

class						GameEngine : public gdl::Game 
{
private:
  int						_nbHuman;
  int						_nbIA;
  Screen					_screen;
  std::vector<t_event>				_events;
  std::map<t_input, inputFuncptr>		_funcptrBind;
  Map						*_map;
  IA						*_iaManager;
public:
  GameEngine(Param const &);
  ~GameEngine();
  
public:
  virtual bool					initialize();
  virtual bool					update();
  virtual void					draw();
  bool						gameOver();

public:
  void						moveCam(int, t_input);
  void						movePlayer(int, t_input);
  void						lockCam(int, t_input);
  void						placeBomb(int, t_input);
  void						updateIA();
};

# endif
