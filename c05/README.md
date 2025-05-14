# Bureaucrat Projesi (C++ Module 05)

Bu projede **C++ programlama dilinde hata yönetimi (exception handling)** kavramını uygulamalı olarak öğreniyoruz. Projemizde, bir memur (Bureaucrat) sınıfı ve bu memurun imzaladığı formlarla (Form) çalışırken oluşabilecek hataları yakalamayı ve yönetmeyi hedefliyoruz.

## Try-Catch Mekanizması Nedir?

Program çalışırken yanlış bir veri girilirse ya da beklenmedik bir hata olursa, program genellikle çöker. Bunun önüne geçmek için C++'ta **try-catch blokları** kullanılır. Bu bloklar sayesinde hataları önceden yakalayıp, kullanıcıya anlaşılır bir hata mesajı gösterebiliriz.

```cpp
try {
    Bureaucrat b("Ali", 0);  // Hatalı çünkü 0 geçerli bir derece değil.
} catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
}
```

## Bureaucrat Sınıfı ve Derece Mantığı

* `const std::string name`: Memurun ismi, değiştirilemez.
* `int grade`: Memurun derecesi, 1 ile 150 arasında olmalı.

| İşlem             | Değişim | Anlamı                        |
| ----------------- | ------- | ----------------------------- |
| Dereceyi artırmak | 3 → 2   | Daha yetkili bir seviye       |
| Dereceyi azaltmak | 10 → 11 | Daha düşük bir yetki seviyesi |

### Hatalar:

* **GradeTooHighException**: Derece 1'den yukarı çıkarsa.
* **GradeTooLowException**: Derece 150'den aşağı düşerse.

### Kolay yazdırma:

```cpp
Bureaucrat john("John", 42);
std::cout << john << std::endl;  // John, bureaucrat grade 42
```

---

# Form Sistemi (C++ Module 05 - ex01)

Bu aşamada **Form** sınıfı ekledik. Memurlar artık formları imzalayabiliyor.

| Özellik          | Görevi                                  |
| ---------------- | --------------------------------------- |
| `name`           | Formun ismi                             |
| `isSigned`       | İmzalı mı? (Başlangıçta false)          |
| `gradeToSign`    | İmzalamak için gereken minimum derece   |
| `gradeToExecute` | Çalıştırmak için gereken minimum derece |

### Form Fonksiyonları:

* `beSigned()`: Bureaucrat formu imzalar.
* `signForm()`: Bureaucrat formu imzalamaya çalışır.

### Hatalar:

* Form oluşturulurken derece kontrol edilir.
* Bureaucrat'ın derecesi yetmezse `GradeTooLowException` fırlatılır.

---

# Execute Sistemi (C++ Module 05 - ex02)

Artık formlar sadece imzalanmıyor, **gerçek işler** yapıyor.

## Neden `AForm` Soyut Sınıfa Dönüştü?

Her form farklı bir işlem yapıyor. Bu yüzden `execute()` fonksiyonunu soyut (abstract) hale getirdik. Böylece `AForm` sınıfı tek başına kullanılamaz, ondan türetilen her form kendi `execute()` fonksiyonunu yazmak zorundadır. Bu, **polimorfizm** kullanarak kodumuzu daha esnek ve genişletilebilir hale getirir.

## Yeni Formlar:

| Form Adı               | İmzalama | Çalıştırma | Görev                            |
| ---------------------- | -------- | ---------- | -------------------------------- |
| ShrubberyCreationForm  | 145      | 137        | ASCII ağaç çizer (dosyaya yazar) |
| RobotomyRequestForm    | 72       | 45         | %50 robotlaştırma yapar          |
| PresidentialPardonForm | 25       | 5          | Hedefi affeder                   |

## RobotomyRequestForm'da Rastgelelik:

```cpp
#include <cstdlib>
#include <ctime>

std::srand(std::time(NULL));
if (std::rand() % 2 == 0) {
    std::cout << "Başarılı!";
} else {
    std::cout << "Başarısız!";
}
```

