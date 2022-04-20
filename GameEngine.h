/* Represents the game engine
@author Yuchen Wu
*/
#ifndef ASSIGN2_ENGINE_H
#define ASSIGN2_ENGINE_H
#include "Player.h"
#include "TileBag.h"
#include "Board.h"

class GameEngine{
    public:
    GameEngine();
    ~GameEngine();

    void addPlayer();
    void setPlayerScore(Player* player, int score);
    void setPlayerName(Player* player, std::string name);

    void replaceTile();
    void drawCard();
    void placeTile();

    void saveGame();
    void loadGame();
    private:
    Player* player1;
    Player* player2;
    TileBag* bag;
};


#endif //v