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

void incluir_pacote(vector<Pacote>& pacotes, vector<Guia>& guias, vector<Cidade>& cidades, vector<Pais>& paises) {
    Pacote pacote;
    cout << "Codigo do Pacote: ";
    cin >> pacote.codigo_pacote;

    // Verificar se o código do pacote já existe
    for (const auto& p : pacotes) {
        if (p.codigo_pacote == pacote.codigo_pacote) {
            cout << "Codigo de pacote ja existe." << endl;
            return;
        }
    }

    cout << "Descricao: ";
    cin.ignore();
    getline(cin, pacote.descricao);
    cout << "Codigo do Guia: ";
    cin >> pacote.codigo_guia;

    // Buscar guia, cidade e país
    for (const auto& guia : guias) {
        if (guia.codigo_guia == pacote.codigo_guia) {
            cout << "Guia: " << guia.nome << endl;
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
            break;
        }
    }

    cout << "Valor por Pessoa: ";
    cin >> pacote.valor_por_pessoa;
    pacote.total_participantes = 0;
    cout << "Quantidade Maxima de Participantes: ";
    cin >> pacote.quant_max_participantes;

    pacotes.push_back(pacote);
}

void incluir_venda(vector<Venda>& vendas, vector<Cliente>& clientes, vector<Pacote>& pacotes) {
    Venda venda;
    cout << "Codigo da Venda: ";
    cin >> venda.codigo_venda;

    // Verificar se o código da venda já existe
    for (const auto& v : vendas) {
        if (v.codigo_venda == venda.codigo_venda) {
            cout << "Codigo de venda ja existe." << endl;
            return;
        }
    }

    cout << "Codigo do Cliente: ";
    cin >> venda.codigo_cliente;

    // Buscar cliente
    for (const auto& cliente : clientes) {
        if (cliente.codigo_cliente == venda.codigo_cliente && !cliente.status) {
            cout << "Cliente: " << cliente.nome << endl;
            for (const auto& cidade : cidades) {
                if (cidade.codigo_cidade == cliente.codigo_cidade) {
                    cout << "Cidade: " << cidade.nome << ", UF: " << cidade.UF << endl;
                    break;
                }
            }
            break;
        }
    }

    cout << "Codigo do Pacote: ";
    cin >> venda.codigo_pacote;

    // Buscar pacote
    for (auto& pacote : pacotes) {
        if (pacote.codigo_pacote == venda.codigo_pacote) {
            cout << "Pacote: " << pacote.descricao << endl;
            cout << "Guia: " << pacote.codigo_guia << endl;
            cout << "Valor por Pessoa: " << pacote.valor_por_pessoa << endl;
            cout << "Quantidade Maxima de Participantes: " << pacote.quant_max_participantes << endl;

            cout << "Quantidade de Pessoas: ";
            cin >> venda.quantidade_pessoas;

            // Verificar se a quantidade de pessoas excede o máximo permitido
            if (pacote.total_participantes + venda.quantidade_pessoas > pacote.quant_max_participantes) {
                cout << "Quantidade de pessoas excede o maximo permitido." << endl;
                return;
            }

            pacote.total_participantes += venda.quantidade_pessoas;
            venda.valor_total = venda.quantidade_pessoas * pacote.valor_por_pessoa;
            cout << "Valor Total: " << venda.valor_total << endl;

            vendas.push_back(venda);
            return;
        }
    }

    cout << "Pacote nao encontrado." << endl;
}
void incluir_pacote(vector<Pacote>& pacotes, vector<Guia>& guias, vector<Cidade>& cidades, vector<Pais>& paises) {
    Pacote pacote;
    cout << "Codigo do Pacote: ";
    cin >> pacote.codigo_pacote;

    // Verificar se o código do pacote já existe
    for (const auto& p : pacotes) {
        if (p.codigo_pacote == pacote.codigo_pacote) {
            cout << "Codigo de pacote ja existe." << endl;
            return;
        }
    }

    cout << "Descricao: ";
    cin.ignore();
    getline(cin, pacote.descricao);
    cout << "Codigo do Guia: ";
    cin >> pacote.codigo_guia;

    // Buscar guia, cidade e país
    for (const auto& guia : guias) {
        if (guia.codigo_guia == pacote.codigo_guia) {
            cout << "Guia: " << guia.nome << endl;
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
            break;
        }
    }

    cout << "Valor por Pessoa: ";
    cin >> pacote.valor_por_pessoa;
    pacote.total_participantes = 0;
    cout << "Quantidade Maxima de Participantes: ";
    cin >> pacote.quant_max_participantes;

    pacotes.push_back(pacote);
}

