//#include <algorithm>
//#include "iostream"
//#include "vector"
//using namespace std;
//
//int main(){
//    int n,k;
//    cin>>n>>k;
//    vector<long long> a(n),b(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        cin >> b[i];
//    }
//    long long ignore[k];
//    long long x=0;
//    long long max=0;
//    for (int j = 0; j < n; j++) {
//        if(max<=abs(a[j] - b[j])){
//            max=abs(a[j] - b[j]);
//            ignore[x]=j;
//            x=(x+1)%k;
//        }
//    }
//    for(int i=0;i<k;i++){
//        a.erase(a.begin()+ignore[i]);
//        b.erase(b.begin()+ignore[i]);
//    }
//    vector<int> diff(n-k);
//    for (int i = 0; i < n-k; ++i) {
//        diff[i] = a[i] - b[i];
//    }
//    //找差值的中值
//    sort(diff.begin(), diff.end());
//    long long add=diff[(n-k)/2];
//    long long res=0;
//    for (int j = 0; j < n-k; j++) {
//        res += abs(a[j] - (b[j]+add));
//    }
//    cout<<res;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long calculate(vector<long long>& sum, int l, int r, vector<long long>& diff) {
    int mid = (r + l) / 2;
    long long stand = diff[mid];
    long long total = 0;
    total += stand * (mid - l + 1) - sum[mid + 1] + sum[l];
    total += sum[r + 1] - sum[mid + 1] - stand * (r - mid);
    return total;
}

//int main() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n), b(n);
//    vector<long long> diff(n);
//    for(int i = 0; i < n; i++){
//        cin >> a[i];
//    }
//    for(int i = 0; i < n; i++){
//        cin >> b[i];
//    }
//    for(int i = 0; i < n; i++){
//        diff[i] =a[i] - b[i];
//    }
//    sort(diff.begin(), diff.end());
//    vector<long long> sum(n + 1);
//    for(int i = 1; i <= n; i++){
//        sum[i] = sum[i - 1] + diff[i - 1];
//    }
//    long long res = LLONG_MAX;
//    int len = n - k;
//    for(int i = 0; i + len - 1 < n; i++){
//        res = min(calculate(sum, i, i + len - 1, diff), res);
//    }
//    cout << res;
//    return 0;
//}

#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr, int n) {
    int d =n/2;
    while(d>0){
        for(int i=d;i<n;i++){
            if(arr[i]<arr[i-d]){
                int temp=arr[i];
                int j=i-d;
                do {
                    arr[j+d]=arr[j];
                    j-=d;
                } while(j>=0&&arr[j]>temp);
                arr[j+d]=temp;
            }
        }
        for (int i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        d/=2;
    }
}

// 对换法
int partition1(std::vector<int>& arr, int low, int high) {
    cout<<low<<" "<<high<<endl;
    int x=low+(high-low)/2;
    swap(arr[x],arr[low]);
    int base=arr[low];
    int i=low,j=high;
    while(i<j){
        while(i<j&&arr[j]>base){
            j--;
        }
        while(i<j&&arr[i]<=base){
            i++;
        }
        if(i<j){
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[low],arr[i]);
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return i;
}

// 轮换法
int partition2(std::vector<int>& arr, int low, int high) {
    cout<<low<<" "<<high<<endl;
    int base=arr[low];
    int i=low,j=high;
    while(i<j){
        while(i<j&&arr[j]>base){
            j--;
        }
        if(j>i){
            arr[i]=arr[j];
            i++;
        }
        while(i<j&&arr[i]<=base){
            i++;
        }
        if(i<j){
            arr[j]=arr[i];
            j--;
        }
    }
    arr[i]=base;
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return i;
}


void quickSort(std::vector<int>& arr, int low, int high, int (*partition)(std::vector<int>&, int, int)) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1, partition);
        quickSort(arr, pivot + 1, high, partition);
    }
}

void radixSort(std::vector<int>& arr) {
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int exp = 1;
    std::vector<int> temp(arr.size());

    while (maxVal / exp > 0) {
        std::vector<int> bucket(10);

        for (int i = 0; i < arr.size(); i++)
            bucket[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        for (int i = arr.size() - 1; i >= 0; i--)
            temp[--bucket[(arr[i] / exp) % 10]] = arr[i];

        for (int i = 0; i < arr.size(); i++)
            arr[i] = temp[i];

        exp *= 10;
        for (int i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

}
int main() {
    std::vector<int> arr = {123,35,6,27,289,41,50,378,692,614,77,861};
    radixSort(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
//int main() {
//    std::vector<int> arr = {46, 79, 66, 38, 40, 84, 40, 65};
////    quickSort(arr, 0, arr.size(), partition1); // 第一趟排序
//    for (int i : arr) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//    return 0;
//}

