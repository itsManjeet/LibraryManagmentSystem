#ifndef DBMS_H
#define DBMS_H

int add_data (char* data, int   roll, char* name, int*  bbk, int*  mob);


int get_data (char* data, char* colname, char* ref, void (*callback)(), void* indata, char *msg);
#endif
