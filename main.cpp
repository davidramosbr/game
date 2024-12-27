#include <iostream>
#include "map.h"
#include "element.h"
#include "player.h"

using namespace std;

int main() {
    // Carrega o player 
    PlayerManager player;
    auto players = player.getPlayers();

    // Carrega os elementos (programação dos objetos do jogo)
    cout << "> Carregando elementos: ";
    ElementManager element;
    if (!element.loadElements()) {
        cout << "Falha ao carregar." << endl;
        return 1;
    }
    const auto& elements = element.getElements();
    uint elementsCount = 0;
    for (const auto& element : elements) { elementsCount++; }
    cout << elementsCount << " carregado(s)." << endl;

    // Carregamento do mapa
    Map map;
    if (!map.loadMap()) {
        cout << "Falha ao carregar mapa." << endl;
        return 1;
    }
    const auto& mapPositions = map.getMap();


    return 0;
}
