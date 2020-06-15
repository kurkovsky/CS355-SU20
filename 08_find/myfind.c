/*
A simple scaffolding to implementat myfind (lab 7)
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
//#include <string.h>

void do_find();

// this function is called for every encountered directory entry 
void process_entry(char *filename){
    struct stat info;
    if(stat(filename,&info)==-1)
        perror(filename);
    else {
        if(S_ISDIR(info.st_mode)) {     // if this directory entry is a subdirectory
            printf("%s is a directory\n", filename);
            // do_find(filename);       // explore this subdirectory
        }
        if(1) {  // ststr() should be used in this condition to see if there's a filename match
            printf("Directory entry: %s\n", filename);
        }
    }
}

// explore all entries of the given directory
void do_find(char *dir_name) {
    DIR *dir_ptr;               // pointer to a directory structure
    struct dirent *dirent_ptr;  // pointer to the current directory entry
    dir_ptr = opendir(dir_name);
    if(dir_ptr==0) {            // opendir could fail, possibly because
        perror(dir_name);       // the directory does not exist
    }
    else {                      // iterate over all directory entries
        while((dirent_ptr=readdir(dir_ptr)) != 0) {
            //printf("Directrory entry: %s\n", dirent_ptr->d_name);
            process_entry(dirent_ptr->d_name);
        }
        closedir(dir_ptr);
    }
}

int main() {
    do_find(".");                 // explore the contents of the current directory
    return 0;
}