#include "WindowScores.hpp"
#include "../resources.hpp"
#include "../../../Controller/Controller.hpp"
#include <iostream>
#include <conio.h>
namespace View
{
    void WindowScores::updateVisibleScores()
    {
        for(uint16_t i = 0; i < number_of_scores_on_current_page_data; i++)
        {
            Model::ScoreboardEntry entry = Controller::getScoreboardEntry(current_page_data * MAX_ELEMENTS_ON_PAGE + i);
            player_name[i].setString("#" + std::to_string(current_page_data * MAX_ELEMENTS_ON_PAGE + i + 1) + ". " + entry.name);
            scores[i].setString(std::to_string(entry.score));
            scores[i].setPosition(horizontal_rect.getPosition().x + horizontal_rect.getGlobalBounds().width - scores[i].getGlobalBounds().width
                                  , player_name[i].getPosition().y);
        }
    }

    void WindowScores::updateScoresOnCurrentPageData()
    {
        if(Controller::getScoreboardSize() == 0)
            number_of_scores_on_current_page_data = 0;
        else
        {
            number_of_scores_on_current_page_data = (current_page_data == total_pages_data)
                ? ((int16_t)(Controller::getScoreboardSize() - 1) % MAX_ELEMENTS_ON_PAGE) + 1
                : MAX_ELEMENTS_ON_PAGE;
        }
    }


    WindowScores::WindowScores()
    {
        total_pages_data = (int16_t)(Controller::getScoreboardSize() - 1) / MAX_ELEMENTS_ON_PAGE;
        updateScoresOnCurrentPageData();

        high_scores_text.setFont(font_default_text);
        high_scores_text.setCharacterSize(32);
        high_scores_text.setFillColor(sf::Color::Yellow);
        high_scores_text.setString("HIGH SCORES");
        high_scores_text.setPosition((WINDOW_WIDTH - high_scores_text.getGlobalBounds().width) / 2, 155.f);

        horizontal_rect.setSize(sf::Vector2f(WINDOW_WIDTH * 0.8, 2.f));
        horizontal_rect.setPosition((WINDOW_WIDTH - horizontal_rect.getGlobalBounds().width) / 2, high_scores_text.getPosition().y + 50);
        //horizontal_rect.setFillColor(sf::Color::White);

        if(number_of_scores_on_current_page_data == 0)
        {
            no_scores_text.setFont(font_default_text);
            no_scores_text.setCharacterSize(28);
            //no_scores_text.setFillColor(sf::Color::White);
            no_scores_text.setString("No scores yet");
            no_scores_text.setPosition((WINDOW_WIDTH - no_scores_text.getGlobalBounds().width) / 2, horizontal_rect.getPosition().y + 20);
        }

        else
        {
            scores_on_page_data.reserve(MAX_ELEMENTS_ON_PAGE);
            vertical_rect.setSize(sf::Vector2f(2.f, WINDOW_HEIGHT * 0.6));
            vertical_rect.setPosition(horizontal_rect.getPosition().x + horizontal_rect.getGlobalBounds().width * 0.5
                                      , horizontal_rect.getPosition().y + horizontal_rect.getGlobalBounds().height);

            for(int i = 0; i < number_of_scores_on_current_page_data; i++)
            {
                player_name[i].setFont(font_default_text);
                player_name[i].setCharacterSize(28);
                //player_name[i].setFillColor(sf::Color::White);
                player_name[i].setPosition(horizontal_rect.getPosition().x
                                           , horizontal_rect.getPosition().y + 10 + horizontal_rect.getGlobalBounds().height + (i * 47));
                scores[i].setFont(font_default_text);
                scores[i].setCharacterSize(28);
                //scores[i].setFillColor(sf::Color::White);
                scores[i].setPosition(scores[i].getPosition().x, player_name[i].getPosition().y);
            }

            go_left_button.setSize(sf::Vector2f(50.f, 50.f));
            go_left_button.setFillColor(sf::Color::Black);
            go_left_button.setPosition(horizontal_rect.getPosition().x + horizontal_rect.getGlobalBounds().width / 2 * 0.8
                                       , vertical_rect.getPosition().y + vertical_rect.getGlobalBounds().height);

            go_right_button.setSize(sf::Vector2f(50.f, 50.f));
            go_right_button.setFillColor(sf::Color::Black);
            go_right_button.setPosition(horizontal_rect.getPosition().x + horizontal_rect.getGlobalBounds().width / 2 * 1.08
                                        , vertical_rect.getPosition().y + vertical_rect.getGlobalBounds().height);

            sign_left.setFont(font_default_text);
            sign_left.setCharacterSize(48);
            sign_left.setString("<");
            sign_left.setPosition(go_left_button.getPosition().x, go_left_button.getPosition().y);

            sign_right.setFont(font_default_text);
            sign_right.setCharacterSize(48);
            sign_right.setString(">");
            sign_right.setPosition(go_right_button.getPosition().x, go_right_button.getPosition().y);

            page_info.setFont(font_default_text);
            page_info.setCharacterSize(24);
            page_info.setString("1/10");
            page_info.setPosition(go_left_button.getPosition().x + go_left_button.getGlobalBounds().width
                                  , go_left_button.getPosition().y + go_left_button.getGlobalBounds().height / 4);
        }
        updateVisibleScores();

    }

    WindowScores::~WindowScores(){ }

    ESection WindowScores::execute()
    {
        while(window.isOpen())
        {
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                else if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                        if(back_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                            return MAIN_MENU;
                        else if(go_left_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            getch();
                        }
                        else if(go_right_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            getch();
                        }
                }
            }

            window.clear(sf::Color::Black);

            window.draw(title_window);
            window.draw(high_scores_text);
            window.draw(horizontal_rect);
            window.draw(back_button);
            window.draw(back_text);

            window.draw(no_scores_text);

            window.draw(vertical_rect);

            for(int i = 0; i < number_of_scores_on_current_page_data; i++)
            {
                window.draw(player_name[i]);
                window.draw(scores[i]);
            }
            window.draw(go_left_button);
            window.draw(go_right_button);
            window.draw(sign_left);
            window.draw(sign_right);
            window.draw(page_info);

            window.display();
        }
    }
}
