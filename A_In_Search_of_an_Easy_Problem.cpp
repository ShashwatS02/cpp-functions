#include<iostream>
int main(){
    int t, n;
    std::cin >> t;
    while(t--){
        std::cin >> n;
        if(n==1){
            std::cout << "HARD\n";
            return 0;
        }
    }
    std::cout << "EASY\n";
}
