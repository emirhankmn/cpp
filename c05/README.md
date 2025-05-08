# Bureaucrat Projesi (C++ Module 05 - ex00)

Bu projede **C++'ta exception (istisna) yönetimi** öğreniyoruz. Programın hata durumlarında kontrolü kaybetmeden nasıl tepki vereceğini sağlamak için bir yapı kuruyoruz.

## Try-Catch Nedir?

Bir program yazarken kullanıcı yanlış bir veri girerse veya beklenmedik bir durum olursa, normalde program çöker. **try-catch** bloğu ile bu hatayı yakalıyoruz ve hata mesajı basıyoruz.

```cpp
try {
    Bureaucrat b("Ali", 0);  // Hata: derece 0 olamaz
} catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
}
```

## Bureaucrat Sınıfı

* `const std::string name`: Memurun ismi (değişmez)
* `int grade`: 1 ile 150 arasında bir derece

| Ne yapıyoruz?        | Sayısal değişim | Anlamı                       |
| -------------------- | --------------- | ---------------------------- |
| Dereceyi artırıyoruz | 3 → 2           | Daha yüksek seviyeye geçiyor |
| Dereceyi azaltıyoruz | 10 → 11         | Daha düşük seviyeye iniyor   |

## Exception'lar

* `GradeTooHighException`: Derece 1'den yüksekse
* `GradeTooLowException`: Derece 150'den düşükse

## Operator Overloading

```cpp
Bureaucrat john("John", 42);
std::cout << john << std::endl;  // John, bureaucrat grade 42
```

---

# Form Sistemi (C++ Module 05 - ex01)

Bu aşamada **Form** sınıfını ekledik. Bureaucrat formları imzalayabiliyor.

| Özellik          | Açıklama                        |
| ---------------- | ------------------------------- |
| `name`           | Form ismi                       |
| `isSigned`       | Başta false                     |
| `gradeToSign`    | İmzalamak için gereken derece   |
| `gradeToExecute` | Çalıştırmak için gereken derece |

* `beSigned()`: Bureaucrat formu imzalar.
* `signForm()`: Bureaucrat sonucu basar.

## Exception'lar

* Form oluştururken derece sınırı kontrol edilir.
* İmzalarken derece yetmezse `GradeTooLowException` fırlatılır.

---

# Execute Sistemi (C++ Module 05 - ex02)

Artık formlar sadece kağıt üstünde kalmıyor, **gerçek iş** yapıyor.

## Ne Değişti?

* `Form` → `AForm` oldu (soyut sınıf)
* `execute()` pure virtual fonksiyon eklendi

## Yeni Formlar

| Form Adı               | İmzalama | Çalıştırma | Görev                            |
| ---------------------- | -------- | ---------- | -------------------------------- |
| ShrubberyCreationForm  | 145      | 137        | ASCII ağaç çizer (dosyaya yazar) |
| RobotomyRequestForm    | 72       | 45         | %50 robotleştirme yapar          |
| PresidentialPardonForm | 25       | 5          | Hedefi affeder                   |

## Rastgelelik Nasıl Sağlanıyor?

`RobotomyRequestForm` için:

```cpp
#include <cstdlib>
#include <ctime>

std::srand(std::time(NULL));  // main()
if (std::rand() % 2 == 0) {
    std::cout << "Başarılı!";
} else {
    std::cout << "Başarısız!";
}
```

## Execute Kontrolleri

* Form imzalı mı?
* Bureaucrat’ın derecesi yeterli mi?

Hatalıysa exception fırlatılır.

---

# Intern Sınıfı (C++ Module 05 - ex03)

Bu aşamada Intern sınıfı ile **form üretimini otomatikleştirdik.**

```cpp
AForm* makeForm(const std::string& formName, const std::string& target);
```

## Örnek Kullanım

```cpp
Intern intern;
AForm* form = intern.makeForm("robotomy request", "Bender");
```

## Yanlış Form Durumu

```cpp
AForm* failForm = intern.makeForm("magic form", "target");
// Çıktı: Intern: Unknown form requested.
```

## Fonksiyon Pointer Dizisi

Yanlış:

```cpp
if (name == "shrubbery creation") { ... }
```

Doğru:

```cpp
struct FormPair {
    std::string name;
    AForm* (*createFunc)(const std::string&);
};
```

Bu sayede yeni form eklemek kolay olur 🚀 Ayrıca bu kullanım bizim işimize şu şekilde yarar: Kodumuz daha esnek ve ölçeklenebilir hale gelir. Yeni bir form eklemek istediğimizde, sadece dizimize bir satır ekleyerek sisteme entegre edebiliriz; ana mantığı değiştirmemize gerek kalmaz. Bu da bakım kolaylığı sağlar ve kod tekrarını önler.

Ayrıca `intern.makeForm("robotomy request", "Bender")` ile doğrudan `RobotomyRequestForm("Bender")` kullanımının farkı şudur: İlki daha dinamik ve esnektir; form ismi string olarak verildiği için hangi formun üretileceği çalışma zamanında belirlenir. İkincisi ise doğrudan belirli bir sınıfı manuel olarak oluşturur ve factory sisteminden bağımsızdır. Yani intern sistemi kodunuzu merkezi hale getirir ve yeni formlar ekledikçe daha sürdürülebilir bir yapı sunar.

| Özellik                       | intern.makeForm kullanımı      | Doğrudan Sınıf Oluşturma     |
| ----------------------------- | ------------------------------ | ---------------------------- |
| Dinamiklik                    | ✔ Çalışma zamanında belirlenir | ✖ Derleme zamanında sabittir |
| Yeni form ekleme kolaylığı    | ✔ Sadece diziyi güncelle       | ✖ Yeni kod yazılması gerekir |
| Kodun merkezileştirilmesi     | ✔ Factory mantığı ile merkezi  | ✖ Bağımsız ve dağınık        |
| Esneklik ve sürdürülebilirlik | ✔ Yüksek                       | ✖ Düşük                      |
