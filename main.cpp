#include "src/View/ConsoleInit.hpp"
#include "src/Controller/Controller.hpp"
#include "src/View/Sections/Gameplay.hpp"
#include "src/View/Sections/Help.hpp"
#include "src/View/Sections/MainMenu.hpp"
#include "src/View/Sections/NewGame.hpp"
#include "src/View/Sections/Scores.hpp"
#include "src/Model/ModelCore.hpp"
#include "src/View/Section.hpp"
#include <iostream>
#include <windows.h>

int main()
{

    Controller::initGame();
    View::consoleInit();

    View::Section* current_section_object;
    View::ESection current_section = View::MAIN_MENU;

    while(current_section)
    {
        switch(current_section)
        {
            case View::MAIN_MENU: { current_section_object = new View::MainMenu; break; }
            case View::GAMEPLAY:  { current_section_object = new View::Gameplay; break; }
            case View::SCORES:    { current_section_object = new View::Scores;   break; }
            case View::HELP:      { current_section_object = new View::Help;     break; }
            default: break;
        }
        current_section = current_section_object->execute();
        delete current_section_object;
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

