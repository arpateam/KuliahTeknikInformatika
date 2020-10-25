#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct isi{
	int banyakData; 
	int isiDatanya[100]; 
	int modus;
	float mean; 
	float median;
};

class Statistic{
	public:
		void header();
		float mengisiData(isi*);
		int data(isi*);
		int mengurutkanData(isi*);
		int cetakDataUrut(isi);
		float mencariMean(isi);
		float mencariMedian(isi);
		int mencariModus(isi);		
};

void Statistic::header(){
	cout <<"=== Mencari data statistik Mean, Median & Modus ===\n\n";	
}

// Program Mengisi data ke dalam Array
float Statistic::mengisiData(isi *x){
	x->isiDatanya[x->banyakData];
		for(int i=0; i<x->banyakData; i++){
			cout << "   Masukkan data pada index ke-" << i << ": ";
			cin >> x->isiDatanya[i];
		}	
}

//program untuk menampilkan hasil input data
int Statistic::data(isi *x){
	
	cout<<"\n\n=== Data Sebelum Diurutkan ===\n\n";
		
		for(int i=0;i<x->banyakData;i++){
			cout<<x->isiDatanya[i]<<" ";
		}
}

// Program mengurutkan data yang telah di isi	
int Statistic::mengurutkanData(isi *x){

	int i, j, l, tmp;
		for (i = 0; i < x->banyakData; i++){
    		for (j = 0; j < x->banyakData - i - 1; j++){
				if (x->isiDatanya[j] > x->isiDatanya[j + 1]){
        		tmp = x->isiDatanya[j];
        		x->isiDatanya[j] = x->isiDatanya[j + 1];
        		x->isiDatanya[j + 1] = tmp;}
			}
		}		
}

// Program untuk mencetak data yang telah di urutkan
int Statistic::cetakDataUrut(isi x){
	cout << "\n\n=== Data Yang Telah Di Urutkan ===\n\n";
		for(int i=0; i<x.banyakData; i++){
			cout << x.isiDatanya[i] << " ";
		}
}

//program untuk mencari mean
float Statistic::mencariMean(isi x){
	float jumlahIsiData=0;
	
		for(int i=0; i<x.banyakData; i++) {
			jumlahIsiData+=x.isiDatanya[i];
		}
		x.mean = jumlahIsiData/x.banyakData;
		return x.mean;	
}

//Program untuk mencari nilai median
float Statistic::mencariMedian(isi x){
 
	int median1=0, median2=0;
		if(x.banyakData%2 == 0) {
			median1 = x.banyakData/2;
			median2 = median1+1;
			median1 = x.isiDatanya[median1-1];
			median2 = x.isiDatanya[median2-1];
			x.median = ((float(median1)+median2)/2);
		} else if(x.banyakData%2 != 0) {
			median1 = x.banyakData/2;
			x.median = x.isiDatanya[median1];
		}
	return x.median;		
	
}

// Program untuk mencari nilai modus
int Statistic::mencariModus(isi x){

	int nilaiModusSementara=0, jumlahNilaiModusSementara=0, nilaiModus=0, jumlahNilaiModus=0;
	
	for(int i=0;i<x.banyakData;i++){
		
		for(int j=0;j<x.banyakData;j++){
			
			if(x.isiDatanya[i]==x.isiDatanya[j]){	
				
				jumlahNilaiModusSementara+=1;
				
				if(jumlahNilaiModusSementara>=jumlahNilaiModus){
					nilaiModusSementara = x.isiDatanya[i];
					
					jumlahNilaiModus = jumlahNilaiModusSementara;
					nilaiModus = nilaiModusSementara;
				}
				
			}
		}
		jumlahNilaiModusSementara=0;
	}

	if(jumlahNilaiModus==1){
		nilaiModus = 0;
	}
	
	x.modus = nilaiModus;
	
}


// Program utama
main(){
	ofstream myfile;	//open file
	
	//penginisialisasian object x untuk struct isi dan object s untuk class Statistic
	isi x;
	Statistic s;
	
	s.header();

	cout << "Masukkan banyaknya data: ";
	cin >> x.banyakData;
	cout<<endl;	
	
	//pemanggilan program
	s.mengisiData(&x);
	s.data(&x);
	s.mengurutkanData(&x);
	s.cetakDataUrut(x);
	
	cout << "\n\n\n=== Hasil Data Statistikanya ===\n";
	cout << "\n1. Mean-nya adalah\t= " << s.mencariMean(x);
	cout << "\n2. Median-nya adalah\t= " << s.mencariMedian(x);
	cout << "\n3. Modus-nya adalah\t= " << s.mencariModus(x);
	
	//program untuk open file
		myfile.open("Simpandata.txt", ios::app);	//penamaan file
		//fail() -> untuk memeriksa suatu kesalahan pada operasi file
		if(!myfile.fail()) {
			myfile<<"\n===================================================\n";
			myfile<< "\n=== Hasil Data Statistikanya ===\n\n";
			myfile<< "\n1. Mean-nya adalah\t= " << s.mencariMean(x);
			myfile<< "\n2. Median-nya adalah\t= " << s.mencariMedian(x);
			myfile<< "\n3. Modus-nya adalah\t= " << s.mencariModus(x);
			myfile.close(); //menutup file
			cout<<"\n\nText telah ditulis ke dalam File"<<endl;
		} else {
			cout<<"File tidak ditemukan"<<endl;
		}
		_getche();
		
	return 0;
}
