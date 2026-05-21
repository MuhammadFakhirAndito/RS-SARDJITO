#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int MAX_QUEUE = 100;
const int MAX_STACK = 100;

int idCounter = 1001;

// =====================
// DATA PASIEN
// =====================
struct Pasien{
	int id;
	char nama[100];
	char keluhan[200];
	char status[50];
};

// =====================
// LINKED LIST
// =====================
struct NodePasien{
	Pasien data;
	NodePasien* next;
};

NodePasien* head = NULL;

// =====================
// QUEUE (ID pasien)
// =====================
int antrian[MAX_QUEUE];
int front = 0;
int rear = -1;
int jumlahQueue = 0;

// =====================
// STACK (riwayat)
// =====================
char riwayat[MAX_STACK][200];
int top = -1;

// =====================
// BST
// =====================
struct NodeBST{
	int id;
	NodePasien* pasien;
	NodeBST* kiri;
	NodeBST* kanan;
};

NodeBST* root = NULL;


// =====================
// FUNGSI STRING
// =====================
void salin(char tujuan[], const char sumber[]){
	int i = 0;
	while(sumber[i] != '\0'){
		tujuan[i] = sumber[i];
		i++;
	}
	tujuan[i] = '\0';
}

int banding(char a[], char b[]){
	int i = 0;
	while(a[i] != '\0' && b[i] != '\0'){
		if(a[i] != b[i]){
			return a[i] - b[i];
		}
		i++;
	}
	return a[i] - b[i];
}


// =====================
// BUAT PASIEN
// =====================
Pasien buatPasien(char nama[], char keluhan[]){
	Pasien p;
	p.id = idCounter++;

	salin(p.nama, nama);
	salin(p.keluhan, keluhan);
	salin(p.status, "Menunggu");

	return p;
}


// =====================
// STACK
// =====================
void pushRiwayat(const char teks[]){
	if(top < MAX_STACK - 1){
		top++;
		salin(riwayat[top], teks);
	}
}

void tampilRiwayat(){
	if(top == -1){
		cout << "Belum ada riwayat.\n";
		return;
	}

	for(int i = top; i >= 0; i--){
		cout << top - i + 1 << ". " << riwayat[i] << endl;
	}
}


// =====================
// QUEUE
// =====================
int queueKosong(){
	return jumlahQueue == 0;
}

int queuePenuh(){
	return jumlahQueue == MAX_QUEUE;
}

void enqueue(int id){
	if(queuePenuh()){
		cout << "Antrian penuh.\n";
		return;
	}

	rear++;
	antrian[rear] = id;
	jumlahQueue++;
}

int dequeue(){
	if(queueKosong()){
		return -1;
	}

	int id = antrian[front];
	front++;
	jumlahQueue--;

	return id;
}

void tampilAntrian(){
	if(queueKosong()){
		cout << "Antrian kosong.\n";
		return;
	}

	for(int i = front; i <= rear; i++){
		cout << i - front + 1 << ". ID " << antrian[i] << endl;
	}
}


// =====================
// LINKED LIST
// =====================
NodePasien* tambahPasienAktif(Pasien p){
	NodePasien* baru = new NodePasien;
	baru->data = p;
	baru->next = NULL;

	if(head == NULL){
		head = baru;
		return baru;
	}

	NodePasien* bantu = head;
	while(bantu->next != NULL){
		bantu = bantu->next;
	}

	bantu->next = baru;
	return baru;
}

NodePasien* cariPasienAktif(int id){
	NodePasien* bantu = head;

	while(bantu != NULL){
		if(bantu->data.id == id){
			return bantu;
		}
		bantu = bantu->next;
	}

	return NULL;
}

void tampilPasienAktif(){
	if(head == NULL){
		cout << "Belum ada pasien aktif.\n";
		return;
	}

	NodePasien* bantu = head;

	while(bantu != NULL){
		cout << "\nID      : " << bantu->data.id << endl;
		cout << "Nama    : " << bantu->data.nama << endl;
		cout << "Keluhan : " << bantu->data.keluhan << endl;
		cout << "Status  : " << bantu->data.status << endl;

		bantu = bantu->next;
	}
}


// =====================
// BST
// =====================
NodeBST* insertBST(NodeBST* node, NodePasien* pasien){
	if(node == NULL){
		NodeBST* baru = new NodeBST;
		baru->id = pasien->data.id;
		baru->pasien = pasien;
		baru->kiri = NULL;
		baru->kanan = NULL;
		return baru;
	}

	if(pasien->data.id < node->id){
		node->kiri = insertBST(node->kiri, pasien);
	}else if(pasien->data.id > node->id){
		node->kanan = insertBST(node->kanan, pasien);
	}

	return node;
}

NodeBST* cariBST(NodeBST* node, int id){
	if(node == NULL || node->id == id){
		return node;
	}

	if(id < node->id){
		return cariBST(node->kiri, id);
	}

	return cariBST(node->kanan, id);
}

