//
// Created by lyh on 2023/12/17.
//

//
//bool back(string s,int n,int k,int A,int B,bool turn){
//    if(B>k){
//        return false;
//    }
//    if(A>k){
//        return true;
//    }
//    char temp=s[0];
//    if(turn) {
//        if(temp=='V') {
//            if (back(s.erase(0, 1), n-1, k, A + 1, B, !turn)) {
//                return true;
//            }
//        }else {
//            if (back(s.erase(0, 1), n-1, k, A, B, !turn)) {
//                return true;
//            }
//        }
//        s.insert(0, 1, temp);
//        temp=s[n-1];
//        if(temp=='V') {
//            if (back(s.erase(0, 1), n-1, k, A + 1, B, !turn)) {
//                return true;
//            }
//        }else{
//            s.insert(0, 1, temp);
//            if (back(s.erase(0, 1), n-1, k, A, B , !turn)) {
//                return true;
//            }
//        }
//    }
//    else{
//        if(temp=='V') {
//            if (back(s.erase(0, 1), n-1, k, A, B+1, !turn)) {
//                return true;
//            }
//        }else {
//            if (back(s.erase(0, 1), n-1, k, A, B, !turn)) {
//                return true;
//            }
//        }
//        s.insert(0, 1, temp);
//        temp=s[n-1];
//        if(temp=='V') {
//            if (back(s.erase(0, 1), n-1, k, A, B+1, !turn)) {
//                return true;
//            }
//        }else{
//            s.insert(0, 1, temp);
//            if (back(s.erase(0, 1), n-1, k, A, B , !turn)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}

//int main(){
//    int n,k;
//    std::string s;
//    std::cin>>n>>k;
//    std::cin>>s;
//    int A=0,B=0;
//    if(back(s,n,k,A,B,true)){
//        std::cout<<"yes"<<std::endl;
//    }else{
//        std::cout<<"no"<<std::endl;
//    }
//    return 0;
//}
//


//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    string s;
//    cin >> s;
//    while(int ){
//
//    }
//    return 0;
//}