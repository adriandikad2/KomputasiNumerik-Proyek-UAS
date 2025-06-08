# 📊 Analisis Break-even Non-Linear dengan Metode Euler

Proyek ini merupakan bagian dari UAS mata kuliah **Komputasi & Numerik** yang disusun oleh Adrian Dika Darmawan (2306250711), Teknik Komputer, Universitas Indonesia. Proyek ini mengimplementasikan **Metode Euler** untuk menganalisis **titik impas (break-even point)** pada model **pendapatan dan biaya non-linear** dalam konteks bisnis.

---

## 🧠 Deskripsi Singkat

Analisis break-even digunakan untuk menentukan titik di mana total pendapatan sama dengan total biaya (profit = 0). Dalam proyek ini, digunakan model non-linear realistis:

- **Pendapatan**: `R(x) = ax − bx³`
- **Biaya**: `C(x) = cx² + de^(0.01x) + e`
- **Profit**: `P(x) = R(x) − C(x)`

Karena bentuk non-linear dari fungsi profit, solusi analitis sulit diperoleh. Oleh karena itu, digunakan **Metode Euler yang dimodifikasi** untuk secara numerik mencari akar dari fungsi profit.

---

## ⚙️ Dataset

Terdapat 5 dataset dengan parameter yang divariasikan untuk mensimulasikan berbagai skenario bisnis:

| Dataset | a    | b       | c    | d     | e     |
|---------|------|---------|------|-------|-------|
| 1       | 218  | 0.0009  | 0.14 | 192   | 4289  |
| 2       | 263  | 0.0007  | 0.13 | 171   | 4417  |
| 3       | 278  | 0.0008  | 0.16 | 110   | 4310  |
| 4       | 255  | 0.0007  | 0.24 | 111   | 4346  |
| 5       | 238  | 0.0005  | 0.24 | 116   | 2814  |

---

## 🧮 Metode Numerik

Metode Euler digunakan dengan pendekatan sebagai berikut:

- Fungsi `P'(x)` dihitung dari turunan fungsi profit.
- Proses iteratif menyesuaikan `x` untuk mendekati kondisi `P(x) ≈ 0`.
- Langkah adaptif berdasarkan nilai `P(x)` dan arah kemiringan `P'(x)` digunakan agar konvergensi efisien.

---

## 💻 Implementasi

### File Utama
- `euler_bep.c`: Menghitung dan menulis data **Revenue**, **Cost**, dan **Profit** ke file `.dat` berdasarkan input parameter dari `dataset.txt`.

### Visualisasi
Visualisasi dilakukan dengan menggunakan **Gnuplot** berdasarkan data `.dat` yang dihasilkan, dengan tampilan tiga kurva:
- Hijau: Revenue
- Merah: Cost
- Biru: Profit

---

## 📈 Analisis Hasil

- Semua dataset menunjukkan **satu titik impas awal** di rentang `x ∈ [0, 100]`.
- Setelah titik impas, kurva profit menunjukkan **peningkatan terus-menerus**, menandakan area yang menguntungkan.
- Nilai `a` dan `e` sangat mempengaruhi posisi titik impas:
  - `a ↑` → BEP lebih cepat tercapai.
  - `e ↑` → BEP lebih lambat tercapai.

---

## 📌 Insight Bisnis

- Dataset 3 adalah yang paling menguntungkan (pendapatan tinggi, biaya rendah).
- Dataset 5 cocok untuk bisnis kecil/startup karena biaya tetap rendah dan BEP cepat tercapai.
- Visualisasi membantu memvalidasi bahwa metode numerik menghasilkan hasil realistis meskipun tanpa solusi eksak.

---

## 📂 Struktur Repositori

```
├── document/
│ └── ProyekUAS_2306250711_Adrian.pdf
├── graphics/
│ ├── dataset1.png
│ ├── dataset2.png
│ ├── dataset3.png
│ ├── dataset4.png
│ └── dataset5.png
├── main/
│ ├── dataset.txt
│ ├── dataset_1.dat
│ ├── dataset_2.dat
│ ├── dataset_3.dat
│ ├── dataset_4.dat
│ ├── dataset_5.dat
│ ├── dataset_gen.c
│ ├── dataset_gen.exe
│ ├── euler_bep.c
│ └── euler_bep.exe
└── README.md
```

---

## 📎 Referensi

- Antony, J. (2016). *Break Even Analysis*
- Kolm, P. N. (2019). *Numerical Methods for Financial Applications*
- Chapra, S. & Canale, R. (2016). *Numerical Methods for Engineers*

---

## 🔗 Link Repositori

GitHub: [https://github.com/adriandikad2/KomputasiNumerik-Proyek-UAS](https://github.com/adriandikad2/KomputasiNumerik-Proyek-UAS)

---

## ✍️ Author

**Adrian Dika Darmawan**  
NPM: 2306250711  
Program Studi Teknik Komputer  
Universitas Indonesia
