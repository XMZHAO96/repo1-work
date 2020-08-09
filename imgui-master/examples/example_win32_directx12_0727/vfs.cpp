#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<iostream>

#include"vfs.h"

using namespace std;

vfs::vfs(){
	ifstream in_stream;
	int i;
	in_stream.open("log.txt");
	Node df;
	if(in_stream.fail())
	{
		cout<<"Input file opening failed.\n";
		exit(1);
	}
	else{
		for(i=0;i<MAX_SIZE;i++)
		{
			in_stream>>df.flag>>df.name>>df.parent>>df.left>>df.right>>df.path;
			node[i]=df;
		}
	}
	in_stream.close();
	curdir=0;
	fd=0;


}
vfs::~vfs(){
	ofstream out_stream;
	int i;
	out_stream.open("log.txt");
	if(out_stream.fail())
	{
		cout<<"Output file opening failed.\n";
		exit(1);
	}
	else{
		Node df;
		for(i=0;i<MAX_SIZE;i++)
		{
			df=node[i];
			out_stream<<df.flag<<"    "<<df.name<<"    "<<df.parent<<"    "<<df.left<<"    "<<df.right<<"    "<<df.path<<"    "<<endl;
		}
	}
	out_stream.close();
	

}


bool vfs::FindDir(int t, char* name){
	fd=-1;
	if(strcmp(node[t].name,name)==0&&(node[t].flag==1||node[t].flag==0)){
		fd=t;
		return true;}
	if(node[t].left==-1){
		return false;}
	s_Dirout(t,name);
	if(fd==-1)
		return false;
	else{
		if(strcmp(node[fd].name,name)==0)
			return true;
		else
			return false;
	}
}

void vfs::s_Dirout(int t, char *name){
	if(t==-1)
		return;
	else{
		if(strcmp(node[t].name,name)==0){
			fd=t;
			return;}
		s_Dirout(node[t].right,name);
		s_Dirout(node[t].left,name);}
	return;
}

void vfs::s_ShowDir(char *line)
{
	int t;
	if(!FindDir(0,line))
	{
		cout<<endl<<line<<"Directory doesnot exist\n"<<endl<<endl;
		return;
	}
	t=fd;
	cout<<endl<<"Current directory:"<<node[t].name<<endl<<endl;

}


void vfs::s_Createdir(char *name){
	int i,j;
	while(!DirExist(curdir,name)){
		cout<<"Folder already exist"<<endl<<"Please enter a different name"<<endl;
		cin>> name;}
	j= point(curdir);
	if(node[curdir].left==-1){
		node[curdir].left=2*curdir+1;
		i=node[curdir].left;}
	else{
		node[j].right=2*j+2;
		i=node[j].right;
	}
	node[i].flag=1;
	strcpy(node[i].name,name);
	node[i].parent=curdir;
	node[i].left=-1;
	node[i].right=-1;
	node[i].path=node[curdir].path+"/"+name;
	cout<<"Folder "<<name<<" created successfully"<<endl<<endl;
}

void vfs::s_Cd(char *dir){
	if(!FindDir(0,dir)){
		cout<<endl<<"No such directory"<<endl;
		return;}
	if(node[fd].flag==1||node[fd].flag==0){
		curdir=fd;
		cout<<"Goto "<< node[curdir].name<<endl<<endl;
		cout<<"Current directory: "<<node[curdir].path<<endl<<endl;
	}
	else
		cout<<"Couldn't access file!"<<endl<<endl;
	return;
}



void vfs::dir(int t){
	if(t==-1){
		return;
	}
	else{
		int j=node[t].parent;
		if(node[t].flag==1){
			cout<<"<"<<node[t].path<<"> "<<node[j].name<<" "<<"includes directory:"<<node[t].name<<endl;
		}
		else{
			cout<<"<"<<node[t].path<<"> "<<node[j].name<<" "<<"includes file: "<< node[t].name<<endl; }
		dir(node[t].right);
		dir(node[t].left);
	}
}

