#include "Gameplay.hpp"
#include "../../Controller/Controller.hpp"
#include "../../keyCodes.hpp"
#include "../ViewFunctions.hpp"
#include <iostream>
#include <conio.h>

namespace View
{
    Gameplay::Gameplay()
    {
        Controller::resetGameplay();
        board_height = Controller::getBoardHeight();
        board_width  = Controller::getBoardWidth();
        Controller::playGameplaySong();
    }

    Gameplay::~Gameplay(){ }

    void Gameplay::print_board()
    {
        snake_body = Controller::getSnake();
        system("cls");
        printHeader();
        board_string = "";
        fruit_position = Controller::getFruitPosition();
        int leftPadding = (CONSOLE_WIDTH - Controller::getBoardWidth()) / 2;
        for(int y = 0; y < board_height; ++y)
        {
            board_string += std::string(leftPadding, ' ');

            for(int x = 0; x < board_width; x++)
            {
                Position current_position = { x, y };
                if(snake_body.count(current_position))
                    board_string += static_cast<char>(219);

                else if(current_position == fruit_position)
                    board_string += static_cast<char>(4);

                else
                    board_string += ".";
            }
            board_string += "\n";
        }
        board_string += "\n";
        std::cout << board_string;
        centerX(7);
        std::cout << "Score: " << Controller::getScore() << std::endl;

        #ifndef NDEBUG
            std::cout << "tailpos: "<< static_cast<uint16_t>(Model::Game::Snake::tail_position.first)
            << ", " << static_cast<uint16_t>(Model::Game::Snake::tail_position.second);
            switch(Model::Game::Snake::head_direction)
            {
                case UP:
                    std::cout << " head_dir: UP" << std::endl;
                    break;
                case RIGHT:
                    std::cout << " head_dir: RIGHT" << std::endl;
                    break;
                case DOWN:
                    std::cout << " head_dir: DOWN" << std::endl;
                    break;
                case LEFT:
                    std::cout << " head_dir: LEFT" << std::endl;
                    break;
            }
            std::cout << "headpos: "<< static_cast<uint16_t>(Model::Game::Snake::head_position.first) << ", "
            << static_cast<uint16_t>(Model::Game::Snake::head_position.second) << std::endl;
        #endif

    }

    ESection Gameplay::execute()
    {
        while(true)
        {
            print_board();

            uint16_t sleep_duration = std::max(35, 200 - 2 * Controller::getScore());
            Sleep(sleep_duration);

            Controller::handleUserInput();
            if(!Controller::moveSnake())
                break;
        }
        centerX(10);
        std::cout << "GAME OVER!" << std::endl;

        Controller::playGameOverSong();

        bool is_selected = true;
        if(Controller::doesScoreQualify(Controller::getScore()))
        {
            std::string menu_items[] = {"Yes", "No"};
            uint8_t     option_index = 0;
            std::string player_name;

            centerX(16);
            std::cout << "Save this score?" << std::endl;

            while(is_selected)
            {
                for(uint8_t i = 0; i < 2; ++i)
                {
                    int padding = (CONSOLE_WIDTH - menu_items[i].length() - 4) / 2;
                    if(i == option_index)
                    {
                        setConsoleColor(4); // set red color
                        std::cout << std::string(padding, ' ') <<  "> " << menu_items[i] << std::endl;
                        resetConsoleColor();
                    }

                    else
                        std::cout << std::string(padding, ' ') << "  " << menu_items[i] << std::endl;
                }

                char key = getch();
                switch(key)
                {
                    case KEY_UP:
                        option_index = (option_index - 1 + 2) % 2;
                        break;
                    case KEY_DOWN:
                        option_index = (option_index + 1) % 2;
                        break;
                    case KEY_ENTER:
                        if(option_index == 0) // "Yes" selected
                        {
                            centerX(12);
                            std::cout << "Your name: ";
                            std::cin >> player_name;
                            centerX(21);
                            std::cout << player_name <<" score has been saved!" << std::endl;
                            Controller::addScoreboardEntry(player_name, Controller::getScore());
                            Controller::saveScoreboard();
                            player_name = "";
                            getch();
                        }
                        else
                        {
                            centerX(24);
                            std::cout << "Score has not been saved." << std::endl;
                            getch();
                        }

                        system("cls");
                        print_board();
                        centerX(30);
                        std::cout << "Press ENTER to resume the game" << std::endl;
                        centerX(34);
                        std::cout << "Press BACKSPACE to go back to menu";
                        key = getch();
                        switch(key)
                        {
                            case KEY_ENTER:
                                system("cls");
                                return GAMEPLAY;
                            case KEY_BACKSPACE:
                                system("cls");
                                return MAIN_MENU;
                        }

                        is_selected = false;
                        break;
                }
                system("cls");
                print_board();
                centerX(10);
                std::cout << "GAME OVER!" << std::endl;
                centerX(16);
                std::cout << "Save this score?" << std::endl;
            }
        }
        else
        {
            while(is_selected)
            {
                centerX(30);
                std::cout << "Your score does not qualify..." << std::endl << std::endl;
                getch();

                system("cls");
                print_board();

                centerX(30);
                std::cout << "Press ENTER to resume the game" << std::endl;
                centerX(34);
                std::cout << "Press BACKSPACE to go back to menu";
                char key = getch();
                switch(key)
                {
                    case KEY_ENTER:
                        system("cls");
                        return GAMEPLAY;
                    case KEY_BACKSPACE:
                        system("cls");
                        return MAIN_MENU;
                }
                is_selected = false;
            }
        }

        system("cls");
        return MAIN_MENU;
    }
}
