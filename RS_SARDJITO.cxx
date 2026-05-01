#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	int pilihan;
	
	do {
		cout << "=======================================" << endl;
		cout << "||       WELCOME TO RS SARDJITO      ||" << endl;
		cout << "=======================================" << endl;
		cout << "||" << "1. Masuk sebagai medic" << endl;
		cout << "||" << "2. Masuk sebagai pasien" << endl;
		cout << "||" << "3. Keluar" << endl;
		cout << "=======================================" << endl;
		cout << "||" << "Pilihan  : "; cin >> pilihan; 
	
		if(pilihan == 1){
			string Usn;
			int Pass;
			string UsnBenar = "admin";
			int PassBenar = 123;
			
			cout << "\n=======================================" << endl;
			cout << "||             Halo Medic!             ||" << endl;
			cout << "||   Silahkan login untuk melanjutkan  ||" << endl;
			cout << "=========================================" << endl;
			
			cout << "Masukkan Username : "; cin >> Usn;
			cout << "Masukkan Password : "; cin >> Pass;
			
			bool LoginBerhasil = (Usn == UsnBenar && Pass == PassBenar);
			
			if (LoginBerhasil){
				int pilihKaryawan;
				do{
					cout << "\n=======================================" << endl;
					cout << "||            WELCOME MEDIC!           ||" << endl;
					cout << "=========================================" << endl;
					cout << "||" << "1. Kelola Data Pasien" << endl;
					cout << "||" << "2. Antrian Pasien" << endl;
					cout << "||" << "3. Pemeriksaan Pasien" << endl;
					cout << "||" << "4. Kelola Obat" << endl;
					cout << "||" << "5. Riwayat Pasien" << endl;
					cout << "||" << "6. Cari Pasien" << endl;
					cout << "||" << "7. Simpan Data" << endl;
					cout << "||" << "8. Logout" << endl;
					cout << "=======================================" << endl;
					cout << "||" << "Pilihan  : "; cin >> pilihKaryawan; 
				
					if (pilihKaryawan == 1){
						
					}else if (pilihKaryawan == 2){
						
					}else if (pilihKaryawan == 3){
						
					}else if (pilihKaryawan == 4){
						
					}else if(pilihKaryawan == 5){
						
					}else if(pilihKaryawan == 6){
						
					}else if(pilihKaryawan == 7){
						
					}else if(pilihKaryawan == 8){
						cout << "Terimakasih Medic, Selamat Beristirahat!" << endl;
						system("pause");
					}
				}while(pilihKaryawan != 8);
				
			}else{
				cout << "\nusername dan password salah!\n";
			}
		
		}else if (pilihan == 2){
			int pilihPelanggan;
			do{
				cout << "\n=======================================" << endl;
				cout << "||            WELCOME MATE!            ||" << endl;
				cout << "=========================================" << endl;
				cout << "||" << "1. Daftar" << endl;
				cout << "||" << "2. Ambil Nomor Antrian" << endl;
				cout << "||" << "3. Cek Status Antrian" << endl;
				cout << "||" << "4. Cari Obat" << endl;
				cout << "||" << "5. Logout" << endl;
				cout << "=======================================" << endl;
				cout << "||" << "Pilihan  : "; cin >> pilihPelanggan;
				
				if(pilihPelanggan == 1){
					
				}else if(pilihPelanggan == 2){
					
				}else if(pilihPelanggan == 3){
					
				}else if(pilihPelanggan == 4){
					
				}else if(pilihPelanggan == 5){
					cout << "\nTerima kasih telah menggunakan layanan kami. Semoga lekas sehat!" << endl;
					system("pause");
				}
				
			}while(pilihPelanggan != 5);
		
		}else if (pilihan == 3){
			cout << "Program selesai.\n";
		}else{
			system("cls");
		}
	
	}while (pilihan != 3);

	return 0;
}
