/*
 * Postman.h
 */

#ifndef SRC_POSTMAN_H_
#define SRC_POSTMAN_H_

#include "Mail.h"
#include <string>
#include <vector>

class Postman {
	unsigned int id;
	string name;
	vector<Mail *> myMail;
public:
	Postman();
	Postman(string name);
	void setName(string nm);
	void addMail(Mail *m);
	void addMail(vector<Mail *> mails);
	string getName() const;
	vector<Mail *> getMail() const;
	unsigned int getID() const;
	bool operator<(const Postman & p2) const;

};

class NoPostmanException{
    string name;

public:
    string getName(){
    	return name;
    };
    NoPostmanException(string name): name(name){};

};


#endif /* SRC_POSTMAN_H_ */
