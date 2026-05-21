# 🏥 Sistem Manajemen Antrian RS Sardjito

Proyek praktikum ini adalah aplikasi berbasis CLI (Command Line Interface) menggunakan bahasa C++ untuk mensimulasikan manajemen pelayanan pasien di RS Sardjito. Proyek ini mengintegrasikan berbagai struktur data fundamental.

---

## 🛠️ Struktur Data yang Digunakan

Aplikasi ini mengombinasikan beberapa struktur data untuk mengelola informasi pasien secara efisien:
1. **Linked List (`NodePasien`)**: Digunakan untuk menyimpan seluruh daftar pasien yang sedang aktif secara dinamis.
2. **Queue / Antrian (`antrian[]`)**: Mengelola urutan nomor ID pasien berdasarkan siapa yang datang lebih dulu (*First In, First Out*).
3. **Stack / Tumpukan (`riwayat[][]`)**: Menyimpan riwayat aktivitas pemeriksaan pasien yang baru saja selesai (*Last In, First Out*).
4. **Binary Search Tree (BST) (`NodeBST`)**: Disiapkan untuk mempercepat proses pencarian data pasien berdasarkan ID unik mereka.

---

## 📌 Status Fitur & Pembagian Tugas (Work in Progress)

> [!NOTE]
> **Status Project:** 🔄 *Belum Selesai (Setengah Jadi)*
> Struktur data utama dan kerangka menu sudah siap. Beberapa fungsi implementasi menu utama masih kosong dan perlu diteruskan.

### 👨‍⚕️ 1. Menu Medic / Karyawan (Login: admin / 123)
* [x] Tampilkan Pasien Aktif (`tampilPasienAktif()`)
* [x] Lihat Antrian Pasien (`tampilAntrian()`)
* [ ] **Panggil Pasien** ── 🛠️ *BELUM DIIMPLEMENTASI*
* [ ] **Selesaikan Pemeriksaan** ── 🛠️ *BELUM DIIMPLEMENTASI*
* [x] Riwayat Pasien (`tampilRiwayat()`)
* [ ] **Cari Pasien** ── 🛠️ *BELUM DIIMPLEMENTASI*
* [ ] **Sorting Nama Pasien Aktif** ── 🛠️ *BELUM DIIMPLEMENTASI*

### 👥 2. Menu Pasien / Pelanggan
* [ ] **Daftar Pasien Baru** ── 🛠️ *BELUM DIIMPLEMENTASI*
* [x] Cek Status Antrian (`tampilAntrian()`)
* [ ] **Cari Data Pasien** ── 🛠️ *BELUM DIIMPLEMENTASI*

---

## 🚀 Panduan Pengembang (Untuk Anggota Kelompok)

Untuk Mas Zhafif yang akan melanjutkan codingan ini, silakan ikuti alur ini:

1. Lakukan `git pull origin main` terlebih dahulu untuk mengambil kode terbaru.
2. Fokus utama kita adalah melengkapi fungsi-fungsi kosong yang ada di dalam `menuMedic()` dan `menuPasien()`.
3. Manfaatkan fungsi pembantu (*helper*) yang sudah dibuat seperti `buatPasien()`, `enqueue()`, `dequeue()`, `insertBST()`, dan `cariBST()`.
4. Pastikan melakukan uji coba compile setelah menambahkan fungsi baru sebelum melakukan *commit* dan *push* kembali ke GitHub.