void vfs::s_Dir(int t){
	if(node[t].left==-1){
		cout<<endl<<node[t].name<<" is empty"<<endl<<endl;
		return;
	}
	else{
		dir(node[t].left);
		return;
	}
}

void vfs::s_Dir2(char *name){
	int i;
	if(!FindDir(0,name)){
		cout<<endl<<"Directory doesn't exist"<<endl<<endl;
		return;
	}
	i=fd;
	s_Dir(i);
}

bool vfs::DirExist(int t, char *name){
	int i;
	if(node[t].left==-1){
		return true;}
	i=node[t].left;
	if(strcmp(node[i].name,name)==0){
		return false;
	}
	return dirFound(node[i].right,name);
}

bool vfs::dirFound(int t,char* name){
	if(t!=-1){
		if(strcmp(node[t].name,name)==0&&node[t].flag==1){
			return false;
		}
		else{
			dirFound(node[t].right,name);
		}
	}
	return true;
}

int vfs::point(int t){
	int i;
	if(node[t].left==-1){
		i=t;
		return i;
	}
	i=node[t].left;
	while(node[i].right!=-1){
		i=node[i].right;
	}
	return i;
}

bool vfs::F_Exist(int t,char *name){
	int i;
	if(node[t].left==-1)
		return true;
	
	i=node[t].left;
	if(strcmp(node[i].name,name)==0)
		return false;
	return fileFound(node[i].right,name);
}

bool vfs::fileFound(int t,char* name){
	if(t!=-1){
		if(strcmp(node[t].name,name)==0){
			return false;
		}
		else{
			fileFound(node[t].right,name);
		}
	}
	return true;
}

void vfs::nreset(int t){
	node[t].flag=-1;
	strcpy(node[t].name,"NULL");
	node[t].parent=-1;
	node[t].left=-1;
	node[t].right=-1;
	node[t].path="NULL";
}

void vfs::childdel(int t){
	if(t!=-1){
		childdel(node[t].left);
		childdel(node[t].right);
		nreset(t);
	}
}

void vfs::s_Deletedir(){
	int i;
	if(curdir==0){
		cout<<endl<<"Can't delete root directory"<<endl<<endl;
		return;
	}
	if(node[curdir].left==-1){
		s_Dir(curdir);
		cout<<"To delete folder:"<<endl<<"press enter to continue"<<"           "<<"enter 0 to cancel"<<endl;
		cin>>i;
		if(i==0){
			return;
		}
	}
	else{
		cout<<"Can't delete an non-empty folder!Please empty it and try again."<<endl<<endl;
		return;
	}
	int j,k,l;
	j=node[curdir].parent;
	if(node[j].left==curdir)
		node[j].left=node[curdir].right;
	else{
		k=(curdir-2)/2;
		node[k].right=node[curdir].right;
	}
	l=curdir;
	curdir=j;
	childdel(node[l].left);
	nreset(l);
	cout<<"Folder has been deleted"<<endl;
}

void vfs::Fileout(int t, char* name){
	if(t==-1){
		return;
	}
	else{
		if(strcmp(node[t].name,name)==0 && node[t].flag==2)
		{
			curfile=t;
			return;
		}
		Fileout(node[t].right,name);
		Fileout(node[t].left,name);
	}
	return;
}



