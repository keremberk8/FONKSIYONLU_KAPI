# Fonksiyonlu Kapı

Arduino tabanlı, **matematiksel doğrulama + keypad + uzaktan kontrol** bileşenlerini bir araya getiren akıllı kapı ve aydınlatma prototipidir.

Kapının açılması için sistem tarafından rastgele bir sayı üretilir ve tanımlı matematiksel fonksiyonun sonucu kullanıcıdan istenir. Doğru cevap verildiğinde kapı açılır. Aynı sistem içerisinde alkış sensörü, IR kumanda ve Bluetooth üzerinden aydınlatma ve kapı kontrolü de bulunur.

## ✨ Özellikler

- 🔢 Matematiksel fonksiyon ile kapı doğrulaması
- ⌨️ 4x3 keypad ile kullanıcı girişi
- 🚪 Motor / röle üzerinden kapı kontrolü
- 📟 20x4 I2C LCD arayüzü
- 👏 Çift alkış ile ışık kontrolü
- 📺 IR kumanda ile ışık kontrolü
- 📱 Bluetooth üzerinden komut alma
- 🔊 Buzzer ile kullanıcı geri bildirimi
- ⏱️ Cevap için zaman sınırlaması

## 🧠 Doğrulama Mantığı

Sistem rastgele bir `x` değeri üretir ve aşağıdaki fonksiyonu uygular:

```text
f(x) = 2x² + 1
```

Kullanıcının belirlenen süre içerisinde doğru sonucu girmesi halinde kapı açılır. Yanlış cevapta giriş reddedilir.

## 🛠️ Donanım ve Teknolojiler

- Arduino
- Keypad
- 20x4 I2C LCD
- IR receiver
- Bluetooth modülü
- Ses sensörü
- Röle
- Buzzer
- Kapı motoru / aktüatör
- Arduino C/C++

### Kullanılan kütüphaneler

- `Wire`
- `LiquidCrystal_I2C`
- `Keypad`
- `IRremote`
- `SoftwareSerial`

## 🔄 Çalışma Akışı

```text
Başlangıç
   ↓
Keypad üzerinden #
   ↓
Rastgele sayı oluştur
   ↓
f(x) hesapla
   ↓
Kullanıcı sonucu girer
   ↓
Doğru mu?
 ┌─┴──────────┐
 ↓             ↓
Evet          Hayır
 ↓             ↓
Kapıyı aç     Girişi reddet
```

## 💡 Aydınlatma Kontrolü

Aydınlatma üç farklı yöntemle kontrol edilebilir:

- Çift alkış
- IR kumandadaki tanımlı tuşlar
- Bluetooth üzerinden komutlar

Örnek Bluetooth komutları arasında `aç`, `kapat`, `ışığı aç` ve `ışığı kapat` bulunur.

## 📁 Proje Yapısı

```text
FONKSIYONLU_KAPI/
├── fonksiyon_son_deneme.ino
└── README.md
```

## 🚀 Kurulum

1. Arduino IDE'yi açın.
2. Gerekli kütüphaneleri yükleyin.
3. `fonksiyon_son_deneme.ino` dosyasını açın.
4. Donanım bağlantılarını kaynak koddaki pin tanımlarıyla eşleştirin.
5. Kodu Arduino'ya yükleyin.
6. LCD ve Serial Monitor üzerinden sistem durumunu takip edin.

## ⚠️ Güvenlik Notu

Bu proje eğitim/prototip amaçlıdır. Gerçek bir fiziksel erişim sisteminde yalnızca matematiksel bir doğrulama mekanizmasına güvenilmemeli; kimlik doğrulama, yetkilendirme, hata yönetimi ve güvenli haberleşme ayrıca tasarlanmalıdır.

## 🚧 Geliştirme Durumu

**Prototip / deneysel çalışma**

Gelecekte kullanıcı bazlı yetkilendirme, daha güçlü kimlik doğrulama, olay kayıtları ve modüler donanım sürücüleri eklenebilir.
