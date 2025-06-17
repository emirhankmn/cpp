# 📘 C++ Module 08 – Templated Containers, Iterators, Algorithms

Bu modülde, STL’in gücünü kullanarak **şablon (template)** tabanlı fonksiyonlar ve sınıflar yazmayı, **iterator** kullanarak container’lar üzerinde işlem yapmayı ve **hazır algoritmalarla** kodu sadeleştirmeyi öğrendik.

---

## 🔍 Temel Kavramlar

### 🔢 `std::vector` ve Diğer STL Container’ları

STL (Standard Template Library), C++’ta veri saklamak için birçok hazır yapı sunar. Bunlardan bazıları:

* `std::vector<T>`: Dinamik dizi. Hızlı erişim, sona veri eklemek hızlıdır.
* `std::list<T>`: Çift bağlı liste. Araya veri eklemek/silmek kolaydır, ama rastgele erişim yavaştır.
* `std::deque<T>`: Çift uçlu sıra. Baştan ve sondan hızlı erişim sağlar.

Hepsi STL container’dır ve `iterator` desteği sunar.

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

Iterator’lar sadece container’larda gezinmek için değil, daha birçok işlev için kullanılır:

* ✅ **STL algoritmalarıyla birlikte çalışma:**

  * `std::find`, `std::sort`, `std::copy`, `std::for_each`, `std::remove`, `std::reverse` gibi algoritmalar iterator ile çalışır.

* ✅ **Tüm container türleriyle uyumlu çalışma:**

  * `vector`, `list`, `map`, `set`, `deque` gibi yapılarda ortak gezinti sağlar.

* ✅ **İleri/geri gezinme:**

  * `iterator`, `const_iterator`, `reverse_iterator` gibi türlerle farklı yönlerde ve modlarda gezinilebilir.

* ✅ **Özelleştirilmiş veri yapılarında kullanma:**

  * Kendi sınıflarına STL benzeri erişim özellikleri kazandırmak için iterator tanımlayabilirsin.

* ✅ **Okuma ve yazma işlemleri için kontrol:**

  * `iterator` (okuma + yazma), `const_iterator` (sadece okuma), `reverse_iterator` (container’ı tersten gezmek için), `back_inserter` (container’a ekleme yapma) gibi özelleşmiş iterator türleri vardır.

---

## ✅ ex00 – Easy Find

### 🎯 Amaç

STL container’ları içinde **verilen bir değeri bulmaya çalışan** bir `easyfind` fonksiyonu yazmak.

### ⚖️ Nasıl yaptık?

* `template<typename T>` ile yazdık, böylece **her tür container** ile kullanılabilir oldu (`vector`, `list`, `deque`, vs.).
* `std::find()` algoritmasını kullandık (STL <algorithm> başlığında yer alır; belirli bir değeri bir iterator aralığında arar ve bulursa iterator, bulamazsa `end()` döner).
* Eğer değer bulunamazsa `std::runtime_error` fırlattık.
* `typename T::const_iterator` tipini kullandık çünkü iterator tipi template içinde açıkça belirtilmelidir.

### 📌 Örnek

```cpp
std::vector<int> v = {1, 2, 3, 4};
easyfind(v, 3);  // ✅ bulundu
easyfind(v, 99); // ❌ exception
```

---

## ✅ ex01 – Span

### 🎯 Amaç

Bir sınıf (`Span`) yazarak:

* Sabit sayıda tamsayı saklamak
* **En kısa ve en uzun iki sayı farkını** (span) hesaplamak
* Çok sayıda sayı eklemeyi desteklemek (iterator aralığı)

### ⚖️ Nasıl yaptık?

* `addNumber(int)` ile tek tek sayılar eklendi.
* `addNumber(Iterator begin, Iterator end)` ile **çoklu sayı ekleme** sağladık.

Bu, container tabanlı veri kaynaklarından (örneğin `std::vector`, `std::list`) tek tek `addNumber(int)` çağırmak yerine **bir aralıktaki tüm elemanları tek seferde eklememizi** sağlar. STL'de bu tür toplu eklemeler `insert()` gibi fonksiyonlarla yapılır.

Fonksiyonun içi şu şekildedir:

```cpp
template<typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    if (_numbers.size() + std::distance(begin, end) > _maxSize)
        throw std::runtime_error("Too many elements to add.");
    _numbers.insert(_numbers.end(), begin, end);
}
```

### Nasıl çalışıyor?

* `std::distance(begin, end)` → Kaç eleman geleceğini hesaplar.
* `_numbers.size()` + bu sayı, kapasiteyi (`_maxSize`) aşıyorsa hata fırlatır.
* Ardından, `insert()` ile tüm değerleri `_numbers` vektörünün sonuna ekler.

### Örnek kullanım:

```cpp
std::vector<int> nums = {1, 2, 3, 4};
Span sp(10);
sp.addNumber(nums.begin(), nums.end()); // topluca 4 sayı eklenir
```

* Bu fonksiyon `template` olarak tanımlandı ve `.hpp` içinde yazıldı.
* `std::distance()` ile kaç eleman geleceği hesaplandı, `insert()` ile eklendi.
* `shortestSpan()` içinde `std::sort()` sonrası komşu farklar incelendi.
* `longestSpan()` içinde `std::min_element()` ve `std::max_element()` ile uç fark alındı.

### 🧠 Öğrendiğimiz Nokta

* `iterator` kavramı sayesinde her tür container ile **genel çözümler** yazabildik.
* STL algoritmaları kodu kısalttı, sadeleştirdi.

---

## ✅ ex02 – MutantStack

### 🎯 Amaç

STL’deki `std::stack` yapısı **iterator desteklemez**. Biz bu sınıftan türeyen (`inherit`) bir sınıf (`MutantStack`) yazarak onu **gezilebilir hale** getirdik.

### ⚖️ Nasıl yaptık?

* `std::stack<T>`'den kalıtım aldık: `class MutantStack : public std::stack<T>`
* Stack’in içindeki container olan `this->c` üzerinden `begin()` ve `end()` fonksiyonlarını ekledik.
* `typedef typename std::stack<T>::container_type::iterator` ile iterator tipi tanımladık.
* Artık `for` döngüsüyle stack içeriği gezilebilir hale geldi.

### 📌 Örnek

```cpp
MutantStack<int> m;
m.push(1);
m.push(2);
m.push(3);

for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
    std::cout << *it << std::endl;
```

> Normal `std::stack` ile bu yapılamazdı!

---

## 🔚 Genel Kazanımlar

* `template` ve `iterator` kullanarak **esnek, yeniden kullanılabilir kodlar** yazmayı öğrendik.
* STL’in sunduğu `algorithm`, `vector`, `deque` gibi yapıları verimli şekilde kullandık.
* `const_iterator`, `std::distance`, `std::sort`, `std::find` gibi STL araçlarını etkin şekilde uyguladık.
