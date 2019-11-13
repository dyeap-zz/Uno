//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H
#include <string>
#include "Card.h"
#include "Move.h"
#include "Deck.h"
#include <vector>
class Player{
public:
    Player(const std::string& name);
    void addCardToHand(Card card);
    std::string getName() const;
    std::vector<Card> getHand() const;
    void setMove(Move move);
    Move getMove()const;
    Card getCardPlayed() const;
    bool unoCalled()const;
    void processMoveString();
    std::string getAction()const;
    void drawInitialCard(Deck& deck);
    void processPlayMove();
    int getNumCardsDrawnOnThisTurn()const;
    Card getLastCardDrawn()const;
    bool drawCard(Deck& deck,const int& drawLimit);
    void TurnEnding();
    bool getEndTurn()const;
    std::vector<std::string> getVectorMove()const;
    //void setName(const std::string& name);
private:
    std::string name;
    std::vector<Card> hand;
    Move move;
    std::vector<std::string> vectorMove;
    // used for card played
    Card cardPlayed;
    bool uno = 0;
    // used for reneging
    int numCardsDrawnOnThisTurn = 0;
    bool endTurn = 0;
};
#endif //UNO_PLAYER_H
