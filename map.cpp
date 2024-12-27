#include "map.h"
#include <iostream>

/*
    A intenção inicial é, carregar o mapa de um arquivo XML contendo
    posições e seus respectivos items/sprites, e a partir daí, montar
    o mapa no cliente de acordo com a posição atual do jogador.
    Exemplo: O jogador está na posição: {x: 1, y: 2, z: 1, m: 4}
    Então ao entrar no jogo, o cliente busca por todos os elementos
    em um raio de 10 posições em volta dessa posição e exibe para o jogador
    um raio de 7 posições. Ao andar, ele exibe a oitava e carrega mais
    uma linha.
    Resumindo, a função dessa classe é salvar os dados das posições
    e buscar por posições especificas que vão ser carregadas na comunicação
    cliente-servidor.
    Talvez eu possa utilizar uma função especifica para inserir objetos
    ou players em posições especificas, para carrega-los na tela de outros usuários.
    Mas tenho que lembrar que vão existir situações onde eu vou carregar o mapa
    apenas localmente para o jogador (não vou atualizar para todos).
    Por exemplo em missões especificas, ai o jogador faz sozinho no mapa, sem 
    interagir com outros jogadores.

    x - posição horizontal
    y - posição vertical
    z - andar
    m - mapa
*/

bool Map::loadMap() {
    return true;
}

const std::vector<Position>& Map::getMap() const {
    return mapPositions;
}