void incluir_venda(vector<Venda>& vendas, vector<Cliente>& clientes, vector<Pacote>& pacotes) {
    Venda venda;
    cout << "Codigo da Venda: ";
    cin >> venda.codigo_venda;

    // Verificar se o código da venda já existe
    for (const auto& v : vendas) {
        if (v.codigo_venda == venda.codigo_venda) {
            cout << "Codigo de venda ja existe." << endl;
            return;
        }
    }

    cout << "Codigo do Cliente: ";
    cin >> venda.codigo_cliente;

    // Buscar cliente
    for (const auto& cliente : clientes) {
        if (cliente.codigo_cliente == venda.codigo_cliente && !cliente.status) {
            cout << "Cliente: " << cliente.nome << endl;
            for (const auto& cidade : cidades) {
                if (cidade.codigo_cidade == cliente.codigo_cidade) {
                    cout << "Cidade: " << cidade.nome << ", UF: " << cidade.UF << endl;
                    break;
                }
            }
            break;
        }
    }

    cout << "Codigo do Pacote: ";
    cin >> venda.codigo_pacote;

    // Buscar pacote
    for (auto& pacote : pacotes) {
        if (pacote.codigo_pacote == venda.codigo_pacote) {
            cout << "Pacote: " << pacote.descricao << endl;
            cout << "Guia: " << pacote.codigo_guia << endl;
            cout << "Valor por Pessoa: " << pacote.valor_por_pessoa << endl;
            cout << "Quantidade Maxima de Participantes: " << pacote.quant_max_participantes << endl;

            cout << "Quantidade de Pessoas: ";
            cin >> venda.quantidade_pessoas;

            // Verificar se a quantidade de pessoas excede o máximo permitido
            if (pacote.total_participantes + venda.quantidade_pessoas > pacote.quant_max_participantes) {
                cout << "Quantidade de pessoas excede o maximo permitido." << endl;
                return;
            }

            pacote.total_participantes += venda.quantidade_pessoas;
            venda.valor_total = venda.quantidade_pessoas * pacote.valor_por_pessoa;
            cout << "Valor Total: " << venda.valor_total << endl;

            vendas.push_back(venda);
            return;
        }
    }

    cout << "Pacote nao encontrado." << endl;
}

// Funcoes de Consulta e Reorganizacao

void consultar_pacote(vector<Pacote>& pacotes, vector<Guia>& guias, vector<Cidade>& cidades, vector<Pais>& paises) {
    int codigo;
    cout << "Codigo do Pacote a ser consultado: ";
    cin >> codigo;

    for (const auto& pacote : pacotes) {
        if (pacote.codigo_pacote == codigo) {
            cout << "Descricao: " << pacote.descricao << endl;
            cout << "Valor por Pessoa: " << pacote.valor_por_pessoa << endl;
            cout << "Total de Participantes: " << pacote.total_participantes << endl;
            cout << "Quantidade Maxima de Participantes: " << pacote.quant_max_participantes << endl;
            cout << "Valor Total Arrecadado: " << pacote.valor_por_pessoa * pacote.total_participantes << endl;

            // Buscar guia, cidade e país
            for (const auto& guia : guias) {
                if (guia.codigo_guia == pacote.codigo_guia) {
                    cout << "Guia: " << guia.nome << endl;
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
                    break;
                }
            }

            return;
        }
    }

    cout << "Pacote nao encontrado." << endl;
}

