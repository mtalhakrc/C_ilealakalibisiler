
#include <stdio.h>
#define TRUE 1
#define FALSE !TRUE

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* numbers = (int*)malloc(5 * sizeof(int)); // İlk olarak, 5 elemanlık bir int array'ı için bellekte yer ayırıyoruz

    // Diziyi elemanlarına erişerek ve atayarak kullanabiliriz
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    printf("sizeof: %lu\n", sizeof(&numbers[0]));

    // Önceki array'ı yeni boyutlu bir array'a taşıyoruz
    int new_size = 10;
    int* new_numbers = (int*)realloc(numbers, new_size * sizeof(int));

    if (new_numbers != NULL) {
        // Yeni elemanları ayarlıyoruz
        new_numbers[5] = 60;
        new_numbers[6] = 70;
        new_numbers[7] = 80;
        new_numbers[8] = 90;
        new_numbers[9] = 100;

        // Dizinin elemanlarını yazdırıyoruz
        for (int i = 0; i < new_size; i++) {
            printf("%d ", new_numbers[i]);
        }

        free(new_numbers); // Bellekte ayrılan yerleri serbest bırakıyoruz
    } else {
        printf("Bellekte yeterli alan yok!");
    }

    return 0;
}




/*
 * C dilinde assignment (atama) ifadeleri hem bir expression (ifade) hem de bir statement'tır.

Assignment ifadeleri, bir değeri bir değişkene atamak için kullanılır. Örneğin, `x = 5` gibi bir assignment ifadesi, `5` değerini `x` değişkenine atar. Assignment ifadeleri, kendileri de bir değer üretir. Bu değer, atanan değerdir.

Örneğin:

```c
int x = 5;
int y = (x = 10);
```

Yukarıdaki örnekte, `(x = 10)` ifadesi bir assignment ifadesidir. Bu ifade, `10` değerini `x` değişkenine atar ve aynı zamanda bu atanan değeri (`10`) üretir. Bu atanan değer, `y` değişkenine atanır.

Bununla birlikte, assignment ifadeleri aynı zamanda bir statement (ifade) olarak da kullanılabilir. Bir statement olarak kullanıldıklarında, yalnızca atama işlemini gerçekleştirirler ve değer üretmezler. Örneğin:

```c
x = 5;
```

Yukarıdaki örnekte, `x = 5` ifadesi bir assignment statement'tır. Bu ifade, `5` değerini `x` değişkenine atar, ancak kendisi herhangi bir değer üretmez.

Sonuç olarak, assignment ifadeleri C dilinde hem bir expression (ifade) olarak değer üretir hem de bir statement (ifade) olarak kullanılabilir.



 Array değişleninin tuttuğu adres değiştirilebilir mi?
 Evet, doğru. Bir dizi değişkenini, o dizinin 3. elemanına işaret ettiremezsiniz. Dizi değişkeni, yalnızca dizinin başlangıç adresine işaret eder ve bu işaretçi değeri değiştirilemez. Dizinin adresi, dizinin ilk elemanının adresine eşittir ve dizinin elemanları bellekte ardışık olarak saklanır. Dolayısıyla bir dizi değişkeni ile farklı bir dizinin elemanlarına işaret ettirmek mümkün değildir.

 -------

 aşağıdaki iki syntax'ta herhangi bir fark yoktur.
 int withptr(int* arr){
    printf("%d\n", *(arr+1));
    *(arr+1) = 10;
    return 0;
}
int witharr(const int arr[]){
    printf("%d\n", *(arr+1));
    return 0;
};

int main() {
    int deneme[3]  ={1,2,3};
    withptr(deneme);
    witharr(deneme);
}

- when array passed to function, the array size is lost!!
- avoid pointer arithmatic!

int foo(const int array[]){
    printf("%lu\n", sizeof(array));  // burası 8 yazdırır. çünkü bu context'e compiler array'i sadece bir pointer olarak görür.
    return 0;
    //C dilinde array'lar çok ilkeldir. func çağrılarında vs. array lenght vsvs bilgisini kaybeder. ve sadece bir pointer olarak görülür.
}

int main() {
    int array[4];
    foo(array);
    printf("%lu\n", sizeof(array)); //burada ise 16 yazdırır. çünkü compiler bu context'te bu değişkenin bir array olduğunu ve uzunluğunun da 4 olduğunu  bilir
}

 */