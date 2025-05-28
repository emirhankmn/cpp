C++ Module 07 - Templates

Bu modülde, C++ dilinde farklı türlerle çalışabilen esnek ve yeniden kullanılabilir fonksiyonlar ile sınıfların nasıl yazıldığını öğrenmek amaçlanmaktadır. Bunu gerçekleştirmek için template (kalıp) yapılarından faydalanıyoruz.

✨ Temel Kavramlar

Bu modül, C++ dilinde template (kalıp) mantığını kavramamızı sağlamak için hazırlandı. Template yapısı sayesinde farklı veri türleriyle çalışan, türden bağımsız fonksiyonlar ve sınıflar geliştirilebilmektedir.

🔤 Kullanılan Temel Kavramlar:

template: Bu ifade, fonksiyonun veya sınıfın 'T' adında bir tür parametresiyle çalışacağını belirtir. 'T' burada bir yer tutucu tür (placeholder type) olarak görev yapar. Örneğin, swap<int>() çağrıldığında T → int olur.

typename vs. class: template<typename T> ve template<class T> aynı anlama gelir. Her ikisi de bir tür parametresi tanımlar.

const T&: Değişkenin sabit olduğunu ve kopya yerine referansla işlendiğini gösterir. Performans artışı sağlar.

operator[]: Bir sınıfı dizi gibi kullanılabilir hale getirir. Örn: myArray[2] çağrısını mümkün kılar.

deep copy (derin kopya): Kopyalanan nesnelerin bellekte aynı adresi paylaşmaması. Yani biri değiştiğinde diğeri etkilenmez.

exception: Hatalı durumlarda (örneğin geçersiz indeks erişimi) programı güvenli biçimde durdurmak için kullanılan yapı.
kavramamızı sağlamak için hazırlandı. Template yapısı sayesinde farklı veri türleriyle çalışan, türden bağımsız fonksiyonlar ve sınıflar geliştirilebilmektedir. Bu modülde 3 egzersiz boyunca bu mantığın nasıl kullanılacağı uygulamalı şekilde gösterilmektedir.

🔖 Genel Kurallar

Derleyici: c++

Derleme bayrakları: -Wall -Wextra -Werror -std=c++98

STL (vector, map, algorithm vs.) kullanımı yasaktır.

printf, malloc, free, using namespace, friend kullanımı yasaktır.

Tüm sınıflar Orthodox Canonical Form'da yazılmalıdır.

🔧 ex00 – Türden Bağımsız Fonksiyonlar

Bu egzersizde, swap, min, max gibi işlemleri her türle (int, string, float...) çalışabilir şekilde tanımlamayı hedefliyoruz. Yani bir işlemi birden fazla veri türüyle yeniden yazmadan kullanabilmek için template yapılarından faydalanıyoruz.
gibi işlemleri tüm türlerle çalışabilir şekilde yazmak.

Yaptıklarımız:

template<typename T> ile üç ayrı fonksiyon yazdık.

swap() iki değişkenin yerini değiştirir.

min() ve max() karşılaştırma yaparak uygun değeri döndürür.

Hem int, hem std::string gibi farklı türlerle test ettik.

Neden Önemli:

Aynı işlevi tekrar tekrar yazmak yerine tek bir şablonla çok türü desteklemek.

Gerçek hayatta karşılaştırma/sıralama gibi işlemlerde kullanılır.

Teknik Kazanım:

Template fonksiyon yazımı

const & ile referans üzerinden çalışmak

Kod tekrarını önleyerek esneklik kazanmak

🔁 ex01 – iter() Fonksiyonu

Bu egzersizde, bir dizinin her elemanına aynı işlemi uygulayabilecek şekilde genel ve tekrar kullanılabilir bir fonksiyon yazmayı hedefliyoruz. Yani örneğin print() gibi bir fonksiyonu dizi içindeki her elemana otomatik olarak uygulamak istiyoruz.
aynı işlemi uygulayan genel bir fonksiyon yazmak.

Yaptıklarımız:

template<typename T> ile iter fonksiyonunu yazdık.

Parametre olarak: dizi adresi, uzunluğu ve işlem fonksiyonu alır.

Örneğin: iter(arr, 3, print) → her arr[i] için print() çağrılır.

Neden Önemli:

Belirli bir işlemi çok sayıda veriye uygulamak için soyutlama sağlar.

Gerçek dünyada her eleman için log yazmak, dönüştürme yapmak gibi işlemler için kullanılır.

Teknik Kazanım:

Fonksiyon pointer’ı mantığı

Template + davranış soyutlaması

Kapsamlı test ile çok türle çalışabildiğini görme

📦 ex02 – Array<T> Template Sınıfı

Bu egzersizde, std::vector gibi hazır yapılar kullanmadan kendi dinamik array sınıfımızı yazarak hem bellek yönetimini hem de template sınıf mantığını uygulamalı şekilde öğrenmeyi hedefliyoruz.
, türden bağımsız ve güvenli bir dinamik dizi yapısı tasarlamak.

Yaptıklarımız:

template<class T> ile Array sınıfı tanımladık.

Parametreli constructor ile varsayılan değerlerle dizi oluşturduk.

operator[] ile eleman erişimi sağladık, sınır dışı erişimde exception fırlattık.

Deep copy desteği için copy constructor ve operator= tanımladık.

Neden Önemli:

Kendi vector benzeri yapımızı yazmak, template sınıf anlayışını oturtmak.

Gerçek hayatta generic veri yapılarının temelini anlamak.

Teknik Kazanım:

Template class yapımı

Bellek yönetimi (new[], delete[])

Exception-safe operatör tanımlama

Derin kopyalama kavramı

🥈 Genel Kazanımlar

C++'ta template fonksiyonlar ve template sınıflar yazmayı öğrendik.

Fonksiyon pointer'ı mantığını, iter() gibi soyut yöntemlerle uygulamayı kavradık.

Bellek yönetimi, exception handling, derin kopyalama gibi ileri C++ kavramlarını pratik ettik.

STL kullanmadan array mantığını baştan kendimiz kurduk.

Bu modül, STL öncesinde C++ template yapısına alışmak için sağlam bir temel sundu.