#include "game.h"
#include <iostream>
#include <ctime>
int main()
{
    srand(time(NULL));
    Game a(50);
    a.Play();
    return 0;
}