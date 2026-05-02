class Folder : public Node
{
protected:
	Node** list;
	int count;

public:
	Folder(string name, Node* prev) : Node(name, prev) {
		list = nullptr;
		count = 0;
	}
	~Folder() {
		for (int i = 0; i < count; i++)
		{
			delete list[i];
		}
		delete[] list;
	}

	void open() { cout << "Opened: " << getName() << endl; }
	void create() { cout << "Created: " << getName() << endl; }
	void remove() {
		cout << "Removed: " << getName() << endl;
		for (int i = 0; i < count; i++)
		{
			delete list[i];
		}
		delete[] list;
	}
	string getType() {
		return "Folder";
	}
	int getSize() {
		return count;
	}
	int getCount() {
		return count;
	}
	Node** getList() {
		return list;
	}
	void addNode(Node* newnode) {
		Node** temp = new Node * [count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = list[i];
		}
		temp[count] = newnode;
		delete[] list;
		list = temp;
		count++;
	}
};

