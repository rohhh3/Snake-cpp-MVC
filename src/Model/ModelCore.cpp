#include "ModelCore.hpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>

namespace Model
{
    std::vector<ScoreboardEntry> scoreboard;
    bool doesScoreQualify(scoreInt fresh_score)
    {
        if(
           Model::scoreboard.empty() ||
           fresh_score > Model::scoreboard.back().score ||
           Model::scoreboard.size() < Model::MAX_SCOREBOARD_SIZE
           )
            return true;
        return false;
    }

    void addScoreboardEntry(std::string player_name, scoreInt fresh_score)
    {
        if(!doesScoreQualify(fresh_score))
            return;

        // Binary insertion sort in descending order
        int16_t low             = 0;
        int16_t high            = Model::scoreboard.size() - 1;
        int16_t insert_position = -1;

        while(low <= high)
        {
            int16_t mid = (low + high) / 2;
            if(Model::scoreboard[mid].score > fresh_score)
                low = mid + 1;
            else if(Model::scoreboard[mid].score < fresh_score)
                high = mid - 1;
            else
            {
                insert_position = mid;
                break;
            }
        }

        if (insert_position == -1)
            insert_position = low; // If not found, insert after the closest lower score

        Model::scoreboard.emplace(Model::scoreboard.begin() + insert_position, player_name, fresh_score);
    }

    void loadScoreboard()
    {
        Model::scoreboard.clear();

        std::ifstream file(Model::file_path);
            if(!file.is_open())
            {
                std::cerr << "Error: Unable to open the scoreboard file." << std::endl;
                return;
            }
        std::string line;

        while(std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string name;
            int score;

            if(std::getline(iss, name, ',') && iss >> score)
                Model::scoreboard.emplace_back(name, static_cast<scoreInt>(score));
            else
                std::cerr << "Error: Invalid line format in the scoreboard file." << std::endl;
        }
        #ifndef NDEBUG
            std::cout << "File loaded: " << file_path << std::endl;
        #endif
        file.close();
    }

    void saveScoreboard()
    {
        std::ofstream file(Model::file_path);

        if(file.is_open())
        {
            for(auto& i: Model::scoreboard)
                file << i.name << "," << i.score << "\n";
            file.close();
        }
        else
            std::cerr << "Failed to open file: " << Model::file_path;
    }

    Model::ScoreboardEntry getScoreboardEntry(uint16_t id)
    {
        assert(id < Model::scoreboard.size());
        return Model::scoreboard[id];
    }

    uint16_t getScoreboardSize()
    {
        return Model::scoreboard.size();
    }

    void playMenuSong()
    {
        const std::string song_name = "Jeremy-Blake_Powerup.wav";
        const std::string result    = audio_path + song_name;
        PlaySound(result.c_str(), NULL, SND_ASYNC | SND_LOOP);
    }

    void playGameplaySong()
    {
        const std::string song_name = "Joshua-McLean-Mountain-Trials.wav";
        const std::string result    = audio_path + song_name;
        PlaySound(result.c_str(), NULL, SND_ASYNC | SND_LOOP);
    }

    void playGameOverSong()
    {
        const std::string song_name = "Game-over-mbmusic.wav";
        const std::string result    = audio_path + song_name;
        PlaySound(result.c_str(), NULL, SND_ASYNC);
    }

}
