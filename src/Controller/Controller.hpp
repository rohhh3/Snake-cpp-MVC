#pragma once
#include "../Model/ModelCore.hpp"
#include <cstdint>

namespace Controller
{
    Model::ScoreboardEntry getScoreboardEntry(uint16_t id); //indeks elementu w wektorze
    void addScoreboardEntry(std::string player_name, int32_t score);
    bool doesScoreQualify(int32_t score);
    void initGame(); //ma ladowac wyniki z pliku, ustawiac zmiennym z MODELU wartosci poczatkowe
    Model::ESection getCurrentSection();
    void setSection(Model::ESection section);
}
