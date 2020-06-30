#include <iostream>

using namespace std;

template<typename F>
struct Nodo {
	F dato;
	Nodo<F> *left, *right;

	Nodo(F dato)
	{
		this->dato = dato;
		left = right = nullptr;
	}

	Nodo()
	{

	}
};

template<typename F>
struct Arbol_Binario {

	Nodo<F> *root;

	Arbol_Binario()
	{
		this->root = nullptr;
	}

	void insert(F dato)
	{
		insert(root, dato);
	}

	void inorder()
	{
		inorder(root);
	}

	void preorder()
	{
		preorder(root);
	}

	void postorder()
	{
		postorder(root);
	}

	void insert(Nodo<F> *&aux, F dato)
	{
		if (aux == nullptr)
		{
			aux = new Nodo<F>(dato);
		}
		else
		{
			if (aux->dato > dato)
			{
				if (aux->left != nullptr)
				{
					insert(aux->left, dato);
				}
				else
				{
					aux->left = new Nodo<F>(dato);
				}
			}
			else if (aux->dato < dato)
			{
				if (aux->right != nullptr)
				{
					insert(aux->right, dato);
				}
				else
				{
					aux->right = new Nodo<F>(dato);
				}
			}
		}
	}

	Nodo<F> *search(F dato, Nodo<F> *leaf)
	{
		if (leaf != nullptr)
		{
			if (dato == leaf->dato)
			{
				return leaf;
			}
			if (dato < leaf->dato)
			{
				return search(dato, leaf->left);
			}
			else
			{
				return search(dato, leaf->right);
			}
		}
		else
		{
			return nullptr;
		}
	}

	Nodo<F> *search(F dato)
	{
		return search(dato, root);
	}


	void inorder(Nodo<F> *aux)
	{
		if (aux != nullptr)
		{
			inorder(aux->left);
			cout << aux->dato << ", ";
			inorder(aux->right);
		}
	}

	void preorder(Nodo<F> *aux)
	{
		if (aux != nullptr)
		{
			preorder(aux->left);
			preorder(aux->right);
			cout << aux->dato << ", ";
		}
	}

	void postorder(Nodo<F> *aux)
	{
		if (aux != nullptr)
		{
			cout << aux->dato << ", ";
			postorder(aux->left);
			postorder(aux->right);
		}
	}
};
