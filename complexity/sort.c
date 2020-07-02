#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 15000 //乱数で得られる値の最大値
void selection(int *, int);
void merge(int *, int, int);

int *B; // mergesortで必要となる外部領域

/*時間計測関数の外部参照（以降の演習も以下３行はコピー＆ペーストする*/
extern void start_timer(unsigned int *);
extern unsigned get_elapsed_time(unsigned int *);
extern unsigned int start_tm;
/*いつもコピーする部分ここまで*/

int main(int argc, char *argv[])
{
    int i, n, t;
    int *A;

    if (argc != 2)
    { //データサイズが引数として与えられていない
        fprintf(stderr, "Error: argument which indicates the problem size is required.\n");
        exit(1);
    }

    n = atoi(argv[1]);

    A = (int *)malloc(sizeof(int) * (n + 1));
    B = (int *)malloc(sizeof(int) * (n + 1));

    // rand関数でデータを初期化（現状はこのまま使ってよい）
    srand(n);
    for (i = 1; i <= n; i++)
    {
        t = rand();
        if (t < MAX_VALUE)
        {
            A[i] = t;
        }
        else
        {
            A[i] = t % MAX_VALUE;
        }
#ifdef DEBUG
        printf(" A[%5d] = %5d \n", i, A[i]);
#endif
    }
    //データ初期化ここまで

    start_timer(&start_tm); //時間計測開始

    //selection(A, n); //selection sort
    merge(A, 1, n); // merge sort

    // タイマーを止めて、計測時間を表示（今回はこのまま使ってもよい。今後必要に応じて、関数呼出の切り分け等をすること）
    printf("%5d : elapsed time is %10.3f milliseconds. \n", n, get_elapsed_time(&start_tm) * 1.0e-3);

#ifdef DEBUG
    for (i = 1; i <= n; i++)
    {
        printf(" A[%5d] = %5d \n", i, A[i]);
    }
#endif

    free(A);
    free(B);

    return 0;
}

// selection sortの本体
void selection(int *A, int n)
{

    int i, j, min, t;

    for (i = 1; i < n; i++)
    {

        min = i;

        for (j = i + 1; j <= n; j++)
        {

            if (A[j] < A[min])
            {
                min = j;
            }
        }

        t = A[min];
        A[min] = A[i];
        A[i] = t;
    }
}

//再帰版merge sortの本体
void merge(int *A, int left, int right)
{
    //退避用の外部変数はB[]を使う。(既に宣言済み)

    int i, j, k, mid;
    if (right > left)
    {

        mid = (right + left) / 2;

        merge(A, left, mid);
        merge(A, mid + 1, right);

        for (i = left; i <= mid; i++)
        {
            B[i] = A[i];
        }

        for (i = mid + 1, j = right; i <= right; i++, j--)
        {
            B[i] = A[j];
        }

        i = left;
        j = right;

        for (k = left; k <= right; k++)
        {

            if (B[i] < B[j])
            {
                A[k] = B[i++];
            }
            else
            {
                A[k] = B[j--];
            }
        }
    }
}