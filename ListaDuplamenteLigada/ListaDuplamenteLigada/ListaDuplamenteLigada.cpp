#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
	NO* ant;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void exibirReverso();
void inserirElemento();
void excluirPrimeiroElemento();
void excluirUltimoElemento();

//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 9) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Exibir quantidade de elementos \n";
		cout << "4 - Exibir elementos  \n";
		cout << "5 - Exibir elementos na ordem reversa \n";
		cout << "6 - Excluir primeiro elemento \n";
		cout << "7 - Excluir ultimo elemento \n";
		cout << "8 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:inserirElemento();
			break;
		case 3: exibirQuantidadeElementos(); 
			break;
		case 4: exibirElementos();
			break;
		case 5: exibirReverso();
			break;
		case 6: excluirPrimeiroElemento();
			break;
		case 7: excluirUltimoElemento();
			break;
		case 8:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista ja possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		novo->ant = ultimo;
		ultimo->prox = novo;
		ultimo = novo;
	}
}


// funções a serem implementadas no exericio
void exibirReverso()
{
	if (primeiro != NULL) {
		NO* aux = ultimo;
		cout << "Elementos : \n";
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->ant;
		}
	}
	else {
		cout << "Lista vazia \n";
	}
}

void excluirPrimeiroElemento()
{
	NO* aux = primeiro;
	NO* remover = NULL;
	NO* ultimoElemento = ultimo;
	if (aux != NULL) {
		if (aux->prox != NULL) {
			primeiro=primeiro->prox;
			free(aux);
			aux=NULL;
			primeiro->ant=NULL;
			cout << "Elemento removido com sucesso" << endl;
		}
		else {
			free(aux);
			primeiro = NULL;
			ultimo = NULL;
			cout << "Elemento removido com sucesso" << endl;
		}
	}
	else {
		cout << "Lista vazia" << endl;
	}
	
}

void excluirUltimoElemento()
{
	NO* aux = primeiro;
	NO* ultimoElemento = ultimo;
	if (aux != NULL) {
		if (aux->prox == NULL) {
			primeiro = NULL;
			ultimo = NULL;
		}else {
		    ultimo=ultimo->ant;
			free(ultimoElemento);
			ultimoElemento=NULL;
			ultimo->prox=NULL;
			cout << "Elemento removido com sucesso" << endl;
		}
		
	}
	else {
		cout << "Lista vazia" << endl;
	}
}
