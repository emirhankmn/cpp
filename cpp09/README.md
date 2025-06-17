# C++ Module 09 - STL (Standard Template Library)

Bu proje, C++98 standardında STL container'larını kullanarak üc farklı algoritma ve veri yapısı uygulamasını içerir. Her exercise farklı bir STL container kullanır ve gerçek dünya problemlerini çözer.

---

## 📋 İçindekiler

* [Genel Bilgiler](#genel-bilgiler)
* [Exercise 00: Bitcoin Exchange](#exercise-00-bitcoin-exchange)
* [Exercise 01: Reverse Polish Notation](#exercise-01-reverse-polish-notation)
* [Exercise 02: PmergeMe](#exercise-02-pmergeme)
* [Kurulum ve Çalıştırma](#kurulum-ve-çalıştırma)
* [Test Örnekleri](#test-örnekleri)
* [Teknik Detaylar](#teknik-detaylar)
* [Sonuç](#sonuç)
* [Kavramlar](#kavramlar)

---

## 🎯 Genel Bilgiler

### Amaç

C++ STL container'larının farklı kullanım senaryolarını öğrenmek ve gerçek dünya problemlerini çözmek.

### Kullanılan STL Container'lar

* **Exercise 00**: `std::map`
* **Exercise 01**: `std::stack`
* **Exercise 02**: `std::vector`, `std::deque`

### Gereksinimler

* C++98 standard uyumluluğu
* Orthodox Canonical Form
* Robust error handling
* Memory leak prevention

### Sistem Gereksinimleri

* GCC 4.8+ veya C++98 destekleyen derleyici
* Unix/Linux terminal ortamı (WSL, macOS Terminal vb.)

---

## 💰 Exercise 00: Bitcoin Exchange

Bitcoin fiyat veritabanını kullanarak belirli tarihlerdeki Bitcoin değerlerini hesaplar.

### Özellikler

* CSV format veritabanı okuma
* Tarih validasyonu (YYYY-MM-DD)
* En yakın tarih bulma (`lower_bound`)
* 0-1000 aralığında değer kontrolü

### Container

`std::map<std::string, double>`

### Algoritma

1. CSV dosyasını `map`'e yüle
2. Her input satırını kontrol et
3. En yakın tarihi bul ve hesapla

### Dosya Yapısı

```
ex00/
├── Makefile
├── main.cpp
├── BitcoinExchange.hpp
├── BitcoinExchange.cpp
├── data.csv
└── input.txt
```

---

## 🧲 Exercise 01: Reverse Polish Notation

RPN (Ters Polonya Notasyonu) ile matematiksel ifadeleri hesaplar.

### RPN Nedir?

* Normal: `(1 + 2) * 3`
* RPN: `1 2 + 3 *`

### Özellikler

* Tek haneli sayılar (0-9) ⚠️ `12` gibi sayılar desteklenmez
* +, -, \*, / operatörleri
* Stack tabanlı hesaplama

### Container

`std::stack<int>`

### Algoritma

1. Token'lara ayır
2. Sayıysa push, operatörse pop ve hesapla
3. Stack'te kalan son değer sonucu verir

### Dosya Yapısı

```
ex01/
├── Makefile
├── main.cpp
├── RPN.hpp
└── RPN.cpp
```

---

## 🔄 Exercise 02: PmergeMe

Ford-Johnson Merge-Insertion sort algoritmasını iki farklı container ile uygular ve performanslarını kıyaslar.

### Özellikler

* 3000+ eleman desteği
* `vector` vs `deque` performans kıyaslaması
* Duplicate kontrolü
* Microsecond precision

### Container'lar

* `std::vector<int>` - contiguous memory, cache-friendly
* `std::deque<int>` - flexible double-ended queue

### Algoritma Karşılaştırması

| Özellik             | Vector     | Deque         |
| ------------------- | ---------- | ------------- |
| Memory Layout       | Contiguous | Chunked       |
| Random Access       | O(1)       | O(1)          |
| Insert/Delete       | O(n)       | O(1) uçlardan |
| Cache Performance   | Daha iyi   | Daha kötü     |
| Memory Reallocation | Var        | Az            |

### Dosya Yapısı

```
ex02/
├── Makefile
├── main.cpp
├── PmergeMe.hpp
└── PmergeMe.cpp
```

---

## 🚀 Kurulum ve Çalıştırma

```bash
make        # Derleme
make clean  # Objeleri temizle
make fclean # Her şeyi temizle
make re     # Temizle & yeniden derle
```

---

## 🧪 Test Örnekleri

### Bitcoin Exchange

```bash
echo "date,exchange_rate\n2011-01-03,0.3\n2012-01-11,7.1" > data.csv
echo "date | value\n2011-01-03 | 3\n2012-01-11 | 1" > input.txt
./btc input.txt
```

**Beklenen:**

```
2011-01-03 => 3 = 0.9
2012-01-11 => 1 = 7.1
```

### RPN

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  # 72 -> 63 -> 54 -> 45 -> 41 -> 42
./RPN "7 7 * 7 -"                 # 49 - 7 = 42
./RPN "1 2 * 2 / 2 * 2 4 - +"     # Sonuç: 0
```

**Hata Testleri:**

```bash
./RPN "(1 + 1)"       # Syntax hatası
./RPN "1 +"           # Yetersiz operand
```

### PmergeMe

```bash
./PmergeMe 3 5 9 7 4
./PmergeMe $(seq 1 3000 | shuf | tr '\n' ' ')
./PmergeMe -1 5        # Hata: negatif
./PmergeMe abc 123     # Hata: numeric olmayan input
```

**Beklenen:**

```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process... (vector & deque)
```

---

## 🛠 Teknik Detaylar

### Orthodox Canonical Form

```cpp
ClassName();
ClassName(const ClassName& other);
ClassName& operator=(const ClassName& other);
~ClassName();
```

### Error Handling

* Dosya erisimi
* Tarih/sayi kontrolü
* Stack underflow / invalid RPN
* Negatif veya geçersiz input

### Performans ve Optimizasyon

* Hybrid sort (Insertion + Merge)
* Cache avantajlı container kullanımı
* STL ile bellek yönetimi

### Bellek Yönetimi

* RAII
* STL container'lar ile temiz yönetim
* Raw pointer yok, leak yok

---

## 🎓 Sonuç

Bu module, STL container'ların farklı problem türlerine nasıl uyum sağladığını gösterir. Veri yapısı seçimi ve algoritma uyumu, performans ve kod kalitesi için kritik öneme sahiptir.

---

## 📚 Kavramlar

1. **STL Container Kullanımı**: `map`, `stack`, `vector`, `deque` gibi yapılarla pratik uygulama
2. **Algoritma Tasarımı**: Merge-Insertion sort gibi hibrit yaklaşımlar
3. **Performans Kıyaslaması**: Farklı container'ların zaman ve bellek performanslarının test edilmesi
4. **Hata Yönetimi**: Dosya, input ve işlem hataları için sağlam kontrol mekanizmaları
5. **C++98 Standartları**: Modern C++'tan farklı olarak sınırlı özelliklerle kodlama pratiği
6. **Bellek Güvenliği**: RAII ve STL konteynerleri sayesinde bellek sızıntısı olmadan çalışma
7. **Orthodox Canonical Form**: 4 temel C++ sınıf fonksiyonunun uygulanması

---

*Bu proje 42 School C++ Module 09 gereksinimlerini karşılar ve eğitim amacıyla hazırlanmıştır.*
