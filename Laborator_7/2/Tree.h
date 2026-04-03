template <class T>
struct Node
{
	T value;
	Node<T>** children;
	int count;

	Node(const T& val)
	{
		value = val;
		children = nullptr;
		count = 0;
	}

	~Node()
	{
		for (int i = 0; i < count; i++)
			delete children[i];
		delete[] children;
	}
};

template <class T>
class Tree
{
	Node<T>* root;

	Node<T>* find_parent(Node<T>* current, Node<T>* target);

public:
	Tree();
	~Tree();

	void add_node(Node<T>* parentnode, const T& val);
	
	Node<T>* get_node(Node<T>* parentnode);
	
	void delete_node(Node<T>* deletednode);

	void insert(Node<T>* parentnode, const T& val, int index);

	Node<T>* find(bool (*compare)(const T&, const T&), const T& val, Node<T>* parentnode);
	
	void sort(Node<T>* parentnode, bool (*cmp)(const T&, const T&) = nullptr);

	int count(Node <T>* parentnode);
};



template <class T>
Node<T>* Tree<T>::find_parent(Node<T>* current, Node<T>* target)
{
	for (int i = 0; i < current->count; i++)
	{
		if (current->children[i] == target)
			return current;
		Node<T>* recursive = find_parent(current->children[i], target);
		if (recursive) return recursive;
	}
	return nullptr;
}

template <class T>
Tree<T>::Tree()
	{
		root = nullptr;
	}

template <class T>
Tree<T>::~Tree()
	{
		delete root;
	}

template <class T>
	void Tree<T>::add_node(Node<T>* parentnode, const T& val)
	{
		Node<T>* newnod = new Node<T>(val);

		if (parentnode == nullptr)
		{
			root = newnod;
		}
		else
		{
			Node<T>** c = new Node<T>*[parentnode->count + 1];

			for (int i = 0; i < parentnode->count; i++)
			{
				c[i] = parentnode->children[i];
			}
			c[parentnode->count] = newnod;
			delete[] parentnode->children;
			parentnode->children = c;
			parentnode->count++;
		}
	}

template <class T>
Node<T>* Tree<T>::get_node(Node<T>* parentnode)
	{
		return (parentnode == nullptr) ? root : parentnode;
	}

template <class T>
	void Tree<T>::delete_node(Node<T>* deletednode)
	{
		if (deletednode == nullptr || deletednode == root)
		{
			delete root;
			return;
		}
		Node<T>* parent = find_parent(root, deletednode);
		if (parent->count > 1)
		{
			Node<T>** c = new Node<T>*[parent->count - 1];
			int j = 0;
			for (int i = 0; i < parent->count; i++) {
				if (parent->children[i] != deletednode)
					c[j++] = parent->children[i];
			}

			delete[] parent->children;
			parent->children = c;
		}
		delete deletednode;
		parent->count--;
	}

	template <class T>
	void Tree<T>::insert(Node<T>* parentnode, const T& val, int index)
	{
		if (index >= 0 && index < parentnode->count && parentnode)
		{
			Node<T>* newnod = new Node<T>(val);
			Node<T>** c = new Node<T>*[parentnode->count + 1];

			for (int i = 0; i < index; i++)
				c[i] = parentnode->children[i];

			c[index] = newnod;

			for (int i = index; i < parentnode->count; i++)
				c[i + 1] = parentnode->children[i];

			delete[] parentnode->children;
			parentnode->children = c;
			parentnode->count++;
		}
	}
	template <class T>
	Node<T>* Tree<T>::find(bool (*compare)(const T&, const T&), const T& val, Node<T>* parentnode)
	{
		Node<T>* current = (parentnode == nullptr) ? root : parentnode;
		if (!current) return nullptr;

		if (compare(current->value, val)) return current;

		for (int i = 0; i < current->count; i++)
		{
			Node<T>* recursive = find(compare, val, current->children[i]);
			if (recursive) return recursive;
		}

		return nullptr;
	}

	template <class T>
	void Tree<T>::sort(Node<T>* parentnode, bool (*cmp)(const T&, const T&))
	{
		if (!parentnode || parentnode->count < 2) return;

		for (int i = 0; i < parentnode->count - 1; i++)
			for (int j = 0; j < parentnode->count - i - 1; j++)
			{
				bool swap = false;
				if (cmp)
					swap = cmp(parentnode->children[j]->value, parentnode->children[j + 1]->value);
				else
					swap = parentnode->children[j + 1]->value < parentnode->children[j]->value;

				if (swap)
				{
					Node<T>* aux = parentnode->children[j];
					parentnode->children[j] = parentnode->children[j + 1];
					parentnode->children[j + 1] = aux;
				}
			}
	}

	template <class T>
	int Tree<T>::count(Node <T>* parentnode)
	{
		int amount = 1;

		Node<T>* startnode;
		startnode = (parentnode == nullptr) ? root : parentnode;
		if (!startnode)
			return 0;
		for (int i = 0; i < startnode->count; i++)
		{
			amount += count(startnode->children[i]);
		}
		return amount;
	}

