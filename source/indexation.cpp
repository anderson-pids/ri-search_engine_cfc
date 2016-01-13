#include <iostream>
#include <cstdlib>
#include "tads/parser.h"
#include "tads/indexer.h"

using namespace std;

int main()
{
	//TODO:: Could pass base path by parameter 
	Parser *parser = new Parser("base/");
	parser->Process();
	vector<Document *>* collection = parser->GetCollection();
	Indexer *indexer = new Indexer(collection);
	indexer->Initialize();
	indexer->Process();
	indexer->WriteIndexFile();

	delete indexer;
	delete parser;
}