# 🕊️ minitalk - 42 Projesi

**UNIX Sinyalleri ile Süreçler Arası İletişim (IPC)**

Bu proje, [42 Okulu](https://42kocaeli.com.tr/) müfredatı kapsamında geliştirilmiştir.  
Amaç, **sadece UNIX sinyalleri (`SIGUSR1`, `SIGUSR2`) kullanarak** bir istemci (client) ve sunucu (server) arasında veri iletişimi kurmaktır.  
Bu sayede düşük seviyeli süreç yönetimi, sinyal işleme ve bit manipülasyonu kavramları öğrenilir.  

---

## 🔄 İletişim Akışı

> Server bir PID (Process ID) ile başlatılır, client bu PID üzerinden mesajı bit-bit gönderir.  
> Her bit bir sinyal (SIGUSR1 veya SIGUSR2) olarak iletilir.

---

## 📜 Projenin Amacı

`minitalk`, iki farklı süreç arasında iletişim kurulmasını sağlar:  
- **Server:** Mesajları sinyal olarak alır ve terminalde görüntüler.  
- **Client:** Mesajı karakter karakter, bit-bit gönderir.

Bu proje, sistem çağrıları, sinyal mekanizmaları ve senkronizasyon konularına güçlü bir giriş niteliğindedir.

---

## ✨ Özellikler

* **Tamamen Sinyal Tabanlı İletişim** (`SIGUSR1` ve `SIGUSR2`)  
* **Karakterlerin Bit Seviyesinde Gönderimi**  
* **Gerçek Zamanlı Mesaj Onayı** (server → client)  
* **Senkron ve Güvenli İletim Mekanizması**  
* **Bellek sızıntısı ve işlem çakışması olmadan çalışır**  
* **Makefile ile kolay derleme**

---

## 🧠 Öğrenilen Temel Konseptler

* **UNIX Sinyalleri ve `sigaction()` kullanımı**  
* **Bit Manipülasyonu (bit shifting & masking)**  
* **Süreç Yönetimi (`fork()`, `kill()`, `getpid()`)**  
* **Zamanlama ve senkronizasyon sorunlarının çözümü**  
* **Düşük seviyede iletişim protokolü tasarımı**

---

## 🚀 Kurulum ve Çalıştırma

Projeyi klonladıktan sonra:

```bash
# 1. Reposu klonlayın
git clone git@github.com:alperenocak/minitalk.git

# 2. Dizine gidin
cd minitalk

# 3. Derleyin
make

# 4. Sunucuyu başlatın
./server
# PID terminalde görüntülenecektir
