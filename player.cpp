#include "player.h"
#include <iostream>


/*
    A intenção aqui é carregar os players em variaveis internas
    que vão trabalhar com os recursos dentro da engine, sem consumir
    o banco de dados, utilizando-o apenas para salvar e buscar as informações
    em situações especificas.

    Funções necessárias:
    LoadPlayer, vou buscar o player no banco de dados e registra-lo na variavel interna.
    SavePlayer, vou salvar as informações atuais do player no banco de dados.
    GetPlayer, vou buscar se o player ja está registrado na variavel interna.

    --------------------
    As outras situações, como os momentos onde vão ocorrer o save, ou momentos onde vou
    usar o get, vão ser definidos em suas respectivas ações, por exemplo:
    Salvar na hora que o jogador morrer, vai ser carregado na parte onde eu validar
    a morte do jogador, e não aqui.
    Salvar na hora que o jogador avançar os stats, segue o mesmo principio da morte.
*/

bool PlayerManager::loadPlayer(std::string pName) {
    /* 
        Nessa função eu vou na verdade passar um parametro que será a string
        com o pName, usando pName vou buscar no banco de dados mysql os dados desse
        jogador e inseri-los no objeto player, que vai ser indexado no vetor
        players com um id único (uso interno servidor-client).
    */
    Player player;
    const uint id = 1;
    const uint level = 2;
    const uint position = 4;
    player.id = id;
    player.name = pName;
    player.level = level;
    player.position = position;
    players.push_back(player);
    return true;
}

bool PlayerManager::savePlayer(uint playerId) {
    /*
        Nessa função usando o uniqueid gerado ao carregar o player, eu vou
        recuperar os dados do jogador do vetor `players` e salva-los na db.
    */
    return true;
}

const std::vector<Player>& PlayerManager::getPlayers() const {
    // Nessa função eu busco os dados, mas não tenho certeza se deveria ser const...
    return players;
}