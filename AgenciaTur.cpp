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
