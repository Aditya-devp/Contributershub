#include <iostream>

int Custom_max(int a,int b) {
    if (a>b){
        return a;
    }
    return b;
}

int main() {
    // longest arithmetic sum
    int n;
    std::cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    int ans = 2;
    int pd = a[1]-a[0];
    int j =2;
    int curr = 2;

    while(j<n){
        if (pd==a[j]-a[j-1]){
            curr++;
        }
        else{
            pd = a[j]-a[j-1];
            curr =2;
        }
        ans = std::max(ans,curr);
        j++;
    }
    std::cout << ans << std::endl;

   //subarrays
//    int n;
//    std::cin >> n;
//    int a[n];
//    for (int i =0;i<n;i++){
//        std::cin >> a[i];
//    }
//    std::cout << "working of program" << std::endl;
//    int cur = 0 ;
//    for (int i =0;i<n;i++){
//        cur = 0;
//        for(int j=i;j<n;j++){
//            cur += a[j];
//            std::cout << cur << std::endl;
//        }
//    }
// calculate max till i
//    std::cout << "enter size of arrays";
//    int n;
//    std::cin >> n;
//    int arr[n];
//    for(int i=0;i<n;i++){
//        std::cin >> arr[i];
//    }
// //
//    int max = 0;
//    for(int i=0;i<n;i++) {
//        max = Custom_max(arr[i],max);// here we defined own function but we can used std::max;
//        std::cout << max << std::endl;
//    }
    return 0;
}