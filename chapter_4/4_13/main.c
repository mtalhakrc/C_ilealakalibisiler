//
// Created by Talha Karaca on 13.10.2023.
//

//Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
//string s in place.

void func1();
void func2();

#include <stdio.h>
void reverse(char s[]);
int main(){
    char s[] = "talha";
    //func1();
    //func1();
    reverse(s);
    printf("%s\n",s);
}

void func1(){
    static int stint = 0;
    stint += 10;
    return;
}

void func2(){
    static int stint;
    stint += 10;
    return;
}

// NOT: bir önceki örnekte sürekli olarak recursive fonksiyon içine automatic var gönderiyordun. bir diğer yaklaşım ise static variableler ile durum kontrollerini yönetip recursive bir yapı kurmak
void reverse(char str[]){
    static int i = 0; // bu fonksiyon çağrısı boyunca hiçbir çağrıda sıfırlanmıyor.
    static int j = 0; // çok iyi lan oha.

    if (str[i] != '\0'){
        char c = str[i++];
        reverse(str);

        str[j++] = c;
    }
}

/*
 *  NOTLAR:
 *  Static Fonksiyonlar: "static" keywordü ile tanımlanan fonksiyonlar, yalnızca aynı kaynak dosyasındaki kod tarafından çağrılabilirler. Diğer kaynak dosyalarından erişilemezler. Bu, fonksiyonun kapsamını sınırlar ve daha fazla gizlilik sağlar
 *
 * Static Değişkenler: "static" keywordü ile tanımlanan değişkenler, programın yaşam döngüsü boyunca bellekte sürekli olarak saklanır ve programın çalıştırılması sırasında sadece bir kez başlatılır. Bu değişkenler, ilgili fonksiyonun dışında da erişilebilirler ve her çağrıda değerlerini korurlar
 * ve static değişkenler tanımlandığı fonksiyona özgü olurlar.
 *
 * Static Global Değişkenler: "static" keywordü ile tanımlanan global değişkenler, yalnızca tanımlandıkları kaynak dosya içinde erişilebilirler. Diğer kaynak dosyalarından erişilemezler. Bu, global değişkenlerin diğer dosyalarla çakışmasını önler.

 */

