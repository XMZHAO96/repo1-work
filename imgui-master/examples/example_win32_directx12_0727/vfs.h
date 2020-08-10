#ifndef VSF_H
#define VSF_H
#define MAX_SIZE 10000
#include<list>
#include<string>

using namespace std;

/*********************simplified iNode structure*****************************/
struct Node{
	int flag;                         //Flag indicating type of nodes. 0 for root node. 1 for folders and 2 for files.
	char name[20];					  //Node name;
	int parent,left,right;			  //List of related node
	string path;					  //Storage path
};


/*********************Virtual File System Class*****************************/
class vfs{
private:
	int curdir;						  //current working directory
	int curfile;					  //current working file
	Node node[MAX_SIZE];			  //Node array						
	int fd;							  //signals for Node id
	bool fileFound(int t, char* name);//search for file name "name" with a starting node t
	bool dirFound(int t,char* name);  //search for fold name "name" with a starting node t
	int e_time;
public:
	vfs();
	~vfs();
	void s_Command(char* command);	 //system commands
	void s_Cd(char* dir);			 //goto directory "dir"
	char* s_Dir(int t);	
	void s_Dir2(char *name);
	void s_ShowDir(char *line);
	void s_Createdir(char* name);	 //create folder under current directory with an input name
	void s_Dirout(int t, char* name);
	void s_Deletedir();				 //delete current folder if it is empty
	bool DirExist(int t, char* name);
	void Fileout(int t, char* name);
	int  point(int t);
	void s_CreateFile(char *name);   //create file under current directory with an input name
	void s_Fileout(int t, char* name);
	void s_DeleteFile(char *name);   //delete file with a given name
	void s_LoadFile(char *name);	 //load file to the system from external source
	void s_ReadFile(char *name);	 //read file content to the screen
	void s_WriteFile(char *name);    //add content to existing files/
	bool FindDir(int t, char* name);
	bool FindFile(int t, char* name);
	char* dir(int t,int index);

	void nreset(int t);
	bool F_Exist(int t, char *name);
	void childdel(int t);
	void s_ShowFile(char* dir);
	void SystemInit();				 //initiate system 
};
#endif;

	

