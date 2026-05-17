# Sistema de Matchmaking para Jogos Online

## Descrição do Projeto
Este projeto implementa um sistema simples de **matchmaking** responsável por armazenar jogadores em uma fila de espera e formar grupos com níveis de habilidade (score) semelhantes para partidas online. A solução utiliza técnicas de ordenação para facilitar a busca por grupos válidos. Foram implementados manualmente os algoritmos de ordenação **Insertion Sort** e **Merge Sort**, sem o uso de estruturas da STL do C++ ou funções prontas de ordenação.

## Instruções de Compilação
Para compilar o código, certifique-se de que possui o compilador `g++` instalado no seu ambiente. Com todos os arquivos fonte localizados no mesmo diretório, abra o terminal e execute o seguinte comando:

```bash
g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking

```

Este comando gerará um executável chamado `matchmaking` na pasta atual.

## Instruções de Execução

Após a compilação ser concluída com sucesso, você pode executar o programa digitando o seguinte comando no terminal:

**No Linux/macOS:**

```bash
./matchmaking

```

**No Windows (PowerShell/CMD):**

```cmd
.\matchmaking.exe

```

## Organização dos Arquivos

O projeto foi modularizado utilizando classes e possui a seguinte estrutura mínima:

* **`main.cpp`**: Arquivo principal contendo testes para todas as funções implementadas.
* **`Matchmaking.hpp`**: Declaração da classe `Matchmaking`, que gerencia a fila e as regras de formação de grupo.
* **`Matchmaking.cpp`**: Implementação da classe `Matchmaking`.
* **`Player.hpp`**: Declaração da classe `Player`, que representa o jogador aguardando partida.
* **`Player.cpp`**: Implementação da classe `Player`.

## Execução dos Testes (`main.cpp`)

Os testes do sistema estão automatizados e embutidos diretamente no arquivo `main.cpp`. Para testar o sistema, basta compilar e executar o programa conforme as instruções acima. A execução irá percorrer e exibir sequencialmente no terminal os resultados dos seguintes casos de teste:

* Funcionamento do sistema em estado vazio (nenhum players na fila);
* Inserção de jogadores na fila;
* Remoção de jogadores pelo ID;
* Ordenação utilizando o algoritmo insertion sort (incluindo critérios de desempate pelo timestamp);
* Ordenação utilizando o algoritmo merge sort (incluindo critérios de desempate pelo timestamp);
* Tentativas de formação de grupo (bem e mal sucedidas) com base em um limite de diferença de score (`delta`);
* Capacidade do sistema em se resetar;
* Gravação de estado e exibição do estado atual do sistema.