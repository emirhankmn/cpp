# 📦 C++ Module 06 – Tür Dönüşümleri ve Tip Tanıma

Bu modülde **C++ dilindeki tür dönüşümleri (casts)** konusunu detaylıca işliyoruz. Amaç, farklı veri türleri arasında güvenli ve anlamlı dönüşümler yapmayı öğrenmek. Özellikle C++'a özgü üç temel dönüşüm aracı olan:

* `static_cast`: Derleme zamanında yapılan güvenli dönüşümler içindir. Genellikle aritmetik türler veya kalıtım hiyerarşisindeki yukarı doğru dönüşümler için kullanılır.
* `reinterpret_cast`: Düşük seviye, ham veri dönüşümleri için kullanılır. Adresleri, pointer'ları veya veri yapısını başka bir tipe doğrudan çevirmek için uygundur ama dikkatli kullanılmalıdır.
* `dynamic_cast`: Polimorfik sınıflarda, çalışma zamanında nesnenin gerçek türünü kontrol ederek güvenli aşağı dönüşüm (**downcasting**) yapar. **Downcasting**, bir nesneyi `Base*` gibi bir üst sınıf türünden, onun gerçek alt sınıf türüne (örneğin `A*`, `B*`, `C*`) dönüştürme işlemidir. Başarısız olursa `nullptr` (pointer için) veya `std::bad_cast` (referans için) üretir.

Bu araçlarla dilin tipi kontrol mekanizmalarını hem teorik hem pratik açıdan uygulamalı olarak kavrıyoruz.

---

## 🔢 ex00 – ScalarConverter

Bu egzersizde amaç, kullanıcıdan alınan bir string ifadenin (`"42"`, `"a"`, `"42.0f"`, `"nan"` gibi) C++’taki dört temel skaler tipe dönüştürülmesidir:

* `char`
* `int`
* `float`
* `double`

### Bu egzersiyonda:

```cpp
// Örnek pseudo-literal kullanımları:
ScalarConverter::convert("nanf");   // float: nanf, double: nan
ScalarConverter::convert("+inf");   // float: +inff, double: +inf
ScalarConverter::convert("42.0f");  // float: 42.0f, double: 42.0
```

* Literal’in tipi otomatik olarak algılanır.
* Her tipe dönüşüm yapılır ve ekrana yazdırılır.
* `nan`, `inf`, `+inff`, `-inff` gibi pseudo-literal ifadeler tanınır; bunlar C++'ta float ve double türlerinin özel değerleridir. Örneğin, `nan` (Not a Number) matematiksel olarak tanımsız sonuçları ifade ederken, `+inf` veya `-inf` sonsuzluk durumlarını temsil eder.
* Dönüşüm mümkün değilse veya `char` gösterilemezse kullanıcıya bilgi verilir.

### Kazanımlar:

* `static_cast` ile tip dönüşümü yapma

```cpp
int i = 42;
double d = static_cast<double>(i); // int → double
```

* `std::numeric_limits` ile taşma/erişim kontrolleri

```cpp
if (val > std::numeric_limits<int>::max()) {
    std::cout << "int sınırını aşıyor" << std::endl;
}
```

* String’den sayıya dönüşüm (`std::strtol`, `std::strtof` vb.)

```cpp
long l = std::strtol(str.c_str(), NULL, 10);
float f = std::strtof(str.c_str(), NULL);
```

* Formatlı ve hataya dayanıklı çıktı yazımı

---

## 💾 ex01 – Serialization

Bu egzersizde bir pointer’ı **sayısal değere**, sonra tekrar pointer’a çeviriyoruz. Bunu yapmamızın sebebi, bir pointer’ı sadece bellekte tutmak yerine farklı ortamlarda (örneğin log kaydı, ağ iletişimi veya veri depolama) temsil edilebilir ve taşınabilir hale getirmektir. Bu dönüşüm sayesinde adres değeri bir sayıya çevrilerek dışarıya aktarılabilir, ardından tekrar özgün pointer'a çevrilerek veri kullanılabilir hale gelir.

### Kullanılan Fonksiyonlar:

Bu fonksiyonlar, bir veri nesnesinin bellekteki adresini geçici olarak bir sayıya çevirip başka bir yerde veya formatta (örneğin dosyada ya da ağ mesajında) saklamamıza ve sonra tekrar kullanılabilir hale getirmemize yarar. Gerçek dünyada, özellikle ağ üzerinden veri taşıma, loglama sistemleri, debug araçları ya da veri serileştirme sistemlerinde bu tarz bir dönüşüme ihtiyaç duyulur.

