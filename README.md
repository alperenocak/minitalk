# 🧱 so_long - 42 Projesi

**MiniLibX ile 2D Oyun Geliştirme**

Bu proje, [42 Okulu](https://42kocaeli.com.tr/) müfredatı kapsamında geliştirilmiş bir **2D oyun projesidir**.  
Amaç, MiniLibX kütüphanesini kullanarak basit bir oyun motoru tasarlamak, harita dosyalarını yorumlamak ve olay odaklı grafik programlamayı öğrenmektir.  

<img width="800" height="400" alt="so_long demo" src="https://github.com/user-attachments/assets/so_long-demo.png" />

---

## 📜 Projenin Amacı

**so_long**, `.ber` uzantılı haritayı okuyarak oyuncunun tüm koleksiyonları toplayıp çıkışa ulaşmasını amaçlayan küçük bir 2D oyundur.  
Bu proje sayesinde grafik programlama, olay (event) yönetimi ve kaynak optimizasyonu konularında temel beceriler edinilir.

---

## ✨ Özellikler

* **Harita Okuma:** `.ber` uzantılı dosyalardan harita verisi okunur.  
* **Harita Doğrulama:**  
  - Harita dikdörtgen yapıda olmalıdır.  
  - En az bir çıkış (E), bir karakter (P) ve bir koleksiyon (C) bulunmalıdır.  
  - Sınırlar duvar (`1`) ile çevrili olmalıdır.  
* **Karakter Kontrolleri:**  
  - Yön tuşlarıyla hareket (W, A, S, D).  
  - Her adım sayacı terminalde gösterilir.  
* **Oyun Mekanikleri:**  
  - Tüm objeler toplandıktan sonra çıkış aktif hale gelir.  
  - Her hareket ekranı yeniden çizer.  
* **Grafik Arayüz:**  
  - MiniLibX kütüphanesiyle sprite tabanlı render işlemi.  
  - Piksel tamponlama (buffering) ile kesintisiz oyun akışı.  
* **Bellek Yönetimi:**  
  - Tüm kaynaklar oyun sonlandığında serbest bırakılır.  
  - Hatalı dosyalar için güvenli hata yönetimi mevcuttur.

---

## 🧠 Öğrenilen Temel Konseptler

* **Olay Odaklı Programlama (Event Loop)**  
* **MiniLibX ile 2D Görselleştirme**  
* **Harita Ayrıştırma (Parsing)**  
* **Flood Fill Algoritması ile Erişilebilirlik Kontrolü**  
* **Bellek Yönetimi ve Hata Denetimi**  
* **Oyun Döngüsü (Game Loop) ve Girdi Yönetimi**

---

## 🚀 Kurulum ve Çalıştırma

Projeyi klonladıktan sonra derlemek ve çalıştırmak için:

```bash
# 1. Reposu klonlayın
git clone git@github.com:alperenocak/so_long.git

# 2. Dizine gidin
cd so_long

# 3. Derleyin
make

# 4. Oyunu başlatın
./so_long maps/map.ber
