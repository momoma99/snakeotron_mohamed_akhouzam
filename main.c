/*	Authors: Mohamed AKHOUZAM	
	Le snake de l'utilisateur ne peut bouger qu'avec les touche 1,2,3,4

*/

#include "clientAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include "snakeAPI.h"
#include "ret_type.h"
#include "deplace.h"


int main(int argc , char* argv[])
{

	char* serverName = "http://polydev.cia-polytech-sorbonne.fr";
	int port = strtol(argv[2], NULL, 10);
	char* name ="MohamedAKHOUZAM";

	char* gameType ="RANDOM_PLAYER difficulty=1 timeout=100 seed=123 start=0";
	char gameName[200];
	int sizeX;
	int sizeY;
	int nbWalls;

	t_move mymove;
  t_move itmove;


	connectToServer(argv[1], port,name);

	waitForSnakeGame(argv[3],gameName,&sizeX,&sizeY,&nbWalls);

	int* walls = (int*)malloc(sizeof(int));
  int player;
  int d;
  int pivot;
  t_return_code ret;
	player=getSnakeArena(walls);

  printArena();
/*deplacement si l'utilisateur doit commencer*/
  if(player==0)
  {
            mymove=deplace(d);
            ret=sendMove(mymove);
            printArena();
            pivot=!player;

  }
/* Si c'est a l'adversaire de commecner*/
  else
	{
            ret=getMove(&itmove);
            printArena();
            pivot=!player;
  }
/*Tant que les mouvements ne sont pas perdant ou gagnant*/
  while(ret==NORMAL_MOVE)
  {
    if(pivot==0)
    {

    mymove=deplace(d);
    ret=sendMove(mymove);
    printArena();
    pivot=1;
    if(ret==LOOSING_MOVE || ret==WINNING_MOVE)
    {
        closeConnection();
    }

    }
    else if(pivot==1)
    {

    ret=getMove(&itmove);
    printArena();
    pivot=0;
    if(ret==LOOSING_MOVE || ret==WINNING_MOVE)
    {
        closeConnection();
    }

  }
}

}
