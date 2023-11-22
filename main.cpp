#include "src/View/ConsoleInit.hpp"
#include "src/View/Sections/Gameplay.hpp"
#include "src/View/Sections/Help.hpp"
#include "src/View/Sections/MainMenu.hpp"
#include "src/View/Sections/NewGame.hpp"
#include "src/View/Sections/Scores.hpp"

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

    return 0;
}

