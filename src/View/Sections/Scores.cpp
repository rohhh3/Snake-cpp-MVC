#include "Scores.hpp"
#include "../ViewFunctions.hpp"
#include "../../keyCodes.hpp"
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
        std::string text;
        if(number_of_scores_on_current_page == 0)
        {
            printHeader();
            text = "";

            for(int i = 0; i < CONSOLE_WIDTH; i++)
                text += "-";
            text += "\n";

            text += giveSpaceToString(11);
            text += "High Scores\n";
            for(int i = 0; i < CONSOLE_WIDTH; i++)
                text += "-";
            text += '\n';

            text += giveSpaceToString(13);
            text += "No scores yet\n";
            std::cout << text;
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
                text = "";
                /* \/ \/ \/ HIGH SCORES \/\/\/ */
                for(int i = 0; i < CONSOLE_WIDTH; i++)
                    text += "-";
                text += "\n";

                text += giveSpaceToString(11);
                text += "High Scores\n";
                for(int i = 0; i < CONSOLE_WIDTH; i++)
                    text += "-";
                text += '\n';
                /* /\ /\ /\ HIGH SCORES /\ /\ /\ */

                /* \/ \/ \/ COUNT NAME'S LENGTH  \/ \/ \/ */
                uint16_t* names_lenghts = new uint16_t[scores_on_page.size()];

                for(uint16_t i = 0; i < scores_on_page.size(); i++)
                    names_lenghts[i] = scores_on_page[i].name.length();

                /* /\ /\ /\ COUNT NAME'S LENGTH  /\ /\ /\ */

                for(uint16_t i = 0; i < scores_on_page.size(); i++)
                {
                    uint16_t how_many_dots = 50 - names_lenghts[i] - 11;
                    text += giveSpaceToString(CONSOLE_WIDTH / 2 - 18);
                    text +=  scores_on_page[i].name;
                    for(int j = 0; j < how_many_dots; j++)
                        text += ".";
                    text += std::to_string(scores_on_page[i].score) + '\n';
                }
                std::cout << text;
                delete[] names_lenghts;
                setCursorPosition((CONSOLE_WIDTH / 2 ) - 4, 25);
                std::cout << "< " << current_page + 1 << "/" << total_pages + 1 << " >" << std::endl;

                user_input = getch();
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
