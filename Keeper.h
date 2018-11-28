#ifndef _KEEPER_H_
#define _KEEPER_H_

#include "plane.h"
#include "train.h"
#include "car.h"
#include "exceptions.h"

#define COUNT 3

class Keeper {
public:
	Keeper();
	~Keeper();
	void add_transpoter(transpoter* tr, int dec);
	void delete_transpoter(int trNum, int dec);

	plane* get_plane() { return p; }
	train* get_train() { return t; }
	car* get_car() { return c; }
	int get_size(int trNum) { return size[trNum]; }

	void save();
	void load();
private:
	plane *p;
	train *t;
	car *c;
	int size[COUNT];
};

#endif // !KEEPER_H_

