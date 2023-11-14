#include "Scores.hpp"
#include "../ViewFunctions.hpp"
#include "../Section.hpp"
#include "../../Model/ModelCore.hpp"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77


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
            number_of_scores_on_current_page = 0;
        else
        {
            number_of_scores_on_current_page = (current_page == total_pages)
                ? ((int16_t)(Controller::getScoreboardSize() - 1) % MAX_ELEMENTS_ON_PAGE) + 1
                : MAX_ELEMENTS_ON_PAGE;
        }
    }

    void Scores::updateVisibleScores()
    {
        scores_on_page.clear();
        for(uint16_t i = 0; i < number_of_scores_on_current_page; i++)
            scores_on_page.push_back(Controller::getScoreboardEntry((current_page * MAX_ELEMENTS_ON_PAGE) + i));
    }

    ESection Scores::execute()
    {
        char user_input = 0;

        if(number_of_scores_on_current_page == 0)
        {
            printHeader();

            for(int i = 0; i < CONSOLE_WIDTH; i++)
                std::cout << "-";
            std::cout << std::endl;

            centerStringX(11);
            std::cout << "High Scores" << std::endl;
            for(int i = 0; i < CONSOLE_WIDTH; i++)
                std::cout << "-";
            std::cout << std::endl;

            centerStringX(13);
            std::cout << "No scores yet" << std::endl;

            user_input = 0;
            while(user_input != '\b')
                user_input = _getch();
        }

        else
        {
            bool backspace_pressed = false;
            while(!backspace_pressed)
            {
                system("cls");
                updatePage();
                printHeader();

                /* \/ \/ \/ HIGH SCORES \/\/\/ */
                for(int i = 0; i < CONSOLE_WIDTH; i++)
                    std::cout << "-";
                std::cout << std::endl;

                centerStringX(11);
                std::cout << "High Scores" << std::endl;
                for(int i = 0; i < CONSOLE_WIDTH; i++)
                    std::cout << "-";
                std::cout << std::endl;
                /* \/ \/ \/ HIGH SCORES \/\/\/ */

                /* \/ \/ \/ COUNT NAME'S LENGTH  \/ \/ \/ */
                const uint16_t scoreboard_size = scores_on_page.size();
                uint16_t*      names_lenghts    = new uint16_t[scoreboard_size];

                for(int i = 0; i < scoreboard_size; i++)
                    names_lenghts[i] = 0;

                for(int i = 0; i < scoreboard_size; i++)
                {
                    const Model::ScoreboardEntry& entry = scores_on_page[i];
                    names_lenghts[i] += entry.name.length();
                }

                /* \/\ /\ /\ COUNT NAME'S LENGTH  /\ /\ /\ */

                /* PRINT SCORES */
                uint16_t itr = 0;
                for(auto& i : scores_on_page)
                {
                    uint16_t how_many_dots = 50 - names_lenghts[itr] - 11;
                    itr++;
                    centerStringX(CONSOLE_WIDTH / 2 - 18);
                    std::cout <<  i.name;
                    for(int j = 0; j < how_many_dots; j++)
                        std::cout << ".";
                     std::cout<<i.score << std::endl;
                }
                    //std::cout << std::left << std::setw(30) <<  i.name <<  std::setw(30) <<   i.score << std::endl;
                delete[] names_lenghts;

                setCursorPosition((CONSOLE_WIDTH / 2 ) - 4, 25);
                std::cout << "< " << current_page + 1 << "/" << total_pages + 1 << " >" << std::endl;

                user_input = _getch();
                if(user_input != '\b')
                {
                    switch(user_input)
                    {
                        case KEY_RIGHT:
                        {
                            current_page += 1;
                            if(current_page > total_pages)
                                current_page = 0;
                            break;
                        }

                        case KEY_LEFT:
                        {
                            current_page -= 1;
                            if(current_page < 0)
                                current_page = total_pages;
                            break;
                        }
                    }
                }
                else
                    backspace_pressed = true;
            }
        }

        system("cls");
        return MAIN_MENU;
    }
}