void vfs::s_CreateFile(char *name){
	int i,j;
	while(!F_Exist(curdir,name)){
		cout<<endl<<"File already exist"<<endl<<"Please enter a different name:"<<endl;
		cin>>name;
	}
	j=point(curdir);
	if(node[curdir].left==-1){
		node[curdir].left=2*curdir+1;
		i=node[curdir].left;
	}
	else{
		node[j].right=2*j+2;
		i=node[j].right;
	}
	node[i].flag=2;
	strcpy(node[i].name,name);
	int k=node[i].parent;

	node[i].parent=curdir;
	node[i].left=-1;
	node[i].right=-1;
	node[i].path=node[curdir].path+"/"+node[i].name;
	ofstream out_stream;
	out_stream.open(name);
	cout<<endl<<"File "<<node[i].name<<" created!"<<endl<<endl;

}
void vfs::s_LoadFile(char *name){
	int i,j;
	ifstream in_stream;
	in_stream.open(name);
	while(!in_stream.is_open()){
		cout<<endl<<"File doesn't exist"<<endl<<endl;
 		return;
	}
	j=point(curdir);
	if(node[curdir].left==-1){
		node[curdir].left=2*curdir+1;
		i=node[curdir].left;
	}
	else{
		node[j].right=2*j+2;
		i=node[j].right;
	}
	node[i].flag=2;
	strcpy(node[i].name,name);
	int k=node[i].parent;

	node[i].parent=curdir;
	node[i].left=-1;
	node[i].right=-1;
	node[i].path=node[curdir].path+"/"+node[i].name;
	ofstream out_stream;
	out_stream.open(name);
	cout<<endl<<"File "<<node[i].name<<" loaded!"<<endl;

}

void vfs::s_ReadFile(char *name){
	char buffer[256];
	string a;
	if(!FindFile(0,name)){
		cout<<name<<"File doesn't exist"<<endl;
		return;
	}
	ifstream in_stream(name);
	if(!in_stream.is_open()){
		cout << "Unable to open file"<<endl;
        exit(1);
	}
	while (!in_stream.eof()){
		in_stream.getline(buffer,256);
		a=buffer;
		cout<<a<<endl;

	}
	in_stream.close();
}

void vfs::s_WriteFile(char *name){
	if(!FindFile(0,name)){
		cout<<name<<"File doesn't exist"<<endl;
		return;
	}
	
	ofstream out_stream(name);
	char ch[80];
	bool sig=true;
	if(!out_stream.is_open()){
		cout << "Unable to open file"<<endl;
        exit(1);
	}
 
	while(sig){
		cout<<"Please input content,enter EOF when done: ";
		cin>> ch;
		if(!strcmp(ch,"EOF")){
			sig=false;
			break;
		}
		out_stream<<ch<<endl;
		ch[0]='\0';
	
	}
	out_stream.close();
}
	


bool vfs::FindFile(int t, char *name){
	curfile=-1;
	if(node[t].left==-1){
		return false;
	}
	Fileout(t,name);
	if(curdir==-1){
		return false;
	}
	else{
		if(strcmp(node[curfile].name,name)==0 && node[curfile].flag==2){
			return true;
		}
		else{
			return false;}
	}
}

void vfs::s_Fileout(int t,char* name){
	if(t==-1){
		return;
	}
	else{
		if(strcmp(node[t].name,name)==0 && node[t].flag==2){
			curfile=t;
			return;
		}
		Fileout(node[t].right,name);
		Fileout(node[t].left,name);
	}
	return;
}

void vfs::s_DeleteFile(char *name){
	if(!FindFile(0,name)){
		cout<<"File "<<name<<" doesn't exist"<<endl;
		return;
	}
	
	int i,j,k;
	i=node[curfile].parent;
	if(node[i].left==curfile){
		node[i].left=node[curfile].right;
	}
	else{
		j=(curfile-2)/2;
		node[j].right=node[curfile].right;
	}
	k=curfile;
	curfile=i;
	nreset(k);
	remove(name);
	cout<<"File deleted!"<<endl;
}


