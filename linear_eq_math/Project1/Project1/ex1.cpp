//#include <iostream>
//#include <ctime>
//using namespace std;
//
//const int SIZE = 10;
//int arr1[SIZE];
//int arr2[SIZE];
//
//template <class A>
//A MidVal(A a, A b) {
//    return (a + b) / 2;
//}
//
//double MidArr(const int arr[], int size) {
//    int sum = 0;
//    for (int i = 0; i < size; ++i)
//        sum += arr[i];
//    return (double)sum / size;
//}
//
//double MidBoth(const int arr1[], const int arr2[], int size) {
//    int sum = 0;
//    for (int i = 0; i < size; ++i)
//        sum += arr1[i] + arr2[i];
//    return (double)sum / (size * 2);
//}
//
//int main() {
//    srand(time(NULL));
//
//    for (int i = 0; i < SIZE; ++i) {
//        arr1[i] = rand() % 10 + 1;
//        arr2[i] = rand() % 10 + 1;
//    }
//
//    cout << "array 1: ";
//    for (int i = 0; i < SIZE; ++i)
//        cout << arr1[i] << ' ';
//    cout << '\n';
//
//    cout << "array 2: ";
//    for (int i = 0; i < SIZE; ++i)
//        cout << arr2[i] << ' ';
//    cout << '\n';
//
//    cout << "Middle from them: ";
//    for (int i = 0; i < SIZE; ++i)
//        cout << MidVal(arr1[i], arr2[i]) << ' ';
//    cout << '\n';
//
//    cout << "Mid arr1: " << MidArr(arr1, SIZE) << '\n';
//    cout << "Mid arr2: " << MidArr(arr2, SIZE) << '\n';
//    cout << "Mid both: " << MidBoth(arr1, arr2, SIZE) << '\n';
//
//    return 0;
//}