#include <sqlite3.h>
#include <stdio.h>

int
add_data (char* data,
          int   roll,
          char* name,
          int*  bbk,
          int*  mob)
{
    sqlite3* db;

    int exit = sqlite3_open(data,&db);
    if (exit != SQLITE_OK) {
        return -1;
    }
    char* msg;
    char sql_query[4096];
    sprintf(sql_query,"INSERT INTO STUDENT VALUES ( %d , '%s'"
                      ", %d, %d, %d, %d"
                      ", %d, %d, %d );",roll,name,
                                      bbk[0],bbk[1],bbk[2],bbk[3],
                                      mob[0],mob[1],mob[2]);
    printf("query : %s\n",sql_query);
    exit = sqlite3_exec(db,sql_query, NULL, 0, &msg);
    if (exit != SQLITE_OK)
    {
        printf("MSG : %s\n",msg);
        return -2;
    }
    sqlite3_close(db);
    return 0;
}

int
get_data (char* data,
          char* colname,
          char* ref,
          void (*callback)(),
          void* indata,
          char *msg)
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open(data,&db);
    
    if (!rc) return -1;

    char sql_query[4096];    
    sprintf(sql_query,"SELECT %s FROM STUDENT WHERE %s = %s",colname,colname,ref);

    rc = sqlite3_exec(db,sql_query,callback,(void*)indata,&msg);
    if (!rc) return -2;
    sqlite3_close(db);
    return rc;
}