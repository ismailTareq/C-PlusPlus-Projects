#ifndef _TIC_TAC_TOE_H_
#define _TIC_TAC_TOE_H_
#include <iostream>
#include <ctime>




void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);


#endif/*_TIC_TAC_TOE_H_*/
