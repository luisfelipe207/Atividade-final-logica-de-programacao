#include <iostream>
#include <string>
#include <vector> 

using namespace std;

// Estrutura para armazenar uma tarefa
struct Tarefa {
string descricao;
string data;
string status; 
};

vector<Tarefa> tarefas;

// Função para adicionar uma nova tarefa
void adicionarTarefa() {
Tarefa novaTarefa;

cout << "Descrição da tarefa: ";
getline(cin, novaTarefa.descricao);

cout << "Data limite (opcional, formato dd/mm/aaaa): ";
getline(cin, novaTarefa.data);

cout << "Status da tarefa (pendente/concluída): ";
getline(cin, novaTarefa.status);

while (novaTarefa.status != "pendente" && novaTarefa.status != "concluída") {
cout << "Status inválido. Digite 'pendente' ou 'concluída': ";
getline(cin, novaTarefa.status);
}

tarefas.push_back(novaTarefa);
cout << "Tarefa adicionada com sucesso!" << endl;
}

// Função para visualizar todas as tarefas
void visualizarTarefas() {
if (tarefas.empty()) {
cout << "Não há tarefas para mostrar." << endl;
return;
}

cout << "\nLista de Tarefas:\n";
for (int i = 0; i < tarefas.size(); i++) {
cout << i + 1 << " - " << tarefas[i].descricao;
if (!tarefas[i].data.empty()) {
cout << " (Data Limite: " << tarefas[i].data << ")";
}
cout << " (" << tarefas[i].status << ")" << endl;
}
}

// Função para editar uma tarefa
void editarTarefa() {
if (tarefas.empty()) {
cout << "Não há tarefas para editar." << endl;
return;
}

int Tarefa;
cout << "Digite o ID da tarefa a ser editada: ";
cin >> Tarefa;

if (Tarefa < 1 || Tarefa > tarefas.size()) {
cout << "ID de tarefa inválido." << endl;
return;
}

Tarefa;

cout << "Nova descrição da tarefa: ";
getline(cin, tarefas[Tarefa].descricao);

cout << "Nova data limite (opcional, formato dd/mm/aaaa): ";
getline(cin, tarefas[Tarefa].data);

cout << "Novo status da tarefa (pendente/concluída): ";
getline(cin, tarefas[Tarefa].status);

while (tarefas[Tarefa].status != "pendente" && tarefas[Tarefa].status != "concluída") {
cout << "Status inválido. Digite 'pendente' ou 'concluída': ";
getline(cin, tarefas[Tarefa].status);
}
cout << "Tarefa editada com sucesso";

// Funções para gerenciar tarefas
void adicionarTarefa();
void visualizarTarefas();
void editarTarefa();
void removerTarefa();
void buscarTarefa();
void filtrarTarefasPorStatus();
void sair();

// Array para armazenar as informações das tarefas
string tarefas[100][5]; 

int numeroTarefas = 0;

int main() {
int menu;

cout << "\nMenu Principal:" << endl;
cout << "1. Adicionar Tarefa" << endl;
cout << "2. Visualizar Tarefas" << endl;
cout << "3. Editar Tarefa" << endl;
cout << "4. Remover Tarefa" << endl;
cout << "5. Buscar Tarefa" << endl;
cout << "6. Filtrar Tarefas por Status" << endl;
cout << "0. Sair" << endl;
cout << "Digite a opção desejada: ";
cin >> menu;

switch (menu) {
case 1:
adicionarTarefa();
break;
case 2:
visualizarTarefas();
break;
case 3:
editarTarefa();
break;
case 4:
removerTarefa();
break;
case 5:
buscarTarefa();
break;
case 6:
filtrarTarefasPorStatus();
break;
case 0:
sair();
break;
default:
cout << "Opção inválida!" << endl;
}
} while (true);

return 0;