void vfs::SystemInit(){
	ofstream out_stream;
	int i;
	ifstream re_stream;
	re_stream.open("log.txt");
	if(!re_stream.is_open()){
		cout<<"Initialization failed.\n";
		exit(1);
	}
	else{
		for(i=0;i<MAX_SIZE;i++){
			if(node[i].flag==2)
				remove(node[i].name);
		}
	}

	out_stream.open("log.txt");
	out_stream<<0<<"    "<<"root"<<"    "<<-1<<"    "<<-1<<"    "<<-1<<"    "<<"root"<<"    "<<endl;

	for(i=1;i<MAX_SIZE;i++){
		out_stream<<-1<<"    "<<"null"<<"    "<<-1<<"    "<<-1<<"    "<<-1<<"    "<<-1<<"    "<<endl;
	}
	out_stream.close();

	ifstream in_stream;
	in_stream.open("log.txt");
	Node df;
	if(in_stream.fail())
	{
		cout<<"Initialization failed.\n";
		exit(1);
	}
	else{
		for(i=0;i<MAX_SIZE;i++)
		{
			in_stream>>df.flag>>df.name>>df.parent>>df.left>>df.right>>df.path;
			node[i]=df;
			
		}
	}
	in_stream.close();
	curdir=0;
	fd=0;
	cout<<"Initialization succeeded!\n";
}

void vfs::s_Command(char* command){
	char type[20]=" ";
	char param[40]=" ";
	param[39]='\0';
	int i=0;

	while(command[i]!=' '&& command[i]!='\0'){
		
		type[i]=command[i];
		++i;
	}
	type[i]='\0';
	int j=0;

	while(command[i] !='\0'){
		param[j++]=command[++i];
	}
	if(strcmp(type,"help")==0){
		cout<<endl;
		cout<<"**************************************************************************************"<<endl;
		cout<<"cd  <folder name>------------Set current directory to <folder name>\n";
		cout<<"curdir-----------------------Show all the files and folders under current directory\n";
		cout<<"dir <folder name>------------Show all the files and folders under <folder name>\n";
		cout<<"createdir <folder name>------Create folder under current directory \n";
		cout<<"deletedir--------------------Delete current folder\n";
		cout<<"createfile <file name>-------Create file <file name> under current folder\n";
		cout<<"loadfile   <file name>-------Load outsourced file into current folder\n";
		cout<<"readfile   <file name>-------Read file content into screen\n";
		cout<<"writefile  <file name>-------Edit file content, enter EOF when finished\n";
		cout<<"deletefile <file name>-------Delete file <file name>\n";
		cout<<"init-------------------------Initialize the system\n";
		cout<<"exit-------------------------Save and exit system\n";
		cout<<"**************************************************************************************"<<endl;
		cout<<endl<<endl;
	}
	else if(strcmp(type,"init")==0){
		SystemInit();
	}
	else if(strcmp(type,"dir")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a file name"<<endl;
		else{
			s_Dir2(param);
		}
	}
	else if(strcmp(type,"cd")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a route"<<endl;
		else{
			s_Cd(param);
		}
	}
	else if(strcmp(type,"curdir")==0){
			s_Dir(curdir);
		
	}
	else if(strcmp(type,"createdir")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a file name"<<endl;
		else{
			s_Createdir(param);
		}
	}
	else if(strcmp(type,"deletedir")==0){
	
			s_Deletedir();
		
	}
	else if(strcmp(type,"createfile")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a file name"<<endl;
		else{
			s_CreateFile(param);
		}
	}
	else if (strcmp(type,"loadfile")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a file name"<<endl;
		else{
			s_LoadFile(param);
		}
	}
	else if (strcmp(type,"readfile")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a file name"<<endl;
		else{
			s_ReadFile(param);
		}
	}
	else if (strcmp(type,"writefile")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a file name"<<endl;
		else{
			s_WriteFile(param);
		}
	}
	else if(strcmp(type,"deletefile")==0){
		if(strcmp(param," ")==0)
			cout<<"Please enter a file name"<<endl;
		else{
			s_DeleteFile(param);
		}
	}
	else {
		cout<<"Not a internal command,enter help for more info"<<endl;
	}
	return;
}


	
