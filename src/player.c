#include "../include/rogue.h"

Entity* createPlayer(Position start_pos) {
    Entity* newPlayer = calloc(1, sizeof(Entity));
    newPlayer->pos.y = start_pos.y;
    newPlayer->pos.x = start_pos.x;
    newPlayer->ch = '@';
    return newPlayer;
}

void handleInput(int input) {
    Position newPos = { player->pos.y, player->pos.x };
    switch(input) {
    case 'w':
        newPos.y--;
        break;
    case 's':
        newPos.y++;
        break;
    case 'a':
        newPos.x--;
        break;
    case 'd':
        newPos.x++;
        break;
    default:
        break;
    }
    movePlayer(newPos);
}

void movePlayer(Position newPos) {
    // Check if the new position is within map bounds
    if (newPos.y >= 0 && newPos.y < MAP_HEIGHT && 
        newPos.x >= 0 && newPos.x < MAP_WIDTH && 
        map[newPos.y][newPos.x].walkable) {
        player->pos.y = newPos.y;
        player->pos.x = newPos.x;
    }
}