## Execute Kontrolleri:

* Form imzalı mı?
* Bureaucrat'ın derecesi yeterli mi?

Eğer biri sağlanmazsa exception fırlatılır.

---

# Intern Sınıfı (C++ Module 05 - ex03)

Intern sınıfı sayesinde form üretimini **otomatize ettik**.

### Öncesi:

Formları şu şekilde elle oluşturuyorduk:

```cpp
AForm* form = new ShrubberyCreationForm("target");
AForm* form = new RobotomyRequestForm("target");
```

Ve şuna benzer if-else blokları kullanıyorduk:

```cpp
if (formName == "shrubbery creation")
    return new ShrubberyCreationForm(target);
else if (formName == "robotomy request")
    return new RobotomyRequestForm(target);
else
    std::cout << "Unknown form requested." << std::endl;
```

Bu yapı **tekrarlı**, **hantal** ve **merkezi değildi**.

### Sonrası:

```cpp
AForm* form = intern.makeForm("robotomy request", "Bender");
```

`makeForm()` fonksiyonu ile form ismini string olarak veriyoruz, Intern sınıfı bizim için ilgili formu otomatik olarak üretiyor. Yeni bir form eklemek için yalnızca bir satır güncellemek yetiyor.

```cpp
AForm* makeForm(const std::string& formName, const std::string& target);
```

### Yanlış form adı örneği:

```cpp
AForm* failForm = intern.makeForm("magic form", "target");
// Çıktı: Intern: Unknown form requested.
```

## Fonksiyon Pointer Dizisi ile Akıllı Yapı

Önceden:

```cpp
if (name == "shrubbery creation") { ... }
```

Şimdi:

```cpp
struct FormPair {
    std::string name;
    AForm* (*createFunc)(const std::string&);
};
```

Bu yöntem sayesinde:

| Özellik                       | intern.makeForm kullanımı           | Doğrudan Sınıf Oluşturma             |
| ----------------------------- | ----------------------------------- | ------------------------------------ |
| Dinamiklik                    | ✔ Çalışma zamanında belirlenir      | ✖ Derleme zamanında sabittir         |
| Yeni form ekleme kolaylığı    | ✔ Sadece diziyi güncellemek yeterli | ✖ Kodun birçok yerine müdahale gerek |
| Kodun merkezileştirilmesi     | ✔ Factory mantığı ile merkezi       | ✖ Dağınık ve kontrolsüz              |
| Esneklik ve sürdürülebilirlik | ✔ Yüksek                            | ✖ Düşük                              |

Bu yaklaşım kodunuzu hem **bakımı kolay** hem de **ölçeklenebilir** yapar.

---

# Bu Proje Kapsamında Ne Öğrendik?

* **Exception (hata) yönetimi:** Hataların nasıl yakalanıp kullanıcıya uygun bir şekilde gösterileceğini öğrendik.
* **Sınıf tasarımı ve OOP prensipleri:** Özellikle soyut sınıflar (abstract class) ve polimorfizm kavramlarını pratik ettik.
* **Operator overloading:** `<<` operatörü sayesinde nesnelerimizi kolayca yazdırmayı öğrendik.
* **Random (rastgelelik) yönetimi:** C++'ta klasik yöntemlerle nasıl rastgelelik sağlanacağını ve bunun sınıf içi kullanımı gördük.
* **Factory Pattern mantığı:** Intern sınıfı ile form üretimini merkezi bir şekilde yöneterek kodu nasıl daha sürdürülebilir hale getirebileceğimizi gördük.
* **Kodun esnekliğini artırma:** Daha az kod tekrarıyla, daha temiz ve yönetilebilir bir kod yapısı oluşturduk.

Bu proje, C++'ta hem teorik hem pratik olarak hata yönetimi, OOP, sınıf tasarımı ve kod organizasyonu konularında sağlam bir temel oluşturmuştur.
