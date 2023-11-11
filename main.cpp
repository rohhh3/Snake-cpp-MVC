#include "src/View/ConsoleInit.hpp"
#include "src/Controller/Controller.hpp"
#include "src/View/Sections/Gameplay.hpp"
#include "src/View/Sections/Help.hpp"
#include "src/View/Sections/MainMenu.hpp"
#include "src/View/Sections/NewGame.hpp"
#include "src/View/Sections/Scores.hpp"
#include "src/Model/ModelCore.hpp"
#include <iostream>

int main()
{
    Controller::initGame();
    View::console_init();

    View::ESection current_section = View::MAIN_MENU; //inicjalizacja koncepcji sekcji

    while(current_section != View::EXIT)
    {
        switch(current_section)
        {
            case View::MAIN_MENU: { current_section = View::executeMainMenu(); break; }
            case View::NEW_GAME:  { current_section = View::executeNewGame();  break; }
            case View::GAMEPLAY:  { current_section = View::executeGameplay(); break; }
            case View::SCORES:    { current_section = View::executeScores();   break; }
            case View::HELP:      { current_section = View::executeHelp();     break; }
            default: break;
        }
    }

/*
    Controller::addScoreboardEntry("Alice", 100);
    Controller::addScoreboardEntry("Bob", 80);
    Controller::addScoreboardEntry("Charlie", 120);
    Controller::addScoreboardEntry("David", 90);
    Controller::addScoreboardEntry("Eve", 110);

    // Display the sorted scoreboard
    std::cout << "Sorted Scoreboard:\n";
    for(const Model::ScoreboardEntry& entry : Model::scoreboard)
        std::cout << entry.name << ": " << entry.score << std::endl;


    Model::ScoreboardEntry entry = Controller::getScoreboardEntry(2);
    std::cout << entry.name << entry.score;
*/

    return 0;
}

