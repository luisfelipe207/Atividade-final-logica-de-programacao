#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


int main() {

 // Sistema de Gerenciamento de Tarefas
cout << 1. Adicionar Tarefa
cout << 2. Visualizar Tarefas
cout << 3. Editar Tarefa
cout << 4. Remover Tarefa
cout << 5. Buscar Tarefa
cout << 6. Filtrar Tarefas por Status
cout << 0. Sair
cout << Escolha uma opção

class Tarefa {
public:
    int id;
    string titulo;
    string descricao;
    bool concluida;

    Tarefa(int id, const string& titulo, const string& descricao)
        : id(id), titulo(titulo), descricao(descricao), concluida(false) {}
};

class GerenciadorDeTarefas {
private:
    vector<Tarefa> tarefas;
    int proximoId;

public:
    GerenciadorDeTarefas() : proximoId(1) {}

    void adicionarTarefa(const string& titulo, const string& descricao) {
        tarefas.push_back(Tarefa(proximoId++, titulo, descricao));
    }

    void listarTarefas() const {
        for (const auto& tarefa : tarefas) {
            cout << "ID: " << tarefa.id << "\n";
            cout << "Título: " << tarefa.titulo << "\n";
            cout << "Descrição: " << tarefa.descricao << "\n";
            cout << "Concluída: " << (tarefa.concluida ? "Sim" : "Não") << "\n";
            cout << "--------------------------\n";
        }
    }

    void marcarComoConcluida(int id) {
        for (auto& tarefa : tarefas) {
            if (tarefa.id == id) {
                tarefa.concluida = true;
                return;
            }
        }
        cout << "Tarefa com ID " << id << " não encontrada.\n";
    }

    void removerTarefa(int id) {
        for (auto it = tarefas.begin(); it != tarefas.end(); ++it) {
            if (it->id == id) {
                tarefas.erase(it);
                return;
            }
        }
        cout << "Tarefa com ID " << id << " não encontrada.\n";
    }
};

int main() {
    GerenciadorDeTarefas gerenciador;
    int escolha;
    string titulo, descricao;
    int id;

    do {
        cout << "1. Adicionar Tarefa\n";
        cout << "2. Listar Tarefas\n";
        cout << "3. Marcar Tarefa como Concluída\n";
        cout << "4. Remover Tarefa\n";
        cout << "5. Sair\n";
        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {
        case 1:
            cin.ignore();
            cout << "Título: ";
            getline(cin, titulo);
            cout << "Descrição: ";
            getline(cin, descricao);
            gerenciador.adicionarTarefa(titulo, descricao);
            break;
        case 2:
            gerenciador.listarTarefas();
            break;
        case 3:
            cout << "ID da Tarefa: ";
            cin >> id;
            gerenciador.marcarComoConcluida(id);
            break;
        case 4:
            cout << "ID da Tarefa: ";
            cin >> id;
            gerenciador.removerTarefa(id);
            break;
        case 5:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Escolha inválida!\n";
        }
    } while (escolha != 5);

    return 0;
}

 