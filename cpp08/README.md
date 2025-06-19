# 📘 C++ Module 08 – Templated Containers, Iterators, Algorithms

Bu modülde, STL’in gücünü kullanarak **şablon (template)** tabanlı fonksiyonlar ve sınıflar yazmayı, **iterator** kullanarak container’lar üzerinde işlem yapmayı ve **hazır algoritmalarla** kodu sadeleştirmeyi öğrendik.

---

## 🔍 Temel Kavramlar

### 🔢 `std::vector`, `std::deque`, `std::list` Karşılaştırması

#### `std::vector`

```
[1][2][3][4][5] → → → (Contiguous Memory)
```

* Sona ekleme çok hızlı (`push_back`) ✅
* Rastgele erişim çok hızlı (`v[i]`) ✅
* Başa/ortaya ekleme yavaş ❌
* Bellek kullanımı verimli ✅

#### `std::deque`

```
[ ][ ][1][2][3][4][5][ ][ ] (Çift uçlu bloklu yapı)
```

* Hem başa hem sona hızlı erişim ✅
* Rastgele erişim mümkün (`d[i]`) ⚠️ biraz daha yavaş
* Bellek parçalı olduğundan cache verimliliği düşer ❌

#### `std::list`

```
[1]↔[2]↔[3]↔[4]↔[5] (Çift bağlı liste)
```

* Ortaya/başa/sona ekleme-silme hızlı ✅
* Rastgele erişim yok ❌
* Bellek kullanımı daha ağır ❌

> 📌 Büyük veri setlerinde `vector` genelde daha hızlıdır çünkü bellekte tek blokta tutulur. `deque` ise bloklu yapısı nedeniyle büyük veri işleme süresinde `vector`'e göre daha yavaş olabilir.

---

### 🧭 Iterator Nedir?

Iterator, bir container’daki elemanlar arasında gezinebilmek için kullanılır. Pointer gibi davranır:

* `begin()` → ilk elemanı gösterir
* `end()` → son elemandan sonrayı gösterir (sona geldiğini anlamak için kullanılır)

Örnek:

```cpp
std::vector<int> v = {10, 20, 30};
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
}
```

Bu kod, vektörün tüm elemanlarını sırayla yazdırır.

### 🔧 Iterator Kullanım Alanları

* STL algoritmalarıyla birlikte (`std::sort`, `std::find`, `std::copy`...)
* Tüm container türlerinde ortak erişim için
* `const_iterator`, `reverse_iterator`, `back_inserter` gibi türlerde farklı yönlerde ve farklı amaçlarla gezinme için
* Kendi sınıflarımıza STL tarzı erişim kazandırmak için

---

## ✅ ex00 – Easy Find

### ⚠️ Bilgilendirme:

`std::stack`, `std::map`, `std::set` gibi associative/adapted container'larda `std::find` doğrudan kullanılamaz çünkü bunların içerdiği veri tipi `int` değil, `pair` veya özel yapıdır.

### 📌 Örnek:

```cpp
std::map<int, std::string> myMap;
myMap[3] = "three";
easyfind(myMap, 3); // ❌ pair == int karşılaştırılamaz → derleme hatası
```

Bu nedenle `easyfind` sadece `vector`, `list`, `deque`, `array` gibi iterable container'larla kullanılmalıdır.

---

## ✅ ex01 – Span → Template Neden Kullanıldı?

Fonksiyon tanımı:

```cpp
template<typename Iterator>
void addNumber(Iterator begin, Iterator end);
```

Bu fonksiyon farklı container'ların farklı iterator türleriyle çalışabilsin diye `template` ile yazılmıştır:

| Container Türü | Iterator Tipi                |
| -------------- | ---------------------------- |
| `vector<int>`  | `std::vector<int>::iterator` |
| `list<int>`    | `std::list<int>::iterator`   |
| `deque<int>`   | `std::deque<int>::iterator`  |

Eğer `template` olmasaydı, bu fonksiyonu sadece `vector` ile kullanabilirdik. `template` sayesinde **her container’la tek fonksiyon üzerinden** çalışabiliyoruz.

Ayrıca, `std::distance(begin, end)` kullanımı sayesinde **eklenmek istenen eleman sayısı** önceden hesaplanıp kapasite aşılıp aşılmadığı kontrol ediliyor.

---

## ✅ ex02 – MutantStack

### 🎯 Amaç

STL’deki `std::stack` yapısı **iterator desteklemez**. Biz bu sınıftan türeyen (`inherit`) bir sınıf (`MutantStack`) yazarak onu **gezilebilir hale** getirdik.

### ⚖️ Nasıl yaptık?

* `std::stack<T>`'den kalıtım aldık: `class MutantStack : public std::stack<T>`
* Stack’in içindeki container olan `this->c` üzerinden `begin()` ve `end()` fonksiyonlarını ekledik.
* `typedef typename std::stack<T>::container_type::iterator` ile iterator tipi tanımladık.
* `template` class olduğu için tüm fonksiyonlar `.hpp` içinde yazıldı, bu normlara uygundur.

### 📌 Örnek Kullanım

```cpp
MutantStack<int> m;
m.push(1);
m.push(2);
m.push(3);

for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
    std::cout << *it << std::endl;
```

> Normal `std::stack` ile bu yapılamazdı!

### 🔍 Teknik Detaylar

| Yapı Satırı             | Açıklama                                              |
| ----------------------- | ----------------------------------------------------- |
| `this->c`               | `std::stack`’in iç container’ı (genelde `deque`)      |
| `begin()` / `end()`     | Iterator üzerinden stack içeriğine erişimi sağlar     |
| `typedef ... iterator`  | `stack`’in iç container’ının iterator türünü kullanır |
| `template <typename T>` | Her tür veri tipiyle çalışmayı sağlar                 |

### 🧠 Kazanım

Bu egzersiz ile `container adapter`'ları genişletmeyi, STL’in iç yapısını anlamayı ve `inheritance` + `iterator` birlikteliğini kullanarak özelleştirme yapmayı öğrendik.

---

## 🔚 Genel Kazanımlar

* `template` ve `iterator` kullanarak **esnek, yeniden kullanılabilir kodlar** yazmayı öğrendik.
* STL’in sunduğu `algorithm`, `vector`, `deque` gibi yapıları verimli şekilde kullandık.
* `const_iterator`, `std::distance`, `std::sort`, `std::find` gibi STL araçlarını etkin şekilde uyguladık.

Ek olarak:

* `std::stack` gibi container adapter’ların neden `iterator` desteklemediği
* `template<typename Iterator>` ifadesinin neden yazılması gerektiği (her container’ın `iterator` tipi farklı olduğu için)
* `deque` ile `vector` arasında büyük veri setlerinde neden hız farkı oluştuğu
  konuları da somut örneklerle birlikte açıklandı.

Bu bilgilerle birlikte hem yazdığımız kodun **mantığı**, hem de **C++ STL tasarım prensipleri** üzerine derinlemesine bir kavrayış kazanılmış oldu.

---
