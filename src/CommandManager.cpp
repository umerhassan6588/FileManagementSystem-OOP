class CommandManager
{
	Folder* currentFolder;
public:
	CommandManager(Folder* rootFolder) {
		currentFolder = rootFolder;
	}
	void ls() {
		Node** mylist = currentFolder->getList();
		for (int i = 0; i < currentFolder->getCount(); i++)
		{
			cout << "Name: " << mylist[i]->getName() << " | Type: " << mylist[i]->getType() << " | Size: " << mylist[i]->getSize() << endl;
		}
	}
	void mkdir() {
		Folder* newFolder = new Folder(name, currentFolder);
		currentFolder->addNode(newFolder);
	}
private:

};
