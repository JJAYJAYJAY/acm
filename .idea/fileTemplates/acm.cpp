#[[#include]]# <iostream>

using namespace std;

void solve(){

}

int main(){
#[[#ifdef]]# LOCAL
    freopen("${DIR_PATH}/in/${FILE_NAME}.in","r",stdin);
#[[#endif]]#
    int work=1;
    while(work--){
        solve();
    }
#[[#ifdef]]# LOCAL
    fclose(stdin);
#[[#endif]]#
}