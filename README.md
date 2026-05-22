```markdown
# 🏥 Sistem Manajemen Antrian RS Sardjito

Proyek praktikum ini adalah aplikasi berbasis CLI (Command Line Interface) menggunakan bahasa C++ untuk mensimulasikan manajemen pelayanan pasien di RS Sardjito. Proyek ini mengintegrasikan berbagai struktur data fundamental yang saling terhubung untuk menciptakan alur simulasi rumah sakit yang realistis.

---

## 🛠️ Struktur Data yang Digunakan

Aplikasi ini mengombinasikan beberapa struktur data untuk mengelola informasi pasien secara efisien:
1. **Linked List (`NodePasien`)**: Digunakan untuk menyimpan seluruh daftar pasien yang sedang aktif secara dinamis di dalam sistem.
2. **Queue / Antrian (`antrian[]`)**: Mengelola urutan nomor ID pasien berdasarkan siapa yang datang lebih dulu (*First In, First Out*) untuk proses pemanggilan ke ruang pemeriksaan.
3. **Stack / Tumpukan (`riwayat[][]`)**: Menyimpan riwayat aktivitas pemeriksaan pasien yang baru saja selesai (*Last In, First Out*). Rekam medis terakhir akan muncul di urutan teratas.
4. **Binary Search Tree (BST) (`NodeBST`)**: Digunakan untuk mempercepat proses pencarian data pasien secara hierarki berdasarkan ID unik mereka dengan kompleksitas waktu yang optimal.

---

## 📌 Status Fitur & Dokumentasi Fungsi (Selesai 100%)

> [!NOTE]
> **Status Project:** ✅ *Selesai / Production Ready*
> Seluruh komponen logika struktur data, alur menu operasional untuk Medic, dan fungsionalitas interaktif untuk Pasien telah berhasil diimplementasikan penuh dan lulus uji coba.

### 👨‍⚕️ 1. Menu Medic / Karyawan (Login: admin / 123)
* [x] **Tampilkan Pasien Aktif** (`tampilPasienAktif()`) — Menampilkan seluruh data pasien yang terdaftar di Linked List beserta statusnya.
* [x] **Lihat Antrian Pasien** (`tampilAntrian()`) — Melihat daftar antrian ID pasien yang sedang menunggu panggilan.
* [x] **Panggil Pasien** — Melakukan proses *dequeue* pada antrian untuk memanggil pasien berikutnya ke ruang periksa dan mengubah status menjadi "Diperiksa".
* [x] **Selesaikan Pemeriksaan** — Mengubah status pasien menjadi "Selesai", menghapusnya dari daftar pasien aktif, dan memasukkan rekam medis ke dalam Stack riwayat.
* [x] **Riwayat Pasien** (`tampilRiwayat()`) — Menampilkan tumpukan riwayat pasien yang telah selesai diperiksa dari yang paling terbaru.
* [x] **Cari Pasien** — Mencari data pasien secara instan menggunakan ID melalui struktur pohon biner (BST Search).
* [x] **Sorting Nama Pasien Aktif** — Mengurutkan daftar pasien aktif berdasarkan abjad nama secara urut (Ascending).

### 👥 2. Menu Pasien / Pelanggan
* [x] **Daftar Pasien Baru** — Menginput nama dan keluhan, otomatis menghasilkan ID unik (mulai dari 1001), memasukkannya ke Linked List, melakukan *insert* ke BST, serta memasukkan ID ke dalam barisan Queue.
* [x] **Cek Status Antrian** (`tampilAntrian()`) — Memungkinkan pasien melihat sisa antrian yang sedang berjalan.
* [x] **Cari Data Pasien** — Fitur mandiri bagi pasien untuk mengecek data dan status pelayanan mereka menggunakan ID.

---
