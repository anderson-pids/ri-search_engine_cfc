#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include "document.h"

using namespace std;

enum Tag {PN, RN, AN, AU, TI, SO, MJ, MN, AB, EX, RF, CT, NIL, NONE};

class Parser
{
private:
	string base_path, field; //path without id file
	fstream fs;
	unordered_map <string,Tag> tag;
	vector<Document *> *documents;

	int ReadCollection(int doc);
	int ReadDocument();
	string ReadField(Tag tag_field, Tag tag_sin = NONE);
	void InitializeMapTag();
	Tag ConvertStringToTag(string tag);
	void Return1Line(long line_size);

public:
	Parser(string dataset_path);
	~Parser();
	int Process();
	vector<Document *>* GetCollection();
};

#endif