// =====================
// HAPUS PASIEN AKTIF
// =====================
void hapusPasienAktif(int id){
	if(head == NULL) return;

	if(head->data.id == id){
		NodePasien* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	NodePasien* bantu = head;

	while(bantu->next != NULL){
		if(bantu->next->data.id == id){
			NodePasien* temp = bantu->next;
			bantu->next = temp->next;
			delete temp;
			return;
		}
		bantu = bantu->next;
	}
}


// =====================
// HAPUS BST
// =====================
NodeBST* cariMin(NodeBST* node){
	while(node->kiri != NULL){
		node = node->kiri;
	}
	return node;
}

NodeBST* hapusBST(NodeBST* node, int id){
	if(node == NULL) return NULL;

	if(id < node->id){
		node->kiri = hapusBST(node->kiri, id);
	}
	else if(id > node->id){
		node->kanan = hapusBST(node->kanan, id);
	}
	else{
		if(node->kiri == NULL){
			NodeBST* temp = node->kanan;
			delete node;
			return temp;
		}
		else if(node->kanan == NULL){
			NodeBST* temp = node->kiri;
			delete node;
			return temp;
		}

		NodeBST* temp = cariMin(node->kanan);

		node->id = temp->id;
		node->pasien = temp->pasien;
		node->kanan = hapusBST(node->kanan, temp->id);
	}

	return node;
}


// =====================
// SIMPAN FILE
// =====================
void simpanArsip(Pasien p){
	FILE* file = fopen("arsip_pasien.txt", "a");

	if(file == NULL){
		cout << "Gagal membuka file.\n";
		return;
	}

	fprintf(file, "%d|%s|%s|%s\n",
		p.id,
		p.nama,
		p.keluhan,
		p.status);

	fclose(file);
}


// =====================
// CARI DI FILE
// =====================
void cariDiFile(int id){
	FILE* file = fopen("arsip_pasien.txt", "r");

	if(file == NULL){
		cout << "Data arsip belum ada.\n";
		return;
	}

	int fid;
	char nama[100];
	char keluhan[200];
	char status[50];

	while(fscanf(file, "%d|%99[^|]|%199[^|]|%49[^\n]\n",
		&fid,
		nama,
		keluhan,
		status) == 4){

		if(fid == id){
			cout << "\nData ditemukan di arsip\n";
			cout << "ID      : " << fid << endl;
			cout << "Nama    : " << nama << endl;
			cout << "Keluhan : " << keluhan << endl;
			cout << "Status  : " << status << endl;

			fclose(file);
			return;
		}
	}

	fclose(file);
	cout << "Pasien tidak ditemukan.\n";
}


// =====================
// SORTING NAMA
// =====================
void sortingNama(){
	if(head == NULL || head->next == NULL){
		return;
	}

	NodePasien* i;
	NodePasien* j;

	for(i = head; i != NULL; i = i->next){
		for(j = i->next; j != NULL; j = j->next){
			if(banding(i->data.nama, j->data.nama) > 0){
				Pasien temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}


// =====================
// DAFTAR PASIEN
// =====================
void daftarPasien(){
	char nama[100];
	char keluhan[200];

	cin.ignore();

	cout << "Masukkan nama pasien    : ";
	cin.getline(nama, 100);

	cout << "Masukkan keluhan pasien : ";
	cin.getline(keluhan, 200);

	Pasien p = buatPasien(nama, keluhan);

	enqueue(p.id);

	char log[200];
	sprintf(log, "Pasien ID %d mendaftar", p.id);
	pushRiwayat(log);

	FILE* file = fopen("pendaftaran.txt", "a");

	if(file != NULL){
		fprintf(file, "%d|%s|%s|%s\n",
			p.id,
			p.nama,
			p.keluhan,
			p.status);
		fclose(file);
	}

	cout << "\nPendaftaran berhasil.\n";
	cout << "ID pasien    : " << p.id << endl;
	cout << "Nomor antrian: " << jumlahQueue << endl;
}


// =====================
// PANGGIL PASIEN
// =====================
void panggilPasien(){
	int id = dequeue();

	if(id == -1){
		cout << "Tidak ada antrian.\n";
		return;
	}

	FILE* file = fopen("pendaftaran.txt", "r");

	if(file == NULL){
		cout << "Data pendaftaran tidak ada.\n";
		return;
	}

	int fid;
	char nama[100];
	char keluhan[200];
	char status[50];

	while(fscanf(file, "%d|%99[^|]|%199[^|]|%49[^\n]\n",
		&fid,
		nama,
		keluhan,
		status) == 4){

		if(fid == id){
			Pasien p;
			p.id = fid;
			salin(p.nama, nama);
			salin(p.keluhan, keluhan);
			salin(p.status, "Diproses");

			NodePasien* node = tambahPasienAktif(p);
			root = insertBST(root, node);

			char log[200];
			sprintf(log, "Pasien ID %d dipanggil", p.id);
			pushRiwayat(log);

			cout << "Pasien " << p.nama << " dipanggil.\n";

			fclose(file);
			return;
		}
	}

	fclose(file);
}


// =====================
// SELESAI PEMERIKSAAN
// =====================
void selesaiPemeriksaan(){
	int id;
	cout << "Masukkan ID pasien: ";
	cin >> id;

	NodeBST* hasil = cariBST(root, id);

	if(hasil == NULL){
		cout << "Pasien aktif tidak ditemukan.\n";
		return;
	}

	salin(hasil->pasien->data.status, "Selesai");

	simpanArsip(hasil->pasien->data);

	char log[200];
	sprintf(log, "Pasien ID %d selesai diperiksa", id);
	pushRiwayat(log);

	root = hapusBST(root, id);
	hapusPasienAktif(id);

	cout << "Pemeriksaan selesai.\n";
}


// =====================
// CARI PASIEN
// =====================
void cariPasien(){
	int id;
	cout << "Masukkan ID pasien: ";
	cin >> id;

	NodeBST* hasil = cariBST(root, id);

	if(hasil != NULL){
		cout << "\nData ditemukan di pasien aktif\n";
		cout << "ID      : " << hasil->pasien->data.id << endl;
		cout << "Nama    : " << hasil->pasien->data.nama << endl;
		cout << "Keluhan : " << hasil->pasien->data.keluhan << endl;
		cout << "Status  : " << hasil->pasien->data.status << endl;
		return;
	}

	cariDiFile(id);
}

void menuMedic(){
	int pilihKaryawan;

	do{
		cout << "\n=======================================\n";
		cout << "||            WELCOME MEDIC!          ||\n";
		cout << "=======================================\n";
		cout << "||1. Tampilkan Pasien Aktif\n";
		cout << "||2. Lihat Antrian Pasien\n";
		cout << "||3. Panggil Pasien\n";
		cout << "||4. Selesaikan Pemeriksaan\n";
		cout << "||5. Riwayat Pasien\n";
		cout << "||6. Cari Pasien\n";
		cout << "||7. Sorting Nama Pasien Aktif\n";
		cout << "||8. Logout\n";
		cout << "=======================================\n";
		cout << "||Pilihan  : ";
		cin >> pilihKaryawan;

		if(pilihKaryawan == 1){
			tampilPasienAktif();
		}
		else if(pilihKaryawan == 2){
			tampilAntrian();
		}
		else if(pilihKaryawan == 3){
			panggilPasien();
		}
		else if(pilihKaryawan == 4){
			selesaiPemeriksaan();
		}
		else if(pilihKaryawan == 5){
			tampilRiwayat();
		}
		else if(pilihKaryawan == 6){
			cariPasien();
		}
		else if(pilihKaryawan == 7){
			sortingNama();
			cout << "Data pasien aktif berhasil diurutkan.\n";
		}
		else if(pilihKaryawan == 8){
			cout << "Terimakasih Medic, Selamat Beristirahat!\n";
		}

	}while(pilihKaryawan != 8);
}



void menuPasien(){
	int pilihPelanggan;

	do{
		cout << "\n=======================================\n";
		cout << "||            WELCOME MATE!           ||\n";
		cout << "=======================================\n";
		cout << "||1. Daftar\n";
		cout << "||2. Cek Status Antrian\n";
		cout << "||3. Cari Data Pasien\n";
		cout << "||4. Logout\n";
		cout << "=======================================\n";
		cout << "||Pilihan  : ";
		cin >> pilihPelanggan;

		if(pilihPelanggan == 1){
			daftarPasien();
		}
		else if(pilihPelanggan == 2){
			tampilAntrian();
		}
		else if(pilihPelanggan == 3){
			cariPasien();
		}
		else if(pilihPelanggan == 4){
			cout << "\nTerima kasih telah menggunakan layanan kami. Semoga lekas sehat!\n";
		}

	}while(pilihPelanggan != 4);
}

int main(){
	int pilihan;

	do{
		cout << "=======================================\n";
		cout << "||       WELCOME TO RS SARDJITO      ||\n";
		cout << "=======================================\n";
		cout << "||1. Masuk sebagai medic\n";
		cout << "||2. Masuk sebagai pasien\n";
		cout << "||3. Keluar\n";
		cout << "=======================================\n";
		cout << "||Pilihan  : ";
		cin >> pilihan;

		if(pilihan == 1){
			string usn;
			int pass;

			cout << "\n=======================================\n";
			cout << "||             Halo Medic!            ||\n";
			cout << "=======================================\n";

			cout << "Masukkan Username : ";
			cin >> usn;

			cout << "Masukkan Password : ";
			cin >> pass;

			if(
				usn == "admin" &&
				pass == 123
			){
				menuMedic();
			}
			else{
				cout << "\nUsername atau password salah!\n";
			}
		}
		else if(pilihan == 2){
			menuPasien();
		}
		else if(pilihan == 3){
			cout << "Sampai jumpa! Terima kasih.\n";
		}

	}while(pilihan != 3);

	return 0;
}

