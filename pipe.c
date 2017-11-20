#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


//0=read, 1=write
int main() {

  int fds_parent[2];
  int fds_child[2];
  pipe(fds_parent);
  pipe(fds_child);

  if (fork()==0){//child
    close(fds_parent[1]);
    int n;
    read(fds_parent[0],&n,sizeof(int));
    printf("[child] doing maths on: %d\n",n);
    n=n*n;
    close(fds_child[0]);
    write(fds_child[1],&n,sizeof(int));

  }
  else {
    close(fds_parent[0]);
    int n=37;
    write(fds_parent[1],&n,sizeof(int));
    printf("[parent] sending: %d\n",n);
    close(fds_child[1]);
    int i;
    read(fds_child[0],&i,sizeof(int));
    printf("[parent] received: %d\n",i);

  }


  return 0;

}
