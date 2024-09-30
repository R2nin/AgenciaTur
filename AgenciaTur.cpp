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

//Funcoes de Inclusao

void incluir_guia(vector<Guia>& guias, vector<Cidade>& cidades, vector<Pais>& paises) {
    Guia guia;
    cout << "Codigo do Guia: ";
    cin >> guia.codigo_guia;

    // Verificar se o código do guia já existe
    for (const auto& g : guias) {
        if (g.codigo_guia == guia.codigo_guia) {
            cout << "Codigo de guia ja existe." << endl;
            return;
        }
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, guia.nome);
    cout << "Endereco: ";
    getline(cin, guia.endereco);
    cout << "Telefone: ";
    getline(cin, guia.telefone);
    cout << "Codigo da Cidade: ";
    cin >> guia.codigo_cidade;

    // Buscar cidade e país
    for (const auto& cidade : cidades) {
        if (cidade.codigo_cidade == guia.codigo_cidade) {
            cout << "Cidade: " << cidade.nome << ", UF: " << cidade.UF << endl;
            for (const auto& pais : paises) {
                if (pais.codigo_pais == cidade.codigo_pais) {
                    cout << "Pais: " << pais.nome << endl;
                    break;
                }
            }
            break;
        }
    }

    guias.push_back(guia);
}

void incluir_cliente(vector<Cliente>& clientes, vector<Cidade>& cidades, vector<Pais>& paises) {
    Cliente cliente;
    cout << "Codigo do Cliente: ";
    cin >> cliente.codigo_cliente;

    // Verificar se o código do cliente já existe
    for (const auto& c : clientes) {
        if (c.codigo_cliente == cliente.codigo_cliente) {
            cout << "Codigo de cliente ja existe." << endl;
            return;
        }
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, cliente.nome);
    cout << "Endereco: ";
    getline(cin, cliente.endereco);
    cout << "Codigo da Cidade: ";
    cin >> cliente.codigo_cidade;

    // Buscar cidade e país
    for (const auto& cidade : cidades) {
        if (cidade.codigo_cidade == cliente.codigo_cidade) {
            cout << "Cidade: " << cidade.nome << ", UF: " << cidade.UF << endl;
            for (const auto& pais : paises) {
                if (pais.codigo_pais == cidade.codigo_pais) {
                    cout << "Pais: " << pais.nome << endl;
                    break;
                }
            }
            break;
        }
    }

    cliente.status = false;
    clientes.push_back(cliente);
}

//Funcoes de Exclusao

void excluir_cliente(vector<Cliente>& clientes, vector<Venda>& vendas) {
    int codigo;
    cout << "Codigo do Cliente a ser excluido: ";
    cin >> codigo;

    // Verificar se o cliente possui vendas
    for (const auto& venda : vendas) {
        if (venda.codigo_cliente == codigo) {
            cout << "Cliente possui vendas cadastradas. Exclusao nao permitida." << endl;
            return;
        }
    }

    // Excluir cliente
    for (auto& cliente : clientes) {
        if (cliente.codigo_cliente == codigo) {
            cliente.status = true;
            cout << "Cliente excluido com sucesso." << endl;
            return;
        }
    }

    cout << "Cliente nao encontrado." << endl;
}

void excluir_guia(vector<Guia>& guias, vector<Pacote>& pacotes) {
    int codigo;
    cout << "Codigo do Guia a ser excluido: ";
    cin >> codigo;

    // Verificar se o guia possui pacotes
    for (const auto& pacote : pacotes) {
        if (pacote.codigo_guia == codigo) {
            cout << "Guia possui pacotes cadastrados. Exclusao nao permitida." << endl;
            return;
        }
    }

    // Excluir guia
    for (auto it = guias.begin(); it != guias.end(); ++it) {
        if (it->codigo_guia == codigo) {
            guias.erase(it);
            cout << "Guia excluido com sucesso." << endl;
            return;
        }
    }

    cout << "Guia nao encontrado." << endl;
}

//Funcoes de Inclusao de Pacotes e Vendas

