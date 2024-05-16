#include <iostream>
#include <string>
using namespace std;

// Sistema de Gerenciamento de Tarefas
// 1. Adicionar Tarefa
// 2. Visualizar Tarefas
// 3. Editar Tarefa
// 4. Remover Tarefa
// 5. Buscar Tarefa
// 6. Filtrar Tarefas por Status
// 0. Sair
// Escolha uma opção

int main() {
    string tarefas;
    cout << "cite uma tarefa: ";
    getline(cin, tarefas);
    cout << "organizar" << tarefas << "da loja" << endl;
