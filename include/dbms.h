#ifndef DBMS_H
#define DBMS_H

/* add_data 
 * INPUT : 
 *        char *data : .db file
 *        int  roll, char* name, : student data
 *        int * bbk : int list for book bank
 *        int * mob : int list for Montly books
 * 
 * OUTPUT : 
 *        return  0  : success
 *               -1  : error in .db file
 *               -2  : error in query 
*/
int add_data (char* data, int   roll, char* name, int*  bbk, int*  mob);



/*
 * get_data
 * 
 * INPUT : char * colname : column name
 *         char * ref     : refrence for column name
 *         callback       : pointer to callback function
 *         char * msg     : pointer to output msg
 *  
*/
int get_data (char* data, char* colname, char* ref, void (*callback)(), void* indata, char *msg);
#endif
