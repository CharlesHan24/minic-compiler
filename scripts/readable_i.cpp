#include <cstdio>
using namespace std;

#define BUF_LEN 10100
char name[BUF_LEN];

int main(int argc, char* argv[]){
    int _;
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    while ((scanf("%d%s", &_, name)) != EOF){
        printf("%s ", name);
    }
    return 0;
}