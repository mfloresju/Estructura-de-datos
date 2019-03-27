#include <iostream>
#include <cstdlib>
#include <ctime>

template<class T>
class LinkedList
{
private:
	struct Node {
		T data;
		Node *prev;
		Node *next;
		Node() : data(0), prev(NULL), next(NULL) { }
		void print() {
			std::cout << data << "->";
		}
	} *head, *end;
	int length;

public:
	LinkedList<T>(int l) : length(l) {
		if (l < 1) return;

		head = new Node();

		if (l < 2) return;

		int i = 1;
		Node *aux = head;
		while (i++ < length) {
			aux->next = new Node();
			aux->next->prev = aux;
			aux = aux->next;
			end = aux;
		}
	}

	~LinkedList<T>() {
		head = NULL;
	}

	void insert_front(const T& d) {
		if (int(end->data) != 0) {
			std::cout << "Lista llena!" << std::endl;
			return;
		}

		if (head->data == 0) {
			head->data = d;
			return;
		}

		Node *aux = end;
		while (aux != NULL) {
			if (aux->data != 0) {
				if (aux->next != NULL) {
					aux->next->data = aux->data;
					aux->data = 0;
				}
			}
			aux = aux->prev;
		}

		head->data = d;
	}

	void insert_back(const T& d) {
		if (int(end->data) != 0) {
			std::cout << "Lista llena!" << std::endl;
			return;
		}

		if (head->data == 0) {
			head->data = d;
			return;
		}

		Node *aux = head;
		while (aux != NULL) {
			if (aux->data == 0) {
				aux->data = d;
				break;
			}
			aux = aux->next;
		}
	}

	void remove_front() {
		if (head->data == 0) {
			std::cout << "La lista esta vacia" << std::endl;
			return;
		}

		head->data = 0;
		Node *aux = head;
		while (aux != NULL) {
			if (aux->next != NULL) {
				aux->data = aux->next->data;
				aux->next->data = 0;
			}

			aux = aux->next;
		}
	}

	void remove_back() {
		if (head->data == 0) {
			std::cout << "La lista esta vacia" << std::endl;
			return;
		}

		Node *aux = end;
		while (aux != NULL) {
			if (aux->data != 0) {
				aux->data = 0;
				break;
			}
			aux = aux->prev;
		}
	}

	void print() {
		if (head->data == 0) {
			std::cout << "La lista esta vacia" << std::endl;
			return;
		}

		Node *aux = head;
		while (aux != NULL) {
			aux->print();
			if (aux->next == NULL) std::cout << "NULL \n";
			aux = aux->next;
		}
	}
};

int mk_random(int min, int max)
{
	return min + rand() % max;
}

int main()
{
	int value=0;
	std::cout << "Seleccione cantidad de datos: ";
	std::cin >> value;
	srand(time(NULL));
	LinkedList<int> ll(value);

	int iterations = 0;


	do {
		system("cls");

		std::cout << "Seleccione su numero de iteraciones: ";
		std::cin >> iterations;
		if (iterations > 100 || iterations < 1) continue;
	} while (iterations == 0);

	for (int i = 0; i < iterations; ++i) {
		int option = mk_random(1, 5);
		std::cout << "option: " << option << "\n";
		switch (option) {
			case 1: {
				for (int i =0; i<value;i++){
				ll.insert_front(i); }
			} break;
			case 2: {
				ll.remove_front();
			} break;
			case 3: {
				for (int i =0; i<value;i++){
				ll.insert_back(i); }
			} break;
			case 4: {
				ll.remove_back();
			} break;
			case 5: {
				ll.print();
			} break;
		}
	}

	//system("cls");
	//ll.print();

	return 0;
}
