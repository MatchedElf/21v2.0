#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <string>
using namespace std;

struct card {
    char name;
    string mast;
};


class Game {
private:
    vector<card> koloda;
    vector<card> player;
    vector<card> dealer;
    int player_cash;

public:
    Game();
    Game(int cash);
    void make_cards();
    void give_card(int& sum, bool to_player);
    void Play();
    void shuffle();
    ~Game();

};
#endif 

