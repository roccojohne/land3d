#include "main.h"

int main()
{
    auto game = std::make_unique<C_Game>();           // create game
    game->run();                                      // run game
}