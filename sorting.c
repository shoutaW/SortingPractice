#include <stdio.h>
#include <stdlib.h>

// ソートアルゴリズムの関数プロトタイプ宣言
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int n);

int main() {
    int n, choice;
    printf("要素数を入力してください: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int)); // 動的配列の確保

    printf("要素を入力してください:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n使用するソートアルゴリズムを選択してください:\n");
    printf("1. バブルソート\n2. 選択ソート\n3. クイックソート\n");
    printf("番号を入力: ");
    scanf("%d", &choice);

    // 選択されたソートアルゴリズムを実行
    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("バブルソートで整列しました:\n");
            break;
        case 2:
            selectionSort(arr, n);
            printf("選択ソートで整列しました:\n");
            break;
        case 3:
            quickSort(arr, 0, n-1);
            printf("クイックソートで整列しました:\n");
            break;
        default:
            printf("無効な選択です。\n");
            free(arr); // メモリ解放
            return 1;
    }

    printArray(arr, n); // 結果を表示
    free(arr); // メモリ解放
    return 0;
}

// バブルソート
void bubbleSort(int arr[], int n) {
    // 配列の末尾に向かって隣接要素を比較し、順番が逆なら交換
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// 選択ソート
void selectionSort(int arr[], int n) {
    // 未整列部分から最小値を見つけ出し、先頭と交換
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// クイックソート
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high); // ピボットのインデックス
        quickSort(arr, low, pi-1);  // ピボットより左側を再帰的にソート
        quickSort(arr, pi+1, high); // ピボットより右側を再帰的にソート
    }
}

// 配列を分割し、ピボットの位置を返す関数
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 配列の最後の要素をピボットとする
    int i = low-1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

// 配列を表示する関数
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
