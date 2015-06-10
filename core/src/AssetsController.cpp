
#include "AssetsController.hh"

AssetsController* AssetsController::AssetsControllerInstance = NULL;

AssetsController::AssetsController()
{
  _bombModel = new gdl::Model();
  _playerModel = new gdl::Model();
  _wallTexture = new gdl::Texture();
  _voidTexture = new gdl::Texture();
  _fireTexture = new gdl::Texture();
  _gameOverTexture = new gdl::Texture();
  _bonusTexture = new gdl::Texture();
  _playerIndicatorOne = new gdl::Texture();
  _playerIndicatorTwo = new gdl::Texture();
  _playerIndicatorIa = new gdl::Texture();
  assert(_bombModel->load("./assets/bomb.fbx"));
  assert(_playerModel->load("./assets/player.fbx"));
  assert(_wallTexture->load("./assets/wall.tga"));
  assert(_voidTexture->load("./assets/lava.tga"));
  assert(_fireTexture->load("./assets/fire.tga"));
  assert(_gameOverTexture->load("./assets/go.tga"));
  assert(_bonusTexture->load("./assets/bonus.tga"));
  assert(_playerIndicatorIa->load("./assets/pia.tga"));
  assert(_playerIndicatorOne->load("./assets/p1.tga"));
  assert(_playerIndicatorTwo->load("./assets/p2.tga"));
}

AssetsController::~AssetsController()
{
  
}

gdl::Texture*				AssetsController::getFireTexture()
{
  return (AssetsControllerInstance->_fireTexture);
}

gdl::Texture*				AssetsController::getPlayerIndicatorTexture(int who)
{
  switch (who)
    {
    case 0 :
      return (AssetsControllerInstance->_playerIndicatorIa);
    case 1 :
      return (AssetsControllerInstance->_playerIndicatorOne);
    case 2 :
      return (AssetsControllerInstance->_playerIndicatorTwo);
    default :
      return (NULL);
    }
}

gdl::Texture*				AssetsController::getBonusTexture()
{
  return (AssetsControllerInstance->_bonusTexture);
}

gdl::Texture*				AssetsController::getVoidTexture()
{
  return (AssetsControllerInstance->_voidTexture);
}

gdl::Texture*				AssetsController::getWallTexture()
{
  return (AssetsControllerInstance->_wallTexture);
}

gdl::Texture*				AssetsController::getGameOverTexture()
{
  return (AssetsControllerInstance->_gameOverTexture);
}

gdl::Model*				AssetsController::getBombModel()
{
  return (AssetsControllerInstance->_bombModel);
}

gdl::Model*				AssetsController::getPlayerModel()
{
  return (AssetsControllerInstance->_playerModel);
}

void					AssetsController::initAssetsController()
{
  if (AssetsControllerInstance == NULL)
    AssetsControllerInstance = new AssetsController();
}

void					AssetsController::destroyAssetsController()
{
  if (AssetsControllerInstance != NULL)
    delete AssetsControllerInstance;
}
