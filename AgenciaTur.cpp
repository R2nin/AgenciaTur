//Estruturas
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Pais {
    int codigo_pais;
    string nome;
};

struct Cidade {
    int codigo_cidade;
    string nome;
    string UF;
    int codigo_pais;
};

struct Guia {
    int codigo_guia;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
};

struct Cliente {
    int codigo_cliente;
    string nome;
    string endereco;
    int codigo_cidade;
    bool status; // 0 para ativo, 1 para excluído
};

struct Pacote {
    int codigo_pacote;
    string descricao;
    int codigo_guia;
    double valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct Venda {
    int codigo_venda;
    int codigo_cliente;
    int codigo_pacote;
    int quantidade_pessoas;
    double valor_total;
};

struct IndicePacote {
    int codigo_pacote;
    int ender;
};

struct IndiceGuia {
    int codigo_guia;
    int ender;
};

struct IndiceVenda {
    int codigo_venda;
    int ender;
};

struct IndiceCliente {
    int codigo_cliente;
    int ender;
};

//Funcoes de Leitura

void leitura_paises(vector<Pais>& paises) {
    Pais pais1 = {1, "Brasil"};
    Pais pais2 = {2, "Estados Unidos"};
    Pais pais3 = {3, "Franca"};
    Pais pais4 = {4, "Japao"};
    Pais pais5 = {5, "Alemanha"};
    paises.push_back(pais1);
    paises.push_back(pais2);
    paises.push_back(pais3);
    paises.push_back(pais4);
    paises.push_back(pais5);
}

void leitura_cidades(vector<Cidade>& cidades) {
    Cidade cidade1 = {1, "Sao Paulo", "SP", 1};
    Cidade cidade2 = {2, "New York", "NY", 2};
    Cidade cidade3 = {3, "Paris", "IDF", 3};
    Cidade cidade4 = {4, "Tokyo", "TYO", 4};
    Cidade cidade5 = {5, "Berlin", "BER", 5};
    cidades.push_back(cidade1);
    cidades.push_back(cidade2);
    cidades.push_back(cidade3);
    cidades.push_back(cidade4);
    cidades.push_back(cidade5);
}
