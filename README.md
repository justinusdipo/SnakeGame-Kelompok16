# SnakeGame-Kelompok16

## Deskripsi
Snake Game mini merupakan sebuah aplikasi permainan ular sederhana menggunakan bahasa C, yang dimana ular dapat bergerak ke arah sesuai dengan inputan dari pemain untuk menuju makanan yang telah tersedia agar dapat memperoleh skor selama permainan berlansung.

## About
>Notice : This project is created for education purpose at Universitas Indonesia.

## Instruction
1. Gunakan tombol arah pada keyboard untuk menggerakan ular.

2. Kamu akan diberikan makanan di beberapa koordinat layar yang harus kamu makan. Setiap kali kamu makan sebuah makanan maka panjang tubuh ular akan bertambah 1 elemen dan demikian skornya.

3. Di sini kamu diberikan tiga nyawa. Nyawa kamu akan berkurang saat kamu menabrak dinding atau tubuh ular.

4. Kamu dapat menghentikan sementara permainan di tengahnya dengan menekan sembarang pada tombol keyboard. Untuk melanjutkan permainan yang dijeda, tekan tombol lain sekali lagi

5. Jika Kamu ingin keluar, tekan 'esc'


## Code Explanation

#define ATAS 72
#define BAWAH 80
#define KIRI 75
#define KANAN 77
Fungsi ini bertujuan untuk merepresentasikan nilai ASCII dari keyboard "arah".

 'struct koordinat' 
Tipe data ini bertujuan untuk menyimpan kumpulan variabel dari berbagai jenis tipe data dan juga array.

'typedef struct koordinat koordinat'
Fungsi ini bertujuan untuk membuat nama alias/inisial dari suatu tipe data.

'getch()'
Fungsi ini bertujuan untuk menerima input karakter langsung, tanpa penulisan ke blok memori (enter), dan tanpa tampilan karakter ke layar (echo).

 'kbhit()' 
 Fungsi ini bertujuan untuk menentukan, apakah suatu tombol papan ketik ditekan.

'COORD coord'
COORD adalah sebuah struct yang berisikan dua variabel bertipe SHORT, yaitu X dan Y.

'SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)'
Berfungsi untuk mengatur posisi kursor dengan nilai x dan y yang telah di set pada pemanggilan fungsi. Nilai x dan y yang telah di set pada pemanggilan fungsi akan di tampung pada variable coord ini. Kemudian posisi kursor akan digantikan posisi dengan nilainya coord ini.

'SetConsoleCursorPosition()'
Fungsi ini digunakan untuk menetapkan posisi cursor di layar. 

'GetStdHandle()'
Fungsi yang digunakan untuk mendapatkan handle ke layar.

'void rekamjejak()'
Fungsi ini bertujuan untuk menyimpan data nama pemain dan skor dari permainan ke dalam file.txt dan menampilkan histori perolehan skor sebelumnya.

'void load()'
Fungsi ini bertujuan untuk menampilkan proses Loading sebelum permainan dimulai.

'void Gerak()'
Fungsi ini bertujuan untuk menampilkan posisi ular dan makanan pada saat permainan berlangsung yan diperbarui setiap saat.

'void Makanan()'
Fungsi ini bertujuan untuk mengatur posisi makanan yang berubah-ubah secara acak setiap kali ular berhasil memakan makanan tersebut.

'int Skor()'
Fungsi ini bertujuan untuk mengatur perolehan skor dan nyawa yang tersisa.

'void Print()'
Fungsi ini bertujuan untuk menampilkan instruksi cara bermain sebelum permainan dimulai.

'void gotoxy(int x, int y)'
Fungsi ini bertujuan untuk memetakan koordinat pada layar permainan.

'void GotoXY(int x,int y)'
Fungsi ini bertujuan untuk memperbarui posisi koordinat dari pergerakan luar setiap saat selam permainan berlangsung.

'void Belokan()'
Fungsi ini bertujuan untuk mengatur posisi ular berhenti pada suatu titik koordinat ketika tubuhnya berubah arah.

'void Boarder()'
Fungsi ini bertujuan untuk membuat frame/batas dinding area permainan.

'void Bawah()'
Fungsi ini bertujuan untuk mengatur perubahan posisi terhadap ular ke bawah ketika ditekan tombol "down" pada keyboard.

'void Kiri()'
Fungsi ini bertujuan untuk mengatur perubahan posisi terhadap ular ke kiri ketika ditekan tombol "left" pada keyboard.

'void Atas()'
Fungsi ini bertujuan untuk mengatur perubahan posisi terhadap ular ke atas ketika ditekan tombol "up" pada keyboard.

'void Kanan()'
Fungsi ini bertujuan untuk mengatur perubahan posisi terhadap ular ke kanan ketika ditekan tombol "right" pada keyboard.

'void KeluarPermainan()'
Fungsi ini bertujuan untuk menampilkan akhir dari permainan/game over ketika nyawa ular sudah habis.

'int Hanyaskor()'
Fungsi ini bertujuan untuk menyimpan hasil perolehan skor atau jumlah makanan yang terlah berhasil dimakan oleh ular. 

'info=fopen("rekamjejak.txt","a+")'
Fungsi ini digunakan untuk membuka dan menyimpan data hasil permainan pada file rekamjejak.txt

'NamaPemainBaru[j]=toupper(NamaPemain[j])'
Fungsi ini digunakan untuk mengubah karakter awalan dari suatu kata menjadi huruf kapital.

## License
This code is released into the public domain free of any restrictions. The author requests acknowledgement if the code is used, but does not require it. This code is provided free of any liability and without any quality claims by the author.