* `uintptr_t serialize(Data* ptr);`
* `Data* deserialize(uintptr_t raw);`

### Bu egzersiyonda:

```cpp
// Serialize ve deserialize örneği:
Data myData = {42, "Example"};
uintptr_t raw = Serializer::serialize(&myData); // reinterpret_cast burada kullanılıyor
Data* result = Serializer::deserialize(raw);   // tekrar reinterpret_cast ile pointer'a dönüş
std::cout << result->id << " - " << result->name << std::endl;
```

* `reinterpret_cast` ile pointer → integer dönüşümü yapılır.
* `uintptr_t` tipi sayesinde bir pointer'ın bellekteki adresi sayısal bir değere çevrilerek güvenli şekilde saklanabilir. Bu sayede adres, örneğin bir log dosyasına yazılabilir, ağ üzerinden gönderilebilir veya farklı bir yapıda taşınabilir. Daha sonra `deserialize()` fonksiyonu ile bu sayısal değer tekrar orijinal pointer'a çevrilerek veri geri elde edilir.
* Tekrar pointer’a çevrilerek veri doğruluğu test edilir.

### Kazanımlar:

* Düşük seviye bellek işlemleri
* `uintptr_t` kullanım amacı ve yeri
* Güvenli cast işlemleriyle veri taşınabilirliği sağlamak

---

## 🧬 ex02 – Identify Real Type

Bu egzersizde polimorfik yapılarla çalışıyoruz. `Base` sınıfından türeyen `A`, `B`, `C` sınıflarının gerçek türünü, çalışma zamanında belirlemeyi hedefliyoruz.

### Fonksiyonlar:

* `Base* generate();` → Rastgele A/B/C oluşturur
* `void identify(Base* p);` → Pointer ile tipi tanımlar
* `void identify(Base& p);` → Referans ile tipi tanımlar (exception handling ile)

### Bu egzersiyonda:

```cpp
// Identify örnek kullanım:
Base* obj = generate();
identify(obj);      // pointer ile
identify(*obj);     // referans ile
```

* `dynamic_cast` ile güvenli downcasting yapılır.
* `try`/`catch` bloğu ile referans dönüşümündeki hatalar yakalanır.
* Sanal destructor ile polimorfizm desteklenir.

### Kazanımlar:

* RTTI (Run-Time Type Identification) mantığını kavramak
* Polimorfik sınıflar oluşturmak ve kullanmak
* Hatalı cast işlemleriyle başa çıkmak (`std::bad_cast`)

### Neden Kullanılır?

```cpp
Base* ptr = new A();
if (dynamic_cast<A*>(ptr)) { std::cout << "Gerçek tip A" << std::endl; }
```

Bu kullanım, özellikle aşağıdaki durumlarda gereklidir:

* Bir koleksiyonda (örneğin `std::vector<Base*>`) çok sayıda farklı alt sınıf nesnesi varsa, işlem yapmadan önce hangisinin hangi tipe ait olduğunu öğrenmek gerekir.

* Oyun motorları, GUI sistemleri, işlemci komut yorumlayıcıları gibi yapılar `Base*` üzerinden çalışır, ama `Player`, `Button`, `Instruction` gibi özel sınıflara göre davranış sergiler.

* `dynamic_cast` bu ayrımı çalışma zamanında güvenli şekilde yapmamıza imkân tanır.

* Referansla yapılan dönüşümlerde başarısızlık durumu `std::bad_cast` ile yakalanabilir, bu da hata kontrolü için önemlidir.

* `dynamic_cast`, büyük projelerde `Base*` gibi genel tiplerle çalışırken, nesnenin gerçekte hangi alt sınıfa ait olduğunu kontrol etmek için kullanılır.

* Örneğin bir oyun motorunda `Entity*` türündeki nesnenin `Player*`, `Enemy*` mi olduğunu öğrenmek istenebilir.

* Bu yöntem, davranışları doğru nesneye yönlendirmek ve hata yapmamak için kritiktir.

* Polimorfik sınıflar oluşturmak ve kullanmak

* Hatalı cast işlemleriyle başa çıkmak (`std::bad_cast`)

---

## 🧠 Bu Modülde Neleri Öğrendik?

* C++’ta farklı tür dönüşümlerinin kullanım farkları (`static_cast`, `reinterpret_cast`, `dynamic_cast`)
* `uintptr_t` ile pointer ve integer arasında geçiş yapma
* `std::numeric_limits` ile tür sınırlarını denetleme
* Polimorfizm ve sanal destructor’ların önemi
* `dynamic_cast` ile güvenli tür tanıma ve hata kontrolü

---