void exibir_pacotes_completos(vector<Pacote>& pacotes, vector<Guia>& guias, vector<Cidade>& cidades, vector<Pais>& paises) {
    for (const auto& pacote : pacotes) {
        if (pacote.total_participantes == pacote.quant_max_participantes) {
            cout << "Codigo: " << pacote.codigo_pacote << endl;
            cout << "Descricao: " << pacote.descricao << endl;

            // Buscar guia, cidade e país
            for (const auto& guia : guias) {
                if (guia.codigo_guia == pacote.codigo_guia) {
                    cout << "Guia: " << guia.nome << endl;
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
                    break;
                }
            }

            cout << "Valor Total Arrecadado: " << pacote.valor_por_pessoa * pacote.total_participantes << endl;
        }
    }
}

void exibir_vendas(vector<Venda>& vendas, vector<Cliente>& clientes, vector<Pacote>& pacotes) {
    double valor_total_vendido = 0.0;

    for (const auto& venda : vendas) {
        cout << "Codigo da Venda: " << venda.codigo_venda << endl;

        // Buscar cliente
        for (const auto& cliente : clientes) {
            if (cliente.codigo_cliente == venda.codigo_cliente && !cliente.status) {
                cout << "Cliente: " << cliente.nome << endl;
                break;
            }
        }

        // Buscar pacote
        for (const auto& pacote : pacotes) {
            if (pacote.codigo_pacote == venda.codigo_pacote) {
                cout << "Pacote: " << pacote.descricao << endl;
                break;
            }
        }

        cout << "Quantidade de Pessoas: " << venda.quantidade_pessoas << endl;
        cout << "Valor Total da Venda: " << venda.valor_total << endl;
        valor_total_vendido += venda.valor_total;
    }

    cout << "Valor Total Vendido: " << valor_total_vendido << endl;
}

void reorganizar_clientes(vector<Cliente>& clientes) {
    vector<Cliente> novos_clientes;
    for (const auto& cliente : clientes) {
        if (!cliente.status) {
            novos_clientes.push_back(cliente);
        }
    }
    clientes = novos_clientes;
    cout << "Reorganizacao de clientes concluida." << endl;
}


// Funçao de Menu

void menu(vector<Pais>& paises, vector<Cidade>& cidades, vector<Guia>& guias, vector<Cliente>& clientes, vector<Pacote>& pacotes, vector<Venda>& vendas) {
    int opcao;
    do {
        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Incluir Guia" << endl;
        cout << "2. Incluir Cliente" << endl;
        cout << "3. Excluir Cliente" << endl;
        cout << "4. Excluir Guia" << endl;
        cout << "5. Incluir Pacote" << endl;
        cout << "6. Incluir Venda" << endl;
        cout << "7. Consultar Pacote" << endl;
        cout << "8. Exibir Pacotes Completos" << endl;
        cout << "9. Exibir Vendas" << endl;
        cout << "10. Reorganizar Clientes" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                incluir_guia(guias, cidades, paises);
                break;
            case 2:
                incluir_cliente(clientes, cidades, paises);
                break;
            case 3:
                excluir_cliente(clientes, vendas);
                break;
            case 4:
                excluir_guia(guias, pacotes);
                break;
            case 5:
                incluir_pacote(pacotes, guias, cidades, paises);
                break;
            case 6:
                incluir_venda(vendas, clientes, pacotes);
                break;
            case 7:
                consultar_pacote(pacotes, guias, cidades, paises);
                break;
            case 8:
                exibir_pacotes_completos(pacotes, guias, cidades, paises);
                break;
            case 9:
                exibir_vendas(vendas, clientes, pacotes);
                break;
            case 10:
                reorganizar_clientes(clientes);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 0);
}
