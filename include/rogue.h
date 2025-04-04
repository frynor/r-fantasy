#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct {
	int y;
	int x;
} Position;

typedef struct {
	char ch;
	bool walkable;
} Tile;


typedef struct {
	Position pos;
	char ch;
} Entity;

// draw.c functions
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

Entity* createPlayer(Position start_pos);
void handleInput(int input);
void cursesSetup(void);
void gameLoop(void);
void closeGame(void);
Tile** createMapTiles(void);
Position setupMap(void);
void freeMap(void);
void movePlayer(Position newPos);

extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity* player;
extern Tile** map;

#endif
