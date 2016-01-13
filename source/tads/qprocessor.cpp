#include "qprocessor.h"

Qprocessor::Qprocessor(vector<Document *>* base)
{
	this->base = base;
}

Qprocessor::~Qprocessor()
{
	for (int i = 0; i < queries.size(); ++i)
	{
		delete queries[i];
	}
}

void Qprocessor::Initialize()
{
	Query *query;

	for (vector<Document *>::iterator i = base->begin(); i != base->end(); ++i)
	{
		query = new Query();
		query->number = atoi((*i)->GetAttribute("QN").c_str());
		query->content = (*i)->GetAttribute("QU");
		query->rel_total = atoi((*i)->GetAttribute("NR").c_str());
		unordered_map<int,int> docs;
		SelectRelDocs(&docs, (*i)->GetAttribute("RD"));
		query->rel_docs = docs;

		queries.push_back(query);
	}
}

void Qprocessor::SelectRelDocs(unordered_map<int,int> *docs, string listDocs)
{
	string::iterator it;
	string number = "";
	bool get = true;

	for(it = listDocs.begin(); it != listDocs.end(); ++it)
	{
		if (isdigit(*it) && number.size() < 10)
			number += *it;
		else
		{
			if(number != "")
			{
				if(get)
				{
					docs->insert(pair<int,int>(atoi(number.c_str()), 1));
					get = false;
				}
				else 
					get = true;

				number = "";
			}

		}
	}
}

int Qprocessor::Process()
{

}