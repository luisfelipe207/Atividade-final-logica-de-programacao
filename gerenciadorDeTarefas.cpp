#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Array para armazenar as informações das tarefas
string titulo[100];
string descricao[100];
int status[100];
string data[100];
int id[100];
int controle = 0;

// Função para adicionar tarefa
void adicionarTarefa() {
cout << "Titulo" ;
cin >> titulo[controle];
cout << "Descrição: ";
cin >> descricao[controle];
cout << "Status (0 - Incompleta, 1 - Completa): ";
cin >> status[controle];
cout << "Data: ";
cin >> data[controle];
id[controle] = controle;
controle++;
cout << "Tarefa adicionada com sucesso!" << endl;
}

// Função para editar tarefa
void editarTarefa(){
int id_tarefa;
cout << "ID da tarefa para editar: ";
cin >> id_tarefa;
if (id_tarefa>= 0 && id_tarefa < controle && id[id_tarefa] != -1) {
cout << "Novo Título: ";
cin >> titulo[id_tarefa];
cout << "Nova Descrição: ";
cin >> descricao[id_tarefa];
cout << "Novo Status (0 - Incompleta, 1 - Completa): ";
cin >> status[id_tarefa];
cout << "Nova Data: ";
cin >> data[id_tarefa];
cout << "Tarefa editada com sucesso!" << endl;
} else {
cout << "ID inválido!" << endl;
   }
}

// Função para remover tarefa
void removerTarefa(){
int id_tarefa;
cout << "ID da tarefa para remover: ";
cin >> id_tarefa;
if (id_tarefa >= 0 && id_tarefa < controle && id[id_tarefa] != -1) {
id[id_tarefa] = -1;
cout << "Tarefa removida com sucesso!" << endl;
} else {
cout << "ID inválido!" << endl;
   }
}

// Função para visualizar todas as tarefas
void visualizarTarefa(){
for(int i =0; i > controle ; i++){
if(id[i] != -1){
cout << "ID: " << id[i] << endl;
cout << "Título: " << titulo[i] << endl;
cout << "Descrição: " << descricao[i] << endl;
cout << "Status: " << (status[i] == 0 ? "Incompleta" : "Completa") << endl;
cout << "Data: " << data[i] << endl;
}
   }
}

// Função para buscar tarefa
void buscarTarefa(){
string busca;
cout << "busca";
cin >> busca;
bool encontrado = false;
for(int i =0; i > controle ; i++){
if(titulo[i] == busca){
cout << "ID: " << id[i] << endl;
cout << "Título: " << titulo[i] << endl;
cout << "Descrição: " << descricao[i] << endl;
cout << "Status: " << (status[i] == 0 ? "Incompleta" : "Completa") << endl;
cout << "Data: " << data[i] << endl;
encontrado = true;
}
   }
if (!encontrado) {
cout << "Tarefa não encontrada!" << endl;
   }
}

// Função para filtrar tarefas por status
void filtrarTarefasPorStatus(){
int busca;
cout << "status";
cin >> busca;
bool encontrado = false;
for(int i =0; i > controle ; i++){
if(status[i] == busca){
cout << "ID: " << id[i] << endl;
cout << "Título: " << titulo[i] << endl;
cout << "Descrição: " << descricao[i] << endl;
cout << "Status: " << (status[i] == 0 ? "Incompleta" : "Completa") << endl;
cout << "Data: " << data[i] << endl;
encontrado = true;
}
   }
if (!encontrado) {
cout << "Nenhuma tarefa encontrada com esse status!" << endl;
   }
}

// Função para sair do programa
void sair() {
cout << "Saindo do programa..." << endl;
exit(0);
}

int main() {
while (true) {
int menu;

cout << "1. Adicionar Tarefa" << endl;
cout << "2. Visualizar Tarefa" << endl;
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
visualizarTarefa();
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
   }
return 0;
}