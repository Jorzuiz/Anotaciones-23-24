#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PATH_MAX 4096

struct options {
	char *progname;
	int recurse;
};

struct options opt;

void usage(void)
{
	printf("%s [options] [dirname]\n\n", opt.progname);
	printf("lists the contents of dirname (default .)\n");
	printf("options:\n"
		"\t-h:\tshow this help\n"
		"\t-R:\trecursive\n"
	);
}

/* apartado b */
void list_dir(char *name)
{
	DIR* dir;
	dir = opendir(name);

	if(dir==NULL){
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	struct dirent * dirent;
	// readdir returns the NEXT directory name (in struct form)
	// dirent->d_name; name in string 
	// dirent->d_type; type of file (DT_DIR = directory)
	while((dirent= readdir(dir))!= NULL){
		printf("%s \n", dirent->d_name);
	}

	closedir(dir);
}

/* apartado c */
void process_recurse(char *dirname, char *name)
{
	pid_t pid;
	char path[PATH_MAX];
	
	pid= fork();
	if(pid==-1){
		perror("fork");
		exit(1);
	}
	else if(pid == 0){    // Hijo
        strcpy(path, dirname);
        strcat(path, "/");
        strcat(path, name);
        // Crea una copia propia con argumento -R en directorio name
		execl(opt.progname, opt.progname, "-R", name, NULL);
        perror("execl");
		exit(EXIT_FAILURE);
	}
	else{   // Padre
		//waitpid(pid, NULL,0);
		wait(NULL);
	}

}

/* apartado c */
void list_dir_recurse(char *name)
{
	DIR* dir;
	dir = opendir(name);
	
	if(dir==NULL){
		perror("opendir ");
	}
	
    struct dirent * dirent;
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_type == DT_DIR && 
		strcmp(dirent->d_name, ".") != 0 && 
		strcmp(dirent->d_name, "..") != 0) {
            process_recurse(name, dirent->d_name);
        }
    }
	closedir(dir);
}

int main(int argc, char **argv)
{
	char *dirname = ".";
	int o;
	opt.progname = argv[0];
	opt.recurse = 0;

	while((o = getopt(argc, argv,"hR"))!=-1){
		switch (o)
		{
		case 'h':
			printf("Usage");
			usage();
			break;
		case 'R':
			opt.recurse=1;
        	if(argv[optind] != NULL){
				dirname = argv[optind];
			}
		    break;
		default:
			break;
		}
	}

	if (opt.recurse)
        printf("%s:\n", dirname);

    list_dir(dirname);

    if (opt.recurse)
        list_dir_recurse(dirname);

	return 0;
}