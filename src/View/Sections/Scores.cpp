#include "Scores.hpp"
#include "../ViewFunctions.hpp"
#include "../Section.hpp"
#include "../../Model/ModelCore.hpp"
#include <iostream>
#include <conio.h>

namespace View
{
    Scores::Scores()
    {
        current_page = 0;
        total_pages  = (int16_t)(Controller::getScoreboardSize() - 1) / MAX_ELEMENTS_ON_PAGE;
        scores_on_page.reserve(MAX_ELEMENTS_ON_PAGE);
        updateScoresOnCurrentPage();
    }

    Scores::~Scores(){ }

    void Scores::updatePage()
    {
        updateScoresOnCurrentPage();
        updateVisibleScores();
    }

    void Scores::updateScoresOnCurrentPage()
    {
        if(Controller::getScoreboardSize() == 0)
            scores_on_current_page = 0;
        else
        {
            scores_on_current_page = (current_page == total_pages)
                ? ((int16_t)(Controller::getScoreboardSize() - 1) % MAX_ELEMENTS_ON_PAGE) + 1
                : MAX_ELEMENTS_ON_PAGE;
        }
    }

    void Scores::updateVisibleScores()
    {
        scores_on_page.clear();
        for(uint16_t i = 0; i < scores_on_current_page; i++)
            scores_on_page.push_back(Controller::getScoreboardEntry((current_page * MAX_ELEMENTS_ON_PAGE) + i));
    }

    ESection Scores::execute()
    {
        SetConsoleTextAttribute(handle_console, 2); // set green color
        std::cout << title;
        SetConsoleTextAttribute(handle_console, 7); // back to default color

        for(int i = 0; i < CONSOLE_WIDTH; i++)
            std::cout << "-";
        std::cout << std::endl;

        printSpace(11);
        std::cout << "High Scores" << std::endl;
        for(int i = 0; i < CONSOLE_WIDTH; i++)
            std::cout << "-";
        std::cout << std::endl;

        if(scores_on_current_page == 0)
        {
            printSpace(13);
            std::cout << "No scores yet" << std::endl;

            char userInput = 0;
            while(userInput != '\b')
                userInput = _getch();

            system("cls");
            return MAIN_MENU;
        }

        else
        {
            updateVisibleScores();

            for(auto& i : scores_on_page)
                std::cout << i.name << " " << i.score << std::endl;

            printSpace(3);
            std::cout << current_page + 1 << "/" << total_pages + 1 << std::endl;

            char userInput = 0;
            while(userInput != '\b')
                userInput = _getch();

            system("cls");
            return MAIN_MENU;
        }
    }
}
