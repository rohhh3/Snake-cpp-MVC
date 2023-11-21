#pragma once
#include "../Model/ModelCore.hpp"
#include "../Model/GameCore.hpp"


namespace Controller
{
    void initGame();

    bool doesScoreQualify(int32_t score);
    void addScoreboardEntry(std::string player_name, int32_t score);
    void loadScoreboard();
    void saveScoreboard();
    Model::ScoreboardEntry getScoreboardEntry(uint16_t id);
    uint16_t getScoreboardSize();

    void resetGameplay();
    bool moveSnake();
    void addPoint();
    void handleUserInput();
    void changeDirection(EDirection direction);
    uint8_t getBoardWidth();
    uint8_t getBoardHeight();
    scoreInt getScore();
    Position getFruitPosition();
    std::map<Position, EDirection> getSnake();

    void playMenuSong();
    void playGameplaySong();
    void playGameOverSong();
}
