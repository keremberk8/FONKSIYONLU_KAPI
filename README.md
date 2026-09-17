<div align="center">

# 🚪 Fonksiyonlu Kapı

**Arduino • Keypad • Matematiksel Doğrulama • IoT/Remote Control**

Matematiksel doğrulama mekanizmasını kapı ve aydınlatma kontrolüyle birleştiren embedded prototip.

<img src="docs/flow.svg" alt="Doğrulama akışı" width="900">

</div>

---

## ✨ Özellikler

- 🔢 `f(x) = 2x² + 1` doğrulaması
- ⌨️ 4x3 keypad
- 🚪 Motor / röle kontrolü
- 📟 20x4 I2C LCD
- 👏 Çift alkışla ışık
- 📺 IR kumanda
- 📱 Bluetooth komutları
- 🔊 Buzzer feedback
- ⏱️ 7 saniyelik cevap penceresi

## 🧠 Verification Flow

```text
# → Rastgele x → f(x) hesapla → Kullanıcı sonucu
                                      ↓
                              Doğru / Yanlış
                               ↓           ↓
                            Kapıyı aç    Reddet
```

## 💡 Aydınlatma

Işık; çift alkış, IR kumanda veya tanımlı Bluetooth komutları üzerinden kontrol edilir.

## 🛠️ Donanım & Kütüphaneler

Arduino · Keypad · LCD · IR Receiver · Bluetooth · Ses sensörü · Röle · Buzzer · Motor

`Wire` · `LiquidCrystal_I2C` · `Keypad` · `IRremote` · `SoftwareSerial`

## 🚀 Kurulum

1. Arduino IDE'de kartı seçin.
2. Gerekli kütüphaneleri yükleyin.
3. Pinleri kaynak koduyla eşleştirin.
4. Firmware'i yükleyin.
5. Keypad, IR, Bluetooth ve sensörleri ayrı ayrı test edin.

## 🔐 Güvenlik

Bu proje eğitim/prototip amaçlıdır. Fiziksel erişim sistemlerinde matematiksel doğrulama tek başına yeterli bir güvenlik mekanizması değildir; kimlik doğrulama, yetkilendirme ve güvenli haberleşme ayrıca tasarlanmalıdır.

## 📁 Yapı

```text
FONKSIYONLU_KAPI/
├── fonksiyon_son_deneme.ino
├── docs/flow.svg
└── README.md
```

## 🚧 Durum

**Prototip / deneysel çalışma**
